#pragma once
#include <SFML/Graphics.hpp>
#include <cstring>
#include <sstream>
#include <vector>

class TextDubler {
private:
    sf::Vector2f pos_text;
    sf::Color correctColor = sf::Color(64, 64, 64);
    sf::Color wrongColor = sf::Color(182, 0, 14);
    sf::Font font;
    int font_size = 30;
    size_t vec_size = 10;
    size_t time_size = 5;
    // bkgr
    sf::Texture texture_bkground;
    sf::Sprite bkground;

public:
    std::vector<sf::Text> vec_txt;
    std::vector<int> vec_time;
    sf::Text cps_text;
    int cps_max = 0;

    //конструктор
    TextDubler(float x, float y);
    TextDubler();

    //функции
    void addsymWrong(wchar_t sym);
    void addsymCorrect(wchar_t sym);
    bool isAllWrong();
    bool isWrong();
    void delsym(wchar_t sym, bool hardmode);
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