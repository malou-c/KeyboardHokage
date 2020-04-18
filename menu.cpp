#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

int main()
{
	String path; // путь к файлу
	#ifdef WINDOWS // если ОС Windows
	path = "images_menu\\start.png"; // такой путь
	#else // если не Windows
	path = "images_menu/start.png"; // такой
	#endif
	int height = 950, width = 1500; // высота и ширина окна
	//Делаю сглаживание
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	//Инициализирую окно
	RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default, settings);
	window.clear(Color::White);
	

	//Создаю текстуру кнопки "Start"
	Texture starti;
	starti.loadFromFile(path);
	//Спрайт кнопки "Start"
	Sprite start(starti);
	start.setPosition((width / 2) - 142, 100);
	window.draw(start);

	//Пока окно открыто
	while (window.isOpen())
	{
		//Обработка событий
		Event event;
		while (window.pollEvent(event))
		{
			//Если событие закрытия
			if (event.type == Event::Closed)
				//Закрыть окно
				window.close();
		}


		// Если нажата левая кнопка мыши
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			// Если мышь находится в прямоугольнике по координатам x-498, y-100, с размерами 284х54
			if (IntRect((width / 2) - 142, 100, 284, 54).contains(Mouse::getPosition(window)))
			{
				//Здесь будет игра!
			}
		}



		window.display();
	}

	return 0;
}