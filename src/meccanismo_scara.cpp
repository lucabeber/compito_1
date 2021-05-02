#include <math.h>
#include <iostream>

#include "meccanismo_scara.h"
#include "pistone.h"
#include "fc_scara.h"
#include "svg.h"



Meccanismo* meccanismo_init(double r, double bas, double q, double x, double y, double h){
    
    double d = 3*r;
    
    Meccanismo* ret = new Meccanismo; 
    
    // si trasforma l'angolo in radianti 
    double qr=q*3.14/180;

    double a,b,c; 

    // vengono definiti 3 termini che descrivono le equazioni del moto del meccanismo di spinta
    a = sqrt(pow(d,2)-pow(h,2)-2*h*r*sin(qr)-pow(r,2)*pow(sin(qr),2))/d;
    b = (-h-r*sin(qr))/d;
    c = r*cos(qr)+sqrt(pow(d,2)-pow(h,2)-2*h*r*sin(qr)-pow(r,2)*pow(sin(qr),2));


    ret->scara = fc_scara_init(10, r, 3, -q+90, (q+atan2(a,b)*180/3.14-90), x, y);
    // si creano le parti del meccanismo con i parametri ottenuti
    
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
    std::string s =  fc_scara_to_svg(meccanismo->scara) + pist_svg(meccanismo->pistone,misure);
    return s;
}

Meccanismo*  meccanismo_new(std::string file){

    Meccanismo* ret = new Meccanismo; 
    std::cout << "Creazione struttura"<< std::endl;
    // si creano le parti del meccanismo tramite la stringa in ingresso
    ret->scara = fc_svg_to_scara(file);
    std::cout << "Manovella e biella create."<< std::endl;
    
    try {
        std::cout << "Creazione della struttura pistone."<< std::endl;
        ret->pistone = pist_new(file);
    } catch (std::exception& ex) {
        std::cout << "something bad happened!" << ex.what() << std::endl;
        std::cout << "I caught the exception, will continue" << std::endl;
        ret->pistone = NULL;
    };

    return ret;
}

void meccanismo_del(Meccanismo* meccanismo){

    // si richiamano le funzioni per eliminare gli elementi costituenti il meccanismo
    pist_del(meccanismo->pistone);
    fc_delete_robot(meccanismo->scara);

    // per ultimo si elimina la struttura meccanismo
    delete meccanismo;
}
