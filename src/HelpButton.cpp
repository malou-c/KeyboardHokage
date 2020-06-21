#include "HelpButton.hpp"

HelpButton::HelpButton(){};

HelpButton::HelpButton(int x, int y)
{
    MoveLeftCreate(x - 100, y + 325);
    MoveRightCreate(x + 1600, y + 325);
    SdCreate(x, y);
}

void HelpButton::MoveLeftCreate(int x, int y)
{
#ifdef WINDOWS
    l_path = "helpimages\\left.jpg";
#else
    l_path = "helpimages/left.jpg";
#endif
    left.loadFromFile(l_path);
    left_tr.loadFromImage(left);
    left_triangle.setTexture(left_tr);

    left_triangle.setPosition(x, y);
}

void HelpButton::MoveRightCreate(int x, int y)
{
#ifdef WINDOWS
    r_path = "helpimages\\right.jpg";
#else
    r_path = "helpimages/right.jpg";
#endif
    right.loadFromFile(r_path);
    right_tr.loadFromImage(right);
    right_triangle.setTexture(right_tr);

    right_triangle.setPosition(x, y);
}

void HelpButton::DrawMoves(sf::RenderWindow& window)
{
    window.draw(left_triangle);
    window.draw(right_triangle);
}

void HelpButton::MoveLeft()
{
    page_switch--;
}

void HelpButton::MoveRight()
{
    page_switch++;
}

void HelpButton::MoveRightButton(sf::RenderWindow& window, sf::Event event)
{
    if (sf::IntRect(1800, 425, 50, 50).contains(sf::Mouse::getPosition(window))
        && event.type == event.MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left) {
        if (page_switch != 4) {
            MoveRight();
        }
    }
}

void HelpButton::MoveLeftButton(sf::RenderWindow& window, sf::Event event)
{
    if (sf::IntRect(100, 425, 50, 50).contains(sf::Mouse::getPosition(window))
        && event.type == event.MouseButtonReleased
        && event.mouseButton.button == sf::Mouse::Left) {
        if (page_switch != 0) {
            MoveLeft();
        }
    }
}

void HelpButton::SdCreate(int x, int y)
{
    Images.resize(5);
    Textures.resize(5);
    Sprites.resize(5);
    Images[0].loadFromFile("helpimages/sd1.jpg");
    Textures[0].loadFromImage(Images[0]);
    Sprites[0].setTexture(Textures[0]);

    Images[1].loadFromFile("helpimages/sd2.jpg");
    Textures[1].loadFromImage(Images[1]);
    Sprites[1].setTexture(Textures[1]);

    Images[2].loadFromFile("helpimages/sd3.jpg");
    Textures[2].loadFromImage(Images[2]);
    Sprites[2].setTexture(Textures[2]);

    Images[3].loadFromFile("helpimages/sd4.jpg");
    Textures[3].loadFromImage(Images[3]);
    Sprites[3].setTexture(Textures[3]);

    Images[4].loadFromFile("helpimages/sd5.jpg");
    Textures[4].loadFromImage(Images[4]);
    Sprites[4].setTexture(Textures[4]);

    Sprites[0].setPosition(x, y);
    Sprites[1].setPosition(x, y);
    Sprites[2].setPosition(x, y);
    Sprites[3].setPosition(x, y);
    Sprites[4].setPosition(x, y);
}

void HelpButton::DrawSd(sf::RenderWindow& window)
{
    switch (page_switch) {
    case 0:
        window.draw(Sprites[0]);
        break;

    case 1:
        window.draw(Sprites[1]);
        break;
    case 2:
        window.draw(Sprites[2]);
        break;

    case 3:
        window.draw(Sprites[3]);
        break;

    case 4:
        window.draw(Sprites[4]);
        break;

    default:
        break;
    }
}