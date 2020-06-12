#pragma once

#include "../src/file.cpp"

#include <fstream>
#include <string>

TEST_CASE("File::add")
{
    PersonStats person[3], person_loaded[3]; // объекты класса для вгрузки и
                                             // выгрузки информации из файла
    std::ifstream file_data;
    std::string path = "scoreboard_test.dat";
    File file;
    int i = 0;

    file.add(
            strcpy(person[0].user_name, "Carti"),
            strcpy(person[0].text_name, "Magnolia"),
            person[0].time = 2.547f,
            person[0].cps = 3.48f,
            path);
    CHECK((std::string)person[0].user_name == "Carti");
    CHECK((std::string)person[0].text_name == "Magnolia");
    CHECK(person[0].time == 2.547f);
    CHECK(person[0].cps == 3.48f);

    file_data.open(path, std::ios::binary);

    while (file_data.read((char*)&person_loaded[i], sizeof(PersonStats))) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time == person[i].time);
        CHECK(person_loaded[i].cps == person[i].cps);
        i++;
    }
    i = 0;
    file_data.close();

    file.add(
            strcpy(person[1].user_name, "La"),
            strcpy(person[1].text_name, "Flame"),
            person[1].time = 387.4f,
            person[1].cps = 25.1f,
            path);
    CHECK((std::string)person[1].user_name == "La");
    CHECK((std::string)person[1].text_name == "Flame");
    CHECK(person[1].time == 387.4f);
    CHECK(person[1].cps == 25.1f);

    file_data.open(path, std::ios::binary);

    while (file_data.read((char*)&person_loaded[i], sizeof(PersonStats))) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time == person[i].time);
        CHECK(person_loaded[i].cps == person[i].cps);
        i++;
    }
    i = 0;
    file_data.close();

    file.add(
            strcpy(person[2].user_name, "Kanye"),
            strcpy(person[2].text_name, "hey mama"),
            person[2].time = 387.4f,
            person[2].cps = 25.2f,
            path);
    CHECK((std::string)person[2].user_name == "Kanye");
    CHECK((std::string)person[2].text_name == "hey mama");
    CHECK(person[2].time == 387.4f);
    CHECK(person[2].cps == 25.2f);

    file_data.open(path, std::ios::binary);

    while (file_data.read((char*)&person_loaded[i], sizeof(PersonStats))) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time == person[i].time);
        CHECK(person_loaded[i].cps == person[i].cps);
        i++;
    }
    i = 0;
    file_data.close();

    remove("scoreboard_test.dat");
}