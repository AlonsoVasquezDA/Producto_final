#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"

void leerCorreo(CORREO &, string , string );
void leerCuenta(CUENTA &, int , string , double );
void leerDatos(DATOS &, string , int , string , long long , CORREO , CUENTA );
void mostrarDatos(DATOS &);

#endif 
