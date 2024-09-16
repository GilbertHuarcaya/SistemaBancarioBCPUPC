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

    // Métodos de acceso
    int getId();
    string getAccountNumber();
    double getBalance();

    // Métodos de manipulación
    void addTransaction(Operacion transaction);
    double calculateBalance();
    vector<Operacion*> getTransactions();
};
