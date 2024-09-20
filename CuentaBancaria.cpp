#include "pch.h"
#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria()
{
	Contrasenia = ""; NombreCliente = ""; ApellidoCliente = "";
	TipoCuenta = OTRACUENTA; FechaCreacion = "";
	idCliente = 0; idTarjeta = 0;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, ETipoCuenta TipoCuenta, string FechaCreacion, int idCliente)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente;
	this->ApellidoCliente = ApellidoCliente;
	this->TipoCuenta = TipoCuenta; this->FechaCreacion = FechaCreacion;
	this->idCliente = idCliente;
	this->idTarjeta = 0;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, string FechaCreacion, int idCliente)
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
	this->idTarjeta = 0;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, string FechaCreacion, int idCliente, int idTarjeta)
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
		"\nFecha de Creacion: " + FechaCreacion + "\nNombre del Cliente: " + NombreCliente + "\nApellido del Cliente: " + ApellidoCliente +
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

string CuentaBancaria::getFechaCreacion()
{
	return FechaCreacion;
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