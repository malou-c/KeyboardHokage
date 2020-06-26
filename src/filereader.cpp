#include "filereader.hpp"

// берет из файла текст и  вставляет его в  строку wstring
std::wstring readfile_to_wstr(std::string filename)
{
    std::string str;
    std::string msg;
    std::fstream file(filename, std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cout << "file ne open(((" << std::endl;
        return L"error";
    }

    while (true) {
        file >> str;
        msg += str;
        msg += " ";
        if (file.eof())
            break;
    }
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wstr = converter.from_bytes(msg);
    return wstr;
}

int CountChar(std::wstring filestr)
{
    int size = 0, space = 0;
    for (size_t i = 0; i < filestr.size(); i++) {
        size++;
        if (filestr[i] == ' ') {
            space++;
        }
    }
    return size - space;
}
