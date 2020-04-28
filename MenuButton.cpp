#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class MenuButton
{
private:
    std::string name;
    sf::Text out_name;
    int id;
    int l_border; //левая граница кнопки (x)
    int r_border;//правая граница кнопки (x)
    int u_border;//верхняя граница кнопки (y)
    int d_border;//нижняя граница кнопки (y)
    sf::Sprite background;//фон для кнопки
    sf::Font font;//шрифт текста кнопки
    sf::Image image;//фото для фона кнопки
    sf::Texture texture;//текстура для фона кнопки

public:
    MenuButton(int x, int y, std::string button_name)
    {
        name = button_name;//Имя кнопки

        font.loadFromFile("fonts/stdFont.ttf"); //шрифт
        out_name.setString(name);
        out_name.setFont(font);
        out_name.setCharacterSize(16);
        out_name.setColor(sf::Color::Red);
        out_name.setPosition(x + 10, y + 10);

        image.loadFromFile("yo.jpg");

        texture.loadFromImage(image); //загружаем текстуру для фона

        background.setTexture(texture);
        background.setTextureRect(sf::IntRect(0, 0, 100, 100)); //устанавливаем текстуру для спрайта
        background.setPosition(x, y);   //координаты для отрисовки кнопки
        //background.scale(0.5, 0.5);

        set_borders();
    }

    int get_id() { return id; }; //Узнать id кнопки
    /* sf::Sprite get_sprite() { return background; }; */

    void set_borders()//Установить границы кнопки
    {
        l_border = background.getLocalBounds().left;
        r_border = background.getLocalBounds().width;
        u_border = background.getLocalBounds().top;
        d_border = background.getLocalBounds().height;
    }

    int is_clicked(sf::RenderWindow &window) //Проверяет была ли нажата кнопка
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        &&  sf::IntRect((background).getLocalBounds()).contains(sf::Mouse::getPosition(window)))
        {
            return id;
        } else
        {
            return 0;
        }
        
    }

    void draw(sf::RenderWindow &window)//рисует кнопку
    {
        window.draw(background);
        window.draw(out_name);
    }
};

//ДЛЯ ТЕСТОВ
int main()
{
    sf::RenderWindow window(sf::VideoMode(1500, 900), "Test");

    MenuButton button(50, 50, "ABC");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed &&
                 event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        button.draw(window);//////Вот это рисует
        button.is_clicked(window);
        window.display();
    }
}