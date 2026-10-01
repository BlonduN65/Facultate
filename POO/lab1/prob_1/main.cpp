#include <iostream>
#include "siruri.h"
using namespace std;

int main(){
    const char text[]="Ana are mere";
    std::cout << "Lungimea pentru \"" << text << "\" este: " << siruri::str_length(text) << "\n";


    
    return 0;
}