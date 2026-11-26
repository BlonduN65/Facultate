#ifndef CUMPARATURI_H_
#define CUMPARATURI_H_
#include "produs.h"
class Cos{
    private:
    Produs v[5];
    unsigned int nrProduse;
    public: 
        Cos();
        void adaugaProdus(Produs p);
        void afisare()const;
        double calculeazaTotal()const;


};

class BonFiscal{
    private:
        int codbon;
        Produs produsprincipal;

    public:
        BonFiscal(int _codbon,std::string _nume,double _pret);
        void afisare()const;
};




#endif