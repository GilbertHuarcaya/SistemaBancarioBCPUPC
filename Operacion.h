#pragma once
#include <string>
#include <time.h>
using namespace std;
class Operacion {
private:
    int id;
    string Tipo; // "Deposito", "Retiro", "Transferencia", etc.
    double Cantidad;
    string Descripcion;
    string Fecha;
    int idCuentaOrigen;
    int idCuentaDestino;
    string Estado;


public:
    Operacion(string Tipo,
    double Cantidad,
    string Descripcion,
    string Fecha,
    int idCuentaOrigen,
    int idCuentaDestino,
    string Estado);

    // M�todos de acceso
    int getId();
    string getTipo();
    double getCantidad();
    string getDescripcion();
    string getFecha();
    string getEstado();
    int getIdCOrigen();
    int getIdCDestino();
    string Datos();
};
