#include "../src/ScoreBoardFile.hpp"
#include "testparty/catch.hpp"

#include <cstring>
#include <fstream>
#include <vector>

TEST_CASE("ScoreBoardFile::add")
{
    // объекты класса для вгрузки и выгрузки информации из файла
    PersonStats person[3], person_loaded[3];
    std::ifstream file_data;
    std::string path = "scoreboard_test.dat";
    ScoreBoardFile file;
    int i = 0;

    file.add(
            strcpy(person[0].user_name, "Carti"),
            strcpy(person[0].text_name, "Magnolia"),
            person[0].time_ms = 312,
            person[0].time_sec = 4547,
            person[0].time_min = 2547,
            person[0].max_cps = 48,
            path);
    CHECK((std::string)person[0].user_name == "Carti");
    CHECK((std::string)person[0].text_name == "Magnolia");
    CHECK(person[0].time_min == 2547);
    CHECK(person[0].time_sec == 4547);
    CHECK(person[0].time_ms == 312);
    CHECK(person[0].max_cps == 48);

    file_data.open(path, std::ios::binary);

    while (file_data.read((char*)&person_loaded[i], sizeof(PersonStats))) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time_min == person[i].time_min);
        CHECK(person_loaded[i].time_sec == person[i].time_sec);
        CHECK(person_loaded[i].time_ms == person[i].time_ms);
        CHECK(person_loaded[i].max_cps == person[i].max_cps);
        i++;
    }
    i = 0;
    file_data.close();

    file.add(
            strcpy(person[1].user_name, "La"),
            strcpy(person[1].text_name, "Flame"),
            person[1].time_ms = 42,
            person[1].time_sec = 12,
            person[1].time_min = 412,
            person[1].max_cps = 44,
            path);
    CHECK((std::string)person[1].user_name == "La");
    CHECK((std::string)person[1].text_name == "Flame");
    CHECK(person[1].time_min == 412);
    CHECK(person[1].time_sec == 12);
    CHECK(person[1].time_ms == 42);
    CHECK(person[1].max_cps == 44);

    file_data.open(path, std::ios::binary);

    while (file_data.read((char*)&person_loaded[i], sizeof(PersonStats))) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time_min == person[i].time_min);
        CHECK(person_loaded[i].time_sec == person[i].time_sec);
        CHECK(person_loaded[i].time_ms == person[i].time_ms);
        CHECK(person_loaded[i].max_cps == person[i].max_cps);
        i++;
    }
    i = 0;
    file_data.close();

    file.add(
            strcpy(person[2].user_name, "Kanye"),
            strcpy(person[2].text_name, "hey mama"),
            person[2].time_ms = 364,
            person[2].time_sec = 24,
            person[2].time_min = 45,
            person[2].max_cps = 23,
            path);
    CHECK((std::string)person[2].user_name == "Kanye");
    CHECK((std::string)person[2].text_name == "hey mama");
    CHECK(person[2].time_min == 45);
    CHECK(person[2].time_sec == 24);
    CHECK(person[2].time_ms == 364);
    CHECK(person[2].max_cps == 23);

    file_data.open(path, std::ios::binary);

    while (file_data.read((char*)&person_loaded[i], sizeof(PersonStats))) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time_min == person[i].time_min);
        CHECK(person_loaded[i].time_sec == person[i].time_sec);
        CHECK(person_loaded[i].time_ms == person[i].time_ms);
        CHECK(person_loaded[i].max_cps == person[i].max_cps);
        i++;
    }
    i = 0;
    file_data.close();

    remove("scoreboard_test.dat");
}

TEST_CASE("ScoreBoardFile::load")
{
    PersonStats person[3];
    std::vector<PersonStats> person_loaded; // объекты класса для вгрузки и
                                            // выгрузки информации из файла
    std::ofstream file_data;
    std::string path = "scoreboard_test.dat";
    ScoreBoardFile file;

    strcpy(person[0].user_name, "Carti");
    strcpy(person[0].text_name, "Magnolia");
    person[0].time_min = 2547;
    person[0].time_sec = 4547;
    person[0].time_ms = 312;
    person[0].max_cps = 48;
    CHECK((std::string)person[0].user_name == "Carti");
    CHECK((std::string)person[0].text_name == "Magnolia");
    CHECK(person[0].time_min == 2547);
    CHECK(person[0].time_sec == 4547);
    CHECK(person[0].time_ms == 312);
    CHECK(person[0].max_cps == 48);

    strcpy(person[1].user_name, "La");
    strcpy(person[1].text_name, "Flame");
    person[1].time_min = 412;
    person[1].time_sec = 12;
    person[1].time_ms = 42;
    person[1].max_cps = 44;
    CHECK((std::string)person[1].user_name == "La");
    CHECK((std::string)person[1].text_name == "Flame");
    CHECK(person[1].time_min == 412);
    CHECK(person[1].time_sec == 12);
    CHECK(person[1].time_ms == 42);
    CHECK(person[1].max_cps == 44);

    strcpy(person[2].user_name, "Kanye");
    strcpy(person[2].text_name, "hey mama");
    person[2].time_min = 45;
    person[2].time_sec = 24;
    person[2].time_ms = 364;
    person[2].max_cps = 23;
    CHECK((std::string)person[2].user_name == "Kanye");
    CHECK((std::string)person[2].text_name == "hey mama");
    CHECK(person[2].time_min == 45);
    CHECK(person[2].time_sec == 24);
    CHECK(person[2].time_ms == 364);
    CHECK(person[2].max_cps == 23);

    file_data.open(path, std::ios::binary);

    for (int i = 0; i < 3; i++) {
        file_data.write((char*)&person[i], sizeof(PersonStats));
    };

    file_data.close();

    person_loaded = file.load_of_file(path);
    remove("scoreboard_test.dat");

    for (int i = 0; i < 3; i++) {
        CHECK((std::string)person_loaded[i].user_name == person[i].user_name);
        CHECK((std::string)person_loaded[i].text_name == person[i].text_name);
        CHECK(person_loaded[i].time_min == person[i].time_min);
        CHECK(person_loaded[i].time_sec == person[i].time_sec);
        CHECK(person_loaded[i].time_ms == person[i].time_ms);
        CHECK(person_loaded[i].max_cps == person[i].max_cps);
    }
}