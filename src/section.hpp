#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>

class Section {
    sf::Texture texture_sect;
    sf::Text def_text;

public:
    sf::Sprite sprite_sect;
    sf::Text name_txt;
    //конструктор
    Section();
};