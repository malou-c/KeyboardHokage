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
  bool isEndString = false;  // показывает кочился ли текст
  int curr_sym;              // текущий символ
  int start_str;  // с какой строчки идет отрисовка
  int count_text_string;  //скольок строк помещается в  окне

  //все для текстуры
  Sprite sprite;
  //текст внутри окна
  std::vector<std::wstring> text_str;
  std::vector<Text> vec_text;
  int font_size;
  Color text_color;
  //текст дублер
  std::wstring dubler_str;
  Text dubler;
  Color dubler_color;

  //конструкторы
  TextWindow(int x, int y);

  //функии
  //функции связанные  с дублером
  void add_sym_to_dubler(wchar_t sym);
  void pop_sym_to_dubler();
  void dubler_fill();
  void checksym_dubler(int symbol);
  void dubler_clean();

  std::vector<std::wstring> convert_file_to_text(std::string filename);
  void add_word_in_text(std::vector<std::wstring> &text, Word word, int j);
  void change_text_character();
  void change_count_text_str();
  void next_text_str();
  void back_text_str();

  void DrawTextWindow(RenderWindow &window);
  // setters
  void setPos(int x, int y);
  void setText(std::string filename);

  // getters
  Vector2i getPosition();
};