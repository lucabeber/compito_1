#ifndef SVG_H
#define SVG_H

#include <string>

/** Funzione che riceve in ingresso una stringa contente gli oggetti gia' trasformai in SVG
 * 
 *  riceve in ingresso la stringa componenti
 */
std::string svg(std::string componenti);

/** Funzione che trascrive la stringa contenente il SVG in un file
 * 
 *  riceve in ingresso il nome del file su cui trascivere il SVG e la tringa da trascrivere
 */
void svg_to_file(std::string filename, std::string str_svg);

/** Funzione che trascrive il contenuto di un file svg in una stringa
 * 
 *  riceve in ingresso il nome del file da trascrivere
 */
std::string read_svg(std::string filename);

#endif //SVG_H