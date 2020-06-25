#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Folder {
private:
    std::string path;

public:
    Folder(std::string path);
    int CountChar(std::wstring filestr);

    //возвращает имена фалов в дирректории без названия самой
    //дирректории
    std::vector<std::string> contains();
};
