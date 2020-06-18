#pragma once

#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

class Folder {
private:
    std::string path, CC_filename_path;
    size_t char_amout;

public:
    Folder();
    Folder(std::string path);
    size_t CountChar(std::string filename, size_t& size);

    //возвращает имена фалов в дирректории без названия самой
    //дирректории
    std::vector<std::string> contains();
};
