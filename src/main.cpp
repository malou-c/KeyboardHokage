#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Folder.hpp"
#include "MenuButton.hpp"
#include "MyKeyboard.hpp"
#include "PersonStats.hpp"
#include "ScoreBoard.hpp"
#include "clockface.hpp"
#include "screentxt.hpp"
#include "text_dubler.hpp"

using namespace sf;
int ID = 0;                      // глобал  ID
int height = 1000, width = 1900; // высота и ширина окна
bool lidboard_is_load = false; //загружена ли таблица рекордов
std::vector<PersonStats> stats; //для хранения таблицы рекордов

int main()
{
    String path;                     // путь к файлу
#ifdef WINDOWS                       // если ОС Windows
    path = "images_menu\\start.png"; // такой путь
#else                                // если не Windows
    path = "images_menu/start.png"; // такой
#endif
    //Делаю сглаживание
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    //Инициализирую окно
    RenderWindow window(
            VideoMode(width, height), "KeybordNinja", Style::Default, settings);
    window.setVerticalSyncEnabled(true); // вертикальная синхронизация
    window.setFramerateLimit(60);

    //кнопки меню
    MenuButton butExit(width - 100, 0, -1), butBack(100, 600, 0),
            butPlay(100, 100, 1), butRecord(100, 200, 2);

    //клавиатура
    MyKeyboard mykb(270, 600); // инициализируем клавиатру в позиции x y

    //текстовый дублер
    TextDubler txtdubler(700, 430);

    //окно с  текстом
    TextWindow txwin(400, 200, txtdubler); //окно с  текстом
    txwin.setText("texts/text_1.txt");     // берем текст
    txwin.change_count_text_str(); // вычисляем сколько строк поместится в  окно
    txwin.change_text_character(); // вычисляем характеристики текста

    //таймер
    ClockFace clface(10, 10, txtdubler); // инициализируем часы в  позиции x y
    PersonStats test;

    //Пока окно открыто
    while (window.isOpen()) {
        //Обработка событий
        Event event;
        while (window.pollEvent(event)) {
            //Если событие закрытия
            if (event.type == sf::Event::Closed || //если окно закрыто или
                (event.type == sf::Event::KeyPressed && //если нажат esc
                 event.key.code == sf::Keyboard::Escape))
                window.close(); //то закрыть окно
            switch (ID) {
            case 1:
                //клавиатура обновляется только если текст не кончился
                if (!txwin.isEndString) {
                    mykb.Update(event, txwin);
                }

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
        case -1:
            //выходим из приложения
            window.close();
            break;
        case 0:
            // update
            butPlay.is_clicked(window);
            butRecord.is_clicked(window);
            // draw
            //кнопки меню
            butPlay.draw(window);
            butRecord.draw(window);
            lidboard_is_load = false;
            break;
        case 1:
            // update
            butBack.is_clicked(window);
            clface.update_clock();
            if (txwin.isEndString) {
                clface.ClockStop(); // если кончился текст в окне
            }

            // draw
            butBack.draw(window);         // кнопка назад
            clface.DrawClock(window);     //таймер
            mykb.DrawKB(window);          // клавиатура
            txwin.DrawTextWindow(window); // окно с  текстом
            txtdubler.draw(window);
            break;
        case 2:
            // update
            butBack.is_clicked(window);
            // draw
            butBack.draw(window); // кнопка назад
            //Рисуем таблицу рекордов
            if (!lidboard_is_load) {
                stats = load_board();
                lidboard_is_load = true;
            }
            draw_board(window, stats);
            break;

        default:
            break;
        }
        //Выход из приложения
        butExit.is_clicked(window);

        test.window_for_name_input(window, event);

        butExit.draw(window);
        window.display();
    }

    return 0;
}