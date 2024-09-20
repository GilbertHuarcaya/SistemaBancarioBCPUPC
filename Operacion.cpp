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
string Operacion::getEstado() { return Estado; }
int Operacion::getIdCOrigen() { return idCuentaOrigen; }
int Operacion::getIdCDestino() { return idCuentaDestino; }
string Operacion::Datos() {
	return "Id: " + to_string(id) + "Tipo de Operacion: " + Tipo + "Cantidad: " + to_string(Cantidad) +
		"\nDescripcion: " + Descripcion +
		"\nFecha: " + Fecha + "Estado: " + Estado +
		"\nId Cuenta Origen: " + to_string(idCuentaOrigen) + "Id Cuenta Destino: " + to_string(idCuentaDestino);
}
