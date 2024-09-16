#include "pch.h"
#include "Cliente.h"

Cliente::Cliente(const string& nombre, const string& direccion, const string& telefono, const string& id)
    : nombre(nombre), direccion(direccion), telefono(telefono), id(id) {}

string Cliente::descripcion() const {
    return "Nombre: " + nombre + "\nDireccion: " + direccion + "\nTelefono: " + telefono + "\nID: " + id + "\n";
}