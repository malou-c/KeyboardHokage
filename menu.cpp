#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

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
		name = button_name;

		sf::Font font;
		font.loadFromFile("fonts/stdFont.ttf"); //шрифт
		out_name.setFont(font);
		out_name.setString(name);
		out_name.setCharacterSize(16);
		out_name.setColor(sf::Color::Red);
		out_name.setPosition(10, 10);

		sf::Image image;
		image.loadFromFile("yo.jpg");

		sf::Texture texture;
		texture.loadFromImage(image); //загружаем текстуру для фона

		background.setTexture(texture); //устанавливаем текстуру для спрайта
		background.setPosition(x, y);	//координаты для отрисовки кнопки
		background.scale(0.5, 0.5);
	}

	int get_id() { return id; }; //Узнать id кнопки
	//sf::Sprite get_sprite(){ return background; };

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
		window.draw(out_name);
		window.draw(background);
	}
};

int main()
{
	String path;					 // ���� � �����
#ifdef WINDOWS						 // ���� �� Windows
	path = "images_menu\\start.png"; // ����� ����
#else								 // ���� �� Windows
	path = "images_menu/start.png"; // �����
#endif
	int height = 950, width = 1500; // ������ � ������ ����
	//����� �����������
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	//������������� ����
	RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default, settings);
	window.clear(Color::White);

	//������ �������� ������ "Start"
	Texture starti;
	starti.loadFromFile(path);
	//������ ������ "Start"
	Sprite start(starti);
	start.setPosition((width / 2) - 142, 100);
	window.draw(start);

	/* MenuButton button(10, 10);
	button.set_borders(50, 500, 0, 500);
	window.draw(button.get_sprite()); */

	MenuButton button(10, 10, "ABD");

	//���� ���� �������
	while (window.isOpen())
	{
		//��������� �������
		Event event;
		while (window.pollEvent(event))
		{
			//���� ������� ��������
			if (event.type == Event::Closed)
				//������� ����
				window.close();
		}

		// ���� ������ ����� ������ ����
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			// ���� ���� ��������� � �������������� �� ����������� x-498, y-100, � ��������� 284�54
			if (IntRect((width / 2) - 142, 100, 284, 54).contains(Mouse::getPosition(window)))
			{
				//����� ����� ����!
			}
		}
		button.draw(window);
		window.display();
	}

	return 0;
}