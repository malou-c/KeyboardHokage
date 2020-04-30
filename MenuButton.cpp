#pragma once

#include "hpp/MenuButton.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

extern int ID;  // глобал  ID

MenuButton::MenuButton(int x, int y, std::string button_name, int id) {
  this->id = id;
  name = button_name;  //Имя кнопки

  font.loadFromFile("fonts/stdFont.ttf");  //шрифт
  out_name.setString(name);
  out_name.setFont(font);
  out_name.setCharacterSize(16);
  out_name.setColor(sf::Color::Red);
  out_name.setPosition(x + 10, y + 10);

  image.loadFromFile("yo.jpg");

  texture.loadFromImage(image);  //загружаем текстуру для фона

  background.setTexture(texture);
  background.setTextureRect(
      sf::IntRect(0, 0, 100, 100));  //устанавливаем текстуру для спрайта
  background.setPosition(x, y);  //координаты для отрисовки кнопки
  // background.scale(0.5, 0.5);

  set_borders();
}
MenuButton::MenuButton(int x, int y, int id) {
  this->id = id;
  image.loadFromFile("yo.jpg");

  texture.loadFromImage(image);  //загружаем текстуру для фона

  background.setTexture(texture);
  background.setTextureRect(
      sf::IntRect(0, 0, 100, 100));  //устанавливаем текстуру для спрайта
  background.setPosition(x, y);  //координаты для отрисовки кнопки
  // background.scale(0.5, 0.5);

  set_borders();
}

int MenuButton::get_id() { return id; };  //Узнать id кнопки

void MenuButton::set_borders()  //Установить границы кнопки
{
  l_border = background.getLocalBounds().left;
  r_border = background.getLocalBounds().width;
  u_border = background.getLocalBounds().top;
  d_border = background.getLocalBounds().height;
}

void MenuButton::is_clicked(
    sf::RenderWindow &window)  //Проверяет была ли нажата кнопка
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
      sf::IntRect((background).getLocalBounds())
          .contains(sf::Mouse::getPosition(window))) {
    ID = id;
  }
}

void MenuButton::draw(sf::RenderWindow &window)  //рисует кнопку
{
  window.draw(background);
  window.draw(out_name);
}