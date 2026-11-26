#ifndef CALCULATOR_H_
#define CALCULATOR_H_
#include <vector>
#include "hardisk.h"
#include <iostream>
class Calculator{
    private:
        std::vector<HardDisk> v;

    public:
        void AdaugareHardDisk(HardDisk hd);
        void afisare() const;
        void scadeCapacitate(double procent);
        void sorteaza();
};
class Birou{
    private:
        std::string nume;
        Calculator* calc;
    
    public:
        Birou(std::string _nume,Calculator* _calc);
        void afisare() const;
};



#endif