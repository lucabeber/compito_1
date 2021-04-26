#ifndef meccanismo_H
#define meccanismo_H

#include "pistone.h"
#include "biella.h"
#include "svg.h"
#include "manovella.h"


struct Meccanismo{
    Pistone* pistone;
    Manovella* manovella;
    Biella* biella;
};


/** Funzione che crea il meccanismo
 * 
 *  @param hman lunghezza della manovella
 * 
 *  @param hbiel lunghezza della biella
 * 
 *  @param bpist base del pistone
 * 
 *  @param angolo angolo della manovella
 * 
 *  @param x posizione su cui gira la manovella
 * 
 *  @param y posizione su cui gira la manovella
 * 
 *  @param h distanza del pistone da x,y
 * 
 *  @return file svg contenente l'immagine del meccanismo
 * 
 **/
Meccanismo* meccanismo_init(double hman, double hbiel, double bpist, double angolo, double x, double y, double h);


/**
 *  Funzione che trasforma le strutture in stringe svg
 * 
 *  @param meccanismo meccanismo di cui si vuole ottenere il codice svg
 * 
 *  @param misure parametro che indica la presenza o meno di misure all'inerno del disegno
 * 
 *  @return stringa contenete svg
 **/
std::string meccanismo_svg(Meccanismo* meccanismo, bool misure);


/** 
 *  Funzione che libera lo spazio di memoria occupato dall' intero meccanismo
 *  
 *  @param meccanismo spazio di memoria da liberare
 */
void  meccanismo_del(Meccanismo* meccanismo);
#endif