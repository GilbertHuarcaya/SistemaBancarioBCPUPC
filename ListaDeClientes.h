#pragma once
#include "Lista.h"
#include "Cliente.h"
#include "ListaDeCuentasBancarias.h"

class ListaDeClientes :public Lista<Cliente*>
{
public:
	void mostrar();
	void agregarCliente();
	void agregarClienteRandom();
	int buscar(int id);
	int buscarPorDNI(string DNI);
	int buscarPorTelefono(string tlf);
	void actualizarDatos(int id);
	void menu();
	void escribirEnArchivo();
	void cargarClientes();
	//Menu para cliente
	void menuCliente();
};
