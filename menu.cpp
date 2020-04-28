#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

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
		window.display();
	}

	return 0;
}