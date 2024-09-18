#include "pch.h"
#include "Cliente.h"

Cliente::Cliente(const string& nombre,const string& apellido, const string& telefono, const string& email, const string& DNI, const string& id)
    : Nombre(nombre), Apellido(apellido), Telefono(telefono), id(id), Email(email),DNI(DNI){}

string Cliente::descripcion() const {
    return "Nombre: " + Nombre + "\nApellido: " + Apellido + "\nTelefono: " + Telefono +"\nEmail: "+ Email + "\nID: " + id + "\n";
}
string Cliente::getID() { return id; }
string Cliente::getEmail() { return Email; }
string Cliente::getNombre() { return Nombre; }
string Cliente::getTelefono() { return Telefono; }
string Cliente::getDNI() { return DNI; }