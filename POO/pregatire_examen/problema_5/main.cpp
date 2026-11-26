#include "banca.h"
#include "contbancar.h"
#include <iostream>


int main(){
    ContBancar c1;
    ContBancar c2(1000.0,101);

    c1.setSold(500.0);
    c1.setNumarCont(100);
    std::cout<<"Verificare getteri: "<<c1.getSold()<<"\n";

    std::cout<<"Soldul lui c2 este dupa operator unar +"<<+c2<<"RON\n";
    c2=c2-200.0;
    c1.afisare();
    c2.afisare();

    Banca b;
    b.adaugaCont(c1);
    b.adaugaCont(c2);
    b.adaugaCont(ContBancar(10000.0,333));


    std::cout<<"Conturile din banca: \n";
    b.afisare();

    std::cout<<"Aplicare comision:\n";
    b.aplicaComision(10.0);
    b.afisare();

    std::cout<<"Exemplu Agregare:\n";
    Client cl("Popescu Ion",&c2);
    cl.afisare();





    return 0;
}