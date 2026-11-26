#include "vehicule.h"
#include <cstring>

namespace Vehicule{


   // Subpunct: ConstructorVid() - initializeaza marca cu un sir gol alocat dinamic
    Automobil::Automobil(){
        std::cout<<"S-a apelat Constructorul vid din Automobile\n";
        this->marca=new char[1];
        this->marca[0]='\0';
    }


    // Subpunct: ConstructorCuParametri(...) - aloca memorie cat lungimea parametrului + 1 ('\0') si copiaza
    Automobil::Automobil(const char* marcaParam){
        std::cout<<"S-a apelat Constructorul cu parametri din automobile\n";
        this->marca=new char[strlen(marcaParam)+1];
        strcpy(this->marca,marcaParam); 

    }
    // Subpunct: ConstructorDeCopiere(...) - face "Deep Copy" (aloca o noua zona de memorie, nu copiaza doar adresa)
    Automobil::Automobil(const Automobil& other){
        std::cout<<"S-a apelat Constructorul de copiere automobil\n";
        this->marca=new char[strlen(other.marca)+1];
        strcpy(this->marca,other.marca);
    }
    Automobil::~Automobil(){
        std::cout<<"S-a apelat destructorul automobil\n";
        if(this->marca!=nullptr){
            delete[] this->marca;
        }
    }
    Automobil& Automobil::operator=(const Automobil& other){
        std::cout<<"S-a apelat operatorul =\n";
        if(this!=&other){
            delete[] this->marca;
            this->marca=new char[strlen(other.marca)+1];
            strcpy(this->marca,other.marca);
        }
        return *this;
    }
    void Automobil::Citire(){
        std::cout<<"S-a apelat citirea: \n";
        char buffer[100];
        std::cout<<"Introduceti marca autoturismul: \n";
        std::cin.getline(buffer,100);

        delete[] this->marca;
        this->marca=new char[strlen(buffer)+1];
        strcpy(this->marca,buffer);

    }
    void Automobil::Afisare()const{
        std::cout<<"S-a apelat afisarea\n";
        std::cout<<"Marca este: "<<(marca ? marca: "Nespecificat")<<"\n";
    

    }

    bool operator==(const Automobil& a1,const Automobil& a2){
        std::cout<<"S-a apelat operatorul==prieten pentru Automobil\n";
        return strcmp(a1.marca,a2.marca)==0;
    }

    Motocicleta::Motocicleta() : Automobil(), vitezaMaxima(0) {
       std:: cout << "S-a apelat Constructorul Vid din Motocicleta\n";
    }
    Motocicleta::Motocicleta(const char* marcaParam,double vitezaParam):Automobil(marcaParam),vitezaMaxima(vitezaParam){
        std::cout<<"S-a apelat constructorul cu parametrii din motocileta\n";

    }
    Motocicleta::Motocicleta(const Motocicleta& other) : Automobil(other), vitezaMaxima(other.vitezaMaxima) {
        std::cout << "S-a apelat Constructorul de Copiere din Motocicleta\n";
    }

    Motocicleta::~Motocicleta() {
        std::cout << "S-a apelat Destructorul din Motocicleta\n";
    }

    Motocicleta& Motocicleta::operator=(const Motocicleta& other) {
        std::cout << "S-a apelat Operatorul = din Motocicleta\n";
        if (this != &other) {
            Automobil::operator=(other);
            this->vitezaMaxima = other.vitezaMaxima;
        }
        return *this;
    }
    void Motocicleta::Citire() {
        std::cout << "S-a apelat Citire() din Motocicleta\n";
        Automobil::Citire();
        std::cout << "Introduceti viteza maxima a motocicletei: ";
        std::cin >> vitezaMaxima;
    }

    void Motocicleta::Afisare() const {
        std::cout << "S-a apelat Afisare() din Motocicleta\n";
        Automobil::Afisare();
        std::cout << "Viteza maxima: " << vitezaMaxima << " km/h\n";
    }

    // Subpunct: Functie prietena operator == pentru Motocicleta[cite: 602]
    // Face cast la Automobil pentru a refolosi operatorul == din baza, apoi compara vitezele
    bool operator==(const Motocicleta& m1, const Motocicleta& m2) {
        std::cout << "S-a apelat operatorul == prieten pentru Motocicleta\n";
        return static_cast<const Automobil&>(m1) == static_cast<const Automobil&>(m2) && 
               m1.vitezaMaxima == m2.vitezaMaxima;
    }
}