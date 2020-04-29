#pragma once
#include <cstring>
#include <iostream>

class Word {
 private:
  int len = 0;
  std::wstring word = L"";

 public:
  //геттеры
  int get_len();
  std::wstring get_word();
  //сеттеры
  void set_len();

  //функции
  void add(wchar_t letter);
  void clean();
};