#include "header.h"


int main(){

    coada c;
    initCoada(c);
    int x;
    cout<<"Dati valori pana la citirea lui 0 ";
    while(cin>>x && x!=0){
        put(c,x);
    }
    while(!isEmpty(c)){
        int y=get(c);
        cout<<y<<" ";
    }
    return 0;
}