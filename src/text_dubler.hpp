#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>

using namespace sf;

class TextDubler {
private:
    Vector2f position;
    Color correctColor = Color::Black;
    Color wrongColor = Color::Red;
    Font font;
    int font_size = 30;
    size_t vec_size = 10;
    size_t time_size = 5;

public:
    std::vector<Text> vec_txt;
    std::vector<int> vec_time;
    Text cps_text;

    //конструктор
    TextDubler(float x, float y);
    TextDubler();

    //функции
    void addsymWrong(wchar_t sym);
    void addsymCorrect(wchar_t sym);
    bool isAllWrong();
    bool isWrong();
    void delsym(wchar_t sym);
    int countWrong();
    //для показателя CPS
    void cps_plus();
    void cps_nextsec();
    void cps_update();
    // setts
    size_t setVecSize();

    //отрисовка
    void draw(sf::RenderWindow& window);
};