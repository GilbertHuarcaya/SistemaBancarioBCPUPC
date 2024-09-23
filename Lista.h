#pragma once
#include "Nodo.h"
#include <iostream>
#include <functional>

using namespace System;
using namespace std;
typedef unsigned int uint;

template<class T, T NADA = nullptr>
class Lista
{
typedef function<int(T, T)> Comp;
private:
	int idUltimoAgregado = 0;
    uint lon;
    Nodo<T, NADA>* ini;
    Nodo<T, NADA>* fin;
    Nodo<T, NADA>* actual; // Nuevo miembro para mantener el nodo actual
    Comp comparar; // lambda de criterio de comparación
public:
    Lista(): fin(nullptr), actual(nullptr), ini(nullptr), lon(0), idUltimoAgregado(0), comparar([](T a, T b) {return a - b; }) {}
    //Operaciones auxiliares
    virtual ~Lista();
    bool esVacia(); // Comprueba si la lista est� vac�a
    uint longitud();
    virtual void mostrar(); // Muestra la lista (metodo virtual)

	// AGREGAR
    void agregarAlini(T v); // Agrega al ini un elem
	void agregaPos(T elem, uint pos); // Agrega un elemento en una posición
    void agregaPosConIdDesordenado(T elem, uint pos, int id);
    void agregaPorIdDesordenado(T elem, int id);
    void agregarAlFinal(T v); // Agrega un elemento al final de la lista

	// MODIFICAR
    virtual void ordenarPorId(); // Ordena la lista por el id

	void modificarInicial(T elem);  // Modifica el primer elemento de la lista
	void modificarPos(T elem, uint pos); // Modifica un elemento de la lista por su posición
	void modificarPorId(T elem, int id); // Modifica un elemento de la lista por su id
	void modificarFinal(T elem); // Modifica el último elemento de la lista

	// ELIMINAR
    void eliminarPorId(int id); // Elimina un elemento de la lista por su id
	void eliminaInicial(); // Elimina el primer elemento de la lista
	void eliminaPos(uint pos); // Elimina un elemento de la lista por su posición
	void eliminaFinal(); // Elimina el último elemento de la lista

	// BUSCAR
	Nodo<T, NADA>* obtenerNodoPorId(int id); // Obtiene un nodo por su id
	Nodo<T, NADA>* obtenerInicial(); // Obtiene el primer nodo de la lista
    Nodo<T, NADA>* obtenerSiguiente(); // Obtiene el siguiente nodo de la lista
	Nodo<T, NADA>* obtenerPos(uint pos); // Obtiene un nodo por su posición
	Nodo<T, NADA>* obtenerFinal(); // Obtiene el último nodo de la lista

    virtual int buscarId(int id); // Busca un elemento en la lista por su id

};

template <typename T, T NADA>
Lista<T, NADA>::~Lista()
{
    while (!esVacia())
    {
        Nodo<T, NADA>* temp = ini;
        ini = ini->getSiguiente();
        delete temp;
    }
}

template <typename T, T NADA>
uint Lista<T, NADA>::longitud() {
    return lon;
}

template <typename T, T NADA>
bool Lista<T, NADA>::esVacia() {
    return lon == 0;
}

