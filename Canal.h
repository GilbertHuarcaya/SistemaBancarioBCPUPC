#pragma once
#include <string>

using namespace std;

enum ETipoDeCanal {
	VENTANILLA = 1,
	AGENTE,
	WEB,
	APP,
	YAPE,
	OTROCANAL
};

class Canal
{
private:
	string nombre;
	string direccion;
	string ciudad;
	string distrito;
	string departamento;
	bool activo;
	ETipoDeCanal tipoDeCanal;
public:
	Canal();
	Canal(string nombre, string direccion, string ciudad, string distrito, string departamento, bool activo, ETipoDeCanal tipoDeCanal);
	Canal(string nombre, string direccion, string ciudad, string distrito, string departamento, bool activo, int tipoDeCanal);
	Canal(ETipoDeCanal tipoDeCanal);
	~Canal();
	string getNombre();
	string descripcion();
	string getDireccion();
	string getCiudad();
	string getDistrito();
	string getDepartamento();
	ETipoDeCanal getTipoDeCanal();
	bool getActivo();
	void setNombre(string nombre);
	void setDireccion(string direccion);
	void setCiudad(string ciudad);
	void setDistrito(string distrito);
	void setDepartamento(string departamento);
	void setTipoDeCanal(ETipoDeCanal tipoDeCanal);

};

