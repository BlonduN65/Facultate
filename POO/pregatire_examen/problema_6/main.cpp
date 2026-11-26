#include "celula.h"
#include <iostream>
#include "organism.h"
int main(){
    Celula c1;
    Celula c2(150,12.5);
    c1.setNumarMitocondrii(80);
    c1.setDimensiune(100);

    std::cout<<"Verificare set "<<c1.getDimensiune()<<" "<<c1.getMitocondrii()<<" \n";

    c2=c2+2.5;
    c1.afisare();
    c2.afisare();
    
    Organism org;
    org.adaugaCelula(c1);
    org.adaugaCelula(c2);
    org.adaugaCelula(Celula(300,20.0));

    std::cout<<"Celulele: \n";
    org.afisare();

    org.cresteDimensiunea(5.0);
    org.afisare();

    std::cout<<"Exemplu de agregare: \n";
    Laborator lab("Dr. Ionescu",&org);
    lab.afisare();



    return 0;
}