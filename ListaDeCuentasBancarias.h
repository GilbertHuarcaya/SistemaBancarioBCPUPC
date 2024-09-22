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
	void agregarCuentaBancariaRandomPorCliente(Nodo<Cliente*>* cliente);
	int buscar(int id);
	void listarPorIdDeCliente(int idCliente);
	int buscarPorIdDeTarjeta(int idTarjeta);
	void actualizarDatos(int id);
	void actualizarDatosPorCliente(Nodo<Cliente*>* cliente,int id);
	void menu();
	void menuCuentasBancariasPorCliente(Nodo<Cliente*>* clienteActual);
	void menuCuentaBancariaIndividual(Nodo<CuentaBancaria*>* cuentaBancariaActual);
	void escribirEnArchivo();
	void cargarCuentasBancarias();
	void buscarPorTipoCuenta(ETipoCuenta tipoDeCuenta);

	//Menu para cliente
	void menuCuentaBancariaParaCliente(Nodo<CuentaBancaria*>* cuentaBancariaActual);
};