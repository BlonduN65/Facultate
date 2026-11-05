#include <iostream>
#include <fstream>
#include <format>



int main(){
    std::ifstream fin("numere.txt");
    if(!fin){
        std::cerr<<"Eroare fisierul nu s-a deschis\n";
        return 1;
    }
    int n=0;
    fin>>n;
    if(n<1 || n>100){
        std::cerr<<"Eroare valoarea lui n este mai mare decat intervalul ";
        fin.close();
        return 1;
    }
    int v[100];
    int suma=0;
    for(int i=0;i<n;i++){
        fin>>v[i];
        suma+=v[i];
    }
    fin.close();
    double medie=static_cast<double>(suma)/n;
    std::ofstream fout("rezultat.txt");
    if(!fout){
        std::cerr<<"Eroare fisierul de output nu s a putut creea!";
        return 1;
    }

    fout<<"Suma: "<<suma<<"\n";
    fout<<std:: format("Medie : {:.2f}\n",medie);
    fout.close();

    return 0;
}