#include "pch.h"
#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria(int id, string accountNumber, double initialBalance)
{
}

int CuentaBancaria::getId()
{
	return 0;
}

string CuentaBancaria::getAccountNumber()
{
	return string();
}

double CuentaBancaria::getBalance()
{
	return 0.0;
}

void CuentaBancaria::addTransaction(Operacion transaction)
{
}

double CuentaBancaria::calculateBalance()
{
	return 0.0;
}

vector<Operacion*> CuentaBancaria::getTransactions()
{
	return vector<Operacion*>();
}
