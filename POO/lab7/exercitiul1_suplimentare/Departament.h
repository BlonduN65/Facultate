#ifndef DEPARTAMENT_H
#define DEPARTAMENT_H

#include <string>
#include <vector>
#include <memory>
#include "Profesor.h"

class Departament
{
    std::string nume;
    std::vector<std::shared_ptr<Profesor>> profesori; //
public:
    static inline int existente = 0;

    explicit Departament(const std::string& n);
    Departament(const Departament&) = delete;
    Departament& operator=(const Departament&) = delete;
    ~Departament();

    const std::string& getNume() const { return nume; }
    int getNrProfesori() const { return static_cast<int>(profesori.size()); }
    void adauga(const std::shared_ptr<Profesor>& p); //[cite: 18]
    Profesor* cauta(const std::string& n) const; // Returnează tot un Profesor (cu get())[cite: 17]
    void afiseaza() const;
    static int getExistente() { return existente; }
};

#endif