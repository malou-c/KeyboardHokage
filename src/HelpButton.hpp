#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>

class HelpButton {
public:
    int page_switch = 0;
    
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
    std::vector<sf::Image> Images; 
    std::vector<sf::Texture> Textures;
    std::vector<sf::Sprite> Sprites;
    HelpButton(int x, int y);

    //функции
    void HelpButtonCreate(int x, int y);
    void DrawHelpButton(sf::RenderWindow &window);
    void MoveLeftCreate(int x, int y);
    void MoveRightCreate(int x, int y);
    void DrawMoves(sf::RenderWindow &window);
    void MoveRight();
    void MoveLeft();
    void MoveRightButton(sf::RenderWindow& window);
    void MoveLeftButton(sf::RenderWindow& window);
    void DrawSd(sf::RenderWindow &window);
    void SdCreate(int x, int y);
};