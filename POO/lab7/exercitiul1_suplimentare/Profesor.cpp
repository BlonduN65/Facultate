#include "Profesor.h"
#include "Departament.h"
#include <iostream>

Profesor::Profesor(const std::string& n) : nume{n}
{
    existenti++;
    std::cout << "Profesor " << nume << "\n";
}

Profesor::~Profesor()
{
    existenti--;
    std::cout << "~Profesor " << nume << "\n";
}

std::shared_ptr<Departament> Profesor::getDepartament() const
{
    return departament.lock(); //[cite: 19]
}

void Profesor::setDepartament(const std::shared_ptr<Departament>& d)
{
    departament = d;
}

void Profesor::afiseaza() const
{
    auto d = departament.lock();
    if (d) {
        std::cout << nume << " (" << d->getNume() << ")\n";
    } else {
        std::cout << nume << " (fara departament)\n";
    }
}