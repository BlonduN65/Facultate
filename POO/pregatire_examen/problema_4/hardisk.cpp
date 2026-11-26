#include "hardisk.h"

HardDisk::HardDisk():capacitate(0),marca("Necunoscuta"){}
HardDisk::HardDisk(double _capacitate,std::string _marca): capacitate(_capacitate),marca(_marca){}

double HardDisk::operator+() const{
    return this->capacitate;
}

void HardDisk::afisare()const{
    std::cout<<"Marca:"<<this->marca<<" | Capacitatea: "<<this->capacitate<<"GB\n";
}
bool HardDisk:: operator<(const HardDisk& other)const{
    return this->capacitate <other.capacitate;
}
