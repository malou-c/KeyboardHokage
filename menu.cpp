#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "hpp/MenuButton.hpp"
#include "hpp/MyKeyboard.hpp"
#include "hpp/clockface.hpp"
#include "hpp/screentxt.hpp"

using namespace sf;
int ID = 0;                       // глобал  ID
int height = 1000, width = 1900;  // высота и ширина окна

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
  window.setFramerateLimit(60);

  //таймер
  ClockFace clface(10, 10);  // инициализируем часы в  позиции x y

  //кнопки меню
  MenuButton butBack(100, 600, 0),
             butPlay(100, 100, 1),
             butRecord(100, 200, 2);

  //клавиатура
  MyKeyboard mykb(150, 550);  // инициализируем клавиатру в позиции x y

  //окно с  текстом
  TextWindow txwin(400, 200);         //окно с  текстом
  txwin.setText("texts/text_1.txt");  // берем текст
  txwin.change_count_text_str();  // вычисляем сколько строк поместится в  окно
  txwin.change_text_character();  // вычисляем характеристики текста

  //Пока окно открыто
  while (window.isOpen()) {
    //Обработка событий
    Event event;
    while (window.pollEvent(event)) {
      //Если событие закрытия
      if (event.type == Event::Closed)
        //Закрыть окно
        window.close();
      switch (ID) {
        case 1:
          mykb.Update(event, txwin);
          if (event.type == Event::TextEntered && !clface.isStart) {
                        clface.ClockStart();
          }
          break;

        default:
          break;
      }
    }

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
        // update
        butBack.is_clicked(window);
        clface.update_clock();
        if (txwin.isEndString)
          clface.ClockStop();  // если кончился текст в окне
        // draw
        // кнопка назад
        butBack.draw(window);          // кнопка назад
        clface.DrawClock(window);      //таймер
        mykb.DrawKB(window);           // клавиатура
        txwin.DrawTextWindow(window);  // окно с  текстом
        break;
      case 2:
        // update
        butBack.is_clicked(window);
        // draw
        butBack.draw(window);  // кнопка назад

        break;

      default:
        break;
    }

    window.display();
  }

  return 0;
}