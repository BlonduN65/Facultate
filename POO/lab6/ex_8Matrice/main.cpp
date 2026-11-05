#include <iostream>
#include <cassert>
#include "header.h"
void Punctul_a(){
    Matrice m{2,3};
    assert(m.getLinii()==2);
    assert(m.getcoloane()==3);
    for(int i=0;i<m.getLinii();i++)
        for(int j=0;j<m.getcoloane();j++){
            assert(m(i,j)==0);
        }
    m(0,0)=5;
    m(1,2)=10;
    assert(m(0,0)==5);
    assert(m(1,2)==10);
    assert(m(0,1)==0);
    
    const Matrice& mConst=m;
    assert(mConst(0,0)==5);

    std::cout<<"Toate testele de la subpunctul a) au fost trecute cu succes!\n";
}

int main(){

    Punctul_a();





    return 0;

}