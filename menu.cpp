#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "hpp/MenuButton.hpp"
#include "hpp/MyKeyboard.hpp"
#include "hpp/clockface.hpp"
#include "hpp/screentxt.hpp"

using namespace sf;

int height = 950, width = 1500;  // высота и ширина окна

int ID = 0;  // глобал  ID

int main() {
  String path;                      // путь к файлу
#ifdef WINDOWS                      // если ОС Windows
  path = "images_menu\\start.png";  // такой путь
#else                               // если не Windows
  path = "images_menu/start.png";  // такой
#endif

  //Делаю сглаживание
  ContextSettings settings;
  settings.antialiasingLevel = 8;
  //Инициализирую окно
  RenderWindow window(VideoMode(width, height), "KeybordNinja", Style::Default,
                      settings);
  window.setVerticalSyncEnabled(true);  // вертикальная синхронизация

  //таймер
  ClockFace clface(10, 10);  // инициализируем часы в  позиции x y

  //кнопки меню
  MenuButton butPlay(200, 100, 1);
  MenuButton butRecord(200, 100, 2);

  //клавиатура
  MyKeyboard mykb(150, 550);  // инициализируем клавиатру в позиции x y

  //окно с  текстом
  TextWindow txwin(200, 100);  // инициализируем окно с текстом в позиции x y

  //Пока окно открыто
  while (window.isOpen()) {
    //Обработка событий
    Event event;
    while (window.pollEvent(event)) {
      //Если событие закрытия
      if (event.type == Event::Closed)
        //Закрыть окно
        window.close();
    }
    // UPDATE
    butPlay.is_clicked(window);
    butRecord.is_clicked(window);
    clface.update_clock();  // обновление таймера

    // чистим окно
    window.clear(Color::White);

    switch (ID) {
      case 0:
        // update
        butPlay.is_clicked(window);
        butRecord.is_clicked(window);
        // draw
        //кнопки меню
        butPlay.draw(window);
        butRecord.draw(window);
        break;
      case 1:
        mykb.Update(event, txwin);
        // draw
        clface.DrawClock(window);      //таймер
        mykb.DrawKB(window);           // клавиатура
        txwin.DrawTextWindow(window);  // окно с  текстом
        break;

      default:
        break;
    }
    //все что рисуем
    window.clear(Color::White);  // чистим

    //кнопки меню
    butPlay.draw(window);
    butRecord.draw(window);

    window.display();
  }

  return 0;
}