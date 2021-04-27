#include <math.h>
#include <iostream>

#include "meccanismo.h"
#include "pistone.h"
#include "biella.h"
#include "svg.h"
#include "manovella.h"


Meccanismo* meccanismo_init(double r, double d, double bas, double q, double x, double y, double h){
    
    
    Meccanismo* ret = new Meccanismo; 
    
    // si trasforma l'angolo in radianti 
    double qr=q*3.14/180;

    double a,b,c; 

    // vengono definiti 3 termini che descrivono le equazioni del moto del meccanismo di spinta
    a = sqrt(pow(d,2)-pow(h,2)-2*h*r*sin(qr)-pow(r,2)*pow(sin(qr),2))/d;
    b = (-h-r*sin(qr))/d;
    c = r*cos(qr)+sqrt(pow(d,2)-pow(h,2)-2*h*r*sin(qr)-pow(r,2)*pow(sin(qr),2));

    // si creano le parti del meccanismo con i parametri ottenuti
    try {
        std::cout << "Creazione della struttura manovella."<< std::endl;
        ret->manovella = manovella_init(r,x,y,-q);
    } catch (std::exception& ex) {
        std::cout << "something bad happened!" << ex.what() << std::endl;
        std::cout << "I caught the exception, will continue" << std::endl;
        ret->manovella = NULL;
    };
    
    try {
        std::cout << "Creazione della struttura manovella."<< std::endl;
        ret->biella = biella_init(d,x+r*sin(qr),y+r*cos(qr),atan2(a,b)*180/3.14-90);
    } catch (std::exception& ex) {
        std::cout << "something bad happened!" << ex.what() << std::endl;
        std::cout << "I caught the exception, will continue" << std::endl;
        ret->manovella = NULL;
    };
    
    try {
        std::cout << "Creazione della struttura pistone."<< std::endl;
        ret->pistone = pist_init(bas,x-h-bas/2,y+c+bas/4);
    } catch (std::exception& ex) {
        std::cout << "something bad happened!" << ex.what() << std::endl;
        std::cout << "I caught the exception, will continue" << std::endl;
        ret->pistone = NULL;
    };

    return ret;
}

std::string meccanismo_svg(Meccanismo* meccanismo, bool misure){

    // si ottine una stringa contenente l'svg del meccanismo richiamando le funzioni dei vari componenti
    std::string s = manovella_svg(meccanismo->manovella,misure) + pist_svg(meccanismo->pistone,misure) + biella_svg(meccanismo->biella,misure);

    return s;
}

void meccanismo_del(Meccanismo* meccanismo){

    // si richiamano le funzioni per eliminare gli elementi costituenti il meccanismo
    pist_del(meccanismo->pistone);
    manovella_del(meccanismo->manovella);
    biella_del(meccanismo->biella);

    // per ultimo si elimina la struttura meccanismo
    delete meccanismo;
}
