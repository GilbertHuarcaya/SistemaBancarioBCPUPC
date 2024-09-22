#pragma once
#include "Lista.h"
#include "Tarjeta.h"
#include "CuentaBancaria.h"

class ListaDeTarjetas : public Lista<Tarjeta*> {
public:
	void mostrar();
	void agregarTarjeta();
	void agregarTarjetaPorCuentaBancaria(Nodo<CuentaBancaria*>* cuentaBancariaActual);
	void agregarTarjetaRandom();
	void agregarTarjetaRandomPorCuentaBancaria(Nodo<CuentaBancaria*>* cuentaBancariaActual);
	int buscar(int id);
	bool buscarPorIdDeCliente(int idCliente);
	void desactivarPorId(int id);
	void activarPorId(int id);
	void listarTarjetasActivadas();
	void listarTarjetasDesactivadas();
	int obtenerIdDeTarjetaPorIdDeCuentaBancaria(int idCuentaBancaria);
	void actualizarDatos(int id);
	void menu();
	void menuTarjetaIndividual(Nodo<Tarjeta*>*  tarjetaActual);
	void escribirEnArchivo();
	void cargarTarjetas();
};