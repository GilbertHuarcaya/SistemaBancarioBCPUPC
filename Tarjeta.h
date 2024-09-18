#pragma once
#include <string>

using namespace std;
class Tarjeta {
private:
    string id;
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
    Tarjeta(string id, string Codigo, int CVV, bool Activado, string TipoTarjeta, string Divisa, double saldo, string FechaCreacion, string FechaCaducidad,
    string NombreCliente, string ApellidoCliente);
    Tarjeta() {};

    // M�todos de acceso
    string getId();
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

    // M�todos de manipulaci�n
    void updateAmount();
    void validateTarjeta(Tarjeta);
    void Activar();
    void Desactivar();
};
