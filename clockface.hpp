#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace sf;

class ClockFace {
 public:
  Font font;
  Text text;
  Clock msstorage;
  Clock secstorage;
  int time = 0;
  int seconds = 0;
  int minsum = 1;
  int minutes = 0;
  int switcher = 0;
  Vector2i position;
  //конструкторы
  ClockFace();

  //функции
  void update_clock();
  void DrawClock(RenderWindow &window);
  void setPosition(int x, int y);
  void ClockReset();
  void ClockStart();
  void ClockStop();
  void ClockContinue();
};
