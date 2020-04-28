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
	int l_border; //левая правая верхняя нижняя границы
	int r_border;
	int u_border;
	int d_border;
	sf::Sprite background;

public:
	MenuButton(int x, int y, std::string button_name)
	{
		std::string name;
		sf::Text out_name;
		int id;
		int l_border; //левая правая верхняя нижняя границы
		int r_border;
		int u_border;
		int d_border;
		sf::Sprite background;

		name = button_name;

		sf::Font font;
		font.loadFromFile("fonts/stdFont.ttf"); //шрифт
		out_name.setString(name);
		out_name.setFont(font);
		out_name.setCharacterSize(16);
		out_name.setColor(sf::Color::Red);
		out_name.setPosition(10, 10);

		sf::Image image;
		image.loadFromFile("yo.jpg");

		sf::Texture texture;
		texture.loadFromImage(image); //загружаем текстуру для фона

		background.setTexture(texture); //устанавливаем текстуру для спрайта
		background.setPosition(x, y);	//координаты для отрисовки кнопки
		//background.scale(0.5, 0.5);
	}

	int get_id() { return id; }; //Узнать id кнопки
	sf::Sprite get_sprite(){ return background; };

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
	}

	void draw(sf::RenderWindow &window)
	{
		window.draw(background);
		window.draw(out_name);
	}
};