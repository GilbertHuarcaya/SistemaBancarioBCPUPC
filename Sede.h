#pragma once
#include <string>

using namespace std;
class Sede {
private:
    string id;
    string Nombre;
    string Direccion;
    string Telefono;
    bool Activado;

public:
    Sede(int id, string Nombre, string Direccion, string Telefono, bool Activado);

    // M�todos de acceso
    string getId();
    string getNombre();
    string getDireccion();
    string getTelefono();

    // M�todos de manipulaci�n
    void updateName(string Nombre);
    void updateAdress(string Direccion);
    void updatePhone(string Telefono);
    void Activar();
    void Desactivar();
};
