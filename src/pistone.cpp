
#include "pistone.h"
#include <iostream>
#include <cstring>

using namespace std;

Pistone* pist_init(int base){

    // si ritorna il valore null se il valore della base e` minore di 0
    if (base <= 0){
        return NULL;
    }

    // si crea un nuovo puntatore a struttura
    Pistone* ret = new Pistone;

    // si assegnano i valori nella nuova struttura creata
    ret->base       =   base;
    ret->altezza    =   base/2;
    ret->deltaS     =   base*0.15;
    ret->deltaH     =   ret->altezza*0.3;

    return ret;     
}

Posizione* posiz_pist(unsigned int x, unsigned int y){
    
    // si crea un nuovo puntatore a struttura
    Posizione* ret = new Posizione;

    // si assegnano i valori nella nuova struttura creata
    ret->x  =   x;
    ret->y  =   y;

    return ret;
}

string svg_pist(Pistone* pistone, Posizione* posizione){

    // creo un nuovo puntatore a stringa
    string ret, virgola = ",", spazio = " ";

    // scrivo nella stringa il file svg del pistone
    ret =   "<polygon points=\"";
    
    // partendo dal punto iniziale si inseriscono i punti per 
    // costruire il pistone. 

    // coordinate del punto 1
    ret = ret + to_string(posizione->x) + virgola + to_string(posizione->y) + spazio;
    
    // coordinate del punto 2
    ret = ret + to_string(posizione->x + pistone->base) + virgola + to_string(posizione->y) + spazio;

    // coordinate del punto 3
    ret = ret + to_string(posizione->x + pistone->base) + virgola + to_string(posizione->y - pistone->altezza) + spazio;

    // coordinate del punto 4
    ret = ret + to_string(posizione->x + pistone->base - pistone->deltaS) + virgola + to_string(posizione->y - pistone->altezza) + spazio;

    // coordinate del punto 5
    ret = ret + to_string(posizione->x + pistone->base - pistone->deltaS) + virgola + to_string(posizione->y - pistone->altezza + pistone->deltaH) + spazio;

    // coordinate del punto 6
    ret = ret + to_string(posizione->x + pistone->deltaS) + virgola + to_string(posizione->y - pistone->altezza + pistone->deltaH) + spazio;

    // coordinate del punto 7
    ret = ret + to_string(posizione->x + pistone->deltaS) + virgola + to_string(posizione->y - pistone->altezza) + spazio;

    // coordinate del punto 8
    ret = ret + to_string(posizione->x) + virgola + to_string(posizione->y - pistone->altezza)+ "\"" + spazio;

    // chiusura della funzione poligono e stile
    ret +=  "style=\"fill:gray,stroke:black,stroke-width:1\" />";

    return ret;
}