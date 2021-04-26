#include <iostream>
#include <cstring>

#include "pistone.h"
#include "biella.h"
#include "svg.h"
#include "manovella.h"
#include "meccanismo.h"

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
    /*double r=10,d=30,h=10,q=20;
    cout << "Costruzione del meccanismo";
    Manovella* man = manovella_init(30,200,200, 60);

    double a,b;

    

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
    cout<<s2;*/
    
    bool cp = true, d=false;         // variabili booleane che sevono per tenere conto dello stato del programma
    char c;                             // variabile utilizzata per l'istruzione da attuare     
    Meccanismo** arr;                   // doppio puntatore per creazione di un array di meccanismi
    int angolo,delta=0,n;                 // 3 variabili che si utilizzeranno per costruire il meccanismo
    std::string s, nomefile, p, y;      // stringhe di appoggio  
    s.clear();
    y="Yes";

    // creo un ciclo che funziona finche non si mette cp uguale a false
    while ( cp == true){
    std::cout<<"Scegli cosa vuoi fare: (i per informazioni)"<<std::endl;
    std::cin>>c;

    switch (c)
    {
    case 'd':
        // si controlla che in memoria non sia gia presente un meccanismo 
        if (d == true){
            std::cout<<"E' presente un device in memori se desideri continuare sara cancellato (Yes)"<<std::endl;
            std::cin>>p;

            if (p.compare(y) == 0){  //l'utente puo' scegliere se continuare elimenando il meccanismo in memoria o se uscire e salvare prima di eliminare
                for (int i=0; i<n; i++){
                    meccanismo_del(arr[i]);
                } 
                delete arr;
            }else{
                break;
            }
        }

        // si inseriscono i dati per costruire i meccanismi
        std::cout<<"Quanti device sono presenti ?"<<std::endl;
        std::cin>>n;

        // controllo per evitare che non ci siano troppi elementi 
        if (n>8){
            std::cout<<"Non possono essere presenti cosi tanti elementi."<<std::endl;
            break;
        } else if (n<0){
            std::cout<<"Non puo' essere presente un numero negativo di elementi."<<std::endl;
            break;
        }

        arr= new Meccanismo* [n];

        std::cout<<"Angolo della manovella:"<<std::endl;
        std::cin>>angolo;

        if(n>=1){
            std::cout<<"Delta angolo:"<<std::endl;
            std::cin>>delta;
        }else{
            delta=0;
        } 

        for (int i=0; i<n; i++){
            arr[i] = meccanismo_init(50,150,60,angolo+delta*i,50+100*i,200,1);
        } 
        d = true;
        break;
    
    case 's':
        for (int i=0; i<n; i++){
            s += meccanismo_svg(arr[i],0);
            meccanismo_del(arr[i]);
        } 
        delete arr;

        d = false; 

        s = svg(s);

        std::cout<<"Nome del file su cui salvare il codice svg"<<std::endl;
        std::cin>>nomefile;

        svg_to_file(nomefile,s);

        s.clear();
        nomefile.clear();

        
        break;

    case 'l':
        /* code */
        break;
    
    case 'i':
        std::cout<<"Creazione di un nuovo device (d)"<<std::endl;
        std::cout<<"Salvare il device che hai creato (s)"<<std::endl;
        std::cout<<"Leggere un divice da un file salvato (l)"<<std::endl;
        std::cout<<"Fine del programma (f)"<<std::endl;
        break;

    case 'f':
        std::cout<<"Fine del programma"<<std::endl;
        cp = false;
    default:
        break;
    }
    }
    return 0;
}
