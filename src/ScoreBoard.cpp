#include "ScoreBoard.hpp"

//конструктор
ScoreBoard::ScoreBoard(int x, int y)
{
    bckgrnd_pic.loadFromFile("images/SB_background.png");

    bckgrnd_sprite.setTexture(bckgrnd_pic);
    bckgrnd_sprite.setPosition(x, y);
    font.loadFromFile("fonts/stdFont.ttf");
    text.setFont(font);
    text.setString(out_text);
    text.setCharacterSize(font_size);
    text.setFillColor(color_text);
    text.setPosition(x + 14, y + 55);
}
void ScoreBoard::load_board()
{ //Загружаем таблицу
    if (!is_loaded) {
        out_text = "";
        stats = load_of_file(); //Загружаем данные (имя время)
        is_loaded = true;
        //запись информации о первых пользователях в таблице
        for (size_t i = 0; i < stats.size() && i < count_draw; i++) {
            out_text += std::to_string(i + 1)
                    + ") Name: " + (std::string)stats[i].user_name
                    + "\nText: " + (std::string)stats[i].text_name
                    + " Time: " + std::to_string(stats[i].time_min) + ":"
                    + std::to_string(stats[i].time_sec) + ":"
                    + std::to_string(stats[i].time_ms)
                    + " max cps: " + std::to_string(stats[i].max_cps) + "\n";
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
