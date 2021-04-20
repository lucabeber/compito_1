#ifndef PISTONE_H
#define PISTONE_H

#include <string>

/*
 * Libreria C per costruire figure in SVG
 */

/** Struttura che rappresenta le dimensioni del pistone 
 * 
 *  
**/
struct Pistone {
    double base;                // lunghezza di base del pistone
    double altezza;             // altezza del pistone
    double deltaS;              // larghezza della scanalatura del pistone
    double deltaH;              // altezza della scanalatura del pistone
};

/** Struttura che rappresenta le coordinate da cui viene costruitoil pistone 
 * 
 * 
**/
struct Posizione{
    unsigned int x;
    unsigned int y;
};

/** Funzione che inizializza il pistone richiedendo le lunghezze di base e di altezza
 * 
 *  - se la base inserita e` minore di 0, ritorna NULL  (C-style error signalling)
 */
Pistone* pist_init(int base);

/** Funzione che inizializza il pistone richiedendo le lunghezze di base e di altezza
 * 
 *  - se la base inserita e` minore di 0, ritorna NULL  (C-style error signalling)
 */
Posizione* posiz_pist(unsigned int x, unsigned int y);

/** Funzione che crea una stringa svg contenente l'immagine del pisone 
 * 
 *  
 */
std::string svg_pist(Pistone* pistone, Posizione* posizione);

/** Funzione che legge una stringa svg contenente l'immagine del pisone 
 *  e ne costruisce un nuova struct Pistone
 *  - se non viene trovato alcun pistone la funzione ritorna una struttura vuota
 */
Pistone*  nuovo_pist(std::string file);

#endif //PISTONE_H