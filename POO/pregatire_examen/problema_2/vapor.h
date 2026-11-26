#ifndef VAPOR_H_
#define VAPOR_H_
#include <iostream>
namespace Porturi{
    class Vapor{
        private:
            int nrContainere;
            bool inMiscare;
            char* destinatie;
            
            
            public:
                Vapor();
                Vapor(const char* _destinatie,bool _inMiscare,int _nrContainere=150);
                Vapor(const Vapor& other);
                Vapor& operator=(const Vapor& other);
                ~Vapor();

                void Afisare()const;
                void Citire();

                void Citire(const char* _destinatie);
                bool GetInMiscare()const;
                void SetInMiscare(bool _inMiscare = true);
                int GetContainere() const;
                void SetNrContainere(int _nrContainere);

    };
        

}


#endif