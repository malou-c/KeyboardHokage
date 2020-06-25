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

int Folder::CountChar(std::wstring filestr)
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