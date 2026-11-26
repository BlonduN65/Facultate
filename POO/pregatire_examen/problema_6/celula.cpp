#include "celula.h"
#include <iostream>


Celula::Celula():mitoCondrii(0),dimensiune(0){}

Celula::Celula(int _numarMitocondrii,double _dimensiune):mitoCondrii(_numarMitocondrii),dimensiune(_dimensiune){}

void Celula::setNumarMitocondrii(int _numarMitocondrii){
    this->mitoCondrii=_numarMitocondrii;
}
int Celula::getMitocondrii()const {
    return this->mitoCondrii;
}
void Celula::setDimensiune(double _dimensiune){
    this->dimensiune=_dimensiune;
}
double Celula::getDimensiune()const{
    return this->dimensiune;
}
double Celula::operator+()const{
    return this->dimensiune;
}
Celula Celula::operator+(double valoare)const{
    Celula copie(this->mitoCondrii,this->mitoCondrii+valoare);
    return copie;
}
void Celula::afisare()const{
    std::cout<<"Celula->Mitocondrii "<<this->mitoCondrii<<" |Celula->Dimensiune  "<<this->dimensiune<<"\n";
    
}