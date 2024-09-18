#pragma once
#include <string>

using namespace std;

enum ETipoDeCanal {
	WEB = 1,
	APP,
	VENTANILLA,
	AGENTE,
	YAPE,
	OTRO
};

class Canal
{
private:
	string nombre;
	string direccion;
	string ciudad;
	string distrito;
	string departamento;
	string fechaCreacion;
	string fechaModificacion;
	bool activo;
	ETipoDeCanal tipoDeCanal;
public:
	Canal(string nombre, string direccion, string ciudad, string distrito, string departamento, string fechaCreacion, string fechaModificacion, bool activo, ETipoDeCanal tipoDeCanal);
	Canal(string nombre, string direccion, string ciudad, string distrito, string departamento, string fechaCreacion, string fechaModificacion, bool activo, int tipoDeCanal);
	Canal(ETipoDeCanal tipoDeCanal);
	~Canal();
	string getNombre();
	string descripcion();
	string getDireccion();
	string getCiudad();
	string getDistrito();
	string getDepartamento();
	ETipoDeCanal getTipoDeCanal();
	string getFechaCreacion();
	string getFechaModificacion();
	bool getActivo();
	void setNombre(string nombre);
	void setDescripcion(string descripcion);
	void setDireccion(string direccion);
	void setCiudad(string ciudad);
	void setDistrito(string distrito);
	void setDepartamento(string departamento);
	void setTipoDeCanal(ETipoDeCanal tipoDeCanal);
	void setFechaCreacion(string fechaCreacion);
	void setFechaModificacion(string fechaModificacion);

};

