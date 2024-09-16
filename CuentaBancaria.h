#pragma once
#include <string>
#include "Operacion.h"
#include "vector"

using namespace std;

class CuentaBancaria {
private:
    int id;
    string accountNumber;
    double balance;
    vector<Operacion*> transactions;

public:
    CuentaBancaria(int id, string accountNumber, double initialBalance);

    // M�todos de acceso
    int getId();
    string getAccountNumber();
    double getBalance();

    // M�todos de manipulaci�n
    void addTransaction(Operacion transaction);
    double calculateBalance();
    vector<Operacion*> getTransactions();
};
