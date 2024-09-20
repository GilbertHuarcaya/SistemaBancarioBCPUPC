#include "pch.h"
#include "Cliente.h"

Cliente::Cliente()
{
	nombre = "";
	apellido = "";
	direccion = "";
	telefono = "";
	email = "";
	DNI = "";
}

Cliente::Cliente( string nombre,  string apellido,  string direccion,  string telefono,  string email,  string DNI)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->direccion = direccion;
	this->telefono = telefono;
	this->email = email;
	this->DNI = DNI;
}

string Cliente::descripcion()  {
	return "Nombre: " + nombre + "\nDireccion: " +
		direccion + "\nTelefono: " + telefono + "\nEmail: " + email + "\nApellido: " + apellido + 
		"\nDNI:" + DNI;
}

string Cliente::getEmail() { return email; }
string Cliente::getNombre() { return nombre; }
string Cliente::getApellido()
{
    return apellido;
}
string Cliente::getTelefono() { return telefono; }

string Cliente::getDireccion()
{
	return direccion;
}

string Cliente::getDNI()
{
	return DNI;
}

void Cliente::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Cliente::setApellido(string apellido)
{
	this->apellido = apellido;
}

void Cliente::setDireccion(string direccion)
{
	this->direccion = direccion;
}

void Cliente::setTelefono(string telefono)
{
	this->telefono = telefono;
}

void Cliente::setEmail(string email)
{
	this->email = email;
}

void Cliente::setDNI(string DNI)
{
	this->DNI = DNI;
}

