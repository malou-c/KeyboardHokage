#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
//#include "clock.h"
using namespace sf;
using namespace std;

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

	

	//Создаю текстуру кнопки "Start"
	Texture starti;
	starti.loadFromFile(path);
	//Спрайт кнопки "Start"
	Sprite start(starti);
	start.setPosition((width / 2) - 142, 100);

	/*Font font;
	font.loadFromFile("fonts\\CyrilicOld.ttf");
	Text text("", font, 20);
	text.setFillColor(Color::Black); */





	Clock msstorage;
	Clock secstorage;
	int time = 0;
	int seconds = 0;
	int minsum = 1;
	int minutes = 0; 

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
		window.clear(Color::White);

		
		//runclock(window,time,seconds,minsum,minutes, msstorage, secstorage );

		Font font;
		font.loadFromFile("fonts\\CyrilicOld.ttf");
		Text text("", font, 20);
		text.setFillColor(Color::Black);

		if (time < 1000) {
			time = (msstorage.getElapsedTime().asMilliseconds());
		}
		else {
			time = 0;
			msstorage.restart();
		}

		if (seconds < 60) {
			seconds = secstorage.getElapsedTime().asSeconds();
		}
		else {
			seconds = 0;
			secstorage.restart();
		}



		minsum = seconds / 60;
			
			minutes += minsum;

			ostringstream stringmillsec, stringsec, stringmin;
			stringmillsec << time;
			stringsec << seconds;
			stringmin << minutes;


			text.setString("Время: " + stringmin.str() + ":" + stringsec.str() + ":" + stringmillsec.str());
			text.setPosition(200, 200);
			window.draw(text); 



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