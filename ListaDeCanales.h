#pragma once
#include "Lista.h"
#include "Canal.h"
#include "CuentaBancaria.h"

class ListaDeCanales : public Lista<Canal*> 
{
public:
	void mostrar();
	void actualizarDatos(int id);
	void menu();
	void menuDeGestion();
	void menuDeAcceso();
	void menuDeOperacionPorCanal(Nodo<Canal*>* canal);
	void menuDeOperacionPorCuentaBancariaYCanal(Nodo<CuentaBancaria*>* cuentaBancaria, Nodo<Canal*>* canal);
	ETipoDeCanal menuParaObtenerTipoDeCanal();

	//Menu para actualizar canal
	void menuParaActualizarCanal(Nodo<Canal*>* canal);
	void activarCanal(int id);
	void desactivarCanal(int id);


	//Metodos para cargar y escribir en archivo
	void escribirEnArchivo();
	void cargarCanales();

	//Metodos para crear canales
	void agregarCanal();
	void agregarCanalRandom();
	void agregarCanalPorTipo(ETipoDeCanal tipoDeCanal);
	void agregarCanalPorNombre(string nombre);
	void agregarCanalPorDistrito(string distrito);
	void agregarCanalPorDepartamento(string departamento);
	void agregarCanalPorCiudad(string ciudad);


	//Metodos para eliminar canales
	void eliminarCanal(int id);
	void eliminarCanalPorTipo(ETipoDeCanal tipoDeCanal);
	void eliminarCanalPorNombre(string nombre);
	void eliminarCanalPorDistrito(string distrito);
	void eliminarCanalPorDepartamento(string departamento);
	void eliminarCanalPorCiudad(string ciudad);

	//Metodos para buscar canales
	int buscar(int id);
	int buscarPorTipo(ETipoDeCanal tipoDeCanal);
	int buscarPorNombre(string nombre);
	int buscarPorDistrito(string distrito);
	int buscarPorDepartamento(string departamento);
	int buscarPorCiudad(string ciudad);
	int buscarPorActivo(bool activo);

	//Metodos para ordenar canales
	void ordenarPorNombre();
	void ordenarPorDistrito();
	void ordenarPorDepartamento();
	void ordenarPorCiudad();
	void ordenarPorActivo();
	void ordenarPorTipoDeCanal();

	//Metodo para obtener canal
	Nodo<Canal*>* obtenerCanal();

	// Templates de menus
	template<typename T>
	void filtrarYAccederAMenuPorTipo(T tipoDeCanal, string llave);
	template<typename T>
	void filtrarYAccederAMenuPorTipo(T tipoDeCanal, string llave, Nodo<CuentaBancaria*>* cuentaBancaria);
	template<typename T>
	void gestionarPorTipoLista(T tipoDeCanal, string llave);
	template<typename T>
	void gestionarPorTipoIndividual(T tipoDeCanal, string llave);


	//Menu para cliente
	void menuDeAccesoPorCuentaBancariaParaCliente(Nodo<CuentaBancaria*>* cuentaBancaria);
};
