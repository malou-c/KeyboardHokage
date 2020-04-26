#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "filereader.hpp"
using namespace sf;

class Word {
 private:
  int len = 0;
  std::wstring word = L"";

 public:
  int get_len() { return len; }
  std::wstring get_word() { return word; }
  int set_len() { len = word.length(); }
  void clean() {
    word = L"";
    len = 0;
  }

  void add(wchar_t letter) {
    word += letter;
    set_len();
  }

  /*     int wordlen(int i, std::string text)
      {
          i++;
          int countlen = 1;
          while (text[i] != ' ' || text[i] != '.')
          {
              i++;
              countlen++;
          }
          return countlen;
      } */
};

void add(std::vector<std::vector<wchar_t>> &text, Word word,
         int j)  //не тестированно
{
  for (int k = 0; k < word.get_len(); k++) {
    text[j].push_back(word.get_word()[k]);
  }
  text[j].push_back(L' ');
}

std::vector<std::vector<wchar_t>> get_text() {
  int width = (1500 / 8) - 70;
  std::wstring str = readfile_to_wstr("texts/text_1.txt");
  std::vector<std::vector<wchar_t>> text;
  Word word;

  text.resize(1);

  int j = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] != L' ') {
      word.add(str[i]);
    } else {
      if (word.get_len() + text[j].size() < width) {
        add(text, word, j);
        word.clean();
      } else {
        j++;
        text.resize(j + 1);
        add(text, word, j);

        word.clean();
      }
    }
  }

  return text;
}

int main() {
  std::vector<std::vector<wchar_t>> mytext;
  std::cout << "mmm?" << std::endl;
  mytext = get_text();
  std::cout << "go" << std::endl;
  /*
    for (int i = 0; i < mytext.size(); i++) {
      for (int j = 0; i < mytext[i].size(); j++) {
        std::wcout << mytext[i][j];
      }
      std::cout << std::endl;
    }*/

  //параметры окна
  int height = 950, width = 1500;
  ContextSettings settings;
  settings.antialiasingLevel = 8;
  RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default,
                      settings);
  window.clear(Color::White);
  //текст
  Font font;
  font.loadFromFile("fonts/3976.ttf");
  Text text_win;
  text_win.setFont(font);
  text_win.setFillColor(sf::Color::Black);
  text_win.setCharacterSize(25);
  // text_win.setString("ggg");
  std::wstring wstr = L"";
  for (int i = 0; i < mytext[0].size(); i++) {
    wstr += mytext[0][i];
  }

  text_win.setString(wstr);
  std::cout << mytext[0][0] << std::endl;
  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed) window.close();
    }

    if (Mouse::isButtonPressed(Mouse::Left)) {
    }
    window.draw(text_win);
    window.display();
  }

  return 0;
}