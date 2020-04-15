#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main()
{
	int height = 950, width = 1500;
	//Делаю сглаживание
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	//Инициализирую окно
	RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default, settings);
	window.clear(Color::White);


	//Создаю текстуру кнопки "Start"
	Texture starti;
	starti.loadFromFile("start.png");
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
				std::cout << "Eeeee";
				//Здесь будет игра
			}
		}



		window.display();
	}

	return 0;
}