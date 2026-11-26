#include "header.h"
#include <cstring>

using namespace std;

namespace Auto {

    // =========================================================================
    // IMPLEMENTARI CLASA DE BAZA: Vehicul[cite: 604]
    // =========================================================================

    // Constructor cu parametri (valorile default sunt in header.h)[cite: 604]
    Vehicul::Vehicul(const char* _marca, double _vitezaMaxima) {
        cout << "[Vehicul] S-a apelat ConstructorCuParametri\n";
        this->marca = new char[strlen(_marca) + 1];
        strcpy(this->marca, _marca);
        this->vitezaMaxima = _vitezaMaxima;
    }

    // Constructor de copiere (Deep Copy pentru char*)[cite: 604]
    Vehicul::Vehicul(const Vehicul& other) {
        cout << "[Vehicul] S-a apelat ConstructorDeCopiere\n";
        this->marca = new char[strlen(other.marca) + 1];
        strcpy(this->marca, other.marca);
        this->vitezaMaxima = other.vitezaMaxima;
    }

    // Operator de atribuire (=)
    Vehicul& Vehicul::operator=(const Vehicul& other) {
        if (this != &other) {
            delete[] this->marca;
            this->marca = new char[strlen(other.marca) + 1];
            strcpy(this->marca, other.marca);
            this->vitezaMaxima = other.vitezaMaxima;
        }
        return *this;
    }

    // Destructor virtual[cite: 604]
    Vehicul::~Vehicul() {
        cout << "[Vehicul] S-a apelat Destructor\n";
        if (this->marca != nullptr) {
            delete[] this->marca;
            this->marca = nullptr;
        }
    }

    // CERINTA: operator+=(char*) - concateneaza sirul primit la marca[cite: 604]
    Vehicul& Vehicul::operator+=(const char* sufix) {
        cout << "[Vehicul] S-a apelat operator+=(\"" << sufix << "\")\n";
        char* nouaMarca = new char[strlen(this->marca) + strlen(sufix) + 1];
        strcpy(nouaMarca, this->marca);
        strcat(nouaMarca, sufix);

        delete[] this->marca;
        this->marca = nouaMarca;
        return *this;
    }

    // Afisare virtuala[cite: 604]
    void Vehicul::Afisare() const {
        cout << "[Vehicul] Marca: " << (this->marca ? this->marca : "N/A")
             << " | Viteza maxima: " << this->vitezaMaxima << " km/h\n";
    }

    // Citire virtuala[cite: 604]
    void Vehicul::Citire() {
        cout << "[Vehicul] Citire date:\n";
        char buffer[100];
        cout << "  Introduceti marca: ";
        cin >> ws;
        cin.getline(buffer, 100);

        delete[] this->marca;
        this->marca = new char[strlen(buffer) + 1];
        strcpy(this->marca, buffer);

        cout << "  Introduceti viteza maxima: ";
        cin >> this->vitezaMaxima;
    }

    // CERINTA: operator-- postfixat (functie globala prietena) - modifica membrul double[cite: 604]
    Vehicul operator--(Vehicul& v, int) {
        cout << "[Vehicul] S-a apelat operator-- postfixat\n";
        Vehicul copie(v);   // Salvam starea initiala
        v.vitezaMaxima--;   // Scadem cu 1 vitezaMaxima[cite: 604]
        return copie;       // Returnam obiectul dinaintea decrementarii
    }


    // =========================================================================
    // IMPLEMENTARI CLASA DERIVATA: Automobil[cite: 604]
    // =========================================================================

    // Constructor cu parametri[cite: 604]
    Automobil::Automobil(const char* _marca, double _vitezaMaxima,
                         double _masaMaxima, Combustibil _tipCombustibil)
        : Vehicul(_marca, _vitezaMaxima), masaMaxima(_masaMaxima), tipCombustibil(_tipCombustibil) {
        cout << "[Automobil] S-a apelat ConstructorCuParametri\n";
    }

    // Constructor de copiere[cite: 604]
    Automobil::Automobil(const Automobil& other)
        : Vehicul(other), masaMaxima(other.masaMaxima), tipCombustibil(other.tipCombustibil) {
        cout << "[Automobil] S-a apelat ConstructorDeCopiere\n";
    }

    // Operator=
    Automobil& Automobil::operator=(const Automobil& other) {
        if (this != &other) {
            Vehicul::operator=(other);
            this->masaMaxima = other.masaMaxima;
            this->tipCombustibil = other.tipCombustibil;
        }
        return *this;
    }

    // Destructor[cite: 604]
    Automobil::~Automobil() {
        cout << "[Automobil] S-a apelat Destructor\n";
    }

    // CERINTA: operator+=(double) - creste masa maxima cu valoarea parametrului[cite: 604]
    Automobil& Automobil::operator+=(double valoareMasa) {
        cout << "[Automobil] S-a apelat operator+=(" << valoareMasa << ")\n";
        this->masaMaxima += valoareMasa;
        return *this;
    }

    // Afisare suprascrisa[cite: 604]
    void Automobil::Afisare() const {
        Vehicul::Afisare();
        cout << "   -> [Automobil] Masa maxima: " << this->masaMaxima << " kg | Combustibil: ";
        switch (this->tipCombustibil) {
            case electric: cout << "electric"; break;
            case hibrid:   cout << "hibrid"; break;
            case diesel:   cout << "diesel"; break;
            case benzina:  cout << "benzina"; break;
        }
        cout << endl;
    }

    // Citire suprascrisa[cite: 604]
    void Automobil::Citire() {
        Vehicul::Citire();
        cout << "  Introduceti masa maxima (kg): ";
        cin >> this->masaMaxima;

        int optiune;
        cout << "  Alegeti combustibilul (0-electric, 1-hibrid, 2-diesel, 3-benzina): ";
        cin >> optiune;
        if (optiune >= 0 && optiune <= 3) {
            this->tipCombustibil = static_cast<Combustibil>(optiune);
        } else {
            this->tipCombustibil = benzina;
        }
    }

    // CERINTA: operator-- postfixat (functie globala prietena) - modifica membrul double[cite: 604]
    Automobil operator--(Automobil& a, int) {
        cout << "[Automobil] S-a apelat operator-- postfixat\n";
        Automobil copie(a); // Salvam starea initiala
        a.masaMaxima--;     // Scadem cu 1 masaMaxima[cite: 604]
        return copie;       // Returnam obiectul dinaintea decrementarii
    }

}