#include "catch2/catch2.hpp"
#include "meccanismo.h"
#include "pistone.h"
#include "biella.h"
#include "svg.h"
#include "manovella.h"

#include <cstring>

TEST_CASE("test sulla correttezza dei valori in uscita dal meccanismo", "[meccanismo]") {
    
    Meccanismo* ret = meccanismo_init(50,150,60,0,50,200,1);

    REQUIRE( ret->pistone->base == 60);
    REQUIRE( ret->pistone->pos.x == 19);
    REQUIRE( ret->pistone->pos.y == 414);

    REQUIRE( ret->biella->altezza == 150);
    REQUIRE( ret->biella->pos.x == 50);
    REQUIRE( ret->biella->pos.y == 250);
    REQUIRE( ret->biella->pos.rotazione == 0);

    REQUIRE( ret->manovella->altezza == 50);
    REQUIRE( ret->manovella->pos.x == 50);
    REQUIRE( ret->manovella->pos.y == 200);
    REQUIRE( ret->manovella->pos.rotazione == 0);

    meccanismo_del(ret);    
}

TEST_CASE("test altezza manovella e biella negativa, base pistone negativa", "[meccanismo]") {
    
    Meccanismo* ret2 = meccanismo_init(-50,-150,-60,0,50,200,1);
    
    REQUIRE( ret2->pistone == NULL);
    REQUIRE( ret2->manovella == NULL);
    REQUIRE( ret2->biella == NULL);

    meccanismo_del(ret2);    
}

TEST_CASE("letteura da file", "[meccanismo]") {
    
    std::string s = "<!-- Manovella --> <g transform=\"rotate(0 50,200)\" > <rect  x=\"50\" y=\"200\" width=\"6\" height=\"50\" style=\"fill:green;stroke:black;stroke-width:1\" /></g>";
    s += "<!-- 	Pistone --> <polygon points=\"19,414 79,414 79,384 70,384 70,393 28,393 28,384 19,384\" style=\"fill:gray;stroke:black;stroke-width:1\" />";
    s += "<!-- 	Biella --><g transform=\"rotate(0 50,250)\" ><rect  x=\"50\" y=\"250\" width=\"15\" height=\"150\" style=\"fill:green;stroke:black;stroke-width:1\" /></g>";
    
    Meccanismo* ret3 =meccanismo_new(s);

    REQUIRE( ret3->pistone->base == 60);
    REQUIRE( ret3->pistone->pos.x == 19);
    REQUIRE( ret3->pistone->pos.y == 414);

    REQUIRE( ret3->biella->altezza == 150);
    REQUIRE( ret3->biella->pos.x == 50);
    REQUIRE( ret3->biella->pos.y == 250);
    REQUIRE( ret3->biella->pos.rotazione == 0);

    REQUIRE( ret3->manovella->altezza == 50);
    REQUIRE( ret3->manovella->pos.x == 50);
    REQUIRE( ret3->manovella->pos.y == 200);
    REQUIRE( ret3->manovella->pos.rotazione == 0);

    meccanismo_del(ret3);    
}