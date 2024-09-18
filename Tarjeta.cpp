#include "pch.h"
#include "Tarjeta.h"

Tarjeta::Tarjeta(int id, bool Activado, string Codigo, int CVV, double saldo, string TipoTarjeta, string Divisa, string FechaCreacion, string FechaCaducidad, string NombreCliente, string ApellidoCliente)
{
}

int Tarjeta::getId() { return id;}
int Tarjeta::getCVV() { return CVV;}
string Tarjeta::getCodigo() { return Codigo;}
string Tarjeta::getTipoTarjeta() { return TipoTarjeta;}
double Tarjeta::getSaldo() { return saldo;}
string Tarjeta::getDivisa() { return Divisa;}
string Tarjeta::getFechaCreacion() { return FechaCreacion;}
string Tarjeta::getFechaCaducidad() { return FechaCaducidad;}
bool Tarjeta::getActivado() { return Activado;}
string Tarjeta::getNombreCliente() { return NombreCliente;}
string Tarjeta::getApellidoCliente() { return ApellidoCliente;}

void Tarjeta::updateAmount()
{
	this->saldo = saldo;
}

void Tarjeta::activate()
{
	this->Activado = true;
}

void Tarjeta::deactivate()
{
	this->Activado = false;
}

