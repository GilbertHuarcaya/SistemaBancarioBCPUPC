#pragma once
#include <string>
#include "CuentaBancaria.h"
#include "Lista.h"

using namespace std;

class Cliente {
private:
    string nombre;
    string apellido;
    string direccion;
    string telefono;
    string email;
    string DNI;
public:
	Cliente();
    Cliente(string nombre,  string apellido,  string direccion,  string telefono,  string email,  string DNI);
    string descripcion() ;
    string getEmail();
    string getNombre();
    string getApellido();
    string getTelefono();
    string getDireccion();
    string getDNI();
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void setEmail(string email);
    void setDNI(string DNI);
};
