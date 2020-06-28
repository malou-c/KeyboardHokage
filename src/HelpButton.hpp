#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class HelpButton {
private:
    //переменная текущего слайда
    int page_switch = 0;
    //текстуры
    sf::Image hp, left, right;
    sf::Texture help_texture, left_tr, right_tr;
    std::vector<sf::Image> Images;
    std::vector<sf::Texture> Textures;
    //функции create
    void MoveLeftCreate(int x, int y);
    void MoveRightCreate(int x, int y);
    void SdCreate(int x, int y);
    //листать слайды
    void MoveRight();
    void MoveLeft();

public:
    std::string l_path, r_path, h_path;
    sf::Sprite help_sprite, left_triangle, right_triangle;
    std::vector<sf::Sprite> Sprites;
    //конструкторы
    HelpButton();
    HelpButton(int x, int y);

    //функции
    void DrawMoves(sf::RenderWindow& window);
    void MoveRightButton(sf::RenderWindow& window, sf::Event event);
    void MoveLeftButton(sf::RenderWindow& window, sf::Event event);
    void DrawSd(sf::RenderWindow& window);
};