#include "pch.h"
#include "Sede.h"

Sede::Sede(int id, string name, string address, string phone)
{
}

string Sede::getId() { return id; }
string Sede::getNombre() { return Nombre; }
string Sede::getDireccion() { return Direccion; }
string Sede::getTelefono() { return Telefono; }
void Sede::updateName(string name) { this->Nombre = name; }
void Sede::updateAdress(string adress) { this->Direccion = adress; }
void Sede::updatePhone(string phone) { this->Telefono = phone; }
void Sede::Activar() { this->Activado = true; }
void Sede::Desactivar() { this->Activado = false; }
