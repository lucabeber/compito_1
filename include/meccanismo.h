#ifndef meccanismo_H
#define meccanismo_H

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
 *  @return file svg contenente l'immagine del meccanismo
 * 
 **/
void meccanismo(double hman, double hbiel, double bpist, double angolo, double x, double y);

#endif