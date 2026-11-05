#include <iostream>
#include "siruri.h"

int main() {
    // Alocăm un buffer mai mare (100 de elemente) ca să aibă loc inserarea
    char text[100] = "abef";

    std::cout << "Text initial: " << text << "\n";

    // Inserăm subșirul "cd" începând cu poziția 2
    siruri::strins(text, 2, "cd");

    std::cout << "Dupa inserare: " << text << "\n"; // Va afișa: abcdef

    return 0;
}