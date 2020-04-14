#include "MyKeyboard.hpp"
//конструкторы
MyKeyboard::MyKeyboard(int x, int y) {
  sf::String names_line1[13] = {"`", "1", "2", "3", "4", "5", "6",
                                "7", "8", "9", "0", "-", "="};
  sf::String names_line2[12] = {L"q", L"w", L"e", L"r", L"t", L"y",
                                L"u", L"i", L"o", L"p", L"[", L"]"};
  sf::String names_line3[11] = {L"a", L"s", L"d", L"f", L"g", L"h",
                                L"j", L"k", L"l", L";", L"'"};
  sf::String names_line4[10] = {L"z", L"x", L"c", L"v", L"b",
                                L"n", L"m", L",", L".", L"/"};
  vec_buttons.resize(46);
  //первая линия
  for (int i = 0; i < 13; i++) {
    //последовательность важна
    vec_buttons[i].setName(names_line1[i]);
    vec_buttons[i].sprite.setPosition(x + (90 * i), y);
    vec_buttons[i].Create();
  }
  //вторая линия
  for (int i = 13, j = 0; i < 25; i++, j++) {
    //последовательность важна
    vec_buttons[i].setName(names_line2[j]);  // что бы индекс совпал
    vec_buttons[i].sprite.setPosition(x + 110 + (90 * j), y + 70);
    vec_buttons[i].Create();
  }
  //третья линия
  for (int i = 25, j = 0; i < 36; i++, j++) {
    //последовательность важна
    vec_buttons[i].setName(names_line3[j]);  // что бы индекс совпал
    vec_buttons[i].sprite.setPosition(x + 150 + (90 * j), y + 140);
    vec_buttons[i].Create();
  }
  //четвертая линия
  for (int i = 36, j = 0; i < 46; i++, j++) {
    //последовательность важна
    vec_buttons[i].setName(names_line4[j]);  // что бы индекс совпал
    vec_buttons[i].sprite.setPosition(x + 170 + (90 * j), y + 210);
    vec_buttons[i].Create();
  }
}
//функции
void MyKeyboard::DrawKB(sf::RenderWindow &window) {
  for (int i = 0; i < vec_buttons.size(); i++) {
    vec_buttons[i].DrawButton(window);
  }
}

// get
sf::Vector2i MyKeyboard::getPosition() { return position; }

// set
void MyKeyboard::setPosition(int x, int y) {}

// тестовый мейн
int main() {
  // Create the main window
  sf::RenderWindow window(sf::VideoMode(1560, 800), "keyboard mazafaka");

  MyKeyboard keyboard(150, 400);  //  объект клавиатуры
  int val = 0;
  sf::String symbol;
  while (window.isOpen()) {
    // Process events
    sf::Event event;
    sf::Keyboard::Key k;

    while (window.pollEvent(event)) {
      // Close window: exit
      if (event.type == sf::Event::Closed) window.close();

      if (event.type == sf::Event::TextEntered) {
        std::cout << "ASCII character typed: " << event.text.unicode
                  << std::endl;
        symbol = (char)event.text.unicode;
        //меняем цвет
        for (int i = 0; i < keyboard.vec_buttons.size(); i++) {
          if (keyboard.vec_buttons[i].name == symbol) {
            keyboard.vec_buttons[i].sprite.setColor(sf::Color(245, 0, 103));
          }
        }
      } else {
        for (int i = 0; i < keyboard.vec_buttons.size(); i++) {
          keyboard.vec_buttons[i].sprite.setColor(sf::Color::White);
        }
      }

      /*if (event.type == sf::Event::KeyPressed) {
        std::cout << "hi " << val << std::endl;
        val++;
      }*/
    }

    // Clear screen
    window.clear(sf::Color::White);
    keyboard.DrawKB(window);

    window.display();
  }
  return EXIT_SUCCESS;
}