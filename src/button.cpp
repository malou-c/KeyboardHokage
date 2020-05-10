#include "button.hpp"

// конструкторы
ButtonForKB::ButtonForKB(){};

ButtonForKB::ButtonForKB(sf::String name_button)
{
    img.loadFromFile(path);     // подгружаем изображение
    texture.loadFromImage(img); // текстуру
    sprite.setTexture(texture); // спрайт
    font.loadFromFile(FONT);    // шрифт
    text.setFont(font); // устанавливаем шрифт на текст
    text.setColor(sf::Color::Black); // цвет текста
    text.setPosition(
            sprite.getPosition().x + 45,
            sprite.getPosition().y
                    + 20); // положение теста относительно спрайта
    text.setString(name_button); // сам текст
}
//функция повторяющая конструктор
void ButtonForKB::Create()
{
    img.loadFromFile(path);
    texture.loadFromImage(img);
    sprite.setTexture(texture);
    font.loadFromFile(FONT);
    text.setFont(font);
    text.setColor(sf::Color::Black);
    text.setPosition(sprite.getPosition().x + 45, sprite.getPosition().y + 20);
    text.setString(name);
}

// функции

void ButtonForKB::DrawButton(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(text);
}

// get

// set
void ButtonForKB::setName(sf::String str)
{
    name = str;
}
