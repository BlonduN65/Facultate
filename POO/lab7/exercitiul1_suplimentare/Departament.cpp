#include "Departament.h"
#include <iostream>

Departament::Departament(const std::string& n) : nume{n}
{
    existente++;
    std::cout << "Departament " << nume << "\n";
}

Departament::~Departament()
{
    existente--;
    std::cout << "~Departament " << nume << "\n";
}

void Departament::adauga(const std::shared_ptr<Profesor>& p)
{
    profesori.push_back(p);
}

Profesor* Departament::cauta(const std::string& n) const
{
    for (const auto& p : profesori) {
        if (p->getNume() == n) {
            return p.get(); //[cite: 17]
        }
    }
    return nullptr;
}

void Departament::afiseaza() const
{
    std::cout << nume << ":";
    for (const auto& p : profesori) {
        std::cout << " " << p->getNume();
    }
    std::cout << "\n";
}