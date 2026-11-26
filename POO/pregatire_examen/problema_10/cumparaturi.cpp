#include "cumparaturi.h"
#include <iostream>

Cos::Cos():nrProduse(0){}
void Cos::adaugaProdus(Produs p){
    if(this->nrProduse<5)
        {
            this->v[this->nrProduse]=p;
            this->nrProduse++;
        }
}
void Cos::afisare()const{
    for(int i=0;i<this->nrProduse;i++)
        this->v[i].afisare();
}
double Cos::calculeazaTotal()const{
    double total=0;
    for (int i=0;i<this->nrProduse;i++){
        total=total+v[i].getPret();
    }
    return total;
}
BonFiscal::BonFiscal(int _codbon,std::string _nume,double _pret):codbon(_codbon),produsprincipal(_nume,_pret){}
void BonFiscal::afisare()const{
    std::cout<<"Bonul Fiscal "<<this->codbon<<"->";
    this->produsprincipal.afisare();
}