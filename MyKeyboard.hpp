#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "button.hpp"

class MyKeyboard : ButtonForKB {
 private:
  sf::Vector2i position;

 public:
  std::vector<ButtonForKB> vec_buttons;
  //конструкторы
  MyKeyboard(int x, int y);

  //функции
  void DrawKB(sf::RenderWindow &window);

  // get
  sf::Vector2i getPosition();

  // set
  void setPosition(int x, int y);
};
