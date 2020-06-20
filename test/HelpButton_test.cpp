#include "../src/HelpButton.hpp"
#include "testparty/catch.hpp"

TEST_CASE("HelpButton")
{
    HelpButton help;
    int page_switch_test = 0;
    help.page_switch = 0;
    // направо
    page_switch_test++;
    help.MoveRight();
    CHECK(page_switch_test == help.page_switch);
    //налево
    help.page_switch = 5;
    page_switch_test = 5;
    page_switch_test--;
    help.MoveLeft();
    CHECK(page_switch_test == help.page_switch);
}
