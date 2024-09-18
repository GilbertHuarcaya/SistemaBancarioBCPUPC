#include "pch.h"
#include "Tarjeta.h"

Tarjeta::Tarjeta(string id, string Codigo, int CVV, bool Activado, ETipoTarjeta TipoTarjeta, EDivisa Divisa, double saldo, string FechaCreacion, string FechaCaducidad,
string NombreCliente, string ApellidoCliente, int idCuentaBancaria,
int idCliente): id(id),Codigo(Codigo),CVV(CVV),Activado(Activado),TipoTarjeta(TipoTarjeta),Divisa(Divisa),saldo(saldo),
FechaCreacion(FechaCreacion),FechaCaducidad(FechaCaducidad),NombreCliente(NombreCliente),ApellidoCliente(ApellidoCliente),idCuentaBancaria(idCuentaBancaria),
idCliente(idCliente){}

string Tarjeta::getId() { return id; }
int Tarjeta::getCVV() { return CVV; }
string Tarjeta::getCodigo() { return Codigo; }
ETipoTarjeta Tarjeta::getTipoTarjeta() { return TipoTarjeta; }
double Tarjeta::getSaldo() { return saldo; }
EDivisa Tarjeta::getDivisa() { return Divisa; }
string Tarjeta::getFechaCreacion() { return FechaCreacion; }
string Tarjeta::getFechaCaducidad() { return FechaCaducidad; }
bool Tarjeta::getActivado() { return Activado; }
string Tarjeta::getNombreCliente() { return NombreCliente; }
string Tarjeta::getApellidoCliente() { return ApellidoCliente; }

int Tarjeta::getIdCliente()
{
	return idCliente;
}

int Tarjeta::getIdCuentaBancaria()
{
	return idCuentaBancaria;
}

void Tarjeta::updateAmount()
{
	this->saldo = saldo;
}

bool Tarjeta::validateTarjeta(string Codigo)
{
	return this->Codigo == Codigo ? true : false;
}

bool Tarjeta::validateCVV(int CVV)
{
	return this->CVV == CVV ? true : false;
}

bool Tarjeta::validateFechaCaducidad()
{
	return false; //cambiar tipo ed dato para validar la fecha segun cuando se filtre y valide
}

void Tarjeta::Activar(){this->Activado = true;}

void Tarjeta::Desactivar(){this->Activado = false;}
