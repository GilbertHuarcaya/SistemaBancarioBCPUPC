#include "pch.h"
#include "Sede.h"

Sede(int id, string Nombre, string Direccion, string Telefono, bool Activado);
{
	this->id = id;
	this->Nombre = Nombre;
	this->Direccion = Direccion;
	this->Telefono = Telefono;
	this->Activado = true;
}

string Sede::getId() { return id; }
string Sede::getNombre() { return Nombre; }
string Sede::getDireccion() { return Direccion; }
string Sede::getTelefono() { return Telefono; }
void Sede::updateName(string name) { this->Nombre = Nombre; }
void Sede::updateAdress(string adress) { this->Direccion = Direccion; }
void Sede::updatePhone(string phone) { this->Telefono = Telefono; }
void Sede::Activar() { this->Activado = true; }
void Sede::Desactivar() { this->Activado = false; }
