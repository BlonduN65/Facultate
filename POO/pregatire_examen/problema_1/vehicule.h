#ifndef VEHICULE_H_
#define VEHICULE_H_
#include <iostream>

namespace Vehicule{
    class Automobil{
        private:    
             char* marca;//membru privat char

        public:
             Automobil();//constructorvid
             Automobil(const char* marcaParam);// ConstructorCuParametri
             Automobil(const Automobil& other);// ConstructorDeCopiere

             virtual ~Automobil();//OBSERVATIE: Chiar daca nu scrie explicit in enunt, avand char* alocat dinamic
        // si functii virtuale, Destructorul VIRTUAL este OBLIGATORIU pentru a evita memory leaks!
             Automobil& operator=(const Automobil& other);// operator =
            // CERINTA 4 ("Cireasa de pe tort"): "Sa se creeze o functie Afisare si Citire VIRTUALE."[cite: 602]
        // Cuvantul cheie 'virtual' permite polimorfismul la run-time.
             virtual void Citire();
             virtual void Afisare() const;
        // CERINTA 5: "Sa se creeze o functie prietena operatorul == (...) pentru ambele clase."
             friend bool operator==(const Automobil& a1,const Automobil& a2);

    };
    class Motocicleta :public Automobil{
        private:
            double vitezaMaxima;

        public:
            Motocicleta();
            Motocicleta(const char* marcaParam,double vitezaParam);
            Motocicleta(const Motocicleta& other);
            ~Motocicleta() override;

            Motocicleta& operator=(const Motocicleta& other);
            
            void Citire() override;
            void Afisare() const override;

            friend bool operator==(const Motocicleta& m1,const Motocicleta& m2);

    };
}




#endif