#pragma once
#include <string>
#include "Operacion.h"
#include "Lista.h"
#include "Tarjeta.h"
#include "Cola.h"

using namespace std;

class CuentaBancaria {
private:
    string id;
    string Contrasenia;
    string NombreCliente;
    string FechaCreacion;
    string TipoCuenta;
    Cola<Operacion*>* Operaciones;
    Lista<Tarjeta*> *Tarjetas;

public:
    CuentaBancaria(string id, string Contrasenia, string NombreCliente, string TipoCuenta, string FechaCreacion);

    //Metodos para listar datos
    string descripcion();
    // Métodos de acceso
    string getId();

    // Métodos de manipulación
    void addTransaction();
    double calculateBalance();

};