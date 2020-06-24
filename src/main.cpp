#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Folder.hpp"
#include "HelpButton.hpp"
#include "MenuButton.hpp"
#include "MyKeyboard.hpp"
#include "NameInput.hpp"
#include "PersonStats.hpp"
#include "ScoreBoard.hpp"
#include "clockface.hpp"
#include "screentxt.hpp"
#include "text_dubler.hpp"
#include "text_selection.hpp"

using namespace sf;
int ID = 0;                      // глобал  ID
int height = 1000, width = 1900; // высота и ширина окна

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
            VideoMode(width, height),
            "KeyboardNinja",
            Style::Default,
            settings);
    window.setVerticalSyncEnabled(true); // вертикальная синхронизация
    window.setFramerateLimit(60);

    //кнопки меню

    MenuButton butSelectText(100, 200, "MB_play.png", 4);
    MenuButton butHelp(100, 300, "MB_theory.png", 3);
    MenuButton butRecord(100, 400, "MB_records.png", 2);
    MenuButton butExit(100, 500, "MB_exit.png", -1);
    //
    MenuButton butBack(100, 600, 0);
    MenuButton butPlay(100, 100, "MB_play.png", 1);

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
    NameInput name_input;
    PersonStats person_stats;

    //страничка с выбором текста перед игрой
    TextSelection txtselect(300, 30);

    HelpButton help(200, 100);

    //таблица рекордов
    ScoreBoard scorebd;

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
            case 0:
                // update
                butSelectText.is_clicked(window, event);
                butRecord.is_clicked(window, event);
                butHelp.is_clicked(window, event);
                butExit.is_clicked(window, event);
                break;
            case 1:
                //клавиатура обновляется только если текст не кончился
                mykb.Update(event, txwin);
                if (event.type == Event::TextEntered && !clface.isStart) {
                    clface.ClockStart();
                }
                butBack.is_clicked(window, event);
                break;
            case 2:
                // update
                butBack.is_clicked(window, event);
                break;
            case 3:
                // update
                butBack.is_clicked(window, event);
                break;
            case 4:
                // update
                butPlay.is_clicked(window, event);
                butBack.is_clicked(window, event);
                //кнопки << >>
                txtselect.but_update(event, window);
                txtselect.update_sections(txwin, event, window);
                break;

            default:
                break;
            }
            name_input.window_for_name_input(window, event);
            person_stats.set_name(name_input.get_input());
            help.MoveLeftButton(window, event);
            help.MoveRightButton(window, event);
        }
        // чистим окно
        window.clear(Color::White);

        switch (ID) {
        case -1:
            //выходим из приложения
            window.close();
            break;
        case 0:
            //даем добро на рестарт так как мы вышли в меню
            if (!txwin.is_not_reset) {
                txwin.is_not_reset = true;
            }
            // draw
            //кнопки меню
            butSelectText.draw(window);
            butRecord.draw(window);
            butHelp.draw(window);
            butExit.draw(window);
            //
            scorebd.is_loaded = false;
            break;
        case 1:
            //рестартаем текст и таймер
            if (txwin.is_not_reset) {
                txwin.game_reset(clface);
                txwin.is_not_reset = false;
            }
            // если кончился текст в окне
            if (txwin.isEndString && clface.isStart) {
                clface.ClockStop();
                txtdubler.clear();
                //запись в таблицу рекордов
                scorebd.add(
                        name_input.get_input(),
                        txtselect.getCurrent(),
                        14,
                        txtdubler.cps_max);
            }

            // update
            clface.update_clock();

            // draw
            butBack.draw(window);         // кнопка назад
            clface.DrawClock(window);     //таймер
            mykb.DrawKB(window);          // клавиатура
            txwin.DrawTextWindow(window); // окно с  текстом
            txtdubler.draw(window);
            break;
        case 2:
            // draw
            butBack.draw(window); // кнопка назад
            //Рисуем таблицу рекордов
            scorebd.load_board();
            scorebd.draw_board(window);
            break;
        case 3:
            butBack.draw(window);
            help.DrawSd(window);
            help.DrawMoves(window);
            break;
        case 4:
            // draw
            txtselect.draw(window);
            //кнопки
            butPlay.draw(window);
            butBack.draw(window);
            break;

        default:
            break;
        }
        // ввод имени
        name_input.draw(window);
        //вывод ВСЕГО на экран
        window.display();
    }

    return 0;
}