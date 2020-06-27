#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Click {
public:
    bool enable_but = false;
    bool relise_L = true;
    bool relise_R = true;
    //функции
    bool
    isClicked(sf::Sprite sprite, sf::RenderWindow& window, sf::Event event);
    bool isReleased(sf::Event event);
    bool
    isReleased_In(sf::Sprite sprite, sf::RenderWindow& window, sf::Event event);
    bool isContain(sf::Sprite sprite, sf::RenderWindow& window);
    bool
    isFullClick(sf::Sprite sprite, sf::RenderWindow& window, sf::Event event);
};
