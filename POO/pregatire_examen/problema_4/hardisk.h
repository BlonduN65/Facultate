#ifndef HARDISK_H_
#define HARDISK_H_
#include <string>
#include <iostream>
class Calculator;
class HardDisk{
    private:
        double capacitate;
        std::string marca;
    friend class Calculator;
    public:
        HardDisk();
        HardDisk(double _capacitate,const std::string _marca);
        
        double operator+() const;
        void afisare() const;

        //pentru sortarea vectorului

        double getCapacitate() const;
        bool operator<(const HardDisk& other )const;


};


#endif