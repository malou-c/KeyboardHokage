#include "mode_game.hpp"

ModeGame::ModeGame(int x, int y)
{
    //загружаем изображения в текстуры
    tex_easy.loadFromFile("images/MG_easy.png");
    tex_hard.loadFromFile("images/MG_hard.png");
    //текстуры в спрайты
    sprite_easy.setTexture(tex_easy);
    sprite_hard.setTexture(tex_hard);
    //ставим в позицию
    sprite_hard.setPosition(x, y);
    sprite_easy.setPosition(x + sprite_hard.getLocalBounds().width + 20, y);
    //окрашиваем хард по дефолту в enable color
    sprite_hard.setColor(color_enable);
}

void ModeGame::update(sf::RenderWindow& window, sf::Event event)
{
    if (is_hardmode && isClicked(sprite_easy, window, event)) {
        is_hardmode = false;
        sprite_hard.setColor(color_def);
        sprite_easy.setColor(color_enable);

    } else if (!is_hardmode && isClicked(sprite_hard, window, event)) {
        is_hardmode = true;
        sprite_hard.setColor(color_enable);
        sprite_easy.setColor(color_def);
    }
}

void ModeGame::draw(sf::RenderWindow& window)
{
    window.draw(sprite_easy);
    window.draw(sprite_hard);
}