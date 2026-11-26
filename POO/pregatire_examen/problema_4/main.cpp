#include "hardisk.h"
#include "calculator.h"
#include <iostream>

template<typename T>
double sumaCapacitati(T a, T b){
    return (+a)+ (+b);
}


int main(){
    HardDisk hd1;
    HardDisk hd2(1000,"Samsung");
    std::cout<<"Capacitate hd2 "<<+hd2<<"\n";

    hd1.afisare();
    hd2.afisare();

    Calculator pc;
    pc.AdaugareHardDisk(HardDisk(2048,"Seagate"));
    pc.AdaugareHardDisk(HardDisk(512,"Kingstone"));
    pc.AdaugareHardDisk(hd2);

    std::cout<<"Elementele calculatorului\n";
    pc.afisare();

    std::cout<<"Scad cu 50%\n";
    pc.scadeCapacitate(50);
    pc.afisare();

    std::cout<<"Dupa sortare\n";
    pc.sorteaza();
    pc.afisare();

    HardDisk hd3(256,"WD");
    std::cout<<"Suma capacitati: hd2+hd3 :"<<sumaCapacitati(hd2,hd3)<<"\n";

    std::cout<<"Exemplu agregare: \n";
    Birou b("Andrei",&pc);
    b.afisare();

    return 0;
}