#include "pch.h"
#include "Sede.h"

Sede::Sede(int id, string name, string address, string phone)
{
	this->id = id;
	this->name = name;
	this->adress = address;
	this->phone = phone;
	this->isActive = true;
}

int Sede::getId() { return id; }
string Sede::getName() { return name; }
string Sede::getAdress() { return adress; }
string Sede::getPhone() { return phone; }
void Sede::updateName(string name) { this->name = name; }
void Sede::updateAdress(string adress) { this->adress = adress; }
void Sede::updatePhone(string phone) { this->phone = phone; }

void Sede::activate()
{
	this->isActive = true;
}

void Sede::deactivate()
{
	this->isActive = false;
}
