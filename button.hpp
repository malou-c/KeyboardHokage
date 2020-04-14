#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define FONT "fonts/stdFont.ttf"

class ButtonForKB {
 public:
  sf::Image img;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Font font;
  sf::Text text;
  std::string path = "images/button.png";
  sf::String name;
  // конструкторы
  ButtonForKB(sf::String name_button);
  ButtonForKB();
  //функция-конструктор
  void Create();
  //функции
  void DrawButton(sf::RenderWindow &window);
  // get

  // set
  void setName(sf::String str);
};
