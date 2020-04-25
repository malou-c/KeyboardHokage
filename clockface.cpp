#include "clockface.hpp"
//конструктор
ClockFace::ClockFace() {
  font.loadFromFile("fonts/stdFont.ttf");
  text.setFont(font);
  text.setCharacterSize(25);
  text.setFillColor(Color::Black);
  setPosition(0, 0);
}

//функции

void ClockFace::update_clock() {
  if (time < 1000) {
    time = (msstorage.getElapsedTime().asMilliseconds());
  } else {
    time = 0;
    msstorage.restart();
  }

  if (seconds < 60) {
    seconds = secstorage.getElapsedTime().asSeconds();
  } else {
    seconds = 0;
    secstorage.restart();
  }

  minsum = seconds / 60;

  minutes += minsum;
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