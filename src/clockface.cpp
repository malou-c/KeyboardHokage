#include "clockface.hpp"
//конструктор
ClockFace::ClockFace(int x, int y, TextDubler& txtdubler)
{
    font.loadFromFile("fonts/CyrilicOld.ttf");
    //текстовый дублер
    txtDubler = &txtdubler;

    font.loadFromFile("fonts/CyrilicOld.ttf");
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Black);
    text.setPosition(x, y);
}

//функции

void ClockFace::update_clock()
{
    if (switcher == true) {
        // for cps
        if (time200ms < 200) {
            time200ms = (CPSmsstorage.getElapsedTime().asMilliseconds());
        } else {
            txtDubler->cps_nextsec();
            time200ms = 0;
            CPSmsstorage.restart();
        }

        // timer
        if (msec < 1000) {
            msec = (msstorage.getElapsedTime().asMilliseconds());
        } else {
            msec = 0;
            msstorage.restart();
        }

        if (seconds < 60) {
            seconds = (secstorage.getElapsedTime().asSeconds());
        } else {
            seconds = 0;
            secstorage.restart();
        }

        minsum = seconds / 60;

        minutes += minsum;
    }
}

void ClockFace::DrawClock(sf::RenderWindow& window)
{
    std::ostringstream stringmillsec, stringsec, stringmin;
    stringmillsec << msec;
    stringsec << seconds;
    stringmin << minutes;

    text.setString(
            "Time: " + stringmin.str() + ":" + stringsec.str() + ":"
            + stringmillsec.str());
    window.draw(text);
}

void ClockFace::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void ClockFace::ClockReset()
{
    switcher = 0;
    msec = 0;
    seconds = 0;
    minutes = 0;
}

void ClockFace::ClockStart()
{
    msstorage.restart();
    secstorage.restart();
    switcher = 1;
    isStart = true;
}

void ClockFace::ClockStop()
{
    switcher = 0;
    isStart = false;
}
void ClockFace::ClockContinue()
{
    switcher = 1;
}