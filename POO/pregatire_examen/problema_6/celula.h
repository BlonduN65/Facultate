#ifndef CELULA_H_
#define CELULA_H_

class Celula{
    private:
        int mitoCondrii;
        double dimensiune;

    public:
        Celula();
        Celula(int _mitocondrii,double _dimensiune);

        //set si getteri

        void setNumarMitocondrii(int _mitocondrii);
        int getMitocondrii()const;

        void setDimensiune(double _dimensiune);
        double getDimensiune( )const;

        double operator+()const;
        Celula operator+(double valoare)const;

        void afisare()const;


};


#endif