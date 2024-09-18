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

    // M�todos de acceso
    int getId();
    string getTarjetaNumber();
    string getType();
    double getAmount();
    string getCurrency();
    string getCreationdate();
    string getExpirationDate();
    bool getIsActive();

    // M�todos de manipulaci�n
    void updateAmount();
    void validateTarjeta(Tarjeta);
    void activate();
    void deactivate();
};
