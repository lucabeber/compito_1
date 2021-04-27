#include "svg.h"

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>

using namespace std;


string svg(string componenti){

    /* si crea la stringa finale da inserire nel file svg aggiungenndo le specifiche del file svg
       al svg dei poligoni gia' scritti
    */
    string s ;

    // si inizializza il file svg
    s += "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?> \n";

    s += "<svg xmlns=\"http://www.w3.org/2000/svg\" width= \"800\" height=\"600\" style=\"background-color:white\" >\n";

    // si inseriscono i poligoni creati all'interno del file svg
    s += componenti;

    s += "\n</svg>";

    return s;
}

void svg_to_file (string filename, string str_svg){
    // creazione ed apertura del file
    ofstream MyFile(filename);

    // scrivo all'interno del file la stringa svg
    MyFile << str_svg;

    MyFile.close();
}

string read_svg (string filename){

    std::ifstream t(filename);
    std::stringstream buffer;

    buffer << t.rdbuf();
    string s = buffer.str();

    cout << "Il file " << filename << " e` stato letto" << endl;
    cout << s << endl;

    return s;
}