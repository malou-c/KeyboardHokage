#include "Folder.hpp"

Folder::Folder(std::string path)
{
    this->path = path;
};

//возвращает имена фалов в дирректории без названия самой дирректории
std::vector<std::string> Folder::contains()
{
    std::string file_name;
    std::vector<std::string> list;

    for (auto& name : std::filesystem::directory_iterator(this->path)) {
        file_name = name.path().u8string().erase(0, path.size() + 1);

        if (file_name[file_name.size() - 1] == 't'
            && file_name[file_name.size() - 2] == 'x'
            && file_name[file_name.size() - 3] == 't'
            && file_name[file_name.size() - 4] == '.') {
            list.push_back(file_name); //здесь удаляется имя дериктории
        }
    }
    return list;
};