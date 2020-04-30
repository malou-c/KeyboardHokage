#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MenuButton {
 private:
  std::string name;
  sf::Text out_name;
  int id;
  int l_border;           //левая граница кнопки (x)
  int r_border;           //правая граница кнопки (x)
  int u_border;           //верхняя граница кнопки (y)
  int d_border;           //нижняя граница кнопки (y)
  sf::Sprite background;  //фон для кнопки
  sf::Font font;          //шрифт текста кнопки
  sf::Image image;        //фото для фона кнопки
  sf::Texture texture;    //текстура для фона кнопки

 public:
  MenuButton(int x, int y, std::string button_name, int id);
  MenuButton(int x, int y, int id);

  int get_id();  //Узнать id кнопки
  /* sf::Sprite get_sprite() { return background; }; */

  void set_borders();  //Установить границы кнопки

  void is_clicked(sf::RenderWindow &window);  //Проверяет была ли нажата кнопка

  void draw(sf::RenderWindow &window);  //рисует кнопку
};