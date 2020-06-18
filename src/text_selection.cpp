#include "text_selection.hpp"

TextSelection::TextSelection(int x, int y)
{
    //устанавливаем позицию
    pos.x = x;
    pos.y = y;
    // font
    font.loadFromFile("fonts/stdFont.ttf");
    // background
    texture_bg.loadFromFile("images/TS_background.png");
    background.setTexture(texture_bg);
    background.setPosition(pos.x, pos.y);
    //отступы для секций
    indent_sect.x = 18;
    indent_sect.y = 15;
    //класс работы с папками
    std::string path_folder = "texts";
    Folder folder(path_folder);

    //секции
    name_folders = folder.contains();
    sections.resize(name_folders.size());
    int height_sect = sections[0].sprite_sect.getLocalBounds().height;
    std::cout << "count file " << name_folders.size() << std::endl;
    std::cout << "count vecor size " << sections.size() << std::endl;
    for (size_t i = 0; i < name_folders.size(); i++) {
        // позиция секций
        sections[i].sprite_sect.setPosition(
                x + indent_sect.x, y + indent_sect.y + (i * height_sect));

        // название текста
        Text txt(name_folders[i], font, 40);
        txt.setFillColor(Color::Black);
        txt.setPosition(
                x + indent_sect.x, y + indent_sect.y + (i * height_sect));
        sections[i].name_txt = txt;
    }
}

void TextSelection::draw(RenderWindow& window)
{
    //задний фон
    window.draw(background);
    //секции
    for (size_t i = 0; i < (sections.size() % 10); i++) {
        window.draw(sections[i].sprite_sect);
        window.draw(sections[i].name_txt);
    }
}