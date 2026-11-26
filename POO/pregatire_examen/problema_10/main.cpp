#include "cumparaturi.h"
#include "produs.h"
#include <iostream>
#include <memory> // Obligatoriu pentru unique_ptr si shared_ptr

int main() {
    std::unique_ptr<Produs> p1=std::make_unique<Produs>("Laptop",4500.0);
    p1->afisare();
    std::cout<<*p1;

    std::shared_ptr<Produs> p2=std::make_shared<Produs>("mouse",150.0);
    std::shared_ptr<Produs> copie_p2=p2;
    p2->afisare();

    std::cout<<"Numar referinte active :"<<p2.use_count()<<"\n";
    Cos cos;
    cos.adaugaProdus(*p1); // Dereferentiem cu '*' pentru a trimite obiectul Produs
    cos.adaugaProdus(*p2);

    Produs p3("Tastatura Mecanica", 300.0);
    cos.adaugaProdus(p3);

    std::cout << "\n--- Continutul Cosului ---\n";
    cos.afisare();
    std::cout << "Total de plata: " << cos.calculeazaTotal() << " RON\n";

    // 4. Compozitie prin obiect membru direct (BonFiscal)
    std::cout << "\n--- Exemplu Compozitie (BonFiscal) ---\n";
    BonFiscal bon(101, "Monitor 27 inch", 1200.0);
    bon.afisare();




    return 0;
}