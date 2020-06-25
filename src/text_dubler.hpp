#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include <sstream>
#include <vector>

using namespace sf;

class TextDubler {
private:
    Vector2f pos_text;
    Color correctColor = Color(64, 64, 64);
    Color wrongColor = Color(182, 0, 14);
    Font font;
    int font_size = 30;
    size_t vec_size = 10;
    size_t time_size = 5;
    // bkgr
    Texture texture_bkground;
    Sprite bkground;

public:
    std::vector<Text> vec_txt;
    std::vector<int> vec_time;
    Text cps_text;
    int cps_max = 0;

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
    // clear
    void clear();
    // setts
    size_t setVecSize();

    //отрисовка
    void draw(sf::RenderWindow& window);
};