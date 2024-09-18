#pragma once
#include "Lista.h"
#include "CuentaBancaria.h"
#include "DatosRandom.h"

class ListaCuentaB : public Lista<CuentaBancaria*>
{
public:
	void mostrar();
	void agregarCanal();
	void agregarCanalRandom();
	bool buscar(int id);
	bool buscarPorTipo(ETipoDeCanal tipoDeCanal);
	bool buscarPorNombre(string nombre);
	bool buscarPorDistrito(string distrito);
	bool buscarPorDepartamento(string departamento);
	bool buscarPorCiudad(string ciudad);
	bool buscarPorActivo(bool activo);
	void actualizarDatos(int id);
	void menu();
	void escribirEnArchivo();
	void cargarCanales();
};
