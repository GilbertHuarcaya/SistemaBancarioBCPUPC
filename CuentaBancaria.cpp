#include "pch.h"
#include "CuentaBancaria.h"
#include "DatosRandom.h"

CuentaBancaria::CuentaBancaria()
{
	Contrasenia = ""; NombreCliente = ""; ApellidoCliente = "";
	TipoCuenta = OTRACUENTA; FechaCreacion = NULL;
	FechaCreacion_dia = 0; FechaCreacion_mes = 0; FechaCreacion_anio = 0;
	idCliente = 0; idTarjeta = 0;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, ETipoCuenta TipoCuenta, tm* FechaCreacion, int idCliente)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente;
	this->ApellidoCliente = ApellidoCliente;
	this->TipoCuenta = TipoCuenta; this->FechaCreacion = FechaCreacion;
	this->idCliente = idCliente;
	this->idTarjeta = 0;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, tm* FechaCreacion, int idCliente,
	int FechaCreacion_dia, int FechaCreacion_mes, int FechaCreacion_anio)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente;
	this->ApellidoCliente = ApellidoCliente;
	this->FechaCreacion = FechaCreacion;
	this->FechaCreacion_dia = FechaCreacion_dia;
	this->FechaCreacion_mes = FechaCreacion_mes;
	this->FechaCreacion_anio = FechaCreacion_anio;
	this->idCliente = idCliente;
	ETipoCuenta TipoCuentaConEnum;
	switch (TipoCuenta)
	{
	case 1:
		TipoCuentaConEnum = DEBITO;
		break;
	case 2:
		TipoCuentaConEnum = CREDITO;
		break;
	default:
		TipoCuentaConEnum = OTRACUENTA;
		break;
	}
	this->TipoCuenta = TipoCuentaConEnum;
	this->idTarjeta = 0;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, tm* FechaCreacion, int idCliente, int idTarjeta)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente;
	this->ApellidoCliente = ApellidoCliente;
	this->FechaCreacion = FechaCreacion;
	this->idCliente = idCliente;
	ETipoCuenta TipoCuentaConEnum;
	switch (TipoCuenta)
	{
	case 1:
		TipoCuentaConEnum = DEBITO;
		break;
	case 2:
		TipoCuentaConEnum = CREDITO;
		break;
	default:
		TipoCuentaConEnum = OTRACUENTA;
		break;
	}
	this->TipoCuenta = TipoCuentaConEnum;
	this->idTarjeta = idTarjeta;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, tm* FechaCreacion,
	int FechaCreacion_dia, int FechaCreacion_mes, int FechaCreacion_anio, int idCliente, int idTarjeta)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente;
	this->ApellidoCliente = ApellidoCliente;
	this->FechaCreacion = FechaCreacion;
	this->FechaCreacion_dia = FechaCreacion_dia;
	this->FechaCreacion_mes = FechaCreacion_mes;
	this->FechaCreacion_anio = FechaCreacion_anio;
	this->idCliente = idCliente;
	ETipoCuenta TipoCuentaConEnum;
	switch (TipoCuenta)
	{
	case 1:
		TipoCuentaConEnum = DEBITO;
		break;
	case 2:
		TipoCuentaConEnum = CREDITO;
		break;
	default:
		TipoCuentaConEnum = OTRACUENTA;
		break;
	}
	this->TipoCuenta = TipoCuentaConEnum;
	this->idTarjeta = idTarjeta;
}
void CuentaBancaria::addTransaction()
{}

double CuentaBancaria::calculateBalance()
{
	return 0.0;
}

bool CuentaBancaria::validateContrasenia(string Contrasenia)
{
	return this->Contrasenia == Contrasenia;
}

void CuentaBancaria::setIdTarjeta(int idTarjeta)
{
	this->idTarjeta = idTarjeta;
}

void CuentaBancaria::removeTarjeta(int idTarjeta)
{
	this->idTarjeta = 0;
}

string CuentaBancaria::descripcion() {
	return "Contrasenia: " + Contrasenia + "\nTipo de Cuenta: " + getTipoCuenta_str() +
		"\nFecha de Creacion: " + fecha_str_CB(FechaCreacion) + "\nNombre del Cliente: " + NombreCliente + "\nApellido del Cliente: " + ApellidoCliente +
		"\nId del Cliente: " + to_string(idCliente) + "\nId de la Tarjeta: " + to_string(idTarjeta);
}

string CuentaBancaria::getNombreCliente()
{
	return NombreCliente;
}

string CuentaBancaria::getApellidoCliente()
{
	return ApellidoCliente;
}

tm* CuentaBancaria::getFechaCreacion()
{
	return FechaCreacion;
}

int CuentaBancaria::getFechaCreacion_dia()
{
	return FechaCreacion_dia;
}

int CuentaBancaria::getFechaCreacion_mes() 
{
	return FechaCreacion_mes;
}

int CuentaBancaria::getFechaCreacion_anio() 
{
	return FechaCreacion_anio;
}

ETipoCuenta CuentaBancaria::getTipoCuenta()
{
	return TipoCuenta;
}

string CuentaBancaria::getTipoCuenta_str() 
{
	string aux;
	switch (TipoCuenta) {
	case 1:
		aux = "DEBITO";
		break;
	case 2:
		aux = "CREDITO";
		break;
	default:
		aux = "OTRACUENTA";
		break;
	}
	return aux;
}

int CuentaBancaria::getIdCliente()
{
	return idCliente;
}

int CuentaBancaria::getIdTarjeta()
{
	return idTarjeta;
}

string CuentaBancaria::getContrasenia()
{
	return Contrasenia;
}