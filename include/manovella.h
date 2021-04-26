#ifndef manovella_H
#define manovella_H

#include <string>

/*
 * Libreria C per costruire figure in SVG
*/

/** Struttura che rappresenta le coordinate da cui viene costruito la manovella 
 * 
 * 
**/
struct PosizioneM{
    unsigned int x;
    unsigned int y;
    int rotazione;
};

/** Struttura che rappresenta le dimensioni della manovella
 * 
 *  
**/
struct Manovella {
    unsigned int base;                 // lunghezza di base della manovella
    unsigned int altezza;              // altezza della manovella
    PosizioneM pos;                     // posizione della manovella nell'immagine
};

/** Funzione che inizializza la manovella 
 * 
 *  @param base lunghezza di base del pistone 
 * 
 *  @param x coordinata x del pistone
 * 
 *  @param y coordinata y del pistone
 * 
 *  @param rot rotazione della manovella
 * 
 *  @return struttura contenente i dati del pistone
 */
Manovella* manovella_init(unsigned int altezza, unsigned int x, unsigned int y, int rot);

/** Funzione che crea una stringa svg contenente l'immagine della manovella 
 * 
 *  @param manovella struttura contenente i dati del pistone
 * 
 *  @return stringa che contiene i dati in svg del pistone
 */
std::string manovella_svg(Manovella* manovella, bool misure);

/** Funzione che legge una stringa svg contenente l'immagine del pisone 
 *  e ne costruisce un nuova struct Pistone
 *  
 *  @param file stringa contenente il testo letto da un file svg
 * 
 *  @return struttura pistone contenente i dati trovati all'interno del file
 */
Manovella*  manovella_new(std::string file);

/** 
 *  Funzione che libera lo spazio di memoria occupato dalla struttura pistone
 *  
 *  @param manovella spazio di memoria da liberare
 */
void  manovella_del(Manovella* manovella);

#endif //PISTONE_H