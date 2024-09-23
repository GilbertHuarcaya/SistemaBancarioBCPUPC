#pragma once
#include <iostream>
#include <string>
#include <cmath> 
#include <ctime>
#include "ListaDeClientes.h"
#include "ListaDeCanales.h"
#include "ListaDeCuentasBancarias.h"
#include "ListaDeTarjetas.h"
#include "Cliente.h"
#include "Canal.h"
#include "CuentaBancaria.h"
#include "Tarjeta.h"
#include "Operacion.h"

#include <fstream>

using namespace std;

const string RESET = "\033[0m";
const string ORANGE = "\033[33m";  // 
const string BLUE = "\033[34m";    // 

void mostrarBCP() {
    cout << BLUE;
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
    ListaDeClientes* listaClientes = new ListaDeClientes();
    ListaDeCanales* listaCanales = new ListaDeCanales();
    ListaDeCuentasBancarias* listaCuentasB = new ListaDeCuentasBancarias();
    ListaDeTarjetas* listaTarjetas = new ListaDeTarjetas();
    listaClientes->cargarClientes();
    listaCanales->cargarCanales();
    listaCuentasB->cargarCuentasBancarias();
	listaTarjetas->cargarTarjetas();

    do {
        system("cls");
        mostrarBCP();
        cout << "\nMenu:\n";
        cout << "1. Gestion de Clientes\n";
        cout << "2. Gestion de Canales\n";
        cout << "3. Gestion de Cuentas Bancarias\n";
        cout << "4. Gestion de Tarjetas\n";
        cout << "5. Gestion de Operaciones\n";
        cout << "6. Gestion de Canales de Atencion\n";
        cout << "7. Gestion para un solo Cliente\n";
        cout << "8. Reportes y Consultas\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
        case 1: {
            listaClientes->menu();
            break;
        }
        case 2: {
            listaCanales->menu();
            break;
        }
        case 3: {
            listaCuentasB->menu();
            break;
        }
        case 4: {
            listaTarjetas->menu();
            break;
        }
        case 5:
            break;
        case 6:
            break;
        case 7:
            listaClientes->menuCliente();
            break;
        case 8:
            break;
        case 9:
            system("cls");
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 9);
    system("pause");
    system("cls");
    return 0;
}

