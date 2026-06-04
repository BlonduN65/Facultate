#include "header.h"

#include <iostream>
using namespace std;


int main(){

PriorityQueue myQueue;
    Init(myQueue); 

   
    Put(myQueue, 10, 1); 
    Put(myQueue, 50, 5); 
    Put(myQueue, 20, 2); 
    Put(myQueue, 40, 4); 

    if (!IsEmpty(myQueue)) {
        cout << "Elementul din fata (Front): " << Front(myQueue) << endl; 
    }

    cout << "Extragem elementele in ordinea prioritatii:\n";
    while (!IsEmpty(myQueue)) {
       
        cout << "Am extras: " << Get(myQueue) << endl; 
    }
    


    return 0;
}