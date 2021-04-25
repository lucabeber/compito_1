
#include "manovella.h"
#include <iostream>
#include <cstring>

Manovella* manovella_init(unsigned int altezza, unsigned int x, unsigned int y, int rot){

    // controllo sui valori da inserire nella struttura della manovella
    if (altezza <= 0){
        throw std::invalid_argument("La base non puo' avere un valore negativo!");
    } else if (altezza>400) {
        throw std::invalid_argument("Il pistone che stai cercando di cotruire e` troppo grande"); 
    } else if (x<0 || y<0 || x>800 || y>600) {
        throw std::invalid_argument("Le coordinate non sono compatibili con l'immagine");
    } else {

    // si crea un nuovo puntatore a struttura
    Manovella* ret = new Manovella;

    // si assegnano i valori nella nuova struttura creata
    ret->base           =   altezza/8;
    ret->altezza        =   altezza;
    ret->pos.x          =   x;
    ret->pos.y          =   y;
    ret->pos.rotazione  =   rot;
    return ret;

    }     
}

std::string manovella_svg(Manovella* manovella, bool misure){

    // creo un nuovo puntatore a stringa
    std::string ret, apice = "\"", spazio = " ";

    // creo un commento che indica il pezzo che si sta andando a disegnare
    ret = "<!--\n \tManovella \n-->\n";

    // rotazione e spostamento della manovella 
    ret += "<g transform=\"rotate(" + std::to_string(manovella->pos.rotazione) + " " + std::to_string(manovella->pos.x) + "," + std::to_string(manovella->pos.y) + ")\" >\n";
    
    // scrivo nella stringa il file svg della manovella
    ret +=   "<rect  x=\"";
    
    // partendo dal punto iniziale si inseriscono i punti per 
    // costruire il pistone. 

    // coordinate di x
    ret += std::to_string(manovella->pos.x) + apice + spazio;
    
    // coordinate di y
    ret += "y=\"" + std::to_string(manovella->pos.y) + apice + spazio;

    // base rettangolo
    ret += "width=\"" + std::to_string(manovella->base) + apice + spazio;

    // altezza rettangolo
    ret += "height=\"" + std::to_string(manovella->altezza) + apice + spazio;

    // chiusura della funzione poligono e stile
    ret +=  "style=\"fill:green;stroke:black;stroke-width:1\" />";

    if (misure == true){
        // si inserisce il valore della misura
        ret += "<text x = \"" + std::to_string(manovella->pos.x+manovella->base+20) + "\" y = \"" + std::to_string(manovella->pos.y + manovella->altezza/2) + "\"  fill=\"black\" transform=\"rotate(-90 " + std::to_string(manovella->pos.x+manovella->base+20) + "," + std::to_string(manovella->pos.y+manovella->altezza/2) + ")\">";
        ret += std::to_string(manovella->altezza)  + "</text>\n";

        // si inserisce la linea di riferimento della misura
        ret += "<line x1=\"" +  std::to_string(manovella->pos.x+manovella->base+25) + "\" y1=\"" + std::to_string(manovella->pos.y) + "\" x2=\"" + std::to_string(manovella->pos.x+manovella->base+25) + "\" y2= \"" + std::to_string(manovella->pos.y + manovella->altezza);
        ret += "\" style=\"stroke:black;stroke-width:2\" />\n";
    }

    ret += "</g>\n";

    return ret;
}
using namespace std;

Manovella*  manovella_new(std::string str){

    // si trova all'interno della stringa acquisita la parola p
    std::string p = "Manovella";     
    size_t found = str.find(p)+p.size();
    
    //creazione variabili di sostegno
    int a,b,c,d;

    // acquisizione della rotazione 
    p = "rotate(";
    found = str.find(p,found)+p.size();
    size_t found2 = str.find(" ",found);
    // creo una nuova stringa contenente il valore della rotazione
    std::string new_str;
    new_str = str.substr(found, found2);
    
    /* attraverso il comando atoi trasformo la string contenente 
    *  il valore di rot in un intero
    */
    d = atoi(new_str.c_str());
    std::cout<<d<<endl;
    // acquisizione del valore x
    p = "rect  x=\"";
    found = str.find(p,found)+p.size();
    found2 = str.find("\"",found);
    new_str = str.substr(found, found2);
    
    /* attraverso il comando atoi trasformo la string contenente 
    *  il valore di x in un intero
    */
    a = atoi(new_str.c_str());
    std::cout<<a<<endl;
    // creo una nuova stringa contenente il valore di y
    p = "y=\"";
    found = str.find(p,found)+p.size();
    found2 = str.find("\"",found);
    new_str = str.substr(found, found2);
    
    /* attraverso il comando atoi trasformo la string contenente 
    *  il valore di y in un intero
    */
    b = atoi(new_str.c_str());
    std::cout<<b<<endl;
    // creo una nuova manovellaga contenente il valore dell'altezza
    p = "height=\"";
    found = str.find(p,found)+p.size();
    found2 = str.find("\"",found);
    new_str = str.substr(found, found2);
    
    /* attraverso il comando atoi trasformo la string contenente 
    *  il secondo valore dell'altezza in un intero
    */
    c = atoi(new_str.c_str());
    std::cout<<c<<endl;
    return manovella_init(c,a,b,d);
}

void  manovella_del(Manovella* manovella){
    delete manovella;
}