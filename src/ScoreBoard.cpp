#include "ScoreBoard.hpp"

//конструктор
ScoreBoard::ScoreBoard()
{
    int width = 1500;
    bckgrnd_pic.loadFromFile("images/ye.jpg");

    bckgrnd_sprite.setTexture(bckgrnd_pic);
    bckgrnd_sprite.setScale(0.5, 1); //растягивает/сжимает изображение
    bckgrnd_sprite.setPosition(width / 2, 0);

    font.loadFromFile("fonts/stdFont.ttf");
    text.setFont(font);
    text.setString(out_text);
    text.setCharacterSize(16);
    text.setFillColor(sf::Color::Red);
    text.setPosition((width / 2) + (width / 6), 10);
}
void ScoreBoard::load_board()
{ //Загружаем таблицу
    if (!is_loaded) {
        out_text = "";
        stats = load_of_file(); //Загружаем данные (имя время)
        is_loaded = true;

        for (size_t i = 0; i < stats.size() && i < 50;
             i++) //записываем информацию о превых 50
        {         //пользователях в строку
            out_text += std::to_string(i + 1) + ") "
                    + (std::string)stats[i].user_name
                    + " Text: " + (std::string)stats[i].text_name
                    + " Time: " + (std::to_string(stats[i].time))
                    + " cps: " + std::to_string(stats[i].cps) + "\n";
        }
        text.setString(out_text);
    }
}

void ScoreBoard::draw_board(sf::RenderWindow& window)
{
    window.draw(bckgrnd_sprite);
    window.draw(text);
}

void ScoreBoard::clear()
{
    stats.clear();
    is_loaded = false;
};
