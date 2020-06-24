#include "NameInput.hpp"

NameInput::NameInput(int x, int y)
{
    //пространство для отображения имени
    texture_nameplace.loadFromFile("images/NI_name_place.png");
    sprite_nameplace.setTexture(texture_nameplace);
    sprite_nameplace.setPosition(x, y);
    //кнопка изменения имени
    texture_changer.loadFromFile("images/NI_change_button.png");
    //прямоугольники для спрайтов
    rect_def = IntRect(
            0, 0, texture_changer.getSize().x / 2, texture_changer.getSize().y);
    rect_enable = IntRect(
            texture_changer.getSize().x / 2,
            0,
            texture_changer.getSize().x / 2,
            texture_changer.getSize().y);
    sprite_changer.setTexture(texture_changer);
    sprite_changer.setTextureRect(rect_def);
    //ставим в позицию сразу после имени
    sprite_changer.setPosition(x + sprite_nameplace.getGlobalBounds().width, y);

    //все для текста
    font.loadFromFile("fonts/stdFont.ttf");
    text.setPosition(x + 100, y + 10);
    text.setFont(font);
    text.setCharacterSize(font_size);
    text.setFillColor(font_color);
    text.setString(temp_name);
};

void NameInput::update(sf::RenderWindow& window, sf::Event event)
{
    if (isFullClick(sprite_changer, window, event)) {
        // ON-OFF
        if (input_on) {
            input_on = false;
            sprite_changer.setTextureRect(rect_def);
        } else {
            input_on = true;
            sprite_changer.setTextureRect(rect_enable);
        }
    }

    if (input_on && event.type == sf::Event::TextEntered
        && event.text.unicode < 128) {
        switch (event.text.unicode) {
        case 0x8:
            if (temp_name.size() != 0)
                temp_name.erase(temp_name.size() - 1);
            break;

        default:
            if (temp_name.size() <= 50) {
                temp_name += tolower(event.text.unicode);
            }
            break;
        }

        text.setString(temp_name);
    }
}

void NameInput::draw(sf::RenderWindow& window)
{
    window.draw(sprite_nameplace);
    window.draw(text);
    if (ID == 0)
        window.draw(sprite_changer);
}

std::string NameInput::get_input()
{
    return temp_name;
}