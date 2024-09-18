#include "pch.h"
#include "Operacion.h"

Operacion::Operacion(string Tipo,
    double Cantidad,
    string Descripcion,
    string Fecha,
    int idCuentaOrigen,
    int idCuentaDestino,
    string Estado)
{
	this->Tipo = Tipo;
	this->Cantidad = Cantidad;
	this->Descripcion = Descripcion;
	this->Fecha = Fecha;
	this->idCuentaOrigen = idCuentaOrigen;
	this->idCuentaDestino = idCuentaDestino;
	this->Estado = Estado;

}
int Operacion::getId() { return id; }
string Operacion::getTipo() { return Tipo; }
double Operacion::getCantidad() { return Cantidad; }
string Operacion::getDescripcion() { return Descripcion; }
string Operacion::getFecha() { return Fecha; }
