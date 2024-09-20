#pragma once
#include "Lista.h"
#include "CuentaBancaria.h"
#include "Cliente.h"

class ListaDeCuentasBancarias :public Lista<CuentaBancaria*>
{
public:
	void mostrar();
	void agregarCuentaBancaria();
	void agregarCuentaBancariaPorIdDelCliente(int idCliente);
	void agregarCuentaBancariaPorCliente(Nodo<Cliente*>* cliente);
	void agregarCuentaBancariaRandom();
	void agregarCuentaBancariaRandomPorIdDeCliente(int idCliente);
	int buscar(int id);
	void listarPorIdDeCliente(int idCliente);
	int buscarPorIdDeTarjeta(int idTarjeta);
	void actualizarDatos(int id);
	void menu();
	void menuCuentasBancariasPorCliente(Nodo<Cliente*>* clienteActual);
	void menuCuentaBancariaIndividual(Nodo<CuentaBancaria*>* cuentaBancariaActual);
	void escribirEnArchivo();
	void cargarCuentasBancarias();
	void buscarPorTipoCuenta(ETipoCuenta tipoDeCuenta);
};