#pragma once
#include <iostream>
#include <string>
#include <cmath> 
#include <ctime>
#include "ListaDeClientes.h"
#include "ListaDeCanales.h"

using namespace std;

const string RESET = "\033[0m";
const string ORANGE = "\033[33m";  // 
const string BLUE = "\033[34m";    // 

void mostrarBCP() {
    cout << ORANGE;
    cout << R"(
BBBBBBBBBBBBBBBBB     CCCCCCCCCCCCC     PPPPPPPPPPPPPPPPP  
B::::::::::::::::B  CCC::::::::::::C    PP:::::::::::::PP  
B::::::BBBBBB:::::BCC:::::::::::::::C   PP::::::PPPPPP:::::P
BB:::::B     B:::::BCC:::::CCCCCCCC::::C  P:::::P     P:::::P
  B::::B     B:::::BC:::::C       CCCCC  P:::::P     P:::::P
  B::::B     B:::::BC:::::C              P:::::P     P:::::P
  B::::BBBBBB:::::B C:::::C              P:::::PPPPPP:::::P 
  B:::::::::::::BB  C:::::C              P:::::::::::::PP  
  B::::BBBBBB:::::B C:::::C              P::::::PPP 
  B::::B     B:::::BC:::::C              P::::::PPP
  B::::B     B:::::BC:::::C       CCCCCC P:::::.PPP
  B::::B     B:::::B C:::::CCCCCCCC::::CPP::::::PPP
BB:::::BBBBBB::::::B  CC:::::::::::::::CPP::::::PPP 
B:::::::::::::::::B    CCC::::::::::::P PP::::::PPP   
BBBBBBBBBBBBBBBBBB       CCCCCCCCCCCCC   PPPPPPPPPP    
    )" << RESET;
}

int mostrarMenuPrincipal() {
    int opcion;
    int idContador = 1;

    ListaDeClientes listaClientes;
    ListaDeCanales listaCanales;
    mostrarBCP();

    system("pause");

    do {
        system("cls");
        cout << "Menu:\n";
        cout << "1. Menu de clientes\n";
        cout << "2. Menu de canales\n";
        cout << "3. Otro Menu\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
        case 1: {
            listaClientes.menu();
            system("pause");
            break;
        }
        case 2: {
            listaCanales.menu();
            system("pause");
            break;
        }
        case 3: {
            system("pause");
            break;
        }
        case 4:
            system("cls");
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    system("pause");
    return 0;
}

