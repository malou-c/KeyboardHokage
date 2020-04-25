#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
//#include "clock.h"
using namespace sf;
using namespace std;

int main()
{
	String path; // ���� � �����
#ifdef WINDOWS // ���� �� Windows
	path = "images_menu\\start.png"; // ����� ����
#else // ���� �� Windows
	path = "images_menu/start.png"; // �����
#endif
	int height = 950, width = 1500; // ������ � ������ ����
	//����� �����������
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	//������������� ����
	RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default, settings);

	

	//������ �������� ������ "Start"
	Texture starti;
	starti.loadFromFile(path);
	//������ ������ "Start"
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


			text.setString("�����: " + stringmin.str() + ":" + stringsec.str() + ":" + stringmillsec.str());
			text.setPosition(200, 200);
			window.draw(text); 



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