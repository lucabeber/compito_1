#include <iostream>
#include <cstring>

#include "pistone.h"
#include "biella.h"
#include "svg.h"
#include "manovella.h"
#include "meccanismo.h"

int main() {
    
    bool cp = true, mec=false, misure;         // variabili booleane che sevono per tenere conto dello stato del programma
    char c;                             // variabile utilizzata per l'istruzione da attuare     
    Meccanismo** arr;                   // doppio puntatore per creazione di un array di meccanismi
    int angolo,delta=0,n, mod;                 // 3 variabili che si utilizzeranno per costruire il meccanismo
    std::string s, nomefile, p, y, new_str;      // stringhe di appoggio 
    size_t found,found2;

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
        if (mec == true){
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
            arr[i] = meccanismo_init(50,150,60,angolo+delta*i,100*i+(9-n)*50,200,1);
        } 
        mec = true;

        std::cout<<"Il meccanismo e' stato creato"<<std::endl;
        break;
    
    case 's':
        if (mec == false){
            std::cout<<"Non e' presente nessun meccanismo"<<std::endl;
            break;
        }

        std::cout<<"Devono essere presenti le misure (0 no e 1 si)"<<std::endl;
        std::cin>>misure;

        if (misure != 0 && misure != 1){
            std::cout<<"Inserisci un valore valido"<<std::endl;
            break;
        }
        
        s = "<!--\n Sono presenti " + std::to_string(n) + " meccanismi\n-->\n";
        
        for (int i=0; i<n; i++){
            s += "<!--\n Meccanismo " + std::to_string(i+1) + "\n-->\n";
            s += meccanismo_svg(arr[i],misure);
            meccanismo_del(arr[i]);
        } 
        delete arr;

        mec = false; 

        s = svg(s);

        std::cout<<"Nome del file su cui salvare il codice svg"<<std::endl;
        std::cin>>nomefile;

        svg_to_file(nomefile,s);

        s.clear();
        nomefile.clear();

        break;

    case 'l':
        std::cout<<"Nome del file su cui e' salvato il codice svg"<<std::endl;
        std::cin>>nomefile;

        s = svg_read(nomefile);

        p = "Sono presenti ";

        found = s.find(p)+size(p);
        found2 = s.find(" ",found);

        new_str = s.substr(found, found2);

        n = atoi(new_str.c_str());
        
        arr= new Meccanismo* [n];

        if (n<0 || n>8) break;

        for (int i=0; i<n; i++){
            if (i<n-1){
                new_str = "Meccanismo " + std::to_string(i+2);
                found2 = s.find(new_str);
            } else {
                found2 = s.find("/svg",found);
            }

            new_str = s.substr(found, found2);
            arr[i] = meccanismo_new(new_str.c_str());
            found = found2;
        }

        mec = true;

        std::cout<<"Il file e' stato letto e la struttura creata"<<std::endl;
        break;
    
    case 'm':
        if (mec == false){
            std::cout<<"Non e' presente nessun meccanismo"<<std::endl;
            break;
        }

        std::cout<<"Quale meccanismo si vuole modificare?"<<std::endl;
        std::cin>>mod;

        if (mod <= 0 || mod > n ){
            std::cout<<"Il meccanismo scelto non esiste"<<std::endl;
            break;
        }
        
        std::cout<<"Che angolo deve avere la manovella?"<<std::endl;
        std::cin>>angolo;

        meccanismo_del(arr[mod-1]);
        arr[mod-1] = meccanismo_init(45,150,60,angolo,50+100*(mod-1),200,1);

        std::cout<<"L'angolo e' stato modificato"<<std::endl;
        break;

    case 'i':
        std::cout<<"Creazione di un nuovo device (d)"<<std::endl;
        std::cout<<"Salvare il device che hai creato (s)"<<std::endl;
        std::cout<<"Leggere un divice da un file salvato (l)"<<std::endl;
        std::cout<<"Modificare l'angolo di una manovella (m)"<<std::endl;
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
