#include "pch.h"
#include "Tarjeta.h"

Tarjeta::Tarjeta(string id, string Codigo, int CVV, bool Activado, string TipoTarjeta, string Divisa, double saldo, string FechaCreacion, string FechaCaducidad,
string NombreCliente, string ApellidoCliente): id(id),Codigo(Codigo),CVV(CVV),Activado(Activado),TipoTarjeta(TipoTarjeta),Divisa(Divisa),saldo(saldo),
FechaCreacion(FechaCreacion),FechaCaducidad(FechaCaducidad),NombreCliente(NombreCliente),ApellidoCliente(ApellidoCliente){}

string Tarjeta::getId() { return id; }
int Tarjeta::getCVV() { return CVV; }
string Tarjeta::getCodigo() { return Codigo; }
string Tarjeta::getTipoTarjeta() { return TipoTarjeta; }
double Tarjeta::getSaldo() { return saldo; }
string Tarjeta::getDivisa() { return Divisa; }
string Tarjeta::getFechaCreacion() { return FechaCreacion; }
string Tarjeta::getFechaCaducidad() { return FechaCaducidad; }
bool Tarjeta::getActivado() { return Activado; }
string Tarjeta::getNombreCliente() { return NombreCliente; }
string Tarjeta::getApellidoCliente() { return ApellidoCliente; }

void Tarjeta::updateAmount()
{
	this->saldo = saldo;
}

void Tarjeta::Activar(){this->Activado = true;}

void Tarjeta::Desactivar(){this->Activado = false;}
