#include "NameInput.hpp"

NameInput::NameInput()
{
    background.setSize(sf::Vector2f(150.f, 30.f));
    background.setPosition(0, 0);
    background.setFillColor(sf::Color::Green);

    font.loadFromFile("fonts/stdFont.ttf");

    text.setPosition(5, 10);
    text.setFont(font);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
    text.setString(temp_name);
};

void NameInput::window_for_name_input(sf::RenderWindow& window, sf::Event event)
{
    if (sf::IntRect(background.getLocalBounds())
                .contains(sf::Mouse::getPosition(window))
        && event.type == event.MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left) {
        if (background.getFillColor() == sf::Color::Blue) {
            background.setFillColor(sf::Color::Green);
        } else {
            background.setFillColor(sf::Color::Blue);
        }
    }

    if (background.getFillColor() == sf::Color::Blue
        && event.type == sf::Event::TextEntered && event.text.unicode < 128) {
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

        text.setString(temp_name);
    }
}

void NameInput::draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(text);
}

std::string NameInput::get_input()
{
    return temp_name;
}