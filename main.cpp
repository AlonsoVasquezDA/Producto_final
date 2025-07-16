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
            case 1:{
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
	     }
		
            case 2: {
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
		int n = -1;
                for (int i = 0; i < totalClientes; i++) {
                    if (clientes[i].cuenta.numcu == numcu && clientes[i].dni == dni && clientes[i].cuenta.contra == contra) {
                    n = i;
                    break;
                    }
                }

                if (n != -1) {
                   int op2;
                   do {
                        system("cls");
                        cout<<endl;
                     	cout << "Hola, " << clientes[n].nom << ". Bienvenido a tu cuenta BCHP\n";
 		    	cout << endl<<endl;
                    	cout << "========================================" << endl;
                    	cout << "         MENU DE OPERACIONES            " << endl;
                    	cout << "========================================" << endl;
                    	cout << "1.- Mostrar Saldo" << endl;
                    	cout << "2.- Depositar" << endl;
                    	cout << "3.- Retirar" << endl;
                    	cout << "4.- Cambiar contrasena" << endl;
                    	cout << "5.- Transferencia" << endl;
                    	cout << "6.- Salir" << endl;
                    	cout << "========================================" << endl<<endl;
                    	cout<<"Ingrese una opcion: ";
                    	cin >> op2;

                    	double monto;
                    	switch (op2) {
                    	
                    	case 1:
                            cout << "Saldo actual: S/ " << clientes[n].cuenta.din << endl;
                            system("pause");
                             break;
                        
                    	case 2:
                            cout << "Ingrese el monto a depositar: ";
                            cin >> monto;
                            if (monto > 0) {
                            	clientes[n].cuenta.din += monto;
                            	cout << "Deposito exitoso.\n";
                            } else {
                            	cout << "Monto invalido.\n";
                            }
                            system("pause");
                            break;
                        
                        case 3:
                            cout << "Ingrese el monto a retirar: ";
                            cin >> monto;
                            if (monto > 0 && monto <= clientes[n].cuenta.din) {
                            	clientes[n].cuenta.din -= monto;
                            	cout << "\n==============================================" << endl;
                            	cout << "               BOLETA DE RETIRO               " << endl;
                            	cout << "==============================================" << endl;
                            	cout << "Nombre del titular : " << clientes[n].nom << endl;
                            	cout << "DNI                : " << clientes[n].dni << endl;
                            	cout << "Nro. de cuenta     : " << clientes[n].cuenta.numcu << endl;
                            	cout << "Monto retirado     : S/ " << monto << endl;
                            	cout << "Saldo restante     : S/ " << clientes[n].cuenta.din << endl;
                            	cout << "==============================================" << endl;
                            	cout << "La boleta tambien fue enviada a tu correo: \n";
                            	cout << clientes[n].correo.user << "@" << clientes[n].correo.domain << endl;
                            	cout << "==============================================" << endl << endl;    
                            } else {
                            	cout << "Fondos insuficientes o monto invalido.\n";
                            }
                            system("pause");
                            break;
                        
                        case 4: {
                            cin.ignore();
                            string actual, nueva;
                            cout << "Ingrese su contrasena actual: ";
                            getline(cin, actual);
                            if (actual == clientes[n].cuenta.contra) {
                        	cout << "Ingrese la nueva contrasena(8-16 caracteres): ";
                            	getline(cin, nueva);
                            
                            	while(nueva.length() <8 || nueva.length()>16){
                            	     cout<<"La contraseña debe tener entre 8 y 16 caracteres.\n";
                            	     cout<<"Ingrese nuevamente: ";
                            	     getline(cin,nueva);
							}
                            	     clientes[n].cuenta.contra = nueva;
                            	     cout<<"\n==================================\n";
                           	     cout<<"Contrasena actualizada con exito.\n";
                            	     cout<<"==================================\n";
                             } else {
                            cout << "Contrasena incorrecta.\n";
                             }
                             system("pause");
                             break;
                        }
                    
                        case 5: {
			    int cuentaDestino;
                            cout << "Ingrese el numero de cuenta destino: ";
                            cin >> cuentaDestino;
                            int idxDestino = -1;
                            for (int i = 0; i < totalClientes; i++) {
                          	if (clientes[i].cuenta.numcu == cuentaDestino && i != n) {
                               		idxDestino = i;
                               	 break;
                                }
                             }
                             if (idxDestino == -1) {
                                 cout << "Cuenta destino no encontrada o invalida.\n";
                             } else {
                                cout << "Ingrese el monto a transferir: ";
                        	cin >> monto;
                        	if (monto > 0 && monto <= clientes[n].cuenta.din) {
                            		clientes[n].cuenta.din -= monto;
                           		clientes[idxDestino].cuenta.din += monto;
                            		system("cls");
                           		cout <<"===========================\n";
                            		cout <<"   Transferencia exitosa   \n";
                            		cout <<"===========================\n\n\n";
                            		cout <<"===========================================\n";
                            		cout <<"           BOLETA DE TRANSFERENCIA          \n";
                            		cout <<"===========================================\n";
                            		cout <<"ORIGEN\n";
                            		cout <<"Numero de Cuenta: "<<clientes[n].cuenta.numcu<<endl;
                           		cout <<"Titular: "<<clientes[n].nom<<endl;
                            		cout <<"-------------------------------------------\n";
                            		cout <<"DESTINO\n";
                            		cout <<"Beneficiario: "<<clientes[idxDestino].nom<<endl;
                            		cout <<"Numero de cuenta: "<<clientes[idxDestino].cuenta.numcu<<endl;
                            		cout <<"-------------------------------------------\n";
                            		cout <<"DETALLES\n";
                            		cout <<"Monto transferido: S/ " << monto << "\n\n";
                            		cout <<"===========================================\n";
                            		cout << "La boleta tambien fue enviada a tu correo: "<<endl;
                            		cout << clientes[n].correo.user << "@" << clientes[n].correo.domain << endl;
                            		cout << "============================================"<< endl << endl;  
                             	} else {
                                    	cout <<"=======================================\n";
                                	cout << "Fondos insuficientes o monto invalido.\n";
                                	cout <<"=======================================\n";
                                 }
                              }
                              system("pause");
                              break;
                        }
                           
                        case 6: {
                    	   char ops2;
                           cout << "Esta seguro de salir? (S/N): ";
                           cin >> ops2;
                           if (ops2 == 'S' || ops2 == 's') {
                         	cout << "Regresando al menu principal. ";
                            } else {
                          	op2 = -1;
                            }
                            break;
                        }
                        
                        default:
                           cout << "========================================" << endl;
        	           cout << "          Opcion invalida               " << endl;
            	           cout << "========================================" << endl;
                           system("pause");
                           break;
                         }
                    } while (op2 != 6);
                } else {
                    cout << endl<<endl;
                    cout << "========================================" << endl;
                    cout << "     DNI o contrasena incorrectos       " << endl;
                    cout << "========================================" << endl;
                    system("pause");
                   }
               break; 
	    }
		
            case 3:{
	         char ops;
                 cout << "Esta seguro de salir? (S/N): ";
                 cin >> ops;
                 if (ops == 'S' || ops == 's') {
                   cout << endl<<endl;
                   cout << "========================================" << endl;
            	   cout << "  Gracias por confiar en BANCO BCHP      " << endl;
            	   cout << "========================================" << endl<<endl;
                   } else {
                    op = -1;
                   }
                break; 
	       }
		
            default: 
		 cout << endl<<endl;
                 cout << "========================================" << endl;
                 cout << "          Opcion invalida               " << endl;
                 cout << "========================================" << endl;
                 system("pause");   
                break;
        } 

    } while(op!=3);

    return 0; 
}
