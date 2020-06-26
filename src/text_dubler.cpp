#include "text_dubler.hpp"

// constructor
TextDubler::TextDubler()
{
}
TextDubler::TextDubler(float x, float y)
{ //ставим в  позицию
    pos_text.x = x + 15;
    pos_text.y = y + 25;
    // bkgr
    texture_bkground.loadFromFile("images/TD_bkground.png");
    bkground.setTexture(texture_bkground);
    bkground.setPosition(x, y);
    //загружаем шрифт
    font.loadFromFile("fonts/3976.ttf");
    // vector txt
    vec_txt.resize(vec_size);
    Text ch(L"*", font, font_size);
    ch.setFillColor(correctColor);
    for (size_t i = 0; i < vec_txt.size(); i++) {
        vec_txt[i] = ch;
        vec_txt[i].setPosition(pos_text.x + (i * 30), pos_text.y);
    }
    // CPS
    cps_text = ch; // берем те же настройки что и для букв
    cps_text.setPosition(
            x + bkground.getGlobalBounds().width + 5, pos_text.y + 5);
    cps_text.setString("0.0");
    vec_time.resize(time_size);
    //обнуление
    for (size_t i = 0; i < time_size; i++) {
        vec_time[i] = 0;
    }
}
//функции
void TextDubler::addsymWrong(wchar_t sym)
{
    //создаем экземпляр буквы
    Text tch(sym, font, font_size);
    tch.setFillColor(wrongColor);
    tch.setPosition(vec_txt[vec_size - 1].getPosition()); //поз.последней буквы
    Vector2f pos_element; // буфер для позиции
    for (size_t i = 0; i < vec_size - 1; i++) {
        pos_element = vec_txt[i].getPosition();
        vec_txt[i] = vec_txt[i + 1];
        vec_txt[i].setPosition(pos_element);
    }
    //на последнее место ставим текущий символ
    vec_txt[vec_size - 1] = tch;
}
void TextDubler::addsymCorrect(wchar_t sym)
{
    //создаем экземпляр буквы
    Text tch(sym, font, font_size);
    tch.setFillColor(correctColor);
    tch.setPosition(vec_txt[vec_size - 1].getPosition()); //поз.последней буквы
    Vector2f pos_element; // буфер для позиции
    for (size_t i = 0; i < vec_size - 1; i++) {
        pos_element = vec_txt[i].getPosition();
        vec_txt[i] = vec_txt[i + 1];
        vec_txt[i].setPosition(pos_element);
    }
    //на последнее место ставим текущий символ
    vec_txt[vec_size - 1] = tch;
}

bool TextDubler::isWrong()
{
    if (vec_txt[vec_size - 1].getFillColor() == wrongColor) {
        return true;
    }
    return false;
}

bool TextDubler::isAllWrong()
{
    if (vec_txt[0].getFillColor() == wrongColor) {
        return true;
    }
    return false;
}

int TextDubler::countWrong()
{
    int count = 0, i = vec_size - 1;
    if (isAllWrong())
        return -1;
    while (vec_txt[i].getFillColor() == wrongColor) {
        count++;
        i--;
    }
    return count;
}

void TextDubler::delsym(wchar_t sym, bool hardmode)
{
    //если гейм мод easy то символ будет *
    if (!hardmode)
        sym = L'*';
    //создаем экземпляр буквы
    Text tch(sym, font, font_size);
    tch.setFillColor(correctColor);
    tch.setPosition(vec_txt[0].getPosition()); //поз.первой буквы
    Vector2f pos_element; // буфер для позиции
    for (size_t i = vec_size - 1; i > 0; i--) {
        pos_element = vec_txt[i].getPosition();
        vec_txt[i] = vec_txt[i - 1];
        vec_txt[i].setPosition(pos_element);
    }
    //на первое место ставим символ из screentxt
    vec_txt[0] = tch;
}

//функции CPS
void TextDubler::cps_plus()
{
    //прибавляю клик к последнему элементу
    vec_time[time_size - 1]++;
}
void TextDubler::cps_nextsec()
{
    for (size_t i = 0; i < time_size - 1; i++) {
        vec_time[i] = vec_time[i + 1];
    }
    vec_time[time_size - 1] = 0;
}
void TextDubler::cps_update()
{
    float sum = 0;
    for (size_t i = 0; i < time_size - 1; i++) {
        sum += vec_time[i];
    }
    //обновляем cps max
    if (cps_max < sum)
        cps_max = sum;
    std::ostringstream stream_cps;
    stream_cps << sum;
    cps_text.setString(stream_cps.str());
}
// clear
void TextDubler::clear()
{
    for (size_t i = 0; i < vec_txt.size(); i++) {
        vec_txt[i].setString(L"*");
    }
    for (size_t i = 0; i < time_size - 1; i++) {
        vec_time[i] = 0;
    }
    cps_text.setString("0");
}
// draw
void TextDubler::draw(RenderWindow& window)
{
    // bkgr
    window.draw(bkground);
    //буквы
    for (size_t i = 0; i < vec_txt.size(); i++) {
        window.draw(vec_txt[i]);
    }
    // cps
    cps_update();
    window.draw(cps_text);
}

// setts
size_t TextDubler::setVecSize()
{
    return vec_size;
}
