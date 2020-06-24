#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Click {
public:
    bool relise_L = true;
    bool relise_R = true;
    //функции
    bool isClicked(Sprite sprite, RenderWindow& window, Event event);
    bool isReleased(Event event);
    bool isReleased_In(Sprite sprite, RenderWindow& window, Event event);
    bool isContain(Sprite sprite, RenderWindow& window);
};
