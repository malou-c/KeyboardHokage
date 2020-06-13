#pragma once

#include "../src/filereader.cpp"

#include <fstream>

using namespace std;
string path = "test/test_text.txt";

void cleanfile(string path)
{
    //чистит файл перед тестом
    fstream file;
    file.open(path, ios::out | ios::trunc);
    file.clear();
    file.close();
}

template <class T>
void writefile(T msg, string path)
{
    //чистит файл перед тестом
    fstream file;
    file.open(path, ios::out | ios::trunc);
    file << msg;
    file.close();
}

TEST_CASE("filereader")
{
    //записываем сообщение через функцию
    wstring wmsg = L"test msg 1 2 3 ";
    //записываем сообщение
    string msg = "test msg 1 2 3";
    cleanfile(path);
    writefile(msg, path);
    CHECK(readfile_to_wstr(path) == wmsg);
    //проверяем неправильное сообщение
    wstring wrong_msg = L"wrong test";
    CHECK(readfile_to_wstr(path) != wrong_msg);
}