#pragma once

#include <SFML/Graphics.hpp>

extern int width;

class PersonStats {
private:
    sf::RectangleShape background;

public:
    char user_name[50];
    char text_name[50];
    float time;
    float cps;

    PersonStats()
    {
        background.setSize(sf::Vector2f(150.f, 30.f));
        background.setPosition(0, 0);
        background.setFillColor(sf::Color::Green);
    };

    void window_for_name_input(sf::RenderWindow& window, sf::Event event)
    {
        //Если мышк внутри кнопки и была отпущена левая кнопка
        if (sf::IntRect(background.getLocalBounds())
                    .contains(sf::Mouse::getPosition(window))
            && event.type == event.MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left) {
            if (background.getFillColor() != sf::Color::Blue) {
                background.setFillColor(sf::Color::Blue);
            }
        } else if (event.type == event.MouseButtonReleased) {
            background.setFillColor(sf::Color::Green);
        }

        window.draw(background);
    };
};