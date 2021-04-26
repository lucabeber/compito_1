#ifndef BIELLA_H
#define BIELLA_H

#include <string>

/*
 * Libreria C per costruire figure in SVG
*/

/** Struttura che rappresenta le coordinate da cui viene costruito la biella 
 * 
 * 
**/
struct PosizioneB{
    unsigned int x;
    unsigned int y;
    int rotazione;
};

/** Struttura che rappresenta le dimensioni della biella
 * 
 *  
**/
struct Biella {
    unsigned int base;                 // lunghezza di base della biella
    unsigned int altezza;              // altezza della biella
    PosizioneB pos;                     // posizione della biella nell'immagine
};

/** Funzione che inizializza la biella 
 * 
 *  @param altezza altezza della biella
 * 
 *  @param x coordinata x del pistone
 * 
 *  @param y coordinata y del pistone
 * 
 *  @param rot rotazione della biella
 * 
 *  @return struttura contenente i dati del pistone
 */
Biella* biella_init(unsigned int altezza, unsigned int x, unsigned int y, int rot);

/** Funzione che crea una stringa svg contenente l'immagine della biella 
 * 
 *  @param biella struttura contenente i dati del pistone
 * 
 *  @return stringa che contiene i dati in svg del pistone
 */
std::string biella_svg(Biella* biella, bool misure);

/** Funzione che legge una stringa svg contenente l'immagine del pisone 
 *  e ne costruisce un nuova struct Pistone
 *  
 *  @param file stringa contenente il testo letto da un file svg
 * 
 *  @return struttura pistone contenente i dati trovati all'interno del file
 */
Biella*  biella_new(std::string file);

/** 
 *  Funzione che libera lo spazio di memoria occupato dalla struttura pistone
 *  
 *  @param biella spazio di memoria da liberare
 */
void  biella_del(Biella* biella);

#endif //PISTONE_H