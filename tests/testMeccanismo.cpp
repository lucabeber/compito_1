#include "catch2/catch2.hpp"
#include "meccanismo_scara.h"
#include "pistone.h"
#include "fc_scara.h"
#include "svg.h"


#include <cstring>

TEST_CASE("test sulla correttezza dei valori in uscita dal meccanismo", "[meccanismo]") {
    
    Meccanismo* ret = meccanismo_init(50,150,60,0,50,200,1);

    REQUIRE( ret->pistone->base == 60);
    REQUIRE( ret->pistone->pos.x == 19);
    REQUIRE( ret->pistone->pos.y == 414);

    REQUIRE( ret->scara->length == 50);
    REQUIRE( ret->scara->origin.x == 50);
    REQUIRE( ret->scara->origin.y == 200);
    REQUIRE( ret->scara->q1 == 90);


    meccanismo_del(ret);    
}

TEST_CASE("test altezza manovella e biella negativa, base pistone negativa", "[meccanismo]") {
    
    Meccanismo* ret2 = meccanismo_init(-50,-150,-60,0,50,200,1);
    
    REQUIRE( ret2->pistone == NULL);

    meccanismo_del(ret2);    
}

TEST_CASE("letteura da file", "[meccanismo]") {
    
    std::string s = svg_read("meccanismo_test.txt");
    std::cout<<s;
    Meccanismo* ret3 = meccanismo_new(s.c_str());

    REQUIRE( ret3->pistone->base == 60);
    REQUIRE( ret3->pistone->pos.x == 120);
    REQUIRE( ret3->pistone->pos.y == 415);

    REQUIRE( ret3->scara->length == 50);
    REQUIRE( ret3->scara->origin.x == 150);
    REQUIRE( ret3->scara->origin.y == 200);
    REQUIRE( ret3->scara->q1 == 90);

    meccanismo_del(ret3);    
}