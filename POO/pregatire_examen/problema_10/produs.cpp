#include "produs.h"
#include <iostream>
Produs::Produs():pret(0.0),nume("necunoscut"){}

Produs::Produs(std::string _nume,double _pret){
    this->nume=_nume;
    this->pret=_pret;
}
void Produs::setPret(double _pret){
    this->pret=_pret;
}
int Produs ::getPret()const{
    return this->pret;
}
void Produs::afisare()const{
    std::cout<<"Produs: "<<this->nume<<" |Pret"<<this->pret<<"\n";

}

std::ostream& operator<<(std::ostream& out,const Produs& p){
    out<<"Produs: "<<p.nume<<" |Pret"<<p.pret<<" \n";
    return out;
}