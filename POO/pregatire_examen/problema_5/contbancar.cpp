#include "contbancar.h"
#include <iostream>
ContBancar::ContBancar():sold(0.0),numarCont(0){}

ContBancar::ContBancar(double _sold,int _numarCont): sold(_sold),numarCont(_numarCont){}

void ContBancar::setSold(double _sold){
    this->sold=_sold;
}
double ContBancar::getSold()const{
    return this->sold;
}
void ContBancar::setNumarCont(int _numarCont){
    this->numarCont=_numarCont;
}

double ContBancar::operator+() const{
    return this->sold;
}

ContBancar ContBancar::operator-(double valoare )const{
    ContBancar copie(this->sold - valoare,this->numarCont);
    return copie;
}
void ContBancar::afisare()const {
    std::cout<<"Cont nr: "<<this->numarCont<<"|Sold: "<<this->sold<<"Ron\n";

}