#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>



class HelpButton {
public:
    int page_switch = 0;
    bool one_click;
    std::string l_path, r_path, h_path;
    sf::Image hp;
    sf::Texture help_texture;
    sf::Sprite help_sprite;
    sf::Image left;
    sf::Image right;
    sf::Texture left_tr;
    sf::Texture right_tr;
    sf::Sprite left_triangle;
    sf::Sprite right_triangle;
    std::vector<sf::Image> Images = {s1, s2, s3, s4, s5};
    sf::Texture sd1, sd2, sd3, sd4, sd5;
    sf::Sprite sld1, sld2, sld3, sld4, sld5;

    HelpButton(int x, int y);

    //функции
    void HelpButtonCreate(int x, int y);
    void DrawHelpButton(sf::RenderWindow &window);
    void MoveLeftCreate(int x, int y);
    void MoveRightCreate(int x, int y);
    void DrawMoves(sf::RenderWindow &window);
    void MoveRight(sf::RenderWindow& window);
    void MoveLeft(sf::RenderWindow& window);
    void DrawSd(sf::RenderWindow &window);
    void SdCreate(int x, int y);
};