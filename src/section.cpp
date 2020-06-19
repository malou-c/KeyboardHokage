#include "section.hpp"

Section::Section()
{
    texture_sect.loadFromFile("images/TS_section.png");
    sprite_sect.setTexture(texture_sect);
}