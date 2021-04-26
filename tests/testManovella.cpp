#include "catch2/catch2.hpp"
#include "manovella.h"

#include <cstring>

TEST_CASE("test sui valori e sull'altezza negativa manovella", "[manovella]") {
    
    Manovella* ret = manovella_init(300,30,30,60);

    REQUIRE( ret->altezza == 300);
    REQUIRE( ret->pos.x == 30);
    REQUIRE( ret->pos.y == 30);
    REQUIRE( ret->pos.rotazione == 60);

    REQUIRE_THROWS_AS( manovella_init(500,30,30,60), std::invalid_argument);
    REQUIRE_THROWS_AS( manovella_init(300,-30,30,60), std::invalid_argument);
    REQUIRE_THROWS_AS( manovella_init(300,30,-30,60), std::invalid_argument);
    manovella_del(ret);    
}

TEST_CASE("lettura da file manovella", "[manovella]") {
    
    std::string s = "<!--manovella --><g transform=\"rotate(9 74,243)\" ><rect  x=\"74\" y=\"243\" width=\"15\" height=\"150\" style=\"fill:green;stroke:black;stroke-width:1\" /></g>";
    Manovella* ret2 = manovella_new(s);
    
    REQUIRE( ret2->altezza == 150);
    REQUIRE( ret2->pos.x == 74);
    REQUIRE( ret2->pos.y == 243);
    REQUIRE( ret2->pos.rotazione == 9);

    manovella_del(ret2);    
}