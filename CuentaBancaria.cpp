#include "pch.h"
#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria(string id, string Contrasenia, string NombreCliente, string TipoCuenta, string FechaCreacion)
{
	this->id = id; this->Contrasenia = Contrasenia; this->NombreCliente=NombreCliente; this->TipoCuenta = TipoCuenta; this->FechaCreacion = FechaCreacion;
	this->Operaciones = NULL; this->Tarjetas = NULL;
}

string CuentaBancaria::getId(){return id;}

void CuentaBancaria::addTransaction()
{}

double CuentaBancaria::calculateBalance()
{
	return 0.0;
}

string CuentaBancaria::descripcion() {
	return "\nID: " + id + "\nContrasenia: " + Contrasenia + "\nTipo de Cuenta: " + TipoCuenta +
		"\nFecha de Creacion: " + FechaCreacion + "\nNombre del Cliente: " + NombreCliente;
}