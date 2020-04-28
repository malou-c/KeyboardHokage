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
    }

    int get_id() { return id; }; //Узнать id кнопки
    /* sf::Sprite get_sprite() { return background; }; */

    void set_borders(int left_border, int right_border, //Установить границы кнопки
                     int up_border, int down_border)
    {
        l_border = left_border;
        r_border = right_border;
        u_border = up_border;
        d_border = down_border;
    }

    int clicked(int x, int y) //Проверяет была ли нажата кнопка
    {
        if (x >= l_border && x <= r_border &&
            y >= u_border && y <= d_border)
        {
            return id;
        }
        return 0;
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
        window.display();
    }
}