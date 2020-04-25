#include "filereader.hpp"

// берет из файла текст и  вставляет его в  строку wstring
std::wstring readfile_to_wstr(std::string filename) {
  std::string str;
  std::string msg;
  std::fstream file(filename, std::ios::in | std::ios::out);

  while (true) {
    file >> str;
    if (file.eof()) break;
    msg += " ";
    msg += str;
  }
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
  std::wstring wstr = converter.from_bytes(msg);
  return wstr;
}
