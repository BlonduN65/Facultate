#include "header.h"

int main(){
    AVL* a=NULL;
    creare(a);

    cout<<"Arborele afisat este: ";
    inorder(a);
    deleteAVL(a);


}