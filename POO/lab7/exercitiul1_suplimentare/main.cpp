#include <cassert>
#include <iostream>
#include <memory>
#include "Departament.h"
#include "Profesor.h"
void testCiclu()
{
 {
        auto ana = std::make_shared<Profesor>("Ana");
        auto aut = std::make_shared<Departament>("Automatica");
        aut->adauga(ana);
        ana->setDepartament(aut);
        assert(ana->getDepartament() == aut);
        ana->afiseaza();
        std::cout << ana.use_count() << " " << aut.use_count() << "\n";
 }
 // la sfârșitul blocului, profesorul și departamentul trebuie distruși
    assert(Profesor::getExistenti() == 0);
    assert(Departament::getExistente() == 0);
}
void testDepartamentDistrus()
{
    auto ana = std::make_shared<Profesor>("Ana");
    {
        auto aut = std::make_shared<Departament>("Automatica");
        auto calc = std::make_shared<Departament>("Calculatoare");
        aut->adauga(ana);
        calc->adauga(ana); // Ana predă în două departamente
        ana->setDepartament(aut);
        assert(ana.use_count() == 3);
        assert(calc->cauta("Ana") == ana.get());
    }
 // departamentele au fost distruse; Ana există, o deține ana
    assert(Departament::getExistente() == 0);
    assert(ana.use_count() == 1);
    assert(ana->getDepartament() == nullptr);
    ana->afiseaza();
 }

int main()
{
    testCiclu();
    testDepartamentDistrus();
    assert(Profesor::getExistenti() == 0);
    std::cout << "toate testele au trecut\n";
    
    return 0;
}
 
