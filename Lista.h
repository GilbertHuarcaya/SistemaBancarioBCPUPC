#ifndef __Lista_H__
#define __Lista_H__
#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Lista
{
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Lista()
	{
		this->inicio = NULL;
		this->fin = NULL;
	}
	bool esVacia();
	void push_back(T v);
	T next();


};

template<class T>
bool Lista<T>::esVacia()
{
	return (inicio == NULL);
}

template<class T>
void Lista<T>::push_back(T v)
{
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia())
	{
		inicio = nodo;
		fin = inicio;
	}
	else
	{
		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = NULL;
}

template<class T>
T Lista<T>::next()
{
	T dato = inicio->dato;

	if (inicio == fin)
	{
		inicio = NULL;
		fin = NULL;
	}
	else
	{
		inicio = inicio->siguiente;
	}
	return dato;
}

#endif
