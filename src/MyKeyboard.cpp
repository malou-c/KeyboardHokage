#include "MyKeyboard.hpp"

//конструкторы
MyKeyboard::MyKeyboard(int x, int y)
{
    const int count_code = 4;
    const int num_in_line[4] = {13, 12, 11, 10};
    //используется для проверки нажатий
    wchar_t code_line1[num_in_line[0]][count_code]
            = {{L'`', L'~', L'ё', L'Ё'},
               {L'1', L'!', L'1', L'!'},
               {L'2', L'@', L'2', L'2'},
               {L'3', L'#', L'3', L'№'},
               {L'4', L'$', L'4', L'4'},
               {L'5', L'%', L'5', L'%'},
               {L'6', L'^', L'6', L'6'},
               {L'7', L'&', L'7', L'7'},
               {L'8', L'*', L'8', L'*'},
               {L'9', L'(', L'9', L'('},
               {L'0', L')', L'0', L')'},
               {L'r', L'R', L'к', L'К'},
               {L't', L'T', L'е', L'Е'},
               {L'-', L'_', L'-', L'_'},
               {L'=', L'+', L'=', L'+'}};
    wchar_t code_line2[num_in_line[1]][count_code]
            = {{L'q', L'Q', L'й', L'Й'},
               {L'w', L'W', L'ц', L'Ц'},
               {L'e', L'E', L'у', L'У'},
               {L'y', L'Y', L'н', L'Н'},
               {L'u', L'U', L'г', L'Г'},
               {L'i', L'I', L'ш', L'Ш'},
               {L'o', L'O', L'щ', L'Щ'},
               {L'p', L'P', L'з', L'З'},
               {L'[', L'[', L'х', L'Х'},
               {L']', L']', L'ъ', L'Ъ'}};
    wchar_t code_line3[num_in_line[2]][count_code]
            = {{L'a', L'A', L'ф', L'Ф'},
               {L's', L'S', L'ы', L'Ы'},
               {L'd', L'D', L'в', L'В'},
               {L'f', L'F', L'а', L'А'},
               {L'g', L'G', L'п', L'П'},
               {L'h', L'H', L'р', L'Р'},
               {L'j', L'J', L'о', L'О'},
               {L'k', L'K', L'л', L'Л'},
               {L'l', L'L', L'д', L'Д'},
               {L'ж', L'Ж', L'ж', L'Ж'},
               {L'э', L'Э', L'э', L'Э'}};
    wchar_t code_line4[num_in_line[3]][count_code]
            = {{L'z', L'Z', L'я', L'Я'},
               {L'x', L'X', L'ч', L'Ч'},
               {L'c', L'C', L'с', L'С'},
               {L'v', L'V', L'м', L'М'},
               {L'b', L'B', L'и', L'И'},
               {L'n', L'N', L'т', L'Т'},
               {L'm', L'M', L'ь', L'Ь'},
               {L'<', L'<', L'б', L'Б'},
               {L'>', L'>', L'ю', L'Ю'},
               {L'/', L'/', L'/', L'/'}};
    int size_vec
            = num_in_line[0] + num_in_line[1] + num_in_line[2] + num_in_line[3];
    vec_buttons.resize(size_vec);

    //переменные нужные только один раз для заполнения
    int start_fill_but = 0;
    int indentX_line[5] = {0, 80, 80, 64, 260};
    int indent_between = 68;
    sf::Vector2i tile_size(64, 57);
    //заполнение кнопок
    for (size_t num = 0; num < count_code; num++) {
        for (int i = start_fill_but, j = 0; j < num_in_line[num]; i++, j++) {
            //берем нужный тайл и ставим в позицию
            vec_buttons[i].sprite.setTextureRect(sf::IntRect(
                    j * tile_size.x,
                    num * tile_size.y,
                    tile_size.x,
                    tile_size.y));
            vec_buttons[i].sprite.setPosition(
                    x + (indent_between * j) + indentX_line[num],
                    y + (num * indent_between));
            //заполняем коды кнопок
            for (int k = 0; k < count_code; k++) {
                switch (num) {
                case 0:
                    vec_buttons[i].code[k] = code_line1[j][k];
                    break;
                case 1:
                    vec_buttons[i].code[k] = code_line2[j][k];
                    break;
                case 2:
                    vec_buttons[i].code[k] = code_line3[j][k];
                    break;
                case 3:
                    vec_buttons[i].code[k] = code_line4[j][k];
                    break;
                default:
                    break;
                }
            }
        }
        start_fill_but += num_in_line[num];
    }
    // SPACE
    space.sprite.setPosition(x + indentX_line[4], y + indent_between * 4);
    // BACKSPACE
    backspace.sprite.setPosition(x + (indent_between * num_in_line[0]), y);
    // SHIFT
    shift.sprite.setPosition(x, y + (indent_between * 2));
}
//функции
void MyKeyboard::DrawKB(sf::RenderWindow& window)
{
    for (unsigned int i = 0; i < vec_buttons.size(); i++) {
        vec_buttons[i].DrawButton(window);
    }
    // draw sys but
    space.DrawButton(window);
    backspace.DrawButton(window);
    shift.DrawButton(window);
}

// get
sf::Vector2i MyKeyboard::getPosition()
{
    return position;
}

// set
void MyKeyboard::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void MyKeyboard::Update(sf::Event event, TextWindow& txwin, bool hardmode)
{
    int symbol;
    switch (event.type) {
    // нажатие клавиши
    case sf::Event::TextEntered:
        symbol = (int)event.text.unicode;
        //если строка не кончилась
        if (!txwin.isEndString) {
            //символ который нажали проверяем в окне
            txwin.checksym_dubler(symbol, hardmode);
        }

        //меняем цвет клавиши
        for (unsigned int i = 0; i < vec_buttons.size(); i++) {
            for (int j = 0; j < 4; j++) {
                if ((int)vec_buttons[i].code[j] == symbol) {
                    vec_buttons[i].sprite.setColor(color_enable);
                    break;
                }
            }
        }
        if ((int)event.text.unicode == space.code) {
            space.sprite.setColor(color_enable);
        } else if ((int)event.text.unicode == backspace.code) {
            backspace.sprite.setColor(color_enable);
        }
        break;
    case sf::Event::KeyPressed:

        break;

    default:
        //меняем цвет  обратно
        //у  кнопок
        for (unsigned int i = 0; i < vec_buttons.size(); i++) {
            vec_buttons[i].sprite.setColor(color_def);
        }
        space.sprite.setColor(color_def);     // у  пробела
        backspace.sprite.setColor(color_def); // у backspace
        // шифт
        if (shift.sprite.getColor() != color_def) {
            shift.sprite.setColor(color_def);
        }
        break;
    }

    //нажатие шифт
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        shift.sprite.setColor(color_enable);
    }
    // спорное решение решающее отрисовку двух разных клавиш с одинаковым кодом
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Semicolon)) {
        vec_buttons[34].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
        vec_buttons[35].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
        vec_buttons[2].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
        vec_buttons[4].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
        vec_buttons[6].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
        vec_buttons[7].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Slash)) {
        vec_buttons[45].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
        vec_buttons[44].sprite.setColor(color_enable);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {
        vec_buttons[43].sprite.setColor(color_enable);
    }
}
