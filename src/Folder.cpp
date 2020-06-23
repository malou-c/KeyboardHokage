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

void Folder::CountChar(std::string filename, size_t& size)
{
    std::ifstream ccfile(filename.c_str());
    for (size = 0; !ccfile.eof(); size++) {
        ccfile.get();
        std::cout << "Chtonib" << std::endl;
    }
    ccfile.clear();
    ccfile.close();
}