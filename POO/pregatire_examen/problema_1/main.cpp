#include "vehicule.h"
#include <iostream>
using namespace Vehicule;
int main(){

    std::cout<<"Testare automobil\n";
    Automobil a1;
    Automobil a2("DACIA");
    Automobil a3(a2);
    a1=a2;
    if (a1==a2){
        std::cout<<"a1 si a2 au aceiasi marca";

    }
    a1.Afisare();
    std::cout<<"Testare Motocicleta\n";
    Motocicleta m1;
    Motocicleta m2("Yamaha",299.5);
    Motocicleta m3(m2);
    m1=m2;
    if(m1==m2){
        std::cout<<"m1 si m2 sunt identice\n";
    }
    m1.Afisare();

    std::cout<<"testare polimorfism\n";
    Automobil* ptrVehicul=new Motocicleta("Honda",260.0);
    ptrVehicul->Citire();
    ptrVehicul->Afisare();

    std::cout<<"Eliberare memorie\n";
    delete ptrVehicul;




    return 0;
}