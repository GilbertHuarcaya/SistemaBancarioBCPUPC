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
    Sede(int id, string name, string address, string phone);

    // M�todos de acceso
    string getId();
    string getNombre();
    string getDireccion();
    string getTelefono();

    // M�todos de manipulaci�n
    void updateName(string name);
    void updateAdress(string adress);
    void updatePhone(string phone);
    void Activar();
    void Desactivar();
};