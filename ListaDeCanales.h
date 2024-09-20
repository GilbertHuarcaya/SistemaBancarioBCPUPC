#pragma once
#include "Lista.h"
#include "Canal.h"

class ListaDeCanales : public Lista<Canal*> 
{
public:
	void mostrar();
	void agregarCanal();
	void agregarCanalRandom();
	int buscar(int id);
	int buscarPorTipo(ETipoDeCanal tipoDeCanal);
	int buscarPorNombre(string nombre);
	int buscarPorDistrito(string distrito);
	int buscarPorDepartamento(string departamento);
	int buscarPorCiudad(string ciudad);
	int buscarPorActivo(bool activo);
	void actualizarDatos(int id);
	void menu();
	void escribirEnArchivo();
	void cargarCanales();
};
