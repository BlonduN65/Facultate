#ifndef CONTBANCAR_H_
#define CONTBANCAR_H_

class ContBancar{
    private:
        double sold;
        int numarCont;
    public:
        ContBancar();
        ContBancar(double _sold,int _numarCont);
        
        void setSold(double _sold);
        void setNumarCont(int _numarCont);
        double getSold() const;

        double operator+() const;
        ContBancar operator-(double valoare)const;

        void afisare() const;

};

#endif 