#pragma once
#include "ListaDobleEnlazada.h"
#include "Canal.h"
#include "CuentaBancaria.h"

class ListaDeCanales : public ListaDobleEnlazada<Canal*>
{
public:
	void mostrar();
	void actualizarDatos(int id);
	void menu();
	void menuDeGestion();
	void menuDeAcceso();
	void menuDeOperacionPorCanal(NodoDobleEnlazado<Canal*>* canal);
	void menuDeOperacionPorCuentaBancariaYCanal(Nodo<CuentaBancaria*>* cuentaBancaria, NodoDobleEnlazado<Canal*>* canal);
	ETipoDeCanal menuParaObtenerTipoDeCanal();

	//Menu para actualizar canal
	void menuParaActualizarCanal(NodoDobleEnlazado<Canal*>* canal);
	void activarCanal(int id);
	void desactivarCanal(int id);
	//Metodo recursivo para actualizar todos los canales a activo
	void activarTodosLosCanales(NodoDobleEnlazado<Canal*>* canal);

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

	//Metodo para obtener canal
	NodoDobleEnlazado<Canal*>* obtenerCanal();

	// Templates de menus
	void filtrarYAccederAMenuPorTipo(ETipoDeCanal tipoDeCanal, string llave);
	void filtrarYAccederAMenuPorTipo(ETipoDeCanal tipoDeCanal, string llave, Nodo<CuentaBancaria*>*cuentaBancaria);
	void gestionarPorTipoLista(ETipoDeCanal tipoDeCanal, string llave);
	void gestionarPorTipoIndividual(ETipoDeCanal tipoDeCanal, string llave);


	//Menu para cliente
	void menuDeAccesoPorCuentaBancariaParaCliente(Nodo<CuentaBancaria*>*cuentaBancaria);
};
