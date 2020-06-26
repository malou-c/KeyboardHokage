#include "button.hpp"

// конструкторы
ButtonForKB::ButtonForKB()
{
    img.loadFromFile(path);     // подгружаем изображение
    texture.loadFromImage(img); // текстуру
    sprite.setTexture(texture); // спрайт
}

// функции

void ButtonForKB::DrawButton(sf::RenderWindow& window)
{
    window.draw(sprite);
}
