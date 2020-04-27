#pragma once

#include <SFML/Graphics.hpp>

#include "file.cpp"
#include <iostream>

std::vector<PersonStats> load_board()
{//Загружаем таблицу

    std::vector<PersonStats> stats;
    File file;
    stats = file.load();//Загружаем данные (имя время)
    return stats;
}

void draw_board(sf::RenderWindow &window, std::vector<PersonStats> stats,
                int width = 1500, int high = 900)
{//Рисует таблицу рекордов
/*  std::vector<PersonStats> stats;
    File file;
    stats = file.load();//Загружаем данные (имя время)
 */

    sf::Image image;
    image.loadFromFile("ye.jpg");//Фон на котором будут отображаться данные

    sf::Texture bckgrnd_pic; //фон для таблицы рекордов
    bckgrnd_pic.loadFromImage(image);

    sf::Sprite bckgrnd_sprite;
    bckgrnd_sprite.setTexture(bckgrnd_pic);
    bckgrnd_sprite.setScale(0.5, 1);//растягивает/сжимает изображение
    bckgrnd_sprite.setPosition(width / 2, 0);

    sf::Text text;
    std::string out_text = "";

    for (int i = 0; i < stats.size() || i < 50; i++ )//записываем информацию о превых 50
    {                                                //пользователях в строку
        out_text += (std::to_string((i + 1))
                     + ')'
                     + (std::string)stats[i].name
                     + ' ' 
                     + (std::to_string( stats[i].time ))
                     + "\n");
    }

    sf::Font font;
    font.loadFromFile("fonts/stdFont.ttf");//шрифт
    text.setFont(font);
    text.setString(out_text);
    text.setCharacterSize(16);
    text.setColor(sf::Color::Red);
    text.setPosition((width/ 2) + (width / 6) , 10);

    window.draw(bckgrnd_sprite);
    window.draw(text);

}


//ДЛЯ ТЕСТОВ
/* int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 900), "Test");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed ||
              (event.type == sf::Event::KeyPressed &&
               event.key.code == sf::Keyboard::Escape)) {
            window.close();
          }
        }

        window.clear();
        draw_board(window);
        window.display();
    }
}   */