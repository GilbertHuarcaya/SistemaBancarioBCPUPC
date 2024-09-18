#include "pch.h"
#include "Operacion.h"

Operacion::Operacion(int id, string type, double amount, string description)
{
	this->id = id;
	this->type = type;
	this->amount = amount;
	this->description = description;

}
int Operacion::getId() { return id; }
string Operacion::getType() { return type; }
double Operacion::getAmount() { return amount; }
string Operacion::getDescription() { return description; }
string Operacion::getDate() { return date; }