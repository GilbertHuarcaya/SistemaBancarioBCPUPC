#include "pch.h"
#include "Tarjeta.h"

Tarjeta::Tarjeta(int id, string TarjetaNumber, int CVV, string type, string currency, time_t expirationDate)
{
}

int Tarjeta::getId() { return id; }
string Tarjeta::getTarjetaNumber() { return code; }
string Tarjeta::getType() { return type; }
double Tarjeta::getAmount() { return amount; }
string Tarjeta::getCurrency() { return currency; }
string Tarjeta::getCreationdate() { return Creationdate; }
string Tarjeta::getExpirationDate() { return expirationDate; }
bool Tarjeta::getIsActive() { return isActive; }

void Tarjeta::updateAmount()
{
	this->amount = amount;
}

void Tarjeta::validateTarjeta(Tarjeta)
{
	this->isActive = true;
}

void Tarjeta::activate()
{
	this->isActive = true;
}

void Tarjeta::deactivate()
{
	this->isActive = false;
}
