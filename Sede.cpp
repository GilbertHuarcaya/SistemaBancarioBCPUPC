#include "pch.h"
#include "Sede.h"
#include "string"
using namespace std;

Sede::Sede(std::string Nombre, std::string Direccion, std::string Telefono, bool Activado)
{
	this->Nombre = Nombre;
	this->Direccion = Direccion;
	this->Telefono = Telefono;
	this->Activado = true;
}

string Sede::getNombre() { return Nombre; }
string Sede::getDireccion() { return Direccion; }
string Sede::getTelefono() { return Telefono; }
void Sede::updateName(string name) { this->Nombre = Nombre; }
void Sede::updateAdress(string adress) { this->Direccion = Direccion; }
void Sede::updatePhone(string phone) { this->Telefono = Telefono; }
void Sede::Activar() { this->Activado = true; }
void Sede::Desactivar() { this->Activado = false; }
