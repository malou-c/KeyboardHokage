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

bool Click::isReleased_In(Sprite sprite, RenderWindow& window, Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (sf::IntRect(sprite.getGlobalBounds())
                .contains(Mouse::getPosition(window))
        && event.type == event.MouseButtonReleased
        && event.mouseButton.button == Mouse::Left) {
        return true;
    } else {
        return false;
    }
}

bool Click::isContain(Sprite sprite, RenderWindow& window)
{
    if (sf::IntRect(sprite.getGlobalBounds())
                .contains(Mouse::getPosition(window))) {
        return true;
    } else {
        return false;
    }
}

bool Click::isFullClick(Sprite sprite, RenderWindow& window, Event event)
{
    if (!enable_but && isClicked(sprite, window, event)) {
        enable_but = true;
    }
    if (enable_but && isReleased_In(sprite, window, event)) {
        enable_but = false;
        return true;
    }
    return false;
}