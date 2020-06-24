#pragma once
#include "Folder.hpp"
#include "click.hpp"
#include "screentxt.hpp"
#include "section.hpp"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include <vector>

using namespace sf;

class TextSelection : Click {
private:
    Vector2i pos;

public:
    //шрифт
    Font font;
    // background
    Texture texture_bg;
    Sprite background;
    //вектор из секций
    std::vector<Section> sections;
    int curr_sect = -1;
    Color color_curr = Color(128, 128, 128);
    Color color_contain = Color(191, 191, 191);
    //отступы для секций
    Vector2i indent_sect;
    size_t count_section = 10; // кол-во секций
    size_t start_sect = 0;
    size_t count_draw_sect;
    //вектор из названий текстов
    std::vector<std::string> name_folders;
    //кнопки << >>
    Color disable_color = Color(255, 255, 255, 70);
    bool but_relise = true;
    Vector2f but_pos;
    Texture texture_but_left;
    Sprite but_left;
    Texture texture_but_right;
    Sprite but_right;

    //конструктор
    TextSelection(int x, int y);
    //функции
    void update_sections(TextWindow& txtwin, Event event, RenderWindow& window);
    void but_update(Event event, RenderWindow& window);
    void recount_sect();
    // getts
    std::string getCurrent();

    // draw
    void draw(RenderWindow& window);
};