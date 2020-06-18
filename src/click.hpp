#pragma once
#include <SFML/Graphics.hpp>

class Click {
public:
    bool
    isClicked(sf::Sprite sprite, sf::RenderWindow& window, sf::Event event);
};