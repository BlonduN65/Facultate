#include "Vapor.h"
#include <cstring>

namespace Porturi{
    Vapor::Vapor(){
        std::cout<<"S-a apelat constructorul Vapor\n";
        this->nrContainere=0;
        this->inMiscare=false;
        this->destinatie=new char[strlen("Necunoscuta")+1];
        strcpy(this->destinatie,"Necunoscuta");
    }
     Vapor::Vapor(const char* _destinatie,bool _inMiscare,int _nrContainere){
        std::cout<<"S-a apelat constructor cu parametrii\n";
        this->nrContainere=_nrContainere;
        this->inMiscare=_inMiscare;
        this->destinatie=new char[strlen(_destinatie)+1];
        strcpy(this->destinatie,_destinatie);

     }
     Vapor::Vapor(const Vapor& other){
        std::cout<<"S a apelat copierea\n";
        this->nrContainere=other.nrContainere;
        this->inMiscare=other.inMiscare;
        this->destinatie=new char[strlen(other.destinatie)+1];
        strcpy(this->destinatie,other.destinatie);
     }
     Vapor& Vapor::operator=(const Vapor& other){
        if(this!= &other){
            this->nrContainere=other.nrContainere;
            this->inMiscare=other.inMiscare;
            delete[] this->destinatie;
            strcpy(this->destinatie,other.destinatie);
        }
        return *this;
     }
     Vapor::~Vapor(){
        std::cout<<"S-a apelat destructorul\n";
        if(this->destinatie!=nullptr){
            delete[] this->destinatie;
            this->destinatie=nullptr;
        }
     }
     void Vapor::Afisare()const{
        std::cout<<"S-a apelat afisarea\n";
        std::cout << "Destinatie: " << (destinatie ? destinatie : "N/A")
             << " | Nr. containere: " << nrContainere
             << " | In miscare: " << (inMiscare ? "Da" : "Nu") <<"\n";
    }
    void Vapor::Citire() {
    std::cout << "S-a apelat Citire()\n";
    char buffer[100];
    std::cout << "Introduceti destinatia:\n";
    std::cin >> std::ws;
    std::cin.getline(buffer, 100);

    delete[] this->destinatie;
    this->destinatie = new char[strlen(buffer) + 1];
    strcpy(this->destinatie, buffer);

    std::cout << "Introduceti nr-ul de containere:\n";
    std::cin >> this->nrContainere;

    std::cout << "Este in miscare?\n";
    std::cin >> this->inMiscare;
    }

    void Vapor::Citire(const char* _destinatie) {
    std::cout << "S-a apelat Citire(_destinatie)\n";
    
    delete[] this->destinatie;
    this->destinatie = new char[strlen(_destinatie) + 1];
    strcpy(this->destinatie, _destinatie);

    std::cout << "Introduceti nr-ul de containere:\n";
    std::cin >> this->nrContainere;

    std::cout << "Este in miscare?\n";
    std::cin >> this->inMiscare;
    }
    
    bool Vapor::GetInMiscare()const{
        return this->inMiscare;
    }
    
    void Vapor::SetInMiscare(bool _inMiscare){
        
        this->inMiscare = _inMiscare;
    }


    int Vapor::GetContainere()const{
        return this->nrContainere;
    }
    void Vapor::SetNrContainere(int _nrcontainere){
        this->nrContainere=_nrcontainere;
    }

}