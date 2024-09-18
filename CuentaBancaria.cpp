#include "pch.h"
#include "CuentaBancaria.h"

CuentaBancaria::CuentaBancaria(int id, string accountNumber, double initialBalance)
{
	this->id = id;
	this->accountNumber = accountNumber;
	this->balance = initialBalance;
}

int CuentaBancaria::getId() { return id; }
string CuentaBancaria::getAccountNumber() { return accountNumber; }

double CuentaBancaria::getBalance()
{
	return 0.0;
}

void CuentaBancaria::addTransaction(Operacion transaction)
{
	this->transactions.push_back(&transaction);
}

double CuentaBancaria::calculateBalance()
{
	return 0.0;
}

vector<Operacion*> CuentaBancaria::getTransactions()
{
	return vector<Operacion*>();
}
