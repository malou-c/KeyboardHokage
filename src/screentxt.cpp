#include "screentxt.hpp"
// constructors

TextWindow::TextWindow(int x, int y, TextDubler& txtdubler)
{
    //текстовый дублер
    txtDubler = &txtdubler;
    //загружаем спрайт окошечка
    font.loadFromFile("fonts/3976.ttf");
    texture.loadFromFile("images/text_window.png");
    sprite.setTexture(texture);
    setPos(x, y);
    //текст
    text_color = sf::Color::Black;
    dubler_color = sf::Color::Black;
    font_size = 25; // размер текста
    margin_y = 12;  // расстояние между строками
    start_str = 0; // строка с которой начинается вывод
    curr_sym = 0; //текущий символ
}

//функции

void TextWindow::game_reset(ClockFace& clock)
{
    start_str = 0; // строка с которой начинается вывод
    curr_sym = 0;   //текущий символ
    dubler_clean(); //  чистим наложенный текст
    clock.ClockStop();
    clock.ClockReset();
    //дубер вводимых символов
    txtDubler->clear();
    //кончилась ли строка
    isEndString = false;
    // вычисляем сколько строк поместится в окно
    change_count_text_str();
    // вычисляем характеристики текста
    change_text_character();
}

wchar_t TextWindow::fount_sym_forTxtDub()
{
    int num_str = start_str;
    int num_curr_sym = curr_sym;
    // +1 потому что нужен следующий
    int move_sym = (txtDubler->setVecSize() - (txtDubler->countWrong())) + 1;
    if (move_sym > num_curr_sym) {
        move_sym -= (num_curr_sym + 1); //отнимаем от движения <- все символы с
                                        //текущей строки
        num_str--; //берем строку выше
        //текущий символ после сдвига <-
        num_curr_sym = (text_str[num_str].size() - 1) - move_sym;
        if (num_str < 0) {
            return L'*';
        }
        return text_str[num_str][num_curr_sym];
    }
    //сдвиг <-
    num_curr_sym -= move_sym;
    return text_str[num_str][num_curr_sym];
}

//обновляем текст дублера
void TextWindow::add_sym_to_dubler(wchar_t sym)
{
    dubler_str.push_back(sym);
    dubler.setString(dubler_str);
}
void TextWindow::pop_sym_to_dubler()
{
    dubler_str.pop_back();
    dubler.setString(dubler_str);
}
void TextWindow::dubler_fill()
{
    dubler_str = text_str[start_str];
    dubler_str.pop_back(); // убираю один символ
    dubler.setString(dubler_str);
    curr_sym = dubler_str.size();
}
void TextWindow::dubler_clean()
{
    curr_sym = 0;
    dubler_str.clear();
    dubler.setString("");
}

