#include "vapor.h"
#include <iostream>

using namespace Porturi;

int main(){
    Vapor v1;
    Vapor v2("constanta",true,320);
    Vapor v3("Rotterdam",false);

    v1.Afisare();
    v2.Afisare();
    v3.Afisare();


    std::cout<<"Testare setteri si getteri\n";
    v1.SetNrContainere(200);
    v1.SetInMiscare(false);
    v1.Afisare();

    v1.Citire();
    v1.Afisare();

    v2.Citire("Hamburg");
    v2.Afisare();



    return 0;
}