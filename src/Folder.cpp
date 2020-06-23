#include "Folder.hpp"

Folder::Folder(){};

Folder::Folder(std::string path)
{
    this->path = path;
};

//возвращает имена фалов в дирректории без названия самой дирректории
std::vector<std::string> Folder::contains()
{
    std::vector<std::string> list;
    for (auto& name : std::filesystem::directory_iterator(this->path)) {
        //здесь удаляется имя дериктории
        list.push_back(((std::string)name.path()).erase(0, path.size() + 1));
    }
    return list;
};

int Folder::CountChar(std::string filename)
{
    int size = 0;
    char ch;
    std::ifstream ccfile(filename.c_str());
    for (int i = 0; !ccfile.eof(); i++) {
        ccfile >> ch;
        if (ch != ' ')
            size++;
    }
    ccfile.clear();
    ccfile.close();
    return size - 1;
}