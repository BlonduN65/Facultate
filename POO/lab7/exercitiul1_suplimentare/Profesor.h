#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include <memory>

class Departament; // Declarație anticipată[cite: 10]

class Profesor
{
    std::string nume;
    std::weak_ptr<Departament> departament; //[cite: 19]
public:
    static inline int existenti = 0;

    explicit Profesor(const std::string& n);
    Profesor(const Profesor&) = delete;
    Profesor& operator=(const Profesor&) = delete;
    ~Profesor();

    const std::string& getNume() const { return nume; }
    std::shared_ptr<Departament> getDepartament() const; //[cite: 18]
    void setDepartament(const std::shared_ptr<Departament>& d); //[cite: 18]
    void afiseaza() const;
    static int getExistenti() { return existenti; }
};

#endif