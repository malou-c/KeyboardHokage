#include "MenuButton.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

extern int ID; // глобал  ID

MenuButton::MenuButton(int x, int y, int id)
{
    this->id = id;
    image.loadFromFile("images/MB_play.png");
    texture.loadFromImage(image); //загружаем текстуру для фона
    background.setTexture(texture);
    //прямоугольники для спрайтов
    rect_def = IntRect(0, 0, texture.getSize().x / 2, texture.getSize().y);
    rect_enable = IntRect(
            texture.getSize().x / 2,
            0,
            texture.getSize().x / 2,
            texture.getSize().y);

    background.setTextureRect(rect_def); //устанавливаем текстуру для спрайта
    background.setPosition(x, y); //координаты для отрисовки кнопки
}

MenuButton::MenuButton(int x, int y, std::string img_path, int id)
{
    this->id = id;
    image.loadFromFile("images/" + img_path);
    texture.loadFromImage(image); //загружаем текстуру для фона

    background.setTexture(texture);
    //прямоугольники для спрайтов
    rect_def = IntRect(0, 0, texture.getSize().x / 2, texture.getSize().y);
    rect_enable = IntRect(
            texture.getSize().x / 2,
            0,
            texture.getSize().x / 2,
            texture.getSize().y);

    background.setTextureRect(rect_def); //устанавливаем текстуру для спрайта
    background.setPosition(x, y); //координаты для отрисовки кнопки
}

int MenuButton::get_id()
{
    return id;
};

void MenuButton::is_clicked(RenderWindow& window, Event event)
{
    if (isContain(background, window)) {
        //двигаем изображение ко второму тайлу
        background.setTextureRect(rect_enable);
        if (!enable && isClicked(background, window, event)) {
            enable = true;
        }
        if (enable && isReleased_In(background, window, event)) {
            ID = id; // меняем  глобальный   ID
            enable = false;
        }
    } else {
        //двигаем обратно
        background.setTextureRect(rect_def);
    }
}

void MenuButton::draw(sf::RenderWindow& window) //рисует кнопку
{
    window.draw(background);
}