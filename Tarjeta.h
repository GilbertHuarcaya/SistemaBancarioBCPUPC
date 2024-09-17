#pragma once
#include <string>

using namespace std;
class Tarjeta {
private:
    int id;
    bool isActive;
    string code;
    int CVV;
    double amount;
    string type;
    string currency;
    string Creationdate;
    string expirationDate;

public:
    Tarjeta(int id, string TarjetaNumber, int CVV, string type, string currency, time_t expirationDate);

    // Métodos de acceso
    int getId();
    string getTarjetaNumber();
    string getType();
    double getAmount();
    string getCurrency();
    string getDescription();
    string getCreationdate();
    string getExpirationDate();
    bool getIsActive();

    // Métodos de manipulación
    void updateAmount();
    void validateTarjeta(Tarjeta);
    void activate();
    void deactivate();
};
int Tarjeta::getId() { return id;}
string Tarjeta::getTarjetaNumber() { return code;}
string Tarjeta::getType() { return type;}
double Tarjeta::getAmount() { return amount;}
string Tarjeta::getCurrency() { return currency;}
string Tarjeta::getCreationdate() { return Creationdate;}
string Tarjeta::getExpirationDate() { return expirationDate;}
bool Tarjeta::getIsActive() { return isActive;}