#pragma once
#include <string>

using namespace std;

class Cliente {
public:
    Cliente(const string& nombre, const string& direccion, const string& telefono, const string& id);
    string descripcion() const;

private:
    string nombre;
    string direccion;
    string telefono;
    string id;
};