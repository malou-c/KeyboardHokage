#include "text_selection.hpp"

TextSelection::TextSelection(int x, int y)
{
    //устанавливаем позицию
    pos.x = x;
    pos.y = y;
    // font
    font.loadFromFile("fonts/stdFont.ttf");
    // background
    texture_bg.loadFromFile("images/TS_background.png");
    background.setTexture(texture_bg);
    background.setPosition(pos.x, pos.y);
    //отступы для секций
    indent_sect.x = 8;
    indent_sect.y = 48;
    //класс работы с папками
    std::string path_folder = "texts";
    Folder folder(path_folder);

    //секции
    name_folders = folder.contains();
    sections.resize(name_folders.size());
    int height_sect = sections[0].sprite_sect.getLocalBounds().height;
    for (size_t i = 0; i < name_folders.size(); i++) {
        // позиция секций
        sections[i].sprite_sect.setPosition(
                x + indent_sect.x,
                y + indent_sect.y + ((i % 10) * height_sect));

        // название текста
        sf::Text txt(name_folders[i], font, 40);
        txt.setFillColor(sf::Color::Black);
        txt.setPosition(
                x + indent_sect.x,
                y + indent_sect.y + ((i % 10) * height_sect));
        sections[i].name_txt = txt;
    }
    recount_sect(); //изначальный подсчет секций
    //кнопки << >>
    but_pos.x = background.getPosition().x + 260;
    but_pos.y = background.getPosition().y + background.getLocalBounds().height
            + 8;
    texture_but_left.loadFromFile("images/TS_button_left.png");
    but_left.setTexture(texture_but_left);
    but_left.setPosition(but_pos);
    texture_but_right.loadFromFile("images/TS_button_right.png");
    but_right.setTexture(texture_but_right);
    //отступ для второй кнопки
    float indent_x = but_left.getLocalBounds().width + 20;
    but_right.setPosition(
            but_left.getPosition().x + indent_x, but_left.getPosition().y);
}

void TextSelection::update_sections(
        TextWindow& txtwin, sf::Event event, sf::RenderWindow& window)
{
    for (size_t i = start_sect; i < count_draw_sect; i++) {
        //если не текущая секция то проверяем
        if ((int)i != curr_sect) {
            if (sf::IntRect(sections[i].sprite_sect.getGlobalBounds())
                        .contains(sf::Mouse::getPosition(window))) {
                sections[i].sprite_sect.setColor(color_contain);
                if (event.type == event.MouseButtonPressed
                    && event.mouseButton.button == sf::Mouse::Left) {
                    curr_sect = i; // обновляем текущую секцию
                    //меняем цвет активной секции
                    sections[curr_sect].sprite_sect.setColor(
                            sf::Color(color_curr));
                    //меняем параметры текста на новый
                    std::string path_txt = "texts/" + name_folders[curr_sect];
                    txtwin.setText(path_txt); // берем текст
                }
            } else {
                sections[i].sprite_sect.setColor(sf::Color::White);
            }
        }
    }
}

void TextSelection::but_update(sf::Event event, sf::RenderWindow& window)
{
    // <<
    if (start_sect != 0) {
        if (relise_L && isClicked(but_left, window, event)) {
            but_left.setColor(sf::Color(10, 10, 120, 80));
            relise_L = false;
            start_sect -= count_section;
            recount_sect();
        } else if (!relise_L && isReleased(event)) {
            but_left.setColor(sf::Color::White);
            relise_L = true;
        }
    } else if (but_left.getColor() != disable_color) {
        but_left.setColor(disable_color);     // выключаем L
        but_right.setColor(sf::Color::White); // включаем R
    }
    // >>
    if (start_sect + count_section < sections.size()) {
        if (relise_R && isClicked(but_right, window, event)) {
            but_right.setColor(sf::Color(10, 10, 120, 80));
            relise_R = false;
            start_sect += count_section;
            recount_sect();
        } else if (!relise_R && isReleased(event)) {
            but_right.setColor(sf::Color::White);
            relise_R = true;
        }
    } else if (but_right.getColor() != disable_color) {
        but_right.setColor(disable_color);   // выключаем  R
        but_left.setColor(sf::Color::White); // включаем L
    }
}

void TextSelection::recount_sect()
{
    sections.size() - start_sect >= count_section
            ? count_draw_sect = start_sect + count_section
            : count_draw_sect = sections.size();
}

void TextSelection::draw(sf::RenderWindow& window)
{
    //задний фон
    window.draw(background);
    //секции
    for (size_t i = start_sect; i < count_draw_sect; i++) {
        window.draw(sections[i].sprite_sect);
        window.draw(sections[i].name_txt);
    }
    //кнопки << >>
    window.draw(but_left);
    window.draw(but_right);
}

// getts

std::string TextSelection::getCurrent()
{
    return name_folders[curr_sect];
}