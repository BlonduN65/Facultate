#ifndef PRODUS_H_
#define PRODUS_H_
#include <string>
class Produs{

    private: 
        std::string nume;
        double pret;

    public:
        Produs();
        Produs(std::string _nume, double _pret);
        void setPret(double _pret);
        int getPret()const;
        void afisare()const;
        friend std::ostream& operator<<(std::ostream& out,const Produs& p);
};

#endif