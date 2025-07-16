#include "funciones.h"
#include <iostream>
using namespace std;

void leerCorreo(CORREO &c, string u, string d) {
    c.user = u;
    c.domain = d;
}

void leerCuenta(CUENTA &c, int m, string p, double din) {
    c.numcu = m;
    c.contra = p;
    c.din = din;
}

void leerDatos(DATOS &c, string n, int e, string d, long long nu, CORREO em, CUENTA cu) {
    c.nom = n;
    c.edad = e;
    c.dni = d;
    c.cel = nu;
    c.correo = em;
    c.cuenta = cu;
}

void mostrarDatos(DATOS &c) {
    cout << endl;
    cout << "========================================" << endl;
    cout << "         DATOS REGISTRADOS              " << endl;
    cout << "========================================" << endl;
    cout << "Nombre: " << c.nom << endl;
    cout << "Edad: " << c.edad << endl;
    cout << "DNI: " << c.dni << endl;
    cout << "Celular: " << c.cel << endl;
    cout << "Correo: " << c.correo.user << "@" << c.correo.domain << endl;
    cout << "Numero de Cuenta: " << c.cuenta.numcu << endl;
    cout << "========================================" << endl;
}