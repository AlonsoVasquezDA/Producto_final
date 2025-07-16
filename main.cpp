#include <iostream>
#include <string>
#include "estructuras.h"
#include "funciones.h"
using namespace std;


int main (){
    int op;
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
    	cout << "|                     MENU PRINCIPAL                   |" << endl;
    	cout << " ========================================================" << endl;
    	cout << "|  1.- Crear una cuenta                                |" << endl;
    	cout << "|  2.- Ingresar a una cuenta                           |" << endl;
    	cout << "|  3.- Salir                                           |" << endl;
   	 	cout << " ========================================================" << endl;
    	cout << endl;
        cout << "Ingrese una opcion: ";
        cin >> op;
        cout << endl;
        cin.ignore();

        switch(op){
            case 1: 


                break; 

            case 2: 


                break; 

            case 3:
            
            
                break; 

            default: 
                break; 

        }

    } while(op!=3);

    return 0; 
}
