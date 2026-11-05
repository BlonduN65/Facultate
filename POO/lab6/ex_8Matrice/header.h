#ifndef HEADER_H_
#define HEADER_H_

class Matrice {
private:
    int m; // liniile
    int n; // coloanele
    int* elemente;

public:
    Matrice(int m, int n);
    ~Matrice();

    int getLinii() const;
    int getcoloane() const;

    int& operator()(int i, int j);       // varianta non-const
    int operator()(int i, int j) const;  // varianta const
};

#endif // Fara punct si virgula la final!