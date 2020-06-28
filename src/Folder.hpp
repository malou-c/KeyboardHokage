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
    int CountChar(std::string filename);

<<<<<<< HEAD
    //возвращает имена фалов в дирректории без названия самой дирректории
    std::vector<std::string> contains_txt();
||||||| 8a85907
    //возвращает имена фалов в дирректории без названия самой дирректории
    std::vector<std::string> contains();
=======
    //возвращает имена фалов в дирректории без названия самой
    //дирректории
    std::vector<std::string> contains();
>>>>>>> CountChar
};
