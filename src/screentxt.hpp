#pragma once
#include "clockface.hpp"
#include "filereader.hpp"
#include "text_dubler.hpp"
#include "word.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class TextWindow {
private:
    TextDubler* txtDubler; // указатель на текстовый дублер
    sf::Font font;
    int font_size;
    sf::Texture texture;   // background
    sf::Vector2i position; // положение окна с текстом
    sf::Vector2i size;     // размер окна с текстом
    int margin_y;
    sf::Color text_color; // цвет текста
    int count_text_string; //скольок строк помещается в  окне

    int curr_sym;  // текущий символ
    int start_str; // с какой строчки идет отрисовка

    // функции наложенного текста
    void add_sym_to_dubler(wchar_t sym);
    void pop_sym_to_dubler();
    void dubler_fill();
    // слайдеры
    void next_text_str();
    void back_text_str();
    // конвертируем файл в вектор строк с текстом
    std::vector<std::wstring> convert_file_to_text(std::string filename);
    // добавить слово в текст
    void add_word_in_text(std::vector<std::wstring>& text, Word word, int j);

public:
    bool is_not_reset = true;
    bool isEndString = false; // показывает кочился ли текст

    // background
    sf::Sprite sprite;
    //текст внутри окна
    std::vector<std::wstring> text_str;
    std::vector<sf::Text> vec_text;
    //текст дублер
    std::wstring dubler_str;
    sf::Text dubler;
    sf::Color dubler_color;

    //конструкторы
    TextWindow(int x, int y, TextDubler&);

    //функии
    void game_reset(ClockFace& clock);
    //функции для окошка текстового дублера
    wchar_t fount_sym_forTxtDub();

    //функции связанные  с дублером (наложенный текст)
    void checksym_dubler(int symbol, bool hardmode);
    void dubler_clean();

    void change_text_character();
    void change_count_text_str();
    void DrawTextWindow(sf::RenderWindow& window);
    // setters
    void setPos(int x, int y);
    void setText(std::string filename);

    // getters
    sf::Vector2i getPosition();
};