#include "HelpButton.h"

HelpButton::HelpButton(int x, int y)
{
    
    MoveLeftCreate(x-100, y + 325);
    MoveRightCreate(x + 1600,  y + 325);
    SdCreate(x, y);
}

void HelpButton::HelpButtonCreate(int x, int y)
{
#ifdef WINDOWS                       
    h_path = "helpimages\\help.png"; 
#else                                
    h_path = "helpimages/help.png";  
#endif
    hp.loadFromFile(h_path);
    help_texture.loadFromImage(hp);
    help_sprite.setTexture(help_texture);

    help_sprite.setPosition(x, y);
}

void HelpButton::DrawHelpButton(sf::RenderWindow& window)
{
    window.draw(help_sprite);
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

void HelpButton::MoveRight(sf::RenderWindow &window)
{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && sf::IntRect(1800, 425, 50, 50)
                   .contains(sf::Mouse::getPosition(window))) {
        if (page_switch != 4) {
                Sleep(500);
            page_switch++;
        }
    }
   
}

void HelpButton::MoveLeft(sf::RenderWindow& window)
{
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)
        && sf::IntRect(100, 425, 50, 50)
                   .contains(sf::Mouse::getPosition(window))) {
        if (page_switch != 0) {
                Sleep(500);
            page_switch--;
        }
    }
    
}

void HelpButton::SdCreate(int x, int y)
{
    s1.loadFromFile("helpimages\\sd1.jpg");
    sd1.loadFromImage(s1);
    sld1.setTexture(sd1);

    s2.loadFromFile("helpimages\\sd2.jpg");
    sd2.loadFromImage(s2);
    sld2.setTexture(sd2);

    s3.loadFromFile("helpimages\\sd3.jpg");
    sd3.loadFromImage(s3);
    sld3.setTexture(sd3);

    s4.loadFromFile("helpimages\\sd4.jpg");
    sd4.loadFromImage(s4);
    sld4.setTexture(sd4);

    s5.loadFromFile("helpimages\\sd5.jpg");
    sd5.loadFromImage(s5);
    sld5.setTexture(sd5);

    sld1.setPosition(x, y);
    sld2.setPosition(x, y);
    sld3.setPosition(x, y);
    sld4.setPosition(x, y);
    sld5.setPosition(x, y);
}

void HelpButton::DrawSd(sf::RenderWindow& window)
{
    switch (page_switch) {
    case 0:
        window.draw(sld1);
        break;

    case 1:
        window.draw(sld2);
        break;
    case 2:
        window.draw(sld3);
        break;

    case 3:
        window.draw(sld4);
        break;

    case 4:
        window.draw(sld5);
        break;

    default:
        break;
    }
}