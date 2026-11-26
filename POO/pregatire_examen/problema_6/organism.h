#ifndef ORGANISM_H_
#define ORGANISM_H_
#include "celula.h"
#include <string>
class Organism{
      private: 
        Celula vec[5];
        unsigned int nrCelule;
      public:
        Organism();
        void adaugaCelula(Celula c);
        void afisare()const;
        void cresteDimensiunea(double valoare);

};
//agregare
class Laborator{
    private:
        std::string numeCercetator;
        Organism* proba;
    public:
        Laborator(std::string _numeCercetator,Organism* _probe);
        void afisare()const;

};


#endif