#pragma once
#include <string>
#include "Operacion.h"
#include "Lista.h"
#include "Tarjeta.h"
#include "Cola.h"

using namespace std;

enum ETipoCuenta {
    DEBITO = 1,
    CREDITO,
    OTRACUENTA
};

class CuentaBancaria {
private:
    string Contrasenia;
    string FechaCreacion;
    ETipoCuenta TipoCuenta;
    int idCliente;
    string NombreCliente;
	string ApellidoCliente;
	int idTarjeta;
    //Cola<Operacion*>* Operaciones;
    //Lista<Tarjeta*> *Tarjetas;

public:
    CuentaBancaria();
    CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, ETipoCuenta TipoCuenta, string FechaCreacion, int idCliente);
    CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, string FechaCreacion, int idCliente);
    CuentaBancaria(string Contrasenia, string NombreCliente, string ApellidoCliente, int TipoCuenta, string FechaCreacion, int idCliente, int idTarjeta);

    //Metodos para listar datos
    string descripcion();
    // M�todos de acceso
    string getContrasenia();
    string getNombreCliente();
	string getApellidoCliente();
    string getFechaCreacion();
    ETipoCuenta getTipoCuenta();
    string getTipoCuenta_str();
    int getIdCliente();
	int getIdTarjeta();
    // M�todos de manipulaci�n
    void addTransaction();
    double calculateBalance();
    bool validateContrasenia(string Contrasenia);
	void setIdTarjeta(int idTarjeta);
	void removeTarjeta(int idTarjeta);
};
