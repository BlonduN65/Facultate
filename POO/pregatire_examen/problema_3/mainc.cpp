#include "header.h"
#include <iostream>

using namespace std;
using namespace Auto;

int main() {
    // =========================================================================
    // CERINTA 1: Instantiati obiecte de tip Automobil astfel incat sa fie 
    // apelati toti constructorii definiti (inclusiv cei din baza).[cite: 604]
    // =========================================================================
    cout << "=== 1. APELARE CONSTRUCTORI AUTOMOBIL ===\n";
    Automobil a1;                                       // Constructor cu parametri (valori default)[cite: 604]
    Automobil a2("Dacia Duster", 180.5, 1850.0, diesel);// Constructor cu parametri expliciti[cite: 604]
    Automobil a3(a2);                                   // Constructor de copiere[cite: 604]

    // =========================================================================
    // CERINTA 2: Puneti in evidenta apelarea functiilor operator+=() si 
    // operator-- pentru cele doua clase.[cite: 604]
    // =========================================================================
    cout << "\n=== 2. TESTARE OPERATOR+= SI OPERATOR-- ===\n";
    
    // Testare pe clasa de baza Vehicul
    Vehicul v1("Audi", 240.0);
    v1 += " RS6";   // Concateneaza " RS6" la marca -> "Audi RS6"[cite: 604]
    v1--;           // Scade vitezaMaxima cu 1 -> 239.0[cite: 604]
    v1.Afisare();

    // Testare pe clasa derivata Automobil
    a2 += 150.0;    // Creste masaMaxima cu 150 -> 2000.0[cite: 604]
    a2--;           // Scade masaMaxima cu 1 -> 1999.0[cite: 604]
    a2.Afisare();

    // =========================================================================
    // CERINTA 3: Polimorfism la run-time prin intermediul unui pointer la 
    // clasa de baza (Vehicul*), initializat atat cu adrese ale bazei, 
    // cat si cu adrese ale derivatei.[cite: 604]
    // =========================================================================
    cout << "\n=== 3. TESTARE POLIMORFISM LA RUN-TIME ===\n";
    Vehicul* ptr = nullptr;

    // Cazul A: Pointerul pointeaza catre un obiect de tip Vehicul[cite: 604]
    cout << "--- Pointerul pointeaza catre Vehicul ---\n";
    ptr = &v1;
    ptr->Citire();  // Apeleaza Vehicul::Citire()
    ptr->Afisare(); // Apeleaza Vehicul::Afisare()

    // Cazul B: Pointerul pointeaza catre un obiect de tip Automobil[cite: 604]
    cout << "\n--- Pointerul pointeaza catre Automobil ---\n";
    ptr = &a1;
    ptr->Citire();  // Apeleaza Automobil::Citire()
    ptr->Afisare(); // Apeleaza Automobil::Afisare()

    cout << "\n=== 4. FINAL PROGRAM ===\n";
    return 0;
}