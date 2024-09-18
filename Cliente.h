#pragma once
#include <string>

using namespace std;

class Cliente {
private:
    string nombre;
    string apellido;
    string direccion;
    string telefono;
    string email;
    string DNI;
public:
    Cliente(string nombre,  string apellido,  string direccion,  string telefono,  string email,  string DNI);
    string descripcion() ;
    string getEmail();
    string getNombre();
    string getApellido();
    string getTelefono();
    string getDNI();
    void setNombre(string nombre);
    void setApellido(string apellido);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void setEmail(string email);
    void setDNI(string DNI);
};
