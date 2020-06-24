#include "click.hpp"

bool Click::isClicked(Sprite sprite, RenderWindow& window, Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (sf::IntRect(sprite.getGlobalBounds())
                .contains(Mouse::getPosition(window))
        && event.type == event.MouseButtonPressed
        && event.mouseButton.button == Mouse::Left) {
        return true;
    } else {
        return false;
    }
}

bool Click::isReleased(Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (event.type == event.MouseButtonReleased
        && event.mouseButton.button == Mouse::Left) {
        return true;
    } else {
        return false;
    }
}