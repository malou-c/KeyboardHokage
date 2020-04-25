#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "clockface.hpp"
using namespace sf;
using namespace std;

int main() {
  String path;                      // ���� � �����
#ifdef WINDOWS                      // ���� �� Windows
  path = "images_menu\\start.png";  // ����� ����
#else                               // ���� �� Windows
  path = "images_menu/start.png";  // �����
#endif
  int height = 950, width = 1500;  // ������ � ������ ����
  //����� �����������
  ContextSettings settings;
  settings.antialiasingLevel = 8;
  //������������� ����
  RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default,
                      settings);

  //������ �������� ������ "Start"
  Texture starti;
  starti.loadFromFile(path);
  //������ ������ "Start"
  Sprite start(starti);
  start.setPosition((width / 2) - 142, 100);

    ClockFace clface;

  //���� ���� �������
  while (window.isOpen()) {
    //��������� �������
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }
    window.clear(Color::White);
    clface.update_clock();

    // runclock(window,time,seconds,minsum,minutes, msstorage, secstorage );

    if (Mouse::isButtonPressed(Mouse::Left)) {
      if (IntRect((width / 2) - 142, 100, 284, 54)
              .contains(Mouse::getPosition(window))) {
      }
    }
    clface.DrawClock(window);
    window.display();
  }

  return 0;
}