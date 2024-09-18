#include "pch.h"
#include "Canal.h"

Canal::Canal(string nombre, string descripcion, string direccion, string ciudad, string distrito, string departamento, string fechaCreacion, string fechaModificacion, bool activo, ETipoDeCanal tipoDeCanal)
{
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->direccion = direccion;
	this->ciudad = ciudad;
	this->distrito = distrito;
	this->departamento = departamento;
	this->fechaCreacion = fechaCreacion;
	this->fechaModificacion = fechaModificacion;
	this->activo = activo;
	this->tipoDeCanal = tipoDeCanal;
}

Canal::Canal(ETipoDeCanal tipoDeCanal)
{
	this->nombre = "";
	this->descripcion = "";
	this->direccion = "";
	this->ciudad = "";
	this->distrito = "";
	this->departamento = "";
	this->fechaCreacion = "";
	this->fechaModificacion = "";
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

string Canal::getDescripcion()
{
	return descripcion;
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

string Canal::getFechaCreacion()
{
	return fechaCreacion;
}

string Canal::getFechaModificacion()
{
	return fechaModificacion;
}

bool Canal::getActivo()
{
	return activo;
}

void Canal::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Canal::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
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

void Canal::setFechaCreacion(string fechaCreacion)
{
	this->fechaCreacion = fechaCreacion;
}

void Canal::setFechaModificacion(string fechaModificacion)
{
	this->fechaModificacion = fechaModificacion;
}
