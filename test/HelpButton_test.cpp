#include "../src/HelpButton.hpp"
#include "testparty/catch.hpp"
#include <iostream>

HelpButton help;

TEST_CASE("HelpButton")
{
    SECTION("MoveRight")
    {
        help.page_switch = 0;
        int page_switch_test = 0;
        for (int i = 0; i < 5; i++) {
            page_switch_test++;
            help.MoveRight();
            CHECK(page_switch_test == help.page_switch);
           
        }
    }

    SECTION("MoveRight")
    {
        help.page_switch = 0;
        int page_switch_test = 5;
        for (int i = 5; i > 0; i--) {
            page_switch_test--;
            help.MoveLeft();
            CHECK(page_switch_test == help.page_switch);
        }
    }
}


