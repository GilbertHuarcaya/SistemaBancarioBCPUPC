#include "pch.h"
#include "Tarjeta.h"
#include "DatosRandom.h"

Tarjeta::Tarjeta(string Codigo, int CVV, bool Activado, ETipoTarjeta TipoTarjeta, EDivisa Divisa, double saldo, tm* FechaCreacion, tm* FechaCaducidad,
int FechaCreacion_mes, int FechaCreacion_anio, int FechaCaducidad_mes, int FechaCaducidad_anio, string NombreCliente, string ApellidoCliente, int idCuentaBancaria,
int idCliente): Codigo(Codigo),CVV(CVV),Activado(Activado),TipoTarjeta(TipoTarjeta),Divisa(Divisa),saldo(saldo),
FechaCreacion(FechaCreacion),FechaCaducidad(FechaCaducidad), FechaCreacion_mes(FechaCreacion_mes), FechaCreacion_anio(FechaCreacion_anio),
FechaCaducidad_mes(FechaCaducidad_mes),FechaCaducidad_anio(FechaCaducidad_anio),NombreCliente(NombreCliente),ApellidoCliente(ApellidoCliente),
idCuentaBancaria(idCuentaBancaria),idCliente(idCliente){}

Tarjeta::Tarjeta(string Codigo, int CVV, bool Activado, int TipoTarjeta, int Divisa, double saldo,tm* FechaCreacion, tm* FechaCaducidad, 
	int FechaCreacion_mes, int FechaCreacion_anio, int FechaCaducidad_mes, int FechaCaducidad_anio, string NombreCliente, string ApellidoCliente,
	int idCuentaBancaria, int idCliente)
{
	this->Codigo = Codigo; this->CVV = CVV;
	this->Activado = Activado; this->saldo = saldo;
	this->FechaCreacion = FechaCreacion; this->FechaCaducidad = FechaCaducidad;
	this->NombreCliente = NombreCliente; this->ApellidoCliente = ApellidoCliente;
	this->idCuentaBancaria = idCuentaBancaria; this->idCliente = idCliente;
	this->FechaCreacion_mes = FechaCreacion_mes;
	this->FechaCreacion_anio = FechaCreacion_anio;
	this->FechaCaducidad_mes = FechaCaducidad_mes;
	this->FechaCaducidad_anio = FechaCaducidad_anio;
	ETipoTarjeta TipoTarjetaEnum;
	EDivisa DivisaEnum;
	switch (TipoTarjeta) {
	case 1:
		TipoTarjetaEnum = VISA;
		break;
	case 2:
		TipoTarjetaEnum = AMERICANEXPRESS;
		break;
	default:
		TipoTarjetaEnum = VISA;
		break;
	}
	switch (Divisa) {
	case 1:
		DivisaEnum = SOLES;
		break;
	case 2:
		DivisaEnum = DOLARES;
		break;
	default:
		DivisaEnum = SOLES;
		break;
	}
	this->TipoTarjeta = TipoTarjetaEnum;
	this->Divisa = DivisaEnum;
}

int Tarjeta::getCVV() { return CVV; }
string Tarjeta::getCodigo() { return Codigo; }
ETipoTarjeta Tarjeta::getTipoTarjeta() { return TipoTarjeta; }
double Tarjeta::getSaldo() { return saldo; }
EDivisa Tarjeta::getDivisa() { return Divisa; }
tm* Tarjeta::getFechaCreacion() { return FechaCreacion; }
tm* Tarjeta::getFechaCaducidad() { return FechaCaducidad; }
int Tarjeta::getFechaCreacion_mes() { return FechaCreacion_mes; }
int Tarjeta::getFechaCreacion_anio() { return FechaCreacion_anio; }
int Tarjeta::getFechaCaducidad_mes() { return FechaCaducidad_mes; }
int Tarjeta::getFechaCaducidad_anio() { return FechaCaducidad_anio; }
bool Tarjeta::getActivado() { return Activado; }
string Tarjeta::getNombreCliente() { return NombreCliente; }
string Tarjeta::getApellidoCliente() { return ApellidoCliente; }
string Tarjeta::getActivado_str() { return Activado ? "Si" : "No"; }
string Tarjeta::getTipoTarjeta_str()
{
	switch (TipoTarjeta) {
	case VISA:
		return "VISA";
		break;
	case AMERICANEXPRESS:
		return "AMERICAN EXPRESS";
		break;
	}
}
string Tarjeta::getDivisa_str() {
	switch (Divisa) {
	case SOLES:
		return "SOLES";
		break;
	case DOLARES:
		return "DOLARES";
		break;
	}
}
int Tarjeta::getActivado_int() {
	return Activado ? 1 : 0;
}

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
	return FechaCaducidad_anio > FechaCreacion_anio ? true : false;
}

void Tarjeta::Activar(){this->Activado = true;}

void Tarjeta::Desactivar(){this->Activado = false;}

string Tarjeta::descripcion() {
	return "\nCodigo: " + Codigo + " CVV: " + to_string(CVV) + " Activado: " + getActivado_str() +
		"\nSaldo: " + to_string(saldo) + " Tipo de Tarjeta: " + getTipoTarjeta_str() + " Divisa: " + getDivisa_str() +
		"\nFecha de Creacion: " + fecha_str(FechaCreacion) + " Fecha de Caducidad: " + fecha_str(FechaCaducidad) +
		"\nNombre del Cliente: " + NombreCliente + " Apellido del Cliente: " + ApellidoCliente + " Id Cuenta Bancaria: " + to_string(idCuentaBancaria);
}