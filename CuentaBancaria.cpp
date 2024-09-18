#include "pch.h"
#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, ETipoCuenta TipoCuenta, string FechaCreacion, int idCliente)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente; this->TipoCuenta = TipoCuenta; this->FechaCreacion = FechaCreacion;
	this->idCliente = idCliente;
}

CuentaBancaria::CuentaBancaria(string Contrasenia, string NombreCliente, int TipoCuenta, string FechaCreacion, int idCliente)
{
	this->Contrasenia = Contrasenia; this->NombreCliente = NombreCliente; this->FechaCreacion = FechaCreacion;
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
		TipoCuentaConEnum = OTRO;
		break;
	}
	this->TipoCuenta = TipoCuenta;
}

void CuentaBancaria::addTransaction()
{}

double CuentaBancaria::calculateBalance()
{
	return 0.0;
}

bool CuentaBancaria::validateContrasenia(string Contrasenia)
{
	this->Contrasenia == Contrasenia;
}

string CuentaBancaria::descripcion() {
	return "Contrasenia: " + Contrasenia + "\nTipo de Cuenta: " + TipoCuenta +
		"\nFecha de Creacion: " + FechaCreacion + "\nNombre del Cliente: " + NombreCliente;
}

string CuentaBancaria::getNombreCliente()
{
	return NombreCliente;
}

string CuentaBancaria::getFechaCreacion()
{
	return FechaCreacion;
}

ETipoCuenta CuentaBancaria::getTipoCuenta()
{
	return TipoCuenta;
}

int CuentaBancaria::getIdCliente()
{
	return idCliente;
}
