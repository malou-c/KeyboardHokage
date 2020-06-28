#pragma once
#include "Folder.hpp"
#include "click.hpp"
#include "screentxt.hpp"
#include "section.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include <vector>

class TextSelection : Click {
private:
    sf::Vector2i pos;
    sf::Font font; //шрифт
    //вектор из секций
    std::vector<Section> sections;
    int curr_sect = -1;
    sf::Color color_curr = sf::Color(128, 128, 128);
    sf::Color color_contain = sf::Color(191, 191, 191);
    //отступы для секций
    sf::Vector2i indent_sect;
    size_t count_section = 10; // кол-во секций
    size_t start_sect = 0;
    size_t count_draw_sect;
    // texture
    sf::Texture texture_but_left;
    sf::Texture texture_but_right;
    sf::Texture texture_bg;

    sf::Vector2f but_pos;
    sf::Color disable_color = sf::Color(255, 255, 255, 70);

public:
    // background
    sf::Sprite background;
    //вектор из названий текстов
    std::vector<std::string> name_folders;
    //кнопки << >>
    bool but_relise = true;
    sf::Sprite but_left;
    sf::Sprite but_right;

    //конструктор
    TextSelection(int x, int y);
    //функции
    void update_sections(
            TextWindow& txtwin, sf::Event event, sf::RenderWindow& window);
    void but_update(sf::Event event, sf::RenderWindow& window);
    void recount_sect();
    // getts
    std::string getCurrent();
    // draw
    void draw(sf::RenderWindow& window);
};