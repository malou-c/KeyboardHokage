#include "word.hpp"

//геттеры
int Word::get_len() { return len; }
std::wstring Word::get_word() { return word; }
//сеттеры
void Word::set_len() { len = word.length(); }

//функции
void Word::add(wchar_t letter) {
  word += letter;
  set_len();
}
void Word::clean() {
  word = L"";
  len = 0;
}
