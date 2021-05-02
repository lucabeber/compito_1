#ifndef meccanismo_H
#define meccanismo_H

#include "pistone.h"
#include "fc_scara.h"
#include "svg.h"



struct Meccanismo{
    Pistone* pistone;
    fc_scara* scara;
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

/** Funzione che legge una stringa svg contenente l'immagine del meccanismo 
 *  e ne costruisce un nuova struct 
 *  
 *  @param s stringa contenente il testo letto da un file svg
 * 
 *  @return struttura pistone contenente i dati trovati all'interno del file
 */
Meccanismo*  meccanismo_new(std::string file);


/** 
 *  Funzione che libera lo spazio di memoria occupato dall' intero meccanismo
 *  
 *  @param meccanismo spazio di memoria da liberare
 */
void  meccanismo_del(Meccanismo* meccanismo);
#endif