#include <iostream>

#include "pistone.h"
#include "svg.h"

using namespace std;

int main() {

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

    cout << "\nFine programma\n";
    return 0;
}
