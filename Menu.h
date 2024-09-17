#pragma once
#include <iostream>
#include <string>
#include <cmath> 

using namespace std;

const string RESET = "\033[0m";
const string ORANGE = "\033[33m";  // 
const string BLUE = "\033[34m";    // 

struct Usuario
{
    int ID;
    string nombre;
    string apellido;
    string telefono;
    string email;
    string dni;
    string tipoTarjeta;
    string canal;
};

struct nodo
{
    Usuario usuario;
    nodo* siguiente;
};

class GestorUsuarios {
private:
    nodo* cabeza;

public:
    GestorUsuarios() : cabeza(nullptr) {}

    void registrarUsuario(const Usuario& usuario)
    {
        nodo* nuevoNodo = new nodo;
        nuevoNodo->usuario = usuario;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        cout << "Usuario registrado exitosamente." << endl;
    }

    void mostrarUsuarios() const
    {
        nodo* actual = cabeza;
        if (actual == nullptr) {
            cout << "No hay usuarios registrados." << endl;
        }
        else {
            while (actual != nullptr) {
                mostrarUsuario(actual->usuario);
                actual = actual->siguiente;
            }
        }
    }

    bool iniciarSesion(int id) const
    {
        nodo* actual = cabeza;
        while (actual != nullptr)
        {
            if (actual->usuario.ID == id)
            {
                cout << "Inicio de sesión exitoso." << endl;
                mostrarUsuario(actual->usuario);
                return true;
            }
            actual = actual->siguiente;
        }
        cout << "Usuario no encontrado." << endl;
        return false;
    }

    // Destructor para liberar la memoria de los nodos
    ~GestorUsuarios()
    {
        while (cabeza != nullptr)
        {
            nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

private:
    // Función auxiliar para mostrar la información de un usuario
    void mostrarUsuario(const Usuario& usuario) const
    {
        cout << "ID: " << usuario.ID << endl;
        cout << "Nombre: " << usuario.nombre << endl;
        cout << "Apellido: " << usuario.apellido << endl;
        cout << "Teléfono: " << usuario.telefono << endl;
        cout << "Email: " << usuario.email << endl;
        cout << "DNI: " << usuario.dni << endl;
        cout << "Tipo de Tarjeta: " << usuario.tipoTarjeta << endl;
        cout << "Canal: " << usuario.canal << endl;
        cout << "-----------------------------" << endl;
    }
};

Usuario crearUsuario(int id)
{
    Usuario usuario;
    usuario.ID = id;
    cout << "Nombre: ";
    cin >> usuario.nombre;
    cout << "Apellido: ";
    cin >> usuario.apellido;
    cout << "Teléfono: ";
    cin >> usuario.telefono;
    cout << "Email: ";
    cin >> usuario.email;
    cout << "DNI: ";
    cin >> usuario.dni;
    cout << "Tipo de Tarjeta: ";
    cin >> usuario.tipoTarjeta;
    cout << "Canal (por ejemplo, Web, Tienda, Móvil): ";
    cin >> usuario.canal;
    return usuario;
}

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

int mostrarUsuarios() {
    GestorUsuarios gestor;
    int opcion;
    int idContador = 1;

    mostrarBCP();

    system("pause");

    do {
        system("cls");
        cout << "Menu:\n";
        cout << "1. Registrar Usuario\n";
        cout << "2. Iniciar Sesion\n";
        cout << "3. Mostrar Usuarios\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            Usuario nuevoUsuario = crearUsuario(idContador++);
            gestor.registrarUsuario(nuevoUsuario);
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            int id;
            cout << "Ingrese su ID: ";
            cin >> id;
            gestor.iniciarSesion(id);
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            gestor.mostrarUsuarios();
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

