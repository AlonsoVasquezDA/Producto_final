#include <iostream>
#include <string>
#include "estructuras.h"
#include "funciones.h"
using namespace std;


int main (){
    int op;
    DATOS clientes[100];
    int totalClientes = 0;
    string nom, user, domain, contra,dni;
    int edad, numcu;
    long long cel;
    double din = 0.0;
    CORREO email;
    CUENTA cuenta;

    cout << " ======================================================================\n";
    cout << "||                                                                    ||\n";
    cout << "||                   Bienvenido al banco BCHP                         ||\n";
    cout << "||                 Presione Enter para ingresar                       ||\n";
    cout << "||                                                                    ||\n";
    cout << " ======================================================================\n";
    cin.get(); 
    
    do{
        system("cls");
	cout << " ========================================================" << endl;
    	cout << "|                     MENU PRINCIPAL                    |" << endl;
    	cout << " ========================================================" << endl;
    	cout << "|  1.- Crear una cuenta                                 |" << endl;
    	cout << "|  2.- Ingresar a una cuenta                            |" << endl;
    	cout << "|  3.- Salir                                            |" << endl;
   	 cout << " ========================================================" << endl;
    	cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;
        cout << endl;
        cin.ignore();

        switch(op){
            case 1:
                system("cls");
                if (totalClientes >= 100) {
  				    cout << endl<<endl;
                    cout << "============================================" << endl;
                    cout << "  Lo sentimos, limite de cuentas alcanzado  " << endl;
                    cout << "============================================" << endl<<endl;
                    system("pause");
                    break;
                } 
                cout << endl;
                cout << "========================================" << endl;
                cout << "       REGISTRO DE NUEVA CUENTA         " << endl;
                cout << "========================================" << endl<<endl;
                cout << "Ingrese su nombre: ";
                getline(cin, nom);

                cout << "Ingrese su edad: ";
                cin >> edad;
                while (edad < 18) {
                    cout << "Debe ser mayor de edad para crear una cuenta.\n";
                    cout << "Ingrese nuevamente su edad: ";
                    cin >> edad;
                    cin.ignore();
                }

                cout << "Ingrese su DNI: ";
                cin >> dni;
                while (dni.length() < 8 || dni.length() > 8) {
                    cout << "El DNI debe tener exactamente 8 digitos.\nIngrese nuevamente: ";
                    cin >> dni;
                }

                cout << "Ingrese su numero telefonico: ";
                cin >> cel;
                while (cel < 900000000 || cel > 999999999) {
                    cout << "El numero debe tener 9 digitos y comenzar con 9.\nIngrese nuevamente: ";
                    cin >> cel;
                }

                cout << "Ingrese el correo electronico (usuario@dominio):\n";
                cout << "\tUsuario: ";
                cin >> user;
                cout << "\tDominio: ";
                cin >> domain;

                cout << "Genere una contrasena (8-16 caracteres): ";
                cin >> contra;
                while (contra.length() < 8 || contra.length() > 16) {
               	    cout << "La contrasena debe tener entre 8 y 16 caracteres.\n";
        		    cout << "Ingrese nuevamente: ";
        		    cin >> contra;
    		    }

                cout << "Ingrese su numero de cuenta (4 digitos): ";
                cin >> numcu;
                while (numcu < 1000 || numcu > 9999) {
                    cout << "El numero de cuenta debe tener 4 digitos.\nIngrese nuevamente: ";
                    cin >> numcu;
                }
                
                int repetido = 0;
                for (int i = 0; i < totalClientes; i++) {
                    if (clientes[i].cuenta.numcu == numcu) {
                        repetido++;
                    }
                }

                while (repetido > 0) {
                    cout << "Ese numero de cuenta ya esta registrado."<<endl;
				    cout << "Ingrese uno diferente: ";
                    cin >> numcu;
                    repetido = 0;
                    for (int i = 0; i < totalClientes; i++) {
                        if (clientes[i].cuenta.numcu == numcu) {
                            repetido++;
                        }
                    }
                }

                leerCorreo(email, user, domain);
                leerCuenta(cuenta, numcu, contra, din);
                leerDatos(clientes[totalClientes], nom, edad, dni, cel, email, cuenta);

                totalClientes++;
                system("cls");
                cout << "========================================" << endl;
                cout << "     Cuenta creada exitosamente!        " << endl;
                cout << "========================================" << endl<<endl;
                mostrarDatos(clientes[totalClientes - 1]);
                system("pause");

                break; 

            case 2: 
		system("cls");
              	cout << endl<<endl<<endl;
           	cout << "========================================" << endl;
           	cout << "       INGRESO A CUENTA EXISTENTE        " << endl;
            	cout << "========================================" << endl;
            	cout << "Ingrese su numero de cuenta: ";
            	cin >> numcu;
            	cout << "Ingrese su DNI: ";
            	cin >> dni;
            	cout << "Ingrese su contrasena: ";
            	cin >> contra;


                break; 

            case 3:
            
            
                break; 

            default: 
                break; 

        }

    } while(op!=3);

    return 0; 
}
