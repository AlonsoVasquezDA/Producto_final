#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>
using namespace std;

struct CORREO {
    string user;
    string domain;
};

struct CUENTA {
    int numcu;
    string contra;
    double din;
};

struct DATOS {
    string nom;
    int edad;
    string dni;
    long long cel;
    CORREO correo;
    CUENTA cuenta;
};

#endif 