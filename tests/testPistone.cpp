#include "catch2/catch2.hpp"
#include "pistone.h"

#include <cstring>

TEST_CASE("test sui valori e sulla base negativa", "[pistone]") {
    
    Pistone* ret = pist_init(300,30,30);

    REQUIRE( ret->base == 300);
    REQUIRE( ret->pos.x == 30);
    REQUIRE( ret->pos.y == 30);

    REQUIRE_THROWS_AS( pist_init(-300,30,30), std::invalid_argument);
    REQUIRE_THROWS_AS( pist_init(30,1000,30), std::invalid_argument);
    REQUIRE_THROWS_AS( pist_init(30,30,1000), std::invalid_argument);
    pist_del(ret);    
}

TEST_CASE("lettura da file", "[pistone]") {
    
    std::string s = "<polygon points=\"119,383 179,383 179,353 170,353 170,362 128,362 128,353 119,353\" />";
    Pistone* ret2 = pist_new(s);
    
    REQUIRE( ret2->base == 60);
    REQUIRE( ret2->pos.x == 119);
    REQUIRE( ret2->pos.y == 383);

    pist_del(ret2);    
}
