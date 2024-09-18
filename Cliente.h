#pragma once
#include <string>
#include "Lista.h"
#include "CuentaBancaria.h"

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
    string nombre;
    string apellido;
    string telefono;
    string email;
    string DNI;
    string id;
    Lista<CuentaBancaria*> CuentasBancarias;

};
string Cliente::getID(){return id;}
string Cliente::getEmail() {return email;}
string Cliente::getNombre() {return nombre;}
string Cliente::getTelefono() { return telefono;}
string Cliente::getDNI() { return DNI;}