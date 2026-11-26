#include "calculator.h"
#include <algorithm>
#include <iostream>

void Calculator::AdaugareHardDisk(HardDisk hd){
    this->v.push_back(hd);
}
void Calculator::afisare()const{
    for(int i=0;i<this->v.size();i++){
        this->v[i].afisare();
    }
}
void Calculator::scadeCapacitate(double procent) {
    for (int i = 0; i < this->v.size(); i++) {
        this->v[i].capacitate = this->v[i].capacitate - (this->v[i].capacitate * procent / 100.0);
    }
}
void Calculator::sorteaza(){
    std::sort(this->v.begin(),this->v.end());
}

Birou::Birou(std::string _nume,Calculator* _calc){
    this->nume=_nume;
    this->calc=_calc;
}
void Birou::afisare()const{
    std::cout<<"Birou: "<<this->nume<<"\n";
    this->calc->afisare();

}