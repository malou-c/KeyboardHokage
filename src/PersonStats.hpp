#pragma once

#include <SFML/Graphics.hpp>

extern int width;

class PersonStats {
private:
    sf::RectangleShape background;

public:
    char user_name[50]; //имя пользователя
    char text_name[50]; //название текста
    float time;
    float cps; // clicks per second

    bool pressed, released; //необходимы для корректной смены цвета при нажатии
                            //на интерфейс ввода имени

    PersonStats()
    {
        background.setSize(sf::Vector2f(150.f, 30.f));
        background.setPosition(0, 0);
        background.setFillColor(sf::Color::Green);
    };

    void window_for_name_input(sf::RenderWindow& window, sf::Event event)
    {
        //////Смена цвета при нажатии на интерфейс ввода ///////////////////////
        if (sf::IntRect(background.getLocalBounds())
                    .contains(sf::Mouse::getPosition(window))
            && event.type == event.MouseButtonPressed
            && event.mouseButton.button == sf::Mouse::Left) {
            this->pressed = true;
        }

        if (this->pressed
            && sf::IntRect(background.getLocalBounds())
                       .contains(sf::Mouse::getPosition(window))
            && event.type == event.MouseButtonReleased
            && event.mouseButton.button == sf::Mouse::Left) {
            this->released = true;
            this->pressed = false;
        }

        if (released) {
            if (background.getFillColor() == sf::Color::Green) {
                background.setFillColor(sf::Color::Blue);
            } else {
                background.setFillColor(sf::Color::Green);
            }
        }

        this->released = false;
        ////////////////////////////////////////////////////////////////////////
        window.draw(background);
    };
};