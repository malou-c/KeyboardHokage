#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "button.hpp"
#include "screentxt.hpp"
#include "sysbutton.hpp"

class MyKeyboard {
private:
    sf::Vector2i position;
    sf::Color color_def = sf::Color::White;
    sf::Color color_enable = sf::Color(141, 141, 141);

public:
    std::vector<ButtonForKB> vec_buttons;
    SysButtonForKB space{"images/MK_space.png", 32};
    SysButtonForKB backspace{"images/MK_bkspace.png", 8};
    SysButtonForKB shift{"images/MK_shift.png"};
    //конструкторы
    MyKeyboard(int x, int y);

    //функции
    //рисуем клаватуру
    void DrawKB(sf::RenderWindow& window);
    // обновляем события (внутри цикла pollEvent)
    void Update(sf::Event event, TextWindow& txwin, bool hardmode);

    // get
    sf::Vector2i getPosition();

    // set
    void setPosition(int x, int y);
};
