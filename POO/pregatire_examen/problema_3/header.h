#ifndef HEADER_H_
#define HEADER_H_
#include <iostream>
namespace Auto{
    enum Combustibil{
        electric,
        hibrid,
        diesel,
        benzina
    };
    class Vehicul{
        private:
            char* marca;
            double vitezaMaxima;
        
        public:
            Vehicul(const char* _marca="Necunoscut",double _vitezaMaxima=0.0);
            Vehicul(const Vehicul& other);
            Vehicul& operator=(const Vehicul& other);
            
            virtual ~Vehicul();
            Vehicul& operator+=(const char* sufix);
            
            virtual void Afisare() const;
            virtual void Citire();

            friend Vehicul operator--(Vehicul& v, int);
    };
    class Automobil:public Vehicul{
        private:
            double masaMaxima;
            Combustibil tipCombustibil;
        public:
            Automobil(const char* _marca="Necunoscut",double _vitezaMaxima=0.0,double _masaMaxima=1500.0,Combustibil _tipCombustibil=benzina);
            Automobil(const Automobil& other);
            Automobil& operator=(const Automobil& other);

            ~Automobil() override;
            Automobil& operator+=(double valoareMasa);
            void Afisare() const override;
            void Citire() override;

        // CERINTA: Forma postfixata pentru operator-- ca functie globala prietena[cite: 604]
            friend Automobil operator--(Automobil& a, int);
        };


}


#endif