#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>

using namespace sf;

class Section {
public:
    Texture texture_sect;
    Sprite sprite_sect;
    Text def_text;
    Text name_txt;
    //конструктор
    Section();
};