#pragma once

class PersonStats {
private:
public:
    char user_name[9];  //имя пользователя
    char text_name[50]; //название текста
    float time;
    float cps; // clicks per second

    void set_name(std::string name)
    {
        strcpy(user_name, name.c_str());
    };
};