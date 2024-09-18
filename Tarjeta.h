#pragma once
#include <string>

using namespace std;
class Tarjeta {
private:
    int id;
    bool Activado;
    string Codigo;
    int CVV;
    double saldo;
    string TipoTarjeta;
    string Divisa;
    string FechaCreacion;
    string FechaCaducidad;
    string NombreCliente;
    string ApellidoCliente;

public:
    Tarjeta(int id, string TarjetaNumber, int CVV, string type, string currency, time_t expirationDate);
    Tarjeta() {};

    // Métodos de acceso
    int getId();
    int getCVV();
    string getCodigo();
    string getTipoTarjeta();
    double getSaldo();
    string getDivisa();
    string getFechaCreacion();
    string getFechaCaducidad();
    bool getActivado();
    string getNombreCliente();
    string getApellidoCliente();

    // Métodos de manipulación
    void updateAmount();
    void validateTarjeta(Tarjeta);
    void activate();
    void deactivate();
};
int Tarjeta::getId() { return id;}
int Tarjeta::getCVV() { return CVV;}
string Tarjeta::getCodigo() { return Codigo;}
string Tarjeta::getTipoTarjeta() { return TipoTarjeta;}
double Tarjeta::getSaldo() { return saldo;}
string Tarjeta::getDivisa() { return Divisa;}
string Tarjeta::getFechaCreacion() { return FechaCreacion;}
string Tarjeta::getFechaCaducidad() { return FechaCaducidad;}
bool Tarjeta::getActivado() { return Activado;}
string Tarjeta::getNombreCliente() { return NombreCliente;}
string Tarjeta::getApellidoCliente() { return ApellidoCliente;}