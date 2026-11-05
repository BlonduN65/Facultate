#include "header.h"
#include <iostream>

int *citesteTablou(int *n){
    if(n==nullptr)
        {
            return nullptr;
        }
    std::cout<<"Introduceti numarul de elemente de la tastura";
    std::cin>>*n;
    if(*n<=0){
        std::cout<<"Nu este suficient spatiu ,alocare esuata!";
        return nullptr;
    }
    int *v=new int [*n];
    std::cout<<"Introduceti cele "<<*n<<"elemente";
    for(int i=0;i<*n;i++){
        std::cin>>*(v+i);
    }

}