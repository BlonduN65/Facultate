#ifndef BANCA_H_
#define BANCA_H_
#include <string>
#include "contbancar.h"
class Banca{
    private:
        ContBancar conturi[5];
        int nrConturi;
    public:
        Banca();
        
        void adaugaCont(ContBancar c);
        void afisare()const;

        void aplicaComision(double procent);

};
class Client{
    private:
        std::string nume;
        ContBancar* contPersonal;
    public:
        Client(std::string _nume, ContBancar* _contPersonal);
        void afisare()const;

};


#endif