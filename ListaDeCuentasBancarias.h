#pragma once
#include "Lista.h"
#include "CuentaBancaria.h"

class ListaDeCuentasBancarias :
    public Lista<CuentaBancaria*>
{
public:
	void mostrar();
	void agregarCuentaBancaria();
	void agregarCuentaBancariaRandom();
	bool buscar(int id);
	bool buscarPorIdDeCliente(int idCliente);
	void actualizarDatos(int id);
	void menu();
	void escribirEnArchivo();
	void cargarCuentasBancarias();
};

