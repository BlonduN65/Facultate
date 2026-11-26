#include "banca.h"
#include <iostream>


Banca::Banca(){
    nrConturi=0;
}
void Banca::adaugaCont(ContBancar c){
    if(this->nrConturi<5){
        this->conturi[this->nrConturi]=c;
        this->nrConturi++;
    }
    else{
        std::cout<<"Banca a atins limita de conturi!\n";
    }
}

void Banca::afisare()const{
    for (int i=0;i<nrConturi;i++){
        this->conturi[i].afisare();
    }
}
void Banca::aplicaComision(double procent){
    for(int i=0;i<nrConturi;i++){
        double valoareaComision=(+this->conturi[i])*(procent/100);
        this->conturi[i]=this->conturi[i]-valoareaComision;
    }
}
Client::Client(std::string _nume,ContBancar* _contPersonal ){
    this->nume=_nume;
    this->contPersonal=_contPersonal;
}

void Client::afisare()const{
    std::cout<<"Nume: "<<this->nume<<"->";
    if(this->contPersonal!=nullptr){
        this->contPersonal->afisare();

    }
}