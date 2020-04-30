#include "hpp/screentxt.hpp"

// constructors

TextWindow::TextWindow(int x, int y) {
  //загружаем спрайт окошечка
  font.loadFromFile("fonts/3976.ttf");
  texture.loadFromFile("images/text_window.png");
  sprite.setTexture(texture);
  setPosition(x, y);
  //текст
  text_color = sf::Color::Black;
  dubler_color = sf::Color::Black;
  font_size = 25;  // размер текста
  margin_y = 10;   // расстояние между строками
  start_str = 0;  // строка с которой начинается вывод
  curr_sym = 0;  //текущий символ
}

//функции
//обновляем текст дублера
void TextWindow::add_sym_to_dubler(wchar_t sym) {
  dubler_str.push_back(sym);
  dubler.setString(dubler_str);
}
void TextWindow::pop_sym_to_dubler() {
  dubler_str.pop_back();
  dubler.setString(dubler_str);
}
void TextWindow::dubler_fill() {
  dubler_str = text_str[start_str];
  dubler_str.pop_back();  // убираю один символ
  dubler.setString(dubler_str);
  curr_sym = dubler_str.size();
}
void TextWindow::dubler_clean() {
  curr_sym = 0;
  dubler_str.clear();
  dubler.setString("");
}

void TextWindow::checksym_dubler(int symbol) {
  //отдельно если ввели backspace (8)
  if (symbol == 8) {
    //и  если текущий сивол не первый
    if (curr_sym > 0) {
      pop_sym_to_dubler();
      curr_sym--;
    }
    //если это не первая строка
    else if (start_str > 0) {
      back_text_str();  // сдвиг текста в  окошке
      dubler_fill();  // заполняем дублер всей строкой
    }
  }
  //если текущий символ равен введеному
  if (symbol == (int)text_str[start_str][curr_sym]) {
    std::cout << "right" << text_str[start_str][curr_sym] << std::endl;
    std::cout << "was: " << curr_sym << std::endl;
    add_sym_to_dubler(text_str[start_str][curr_sym]);
    curr_sym++;  //сдвигаем текущий символ
  }
  if (curr_sym == text_str[start_str].size()) {
    dubler_clean();   // сбрасываем дублер
    next_text_str();  // сдвиг текста в  окошке
  }
}
//меняет характеристики текста для вывода
void TextWindow::change_text_character() {
  sprite.setPosition(position.x, position.y);  // ставим окошко в  позицию
  //стираем все  что было ДО в  векторе
  for (int i = 0; i < vec_text.size(); i++) {
    vec_text[i].setString("");
  }
  vec_text.resize(
      count_text_string);  // меняем размер вектора = кол-ву строк в окошке

  std::cout << "razmer vec" << vec_text.size() << std::endl;
  std::cout << "razmer str" << text_str.size() << std::endl;
  for (int i = start_str, j = 0; i < text_str.size(); i++, j++) {
    if (i - start_str >= count_text_string || i >= text_str.size())
      break;  // условия остановки
    vec_text[j].setFont(font);
    vec_text[j].setFillColor(Color::Black);
    vec_text[j].setCharacterSize(font_size);
    vec_text[j].setPosition(getPosition().x + 20,
                            getPosition().y + ((margin_y + font_size) * j));
    vec_text[j].setString(text_str[i]);
  }
  //характериситики дублера
  dubler.setFont(font);
  dubler.setCharacterSize(font_size);
  dubler.setFillColor(dubler_color);
  dubler.setOutlineColor(Color::Green);
  dubler.setOutlineThickness(1);
  dubler.setStyle(Text::Underlined);
  dubler.setPosition(vec_text[0].getPosition());
}

//рисуем текст внутри окна
void TextWindow::DrawTextWindow(RenderWindow &window) {
  window.draw(sprite);  // фон
                        //рисуем текст
  for (int i = 0; i < vec_text.size(); i++) {
    window.draw(vec_text[i]);
  }
  //а тут дублер по верх текста
  window.draw(dubler);
}
//считаем сколько строк поместится в окно
void TextWindow::change_count_text_str() {
  std::cout << "text str size" << text_str.size() << std::endl;
  Text text_help("S", font, font_size);
  for (int i = 1; i <= text_str.size(); i++) {
    std::cout << (text_help.getLocalBounds().height + margin_y) * i
              << std::endl;
    if ((text_help.getLocalBounds().height + margin_y) * (i + 1) >
            sprite.getLocalBounds().height - (font_size * 2) ||
        i == text_str.size()) {
      count_text_string = i;
      break;
    }
  }
  std::cout << "text height" << text_help.getLocalBounds().height << std::endl;
}

void TextWindow::next_text_str() {
  start_str++;
  change_text_character();
}
void TextWindow::back_text_str() {
  start_str--;
  change_text_character();
}

//добовление слова в  текст
void TextWindow::add_word_in_text(std::vector<std::wstring> &text, Word word,
                                  int j)  //не тестированно
{
  text[j].append(word.get_word());
  text[j].push_back(L' ');
}
// конвертирование файла в вектор с текстом
std::vector<std::wstring> TextWindow::convert_file_to_text(
    std::string filename) {
  Text text_help("W", font, font_size);
  std::wstring str = readfile_to_wstr(filename);
  std::vector<std::wstring> text;
  Word word;
  text.resize(1);
  int j = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] != L' ') {
      word.add(str[i]);
    } else {
      text_help.setString(text[j] + word.get_word());
      std::cout << "wtaf " << text_help.getLocalBounds().width << std::endl;

      if (text_help.getLocalBounds().width <
          sprite.getLocalBounds().width - 30) {
        add_word_in_text(text, word, j);
        word.clean();
      } else {
        text[j].pop_back();  // убираем пробел который  написался в конце
        j++;
        text.resize(j + 1);
        add_word_in_text(text, word, j);
        word.clean();
      }
    }
  }
  text[text.size() - 1].pop_back();  //// убираем пробелс  последней строки

  return text;
}

// setters
void TextWindow::setPosition(int x, int y) {
  position.x = x;
  position.y = y;
}
void TextWindow::setText(std::string filename) {
  text_str = convert_file_to_text(filename);
}

// getters
Vector2i TextWindow::getPosition() { return position; }
