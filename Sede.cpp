#include "pch.h"
#include "Sede.h"
#include "string"
using namespace std;

class Sede {
private:
    string Nombre;
    string Direccion;
    string Telefono;
    bool Activado;

public:
    Sede(string Nombre, string Direccion, string Telefono, bool Activado) {
        this->Nombre = Nombre;
        this->Direccion = Direccion;
        this->Telefono = Telefono;
        this->Activado = true;
    }

    string getNombre() { return Nombre; }
    string getDireccion() { return Direccion; }
    string getTelefono() { return Telefono; }
    void updateName(string name) { this->Nombre = name; }
    void updateAdress(string adress) { this->Direccion = adress; }
    void updatePhone(string phone) { this->Telefono = phone; }
    void Activar() { this->Activado = true; }
    void Desactivar() { this->Activado = false; }
};