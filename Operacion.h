#pragma once
#include <string>

using namespace std;
class Operacion {
private:
    int id;
    string type; // "Depósito", "Retiro", "Transferencia", etc.
    double amount;
    string description;
    time_t date;

public:
    Operacion(int id, string type, double amount, string description);

    // Métodos de acceso
    int getId();
    string getType();
    double getAmount();
    string getDescription();
    string getDate();
};


