#pragma once
#include "text_dubler.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace sf;

class ClockFace {
public:
    //для cps
    TextDubler* txtDubler; // ссылка на текстовый дублер
    int time200ms = 0;
    Clock CPSmsstorage;

    Font font;
    Text text;
    Clock msstorage;
    Clock secstorage;
    int msec = 0;
    int seconds = 0;
    int minsum = 1;
    int minutes = 0;
    int switcher = 0;
    bool isStart = false;
    Vector2i position;
    //конструкторы
    ClockFace(int x, int y, TextDubler& txtdubler);

    //функции
    void update_clock();
    void DrawClock(RenderWindow& window);
    void setPosition(int x, int y);
    void ClockReset();
    void ClockStart();
    void ClockStop();
    void ClockContinue();
};
