#pragma once
#include <string>

using namespace std;
class Tarjeta {
private:
    int id;
    bool isActive;
    string code;
    int CVV;
    string type;
    string currency;
    time_t Createdate;
    time_t expirationDate;

public:
    Tarjeta(int id, string TarjetaNumber, int CVV, string type, string currency, time_t expirationDate);

    // M�todos de acceso
    int getId();
    string getTarjetaNumber();
    string getType();
    double getAmount();
    string getDescription();
    time_t getExpirationDate();
    bool getIsActive();

    // M�todos de manipulaci�n
    void updateAmount();
    void validateTarjeta(Tarjeta);
    void activate();
    void deactivate();
};
