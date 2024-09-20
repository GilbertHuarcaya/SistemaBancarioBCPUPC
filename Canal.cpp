#include "pch.h"
#include "Canal.h"

Canal::Canal()
{
	nombre = "";
	direccion = "";
	ciudad = "";
	distrito = "";
	departamento = "";
	activo = false;
	tipoDeCanal = OTROCANAL;
}

Canal::Canal(string nombre, string direccion, string ciudad, string distrito, string departamento, bool activo, ETipoDeCanal tipoDeCanal)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->ciudad = ciudad;
	this->distrito = distrito;
	this->departamento = departamento;
	this->activo = activo;
	this->tipoDeCanal = tipoDeCanal;
}

Canal::Canal(string nombre, string direccion, string ciudad, string distrito, string departamento, bool activo, int tipoDeCanal)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->ciudad = ciudad;
	this->distrito = distrito;
	this->departamento = departamento;
	this->activo = activo;
	ETipoDeCanal tipoDeCanalConEnum;
	switch (tipoDeCanal)
	{
	case 1:
		tipoDeCanalConEnum = WEB;
		break;
	case 2:
		tipoDeCanalConEnum = APP;
		break;
	case 3:
		tipoDeCanalConEnum = VENTANILLA;
		break;
	case 4:
		tipoDeCanalConEnum = AGENTE;
		break;
	case 5:
		tipoDeCanalConEnum = YAPE;
		break;
	default:
		tipoDeCanalConEnum = OTROCANAL;
		break;
	}
	this->tipoDeCanal = tipoDeCanalConEnum;
}

Canal::Canal(ETipoDeCanal tipoDeCanal)
{
	this->nombre = "";
	this->direccion = "";
	this->ciudad = "";
	this->distrito = "";
	this->departamento = "";
	this->activo = true;
	this->tipoDeCanal = tipoDeCanal;
}

Canal::~Canal()
{
}

string Canal::getNombre()
{
	return nombre;
}

string Canal::descripcion()
{
	string tipoDeCanal;
	switch (this->tipoDeCanal)
	{
	case WEB:
		tipoDeCanal = "WEB";
		break;
	case APP:
		tipoDeCanal = "APP";

		break;
	case VENTANILLA:
		tipoDeCanal = "VENTANILLA";

		break;
	case AGENTE:
		tipoDeCanal = "AGENTE";

		break;
	case YAPE:
		tipoDeCanal = "YAPE";

		break;
	case OTROCANAL:
		tipoDeCanal = "OTROCANAL";

		break;
	}

	return "Nombre: " + nombre + "\nDireccion: " +
		direccion + "\nCiudad: " + ciudad + "\nDistrito: " + distrito + "\nDepartamento: " + departamento +
		"\nActivo: " + to_string(activo) + "\nTipo de canal: " + tipoDeCanal;
}

string Canal::getDireccion()
{
	return direccion;
}

string Canal::getCiudad()
{
	return ciudad;
}

string Canal::getDistrito()
{
	return distrito;
}

string Canal::getDepartamento()
{
	return departamento;
}

ETipoDeCanal Canal::getTipoDeCanal()
{
	return tipoDeCanal;
}

bool Canal::getActivo()
{
	return activo;
}

void Canal::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Canal::setDireccion(string direccion)
{
	this->direccion = direccion;
}

void Canal::setCiudad(string ciudad)
{
	this->ciudad = ciudad;
}

void Canal::setDistrito(string distrito)
{
	this->distrito = distrito;
}

void Canal::setDepartamento(string departamento)
{
	this->departamento = departamento;
}

void Canal::setTipoDeCanal(ETipoDeCanal tipoDeCanal)
{
	this->tipoDeCanal = tipoDeCanal;
}
