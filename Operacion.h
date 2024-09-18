#pragma once
#include <string>
#include <time.h>
using namespace std;
class Operacion {
private:
    int id;
    string type; // "Depósito", "Retiro", "Transferencia", etc.
    double amount;
    string description;
    string date;

public:
    Operacion(int id, string type, double amount, string description);

    // Métodos de acceso
    int getId();
    string getType();
    double getAmount();
    string getDescription();
    string getDate();
};
int Operacion::getId() { return id;}
string Operacion::getType() { return type;}
double Operacion::getAmount() { return amount;}
string Operacion::getDescription() { return description;}
string Operacion::getDate() { return date;}