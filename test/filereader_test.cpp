#include "../src/filereader.hpp"
#include "testparty/catch.hpp"

#include <fstream>

std::string path = "test/test_text.txt";

void cleanfile(std::string path)
{
    //чистит файл перед тестом
    std::fstream file;
    file.open(path, std::ios::out | std::ios::trunc);
    file.clear();
    file.close();
}

template <class T>
void writefile(T msg, std::string path)
{
    //чистит файл перед тестом
    fstream file;
    file.open(path, std::ios::out | std::ios::trunc);
    file << msg;
    file.close();
}

TEST_CASE("filereader")
{
    //записываем сообщение через функцию
    std::wstring wmsg = L"test msg 1 2 3 ";
    //записываем сообщение
    std::string msg = "test msg 1 2 3";
    cleanfile(path);
    writefile(msg, path);
    CHECK(readfile_to_wstr(path) == wmsg);
    //проверяем неправильное сообщение
    std::wstring wrong_msg = L"wrong test";
    CHECK(readfile_to_wstr(path) != wrong_msg);
}