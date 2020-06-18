#include "click.hpp"

bool Click::isClicked(
        sf::Sprite sprite, sf::RenderWindow& window, sf::Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (sf::IntRect(sprite.getLocalBounds())
                .contains(sf::Mouse::getPosition(window))
        && event.type == event.MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left) {
        return true;
    } else {
        return false;
    }
}