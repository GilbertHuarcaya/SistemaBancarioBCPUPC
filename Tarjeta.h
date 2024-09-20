#pragma once
#include <string>

enum EDivisa {
    SOLES = 1,
    DOLARES
};

enum ETipoTarjeta {
    VISA = 1,
    AMERICANEXPRESS
};

using namespace std;
class Tarjeta {
private:
    bool Activado;
    string Codigo;
    int CVV;
    double saldo;
    ETipoTarjeta TipoTarjeta;
    EDivisa Divisa;
    string FechaCreacion; //cambiar tipo ed dato para validar la fecha segun cuando se filtre y valide
    string FechaCaducidad; //cambiar tipo ed dato para validar la fecha segun cuando se filtre y valide
    string NombreCliente;
    string ApellidoCliente;
    int idCuentaBancaria;
    int idCliente;

public:
	Tarjeta();
    Tarjeta(string Codigo, int CVV, bool Activado, ETipoTarjeta TipoTarjeta, EDivisa Divisa, double saldo, string FechaCreacion, string FechaCaducidad,
    string NombreCliente, string ApellidoCliente, int idCuentaBancaria,
    int idCliente);
    Tarjeta(string Codigo, int CVV, bool Activado, int TipoTarjeta, int Divisa, double saldo,
        string FechaCreacion, string FechaCaducidad, string NombreCliente, string ApellidoCliente, 
        int idCuentaBancaria, int idCliente);

    //Metodos para listar datos
    string descripcion();

    // M�todos de acceso
    int getCVV();
    string getCodigo();
    ETipoTarjeta getTipoTarjeta();
    double getSaldo();
    EDivisa getDivisa();
    string getFechaCreacion();
    string getFechaCaducidad();
    bool getActivado();
    string getNombreCliente();
    string getApellidoCliente();
    string getActivado_str();
    string getTipoTarjeta_str();
    string getDivisa_str();
    int getIdCliente();
    int getIdCuentaBancaria();
    int getActivado_int();

    // M�todos de manipulaci�n
    void updateAmount();
    bool validateTarjeta(string Codigo);
    bool validateCVV(int CVV);
    bool validateFechaCaducidad();

    void Activar();
    void Desactivar();
};
