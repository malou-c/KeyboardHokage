#include "hpp/clockface.hpp"
//конструктор
ClockFace::ClockFace(int x, int y) {
  font.loadFromFile("fonts\\CyrilicOld.ttf");
  text.setFont(font);
  text.setCharacterSize(25);
  text.setFillColor(Color::Black);
  setPosition(x, y);
}

//функции

void ClockFace::update_clock() {
  if (switcher == true) {
    if (time < 1000) {
      time = (msstorage.getElapsedTime().asMilliseconds());
    } else {
      time = 0;
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

void ClockFace::DrawClock(RenderWindow &window) {
  std::ostringstream stringmillsec, stringsec, stringmin;
  stringmillsec << time;
  stringsec << seconds;
  stringmin << minutes;

  text.setString("Time: " + stringmin.str() + ":" + stringsec.str() + ":" +
                 stringmillsec.str());
  window.draw(text);
}

void ClockFace::setPosition(int x, int y) {
  position.x = x;
  position.y = y;
}

void ClockFace::ClockReset() {
  switcher = 0;
  time = 0;
  seconds = 0;
  minutes = 0;
}

void ClockFace::ClockStart() {
  msstorage.restart();
  secstorage.restart();

  switcher = 1;
}

void ClockFace::ClockStop() { switcher = 0; }
void ClockFace::ClockContinue() { switcher = 1; }