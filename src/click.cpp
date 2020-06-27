#include "click.hpp"

bool Click::isClicked(
        sf::Sprite sprite, sf::RenderWindow& window, sf::Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (sf::IntRect(sprite.getGlobalBounds())
                .contains(sf::Mouse::getPosition(window))
        && event.type == event.MouseButtonPressed
        && event.mouseButton.button == sf::Mouse::Left) {
        return true;
    } else {
        return false;
    }
}

bool Click::isReleased(sf::Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (event.type == event.MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left) {
        return true;
    } else {
        return false;
    }
}

bool Click::isReleased_In(
        sf::Sprite sprite, sf::RenderWindow& window, sf::Event event)
{
    //Если мышк внутри кнопки и была отпущена левая кнопка
    if (sf::IntRect(sprite.getGlobalBounds())
                .contains(sf::Mouse::getPosition(window))
        && event.type == event.MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left) {
        return true;
    } else {
        return false;
    }
}

bool Click::isContain(sf::Sprite sprite, sf::RenderWindow& window)
{
    if (sf::IntRect(sprite.getGlobalBounds())
                .contains(sf::Mouse::getPosition(window))) {
        return true;
    } else {
        return false;
    }
}

bool Click::isFullClick(
        sf::Sprite sprite, sf::RenderWindow& window, sf::Event event)
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