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
    tm* FechaCreacion; 
    tm* FechaCaducidad; 
    int FechaCreacion_mes;
    int FechaCreacion_anio;
    int FechaCaducidad_mes;
    int FechaCaducidad_anio;
    string NombreCliente;
    string ApellidoCliente;
    int idCuentaBancaria;
    int idCliente;

public:
    Tarjeta(string Codigo, int CVV, bool Activado, ETipoTarjeta TipoTarjeta, EDivisa Divisa, double saldo, tm* FechaCreacion, tm* FechaCaducidad,
    int FechaCreacion_mes, int FechaCreacion_anio, int FechaCaducidad_mes, int FechaCaducidad_anio, string NombreCliente, string ApellidoCliente, int idCuentaBancaria,
    int idCliente);

    Tarjeta(string Codigo, int CVV, bool Activado, int TipoTarjeta, int Divisa, double saldo,
        tm* FechaCreacion, tm* FechaCaducidad, int FechaCreacion_mes, int FechaCreacion_anio, int FechaCaducidad_mes, int FechaCaducidad_anio,
        string NombreCliente, string ApellidoCliente, int idCuentaBancaria, int idCliente);

    //Metodos para listar datos
    string descripcion();

    // Metodos de acceso
    int getCVV();
    string getCodigo();
    ETipoTarjeta getTipoTarjeta();
    double getSaldo();
    EDivisa getDivisa();
    tm* getFechaCreacion();
    tm* getFechaCaducidad();
    int getFechaCreacion_mes();
    int getFechaCreacion_anio();
    int getFechaCaducidad_mes();
    int getFechaCaducidad_anio();
    bool getActivado();
    string getNombreCliente();
    string getApellidoCliente();
    string getActivado_str();
    string getTipoTarjeta_str();
    string getDivisa_str();
    int getIdCliente();
    int getIdCuentaBancaria();
    int getActivado_int();

    // Metodos de manipulacion
    void updateAmount();
    bool validateTarjeta(string Codigo);
    bool validateCVV(int CVV);
    bool validateFechaCaducidad();

    void Activar();
    void Desactivar();
};
