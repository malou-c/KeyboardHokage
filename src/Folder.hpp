#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

class Folder {
private:
    std::string path;

public:
    Folder(std::string path);
    void CountChar(std::string filename, size_t& size);

    //возвращает имена фалов в дирректории без названия самой
    //дирректории
    std::vector<std::string> contains();
};
