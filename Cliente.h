#pragma once
#include <string>
#include "CuentaBancaria.h"
#include "Lista.h"

using namespace std;

class Cliente {
public:
    Cliente(const string& nombre, const string& apellido, const string& telefono, const string& email,
    const string& DNI, const string& id);
    Cliente() {}
    string descripcion() const;
    string getID();
    string getEmail();
    string getNombre();
    string getTelefono();
    string getDNI();
private:
    string Nombre;
    string Apellido;
    string Telefono;
    string Email;
    string DNI;
    string id;
    //Lista<CuentaBancaria*> *CuentasBancarias;
};