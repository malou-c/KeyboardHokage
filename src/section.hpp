#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>

class Section {
public:
    sf::Texture texture_sect;
    sf::Sprite sprite_sect;
    sf::Text def_text;
    sf::Text name_txt;
    //конструктор
    Section();
};