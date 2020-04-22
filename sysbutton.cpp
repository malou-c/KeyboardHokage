
#include "hpp/sysbutton.hpp"

// конструкторы

SysButtonForKB::SysButtonForKB(sf::String path, int code) {
  this->code = code;
  this->path = path;
  img.loadFromFile(this->path);  // подгружаем изображение
  texture.loadFromImage(img);    // текстуру
  sprite.setTexture(texture);    // спрайт
}

SysButtonForKB::SysButtonForKB(sf::String path) {
  this->path = path;
  img.loadFromFile(this->path);  // подгружаем изображение
  texture.loadFromImage(img);    // текстуру
  sprite.setTexture(texture);    // спрайт
}

void SysButtonForKB::DrawButton(sf::RenderWindow &window) {
  window.draw(sprite);
}