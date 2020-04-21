#pragma once
#include <SFML/Graphics.hpp>

class Word
{
private:
    int len = 0;
    std::string word = "";

public:
    int get_len() { return len; }
    std::string get_word() { return word; }
    int set_len() { len = word.length(); }
    void clean()
    {
        word = "";
        len = 0;
    }

    void add(char letter)
    {
        word += letter;
        set_len();
    }

/*     int wordlen(int i, std::string text)
    {
        i++;
        int countlen = 1;
        while (text[i] != ' ' || text[i] != '.')
        {
            i++;
            countlen++;
        }
        return countlen;
    } */
};

void add(std::vector<std::vector<char>> &text, Word word, int j) //не тестированно
{
    for (int k = 0; k < word.get_len(); k++)
    {
        text[j].push_back(word.get_word()[k]);
    }
    text[j].push_back(' ');
}

std::vector<std::vector<char>> get_text()
{
    int width = (1500 / 8) - 70;
    std::string str = "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him. The hallway smelt of boiled cabbage and old rag mats. At one end of it a coloured poster, too large for indoor display, had been tacked to the wall. It depicted simply an enormous face, more than a metre wide: the face of a man of about forty-five, with a heavy black moustache and ruggedly handsome features. Winston made for the stairs. It was no use trying the lift. Even at the best of times it was seldom working, and at present the electric current was cut off during daylight hours. It was part of the economy drive in preparation for Hate Week. The flat was seven flights up, and Winston, who was thirty-nine and had a varicose ulcer above his right ankle, went slowly, resting several times on the way. On each landing, opposite the lift-shaft, the poster with the enormous face gazed from the wall. It was one of those pictures which are so contrived that the eyes follow you about when you move. BIG BROTHER IS WATCHING YOU, the caption beneath it ran.";
    std::vector<std::vector<char>> text;
    Word word;

    text.resize(1);

    int j = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            word.add(str[i]);
        }
        else
        {
            if (word.get_len() + text[j].size() < width)
            {
                add(text, word, j);
                word.clean();
            }
            else
            {
                j++;
                text.resize(j + 1);
                add(text, word, j);

                word.clean();
            }
        }
    }

    text[j][text[j].size() - 1] = '.';//добавляет точку в самом последнем предложении текста

    return text;
}