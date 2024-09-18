#pragma once
#include "Lista.h"
#include "Cliente.h"

class ListaDeClientes :public Lista<Cliente*>
{
public:
	void mostrar();
	void agregarCliente();
	void agregarClienteRandom();
	bool buscar(int id);
	void actualizarDatos(int id);
	void menu();
	void escribirEnArchivo();
	void cargarClientes();
};
