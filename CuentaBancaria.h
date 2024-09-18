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
    OTRO
};

class CuentaBancaria {
private:
    string Contrasenia;
    string FechaCreacion;
    string TipoCuenta;
    int idCliente; 
    string NombreCliente;
    //Cola<Operacion*>* Operaciones;
    //Lista<Tarjeta*> *Tarjetas;

public:
    CuentaBancaria(string Contrasenia, string NombreCliente, ETipoCuenta TipoCuenta, string FechaCreacion, int idCliente);
    CuentaBancaria(string Contrasenia, string NombreCliente, int TipoCuenta, string FechaCreacion, int idCliente);

    //Metodos para listar datos
    string descripcion();
    // M�todos de acceso
    string getNombreCliente();
    string getFechaCreacion();
    ETipoCuenta getTipoCuenta();
    int getIdCliente();
    // M�todos de manipulaci�n
    void addTransaction();
    double calculateBalance();
    bool validateContrasenia(string Contrasenia);
};
