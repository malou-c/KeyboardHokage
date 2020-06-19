#pragma once

#include <SFML/Graphics.hpp>

extern int width;

class NameInput {
private:
    sf::RectangleShape background;
    std::string temp_name = "";
    sf::Font font;
    sf::Text text;

public:
    NameInput();

    void window_for_name_input(sf::RenderWindow& window, sf::Event event);

    void draw(sf::RenderWindow& window);

    std::string get_input();
};