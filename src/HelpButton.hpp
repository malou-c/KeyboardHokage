#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class HelpButton {
public:
    int page_switch = 0;
    
    std::string l_path, r_path, h_path;
    sf::Image hp, left, right;
    sf::Texture help_texture, left_tr, right_tr;
    sf::Sprite help_sprite, left_triangle, right_triangle;
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
    void MoveRightButton(sf::RenderWindow& window, sf::Event& event);
    void MoveLeftButton(sf::RenderWindow& window, sf::Event& event);
    void DrawSd(sf::RenderWindow &window);
    void SdCreate(int x, int y);
};