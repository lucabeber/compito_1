#include <iostream>
#include <math.h>

#include "pistone.h"
#include "biella.h"
#include "svg.h"
#include "manovella.h"

using namespace std;

int main() {
    /*
    Biella* biella;

    biella = biella_init(100,200,200,50);

    string s=svg_biella(biella);

    s=svg(s);

    svg_to_file("pistone.svg",s);
    */
    /*
    unsigned int a,b,c;
    cout << "Inizializzazione pistone\n Inserire l'area di base del pistone:";
    cin >> a;
    cout << "Inserire le coordinate x:";
    cin >> b,c;
    cout << "Inserire le coordinate y:";
    cin >> c;

    Pistone* pistone;

    try {
        cout << "Creazione della struttura pistone."<< endl;
        pistone = pist_init(a,b,c);
    } catch (exception& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };
    

    cout << "Pistone inizializzato\n";

    cout << "Creazione stringa\n";

    string s=svg_pist(pistone);

    cout << "Eliminazione struttura pistone";

    cout << s << endl;

    s=svg(s);

    cout << s << endl;

    svg_to_file("pistone.svg",s);

    nuovo_pist(s);
    Pistone* pistone2;
    try {
        cout << "Creazione della struttura pistone."<< endl;
        pistone2 = pist_init(a,b,c);
    } catch (exception& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };
    

    cout << "Pistone inizializzato\n";

    cout << "Creazione nuova stringa\n";

    string s2=svg_pist(pistone2);

    cout << s2 << endl;

    cout << "Eliminazione struttura pistone";

    elimina_pist(pistone);

    cout << "\nFine programma\n";*/
    double r=10,d=30,h=10,q=20;
    cout << "Costruzione del meccanismo";
    Manovella* man = manovella_init(30,200,200, 60);

    double a,b;

    a = sqrt(pow(d,2)-pow(h,2)-2*h*r*sin(q)-pow(r,2)*pow(sin(q),2))/d;
    b = (-h-r*sin(q))/d;

    Biella* bie = biella_init (90, 200 + 30*sin(-60), 200 - 30*cos(-60), atan2(a,b));

    Pistone* pist =  pist_init(30, 500 ,500); 

    string s = manovella_svg(man,1) + biella_svg(bie,1) + pist_svg(pist,1);

    s=svg(s);

    svg_to_file("pistone.svg",s);

    
    Manovella* pistone2;
    try {
        cout << "Creazione della struttura pistone."<< endl;
        pistone2 = manovella_new(s);
    } catch (exception& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };
    std::string s2=manovella_svg(pistone2,0);
    cout<<s2;
    return 0;
}
