#include "pch.h"
#include "Tarjeta.h"

Tarjeta::Tarjeta(int id, string TarjetaNumber, int CVV, string type, string currency, time_t expirationDate)
{
}

int Tarjeta::getId()
{
	return 0;
}

string Tarjeta::getTarjetaNumber()
{
	return string();
}

string Tarjeta::getType()
{
	return string();
}

double Tarjeta::getAmount()
{
	return 0.0;
}

string Tarjeta::getDescription()
{
	return string();
}

time_t Tarjeta::getExpirationDate()
{
	return time_t();
}

bool Tarjeta::getIsActive()
{
	return false;
}

void Tarjeta::updateAmount()
{
}

void Tarjeta::validateTarjeta(Tarjeta)
{
}

void Tarjeta::activate()
{
}

void Tarjeta::deactivate()
{
}
