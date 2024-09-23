#ifndef __COLA_H__
#define __COLA_H__
#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T, T NADA = nullptr>
class Cola
{
private:
	Nodo<T, NADA>* inicio;
	Nodo<T, NADA>* fin;
public:
	Cola()
	{
		this->inicio = nullptr;
		this->fin = nullptr;
	}
	void enqueue(T v);
	T dequeue();
	bool esVacia();

};

template<class T, T NADA>
bool Cola<T, NADA>::esVacia()
{
	return (inicio == nullptr);
}

template<class T, T NADA>
void Cola<T, NADA>::enqueue(T v)
{
	Nodo<T>* nodo = new Nodo<T, NADA>(v);
	if (esVacia())
	{
		inicio = nodo;
		fin = inicio;
	}
	else
	{
		fin->getSiguiente() = nodo;
		fin = nodo;
	}
	nodo = nullptr;
}

template<class T, T NADA>
T Cola<T, NADA>::dequeue()
{
	T dato = inicio->dato;

	if (inicio == fin)
	{
		inicio = nullptr;
		fin = nullptr;
	}
	else
	{
		inicio = inicio->getSiguiente();
	}
	return dato;
}

#endif
