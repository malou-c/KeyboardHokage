#include "../src/Folder.hpp"
#include "testparty/catch.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

TEST_CASE("Folder::contains")
{
    Folder folder("test_files");
    std::vector<std::string> files_name;
    std::string name;

    std::filesystem::create_directory("test_files");

    //Создает файлы с именем file0.txt ... file4.txt
    for (int i = 0; i < 5; i++) {
        name = "test_files/file";
        name += i + '0';
        name += ".txt";
        std::ofstream file(name);
    }

    files_name = folder.contains_txt();
    sort(files_name.begin(), files_name.end());

    for (int i = 0; i < 5; i++) {
        name = "file";
        name += i + '0';
        name += ".txt";
        CHECK(files_name[i] == name);
    }

    std::filesystem::remove_all("test_files");
}
