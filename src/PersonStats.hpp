#pragma once

class PersonStats {
private:
public:
    char user_name[9];  //имя пользователя
    char text_name[50]; //название текста
    int time_ms;
    int time_sec;
    int time_min;
    int max_cps; // clicks per second

    void set_name(std::string name)
    {
        strcpy(user_name, name.c_str());
    };
};