#pragma once
#include "text_dubler.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

class ClockFace {
public:
    //для cps
    TextDubler* txtDubler; // ссылка на текстовый дублер
    int time200ms = 0;
    sf::Clock CPSmsstorage;

    sf::Font font;
    sf::Text text;
    sf::Clock msstorage;
    sf::Clock secstorage;
    int msec = 0;
    int seconds = 0;
    int minsum = 1;
    int minutes = 0;
    int switcher = 0;
    bool isStart = false;
    sf::Vector2i position;
    //конструкторы
    ClockFace(int x, int y, TextDubler& txtdubler);

    //функции
    void update_clock();
    void DrawClock(sf::RenderWindow& window);
    void setPosition(int x, int y);
    void ClockReset();
    void ClockStart();
    void ClockStop();
    void ClockContinue();
};
