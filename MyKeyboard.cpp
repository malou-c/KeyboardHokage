#include "hpp/MyKeyboard.hpp"

//конструкторы
MyKeyboard::MyKeyboard(int x, int y) {
  //используется для проверки нажатий
  wchar_t code_line1[13][4] = {
      {L'`', L'~', L'ё', L'Ё'}, {L'1', L'!', L'1', L'!'},
      {L'2', L'@', L'2', L'"'}, {L'3', L'#', L'3', L'№'},
      {L'4', L'$', L'4', L';'}, {L'5', L'%', L'5', L'%'},
      {L'6', L'^', L'6', L':'}, {L'7', L'&', L'7', L'?'},
      {L'8', L'*', L'8', L'*'}, {L'9', L'(', L'9', L'('},
      {L'0', L')', L'0', L')'}, {L'-', L'_', L'-', L'_'},
      {L'=', L'+', L'=', L'+'}};
  wchar_t code_line2[12][4] = {
      {L'q', L'Q', L'й', L'Й'}, {L'w', L'W', L'ц', L'Ц'},
      {L'e', L'E', L'у', L'У'}, {L'r', L'R', L'к', L'К'},
      {L't', L'T', L'е', L'Е'}, {L'y', L'Y', L'н', L'Н'},
      {L'u', L'U', L'г', L'Г'}, {L'i', L'I', L'ш', L'Ш'},
      {L'o', L'O', L'щ', L'Щ'}, {L'p', L'P', L'з', L'З'},
      {L'[', L'[', L'х', L'Х'}, {L']', L']', L'ъ', L'Ъ'}};
  wchar_t code_line3[11][4] = {
      {L'a', L'A', L'ф', L'Ф'}, {L's', L'S', L'ы', L'Ы'},
      {L'd', L'D', L'в', L'В'}, {L'f', L'F', L'а', L'А'},
      {L'g', L'G', L'п', L'П'}, {L'h', L'H', L'р', L'Р'},
      {L'j', L'J', L'о', L'О'}, {L'k', L'K', L'л', L'Л'},
      {L'l', L'L', L'д', L'Д'}, {L';', L':', L'ж', L'Ж'},
      {L'"', L'"', L'э', L'Э'}};
  wchar_t code_line4[10][4] = {
      {L'z', L'Z', L'я', L'Я'}, {L'x', L'X', L'ч', L'Ч'},
      {L'c', L'C', L'с', L'С'}, {L'v', L'V', L'м', L'М'},
      {L'b', L'B', L'и', L'И'}, {L'n', L'N', L'т', L'Т'},
      {L'm', L'M', L'ь', L'Ь'}, {L',', L'<', L'б', L'Б'},
      {L'.', L'>', L'ю', L'Ю'}, {L'/', L'?', L'.', L','}};
  // используется  для рисования
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
    //заполняем коды кнопок
    for (int k = 0; k < 4; k++) {
      vec_buttons[i].code[k] = code_line1[i][k];
    }
  }
  //вторая линия
  for (int i = 13, j = 0; i < 25; i++, j++) {
    //последовательность важна
    vec_buttons[i].setName(names_line2[j]);  // что бы индекс совпал
    vec_buttons[i].sprite.setPosition(x + 110 + (90 * j), y + 70);
    vec_buttons[i].Create();
    //заполняем коды кнопок
    for (int k = 0; k < 4; k++) {
      vec_buttons[i].code[k] = code_line2[j][k];
    }
  }
  //третья линия
  for (int i = 25, j = 0; i < 36; i++, j++) {
    //последовательность важна
    vec_buttons[i].setName(names_line3[j]);  // что бы индекс совпал
    vec_buttons[i].sprite.setPosition(x + 150 + (90 * j), y + 140);
    vec_buttons[i].Create();
    //заполняем коды кнопок
    for (int k = 0; k < 4; k++) {
      vec_buttons[i].code[k] = code_line3[j][k];
    }
  }
  //четвертая линия
  for (int i = 36, j = 0; i < 46; i++, j++) {
    //последовательность важна
    vec_buttons[i].setName(names_line4[j]);  // что бы индекс совпал
    vec_buttons[i].sprite.setPosition(x + 170 + (90 * j), y + 210);
    vec_buttons[i].Create();
    //заполняем коды кнопок
    for (int k = 0; k < 4; k++) {
      vec_buttons[i].code[k] = code_line4[j][k];
    }
  }
  // SPACE
  space.sprite.setPosition(x + 350, y + 280);
  // BACKSPACE
  backspace.sprite.setPosition(x + 1170, y);
  // SHIFT
  shift.sprite.setPosition(x - 10, y + 210);
}
//функции
void MyKeyboard::DrawKB(sf::RenderWindow &window) {
  for (int i = 0; i < vec_buttons.size(); i++) {
    vec_buttons[i].DrawButton(window);
  }
  // draw sys but
  space.DrawButton(window);
  backspace.DrawButton(window);
  shift.DrawButton(window);
}

// get
sf::Vector2i MyKeyboard::getPosition() { return position; }

// set
void MyKeyboard::setPosition(int x, int y) {}

void MyKeyboard::Update(sf::Event event, TextWindow &txwin) {
  int symbol;
  switch (event.type) {
    // нажатие клавиши
    case sf::Event::TextEntered:
      std::cout << "ASCII character typed: " << event.text.unicode << std::endl;
      symbol = (int)event.text.unicode;
      txwin.checksym_dubler(symbol);
      //меняем цвет
      for (int i = 0; i < vec_buttons.size(); i++) {
        for (int j = 0; j < 4; j++) {
          if ((int)vec_buttons[i].code[j] == symbol) {
            vec_buttons[i].sprite.setColor(sf::Color(245, 0, 103));
            break;
          }
        }
      }
      if (event.text.unicode == space.code) {
        space.sprite.setColor(sf::Color(245, 0, 103));
      } else if (event.text.unicode == backspace.code) {
        backspace.sprite.setColor(sf::Color(245, 0, 103));
      }

      break;
    // мы не обрабатываем другие типы событий
    default:
      //меняем цвет  обратно
      //у  кнопок
      for (int i = 0; i < vec_buttons.size(); i++) {
        vec_buttons[i].sprite.setColor(sf::Color::White);
      }
      space.sprite.setColor(sf::Color::White);      // у  пробела
      backspace.sprite.setColor(sf::Color::White);  // у backspace
      //нажатие шифт
      if (shift.sprite.getColor() != sf::Color::White) {
        shift.sprite.setColor(sf::Color::White);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
        shift.sprite.setColor(sf::Color(245, 0, 103));
      }

      break;
  }
}
