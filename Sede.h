#pragma once
#include <string>

class Sede {
private:
    std::string Nombre;
    std::string Direccion;
    std::string Telefono;
    bool Activado;

public:
    Sede(std::string Nombre, std::string Direccion, std::string Telefono, bool Activado);

    // M�todos de acceso
    std::string getNombre();
    std::string getDireccion();
    std::string getTelefono();

    // M�todos de manipulaci�n
    void updateName(std::string Nombre);
    void updateAdress(std::string Direccion);
    void updatePhone(std::string Telefono);
    void Activar();
    void Desactivar();
};