template <typename T, T NADA>
void Lista<T, NADA>::agregarAlini(T v) 
{
    Nodo<T, NADA>* aux = new Nodo<T, NADA>(v, idUltimoAgregado + 1);
    if (aux != nullptr) {
        ini = aux;
        lon++;
		idUltimoAgregado++;
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::agregarAlFinal(T v)
{
    this->agregaPos(v, lon);
}   

template <typename T, T NADA>
void Lista<T, NADA>::eliminarPorId(int id)
{
	if (lon == 0) return;
	if (ini->getId() == id) {
		eliminaInicial();
	}
	else {
		Nodo<T, NADA>* aux = ini;
		while (aux->getSiguiente() != nullptr) {
			if (aux->getSiguiente()->getId() == id) {
				Nodo<T, NADA>* temp = aux->getSiguiente();
				aux->setSiguiente(temp->getSiguiente());
				delete temp;
				lon--;
				return;
			}
			aux = aux->getSiguiente();
		}
	}
}

template<typename T, T NADA>
inline void Lista<T, NADA>::eliminaInicial()
{
	if (lon == 0) return;
	Nodo<T, NADA>* temp = ini;
	ini = ini->getSiguiente();
	delete temp;
	lon--;
}

template<typename T, T NADA>
inline void Lista<T, NADA>::eliminaPos(uint pos)
{
	if (pos >= lon) return;
	if (pos == 0) {
		eliminaInicial();
	}
	else {
		Nodo<T, NADA>* aux = ini;
		for (int i = 1; i < pos; i++) {
			aux = aux->getSiguiente();
		}
		Nodo<T, NADA>* temp = aux->getSiguiente();
		aux->setSiguiente(temp->getSiguiente());
		delete temp;
		lon--;
	}
}

template<typename T, T NADA>
inline void Lista<T, NADA>::eliminaFinal()
{
	eliminaPos(lon - 1);
}

template <typename T, T NADA>
int Lista<T, NADA>::buscarId(int id)
{
    Nodo<T, NADA>* temp = ini;
    while (temp != nullptr)
    {
        if (temp->getId() == id)
        {
            return temp->getId();
        }
        temp = temp->getSiguiente();
    }
    return 0;
}

template <typename T, T NADA>
Nodo<T, NADA>* Lista<T, NADA>::obtenerNodoPorId(int id)
{
	Nodo<T, NADA>* temp = ini;
	while (temp != nullptr)
	{
		if (temp->getId() == id)
		{
			return temp;
		}
		temp = temp->getSiguiente();
	}
	return new Nodo<T, NADA>();
}

template <typename T, T NADA>
void Lista<T, NADA>::ordenarPorId()
{
    if (esVacia())
    {
        return;
    }

    Nodo<T, NADA>* current = ini;
    Nodo<T, NADA>* index = nullptr;
    T temp;
    int tempId;

    while (current != nullptr)
    {
        index = current->getSiguiente();

        while (index != nullptr)
        {
            if (current->getId() > index->getId())
            {
				tempId = current->getId();
                temp = current->getDato();
				current->setId(index->getId());
                current->setDato(index->getDato());
				index->setId(tempId);
                index->setDato(temp);
            }

            index = index->getSiguiente();
        }

        current = current->getSiguiente();
    }
}

template <typename T, T NADA>
inline void Lista<T, NADA>::mostrar()
{
	Nodo<T, NADA>* temp = ini;
	while (temp != nullptr)
	{
		cout << temp->getDato() << endl;
		temp = temp->getSiguiente();
	}
	cout << endl;
}

template <typename T, T NADA>
Nodo<T, NADA>* Lista<T, NADA>::obtenerSiguiente()
{
    if (actual != nullptr)
    {
        actual = actual->getSiguiente();
    }
    return actual;
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregarAlini(elem);
    }
    else {
        Nodo<T, NADA>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->getSiguiente();
        }
        Nodo<T, NADA>* nuevo = new Nodo<T, NADA>(elem, idUltimoAgregado + 1, aux->getSiguiente());
        if (nuevo != nullptr) {
            aux->setSiguiente(nuevo);
            lon++;
            idUltimoAgregado++;
        }
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaPosConIdDesordenado(T elem, uint pos, int id) {
    if (pos > lon) return;
    if (pos == 0) {
        agregarAlini(elem);
    }
    else {
        Nodo<T, NADA>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->getSiguiente();
        }
        Nodo<T, NADA>* nuevo = new Nodo<T, NADA>(elem, id, aux->getSiguiente());
        if (nuevo != nullptr) {
            aux->setSiguiente(nuevo);
            lon++;
            if (idUltimoAgregado < id) {
                idUltimoAgregado = id;
            };
        }
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::agregaPorIdDesordenado(T elem, int id) {
    agregaPosConIdDesordenado(elem, lon, id);
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->setDato(elem);
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo<T, NADA>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->getSiguiente();
        }
        aux->setDato(elem);
    }
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarPorId(T elem, int id) {
	Nodo<T, NADA>* temp = ini;
	while (temp != nullptr) {
		if (temp->getId() == id) {
			temp->setDato(elem);
			return;
		}
		temp = temp->getSiguiente();
	}
	return;
}

template <typename T, T NADA>
void Lista<T, NADA>::modificarFinal(T elem) {
    modificarPos(elem, long - 1)
}

template <typename T, T NADA>
Nodo<T, NADA>* Lista<T, NADA>::obtenerInicial() {
    return obtenerPos(0);
}
template <typename T, T NADA>
Nodo<T, NADA>* Lista<T, NADA>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo<T, NADA>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->getSiguiente();
        }
        return aux;
    }
    else {
        return new Nodo<T, NADA>();
    }
}

template <typename T, T NADA>
Nodo<T, NADA>* Lista<T, NADA>::obtenerFinal() {
    return obtenerPos(lon - 1);
}
