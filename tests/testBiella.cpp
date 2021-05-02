#include "catch2/catch2.hpp"
#include "biella.h"

#include <cstring>

TEST_CASE("test sui valori e sull'altezza negativa", "[biella]") {
    
    Biella* ret = biella_init(300,30,30,60);

    REQUIRE( ret->altezza == 300);
    REQUIRE( ret->pos.x == 30);
    REQUIRE( ret->pos.y == 30);
    REQUIRE( ret->pos.rotazione == 60);

    REQUIRE_THROWS_AS( biella_init(-500,30,30,60), std::invalid_argument);
    REQUIRE_THROWS_AS( biella_init(300,-30,30,60), std::invalid_argument);
    REQUIRE_THROWS_AS( biella_init(300,30,-30,60), std::invalid_argument);
    biella_del(ret);    
}

TEST_CASE("lettura da file biella", "[biella]") {
    
    std::string s = "<!--Biella --><g transform=\"rotate(9 74,243)\" ><rect  x=\"74\" y=\"243\" width=\"15\" height=\"150\" style=\"fill:green;stroke:black;stroke-width:1\" /></g>";
    Biella* ret2 = biella_new(s);
    
    REQUIRE( ret2->altezza == 150);
    REQUIRE( ret2->pos.x == 74);
    REQUIRE( ret2->pos.y == 243);
    REQUIRE( ret2->pos.rotazione == 9);

    biella_del(ret2);    
}