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

    // Métodos de acceso
    int getId();
    string getAccountNumber();
    double getBalance();

    // Métodos de manipulación
    void addTransaction();
    double calculateBalance();
};
