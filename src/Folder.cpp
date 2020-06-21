#include "Folder.hpp"

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
        list.push_back(name.path().u8string().erase(0, path.size() + 1));
    }
    return list;
};

void Folder::CountChar(std::string filename, size_t& size)
{
    std::ifstream CC_file(filename.c_str());
    for (size = 0; !CC_file.eof(); size++)
        CC_file.get();
    CC_file.clear();
    CC_file.close();
}