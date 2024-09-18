#include "pch.h"
#include "Operacion.h"

Operacion::Operacion(int id, string type, double amount, string description)
{
}
int Operacion::getId() { return id; }
string Operacion::getTipo() { return Tipo; }
double Operacion::getCantidad() { return Cantidad; }
string Operacion::getDescripcion() { return Descripcion; }
string Operacion::getFecha() { return Fecha; }