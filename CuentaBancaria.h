#pragma once
#include <string>
#include "Operacion.h"
#include "Cliente.h"
#include "Tarjeta.h"
#include "Cola.h"

using namespace std;

class CuentaBancaria {
private:
    int id;
    string Contrasenia;
    Cliente* cliente;
    string FechaCreacion;
    string accountNumber;
    Cola<Operacion*> Operaciones;

public:
    CuentaBancaria(int id, string accountNumber, double initialBalance);
    CuentaBancaria(){}

    // M�todos de acceso
    int getId();
    string getAccountNumber();
    double getBalance();

    // M�todos de manipulaci�n
    void addTransaction();
    double calculateBalance();
};
