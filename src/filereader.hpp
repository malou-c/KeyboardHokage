#pragma once
#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

std::wstring readfile_to_wstr(std::string file);
int CountChar(std::wstring filestr);