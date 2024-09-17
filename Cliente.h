#pragma once
#include <string>

using namespace std;

class Cliente {
public:
    Cliente(const string& nombre, const string& direccion, const string& telefono, const string& id);
    string descripcion() const;
    Cliente(){}
    string getID();
    string getEmail();
    string getNombre();
    string getTelefono();
private:
    string nombre;
    string direccion;
    string telefono;
    string email;
    string DNI;
    string id;
};
string Cliente::getID(){return id;}
string Cliente::getEmail() {return email;}
string Cliente::getNombre() {return nombre;}
string Cliente::getTelefono() { return telefono;}