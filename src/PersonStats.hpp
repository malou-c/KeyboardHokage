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
    std::string temp_name = "";
    sf::Font font;
    sf::Text text;

    bool pressed = false, //необходимы для корректной смены цвета при нажатии
            released = true; //на интерфейс ввода имени

    bool key_releasd;

    PersonStats()
    {
        background.setSize(sf::Vector2f(150.f, 30.f));
        background.setPosition(0, 0);
        background.setFillColor(sf::Color::Blue);

        this->font.loadFromFile("fonts/stdFont.ttf");

        this->text.setPosition(5, 10);
        this->text.setFont(this->font);
        this->text.setCharacterSize(18);
        this->text.setFillColor(sf::Color::Black);
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
            if (background.getFillColor() == sf::Color::Blue) {
                background.setFillColor(sf::Color::Green);
            } else {
                background.setFillColor(sf::Color::Blue);
            }
        }

        this->released = false;
        ////////////////////////////////////////////////////////////////////////

        if (background.getFillColor() == sf::Color::Blue
            && event.type == sf::Event::TextEntered
            && event.text.unicode < 128) {
            switch (event.text.unicode) {
            case 0x8:
                if (temp_name.size() != 0)
                    temp_name.erase(temp_name.size() - 1);
                break;

            default:
                if (temp_name.size() <= 50) {
                    temp_name += event.text.unicode;
                }
                break;
            }

            this->text.setString(this->temp_name);
        }

        window.draw(background);
        window.draw(this->text);
    };
};