void TextWindow::checksym_dubler(int symbol, bool hardmode)
{
    //отдельно если ввели backspace (8)
    if (symbol == 8) {
        //находим букву для ТЕКСТОВОГО дублера
        wchar_t sym = fount_sym_forTxtDub();
        //если в  текстовом дублере есть wrong sym
        if (!txtDubler->isWrong()) {
            //и  если текущий сивол не первый
            if (curr_sym > 0) {
                pop_sym_to_dubler();
                curr_sym--;
            }
            //если это не первая строка
            else if (start_str > 0) {
                back_text_str(); // сдвиг текста в  окошке
                dubler_fill(); // заполняем дублер всей строкой
            }
        }
        //из текстового дублера в любом случае удаляем букву
        txtDubler->delsym(sym, hardmode);

    }
    //если текущий символ равен введеному и не было неверных
    else if (
            symbol == (int)text_str[start_str][curr_sym]
            && (!txtDubler->isWrong() || !hardmode)) {
        add_sym_to_dubler(text_str[start_str][curr_sym]);
        curr_sym++; //сдвигаем текущий символ
        //запись в дублер
        txtDubler->addsymCorrect(text_str[start_str][curr_sym - 1]);
        // cps +1 для текущей секунды
        txtDubler->cps_plus();
    } else {
        //запись в дублер
        txtDubler->addsymWrong((wchar_t)symbol);
    }

    if (curr_sym == (int)text_str[start_str].size()) {
        dubler_clean();  // сбрасываем дублер
        next_text_str(); // сдвиг текста в  окошке
    }
}
//меняет характеристики текста для вывода
void TextWindow::change_text_character()
{
    sprite.setPosition(position.x, position.y); // ставим окошко в  позицию
    //стираем все  что было ДО в  векторе
    for (size_t i = 0; i < vec_text.size(); i++) {
        vec_text[i].setString("");
    }
    // меняем размер вектора = кол-ву строк в окошке
    vec_text.resize(count_text_string);
    //если кончились строки
    if (start_str == (int)text_str.size())
        isEndString = true;
    sf::Vector2i indent(20, 3);
    for (int i = start_str, j = 0; i < (int)text_str.size(); i++, j++) {
        if (i - start_str >= count_text_string || i >= (int)text_str.size())
            break; // условия остановки
        vec_text[j].setFont(font);
        vec_text[j].setFillColor(sf::Color::Black);
        vec_text[j].setCharacterSize(font_size);
        vec_text[j].setPosition(
                getPosition().x + indent.x,
                getPosition().y + indent.y + ((margin_y + font_size) * j));
        vec_text[j].setString(text_str[i]);
    }
    //характериситики дублера
    dubler.setFont(font);
    dubler.setCharacterSize(font_size);
    dubler.setFillColor(dubler_color);
    dubler.setOutlineColor(sf::Color::Green);
    dubler.setOutlineThickness(1);
    dubler.setStyle(sf::Text::Underlined);
    dubler.setPosition(vec_text[0].getPosition());
}

//рисуем текст внутри окна
void TextWindow::DrawTextWindow(sf::RenderWindow& window)
{
    window.draw(sprite); // фон
                         //рисуем текст
    for (size_t i = 0; i < vec_text.size(); i++) {
        window.draw(vec_text[i]);
    }
    //а тут дублер поверх текста
    window.draw(dubler);
}

//считаем сколько строк поместится в окно
void TextWindow::change_count_text_str()
{
    sf::Text text_help("S", font, font_size);
    for (size_t i = 1; i <= text_str.size(); i++) {
        if ((text_help.getLocalBounds().height + margin_y) * (i + 1) + margin_y
                    > sprite.getLocalBounds().height - (font_size * 2)
            || i == text_str.size()) {
            count_text_string = i;
            break;
        }
    }
}

void TextWindow::next_text_str()
{
    start_str++;
    change_text_character();
}
void TextWindow::back_text_str()
{
    start_str--;
    change_text_character();
}

//добовление слова в  текст
void TextWindow::add_word_in_text(
        std::vector<std::wstring>& text,
        Word word,
        int j) //не тестированно
{
    text[j].append(word.get_word());
    text[j].push_back(L' ');
}
// конвертирование файла в вектор с текстом
std::vector<std::wstring> TextWindow::convert_file_to_text(std::string filename)
{
    sf::Text text_help("W", font, font_size);
    std::wstring str = readfile_to_wstr(filename);
    std::vector<std::wstring> text;
    Word word;
    text.resize(1);
    int j = 0;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] != L' ') {
            word.add(str[i]);
        } else {
            text_help.setString(text[j] + word.get_word());

            if (text_help.getLocalBounds().width
                < sprite.getLocalBounds().width - 30) {
                add_word_in_text(text, word, j);
                word.clean();
            } else {
                text[j].pop_back(); // убираем пробел который  написался в конце
                j++;
                text.resize(j + 1);
                add_word_in_text(text, word, j);
                word.clean();
            }
        }
    }
    text[text.size() - 1].pop_back(); //// убираем пробелс  последней строки

    return text;
}

// setters
void TextWindow::setPos(int x, int y)
{
    position.x = x;
    position.y = y;
    sprite.setPosition(x, y);
}
void TextWindow::setText(std::string filename)
{
    text_str = convert_file_to_text(filename);
}

// getters
sf::Vector2i TextWindow::getPosition()
{
    return position;
}
