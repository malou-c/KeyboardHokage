#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "button.hpp"
#include "sysbutton.hpp"
class MyKeyboard {
 private:
  sf::Vector2i position;

 public:
  std::vector<ButtonForKB> vec_buttons;
  SysButtonForKB space{"images/space.png", 32};
  SysButtonForKB backspace{"images/backspace.png", 8};
  SysButtonForKB shift{"images/shift.png"};
  //конструкторы
  MyKeyboard(int x, int y);

  //функции
  void DrawKB(sf::RenderWindow &window);

  // get
  sf::Vector2i getPosition();

  // set
  void setPosition(int x, int y);
};
