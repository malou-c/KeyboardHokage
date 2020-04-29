#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "filereader.hpp"
#include "word.hpp"
using namespace sf;

class TextWindow {
 private:
  Font font;
  Texture texture;
  Vector2i position;  // положение окна с текстом
  Vector2i size;      // размер окна с текстом
  int margin_y;

 public:
  int start_str;  // с какой строчки идет отрисовка
  int count_text_string;  //скольок строк помещается в  окне

  //все для текстуры
  Sprite sprite;
  //текст внутри окна
  std::vector<std::wstring> text_str;
  std::vector<Text> vec_text;
  int font_size;
  Color text_color;

  //конструкторы
  TextWindow();

  //функии
  std::vector<std::wstring> convert_file_to_text(std::string filename);
  void add_word_in_text(std::vector<std::wstring> &text, Word word, int j);
  void change_text_character();
  void change_count_text_str();
  void next_text_str();
  void back_text_str();

  void DrawTextWindow(RenderWindow &window);
  // setters
  void setPosition(int x, int y);
  void setText(std::string filename);

  // getters
  Vector2i getPosition();
};