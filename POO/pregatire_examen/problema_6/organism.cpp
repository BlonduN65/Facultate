#include "organism.h"
#include <iostream>
Organism::Organism(){
    this->nrCelule=0;
}
void Organism::adaugaCelula(Celula c){
    if(this->nrCelule<5){
        
        this->vec[this->nrCelule]=c;
        this->nrCelule++;
    }
    else{
        std::cout<<"Organismul a atins limita de 5 celule\n";
    }
}

void Organism::afisare()const{
    for(int i=0;i<this->nrCelule;i++){
        this->vec[i].afisare();
    }
}
void Organism::cresteDimensiunea(double valoare){
    for(int i=0;i<this->nrCelule;i++){
            this->vec[i]=this->vec[i]+valoare;
    }
}

Laborator::Laborator(std::string _numeCercetator,Organism* _proba){
    this->numeCercetator=_numeCercetator;
    this->proba=_proba;
}

void Laborator::afisare()const{
    std::cout<<"Cercetator: "<<this->numeCercetator<<"\n";
    if(this->proba!=nullptr)
        this->proba->afisare();
}