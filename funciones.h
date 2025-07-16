#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"

void leerCorreo(CORREO &c, string u, string d);
void leerCuenta(CUENTA &c, int m, string p, double din);
void leerDatos(DATOS &c, string n, int e, string d, long long nu, CORREO em, CUENTA cu);
void mostrarDatos(DATOS &c);

#endif 