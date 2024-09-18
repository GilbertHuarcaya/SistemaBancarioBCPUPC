#ifndef __NODO_H__
#define __NODO_H__

template<class T>
class Nodo
{
public:
	int id;
	T dato;
	Nodo<T>* siguiente;

	Nodo(T v, int id, Nodo<T>* sig = nullptr)
	{
		this->id = id;
		dato = v;
		siguiente = sig;
	}

	int getId()
	{
		return id;
	}

	T getDato()
	{
		return dato;
	}

	Nodo<T>* getSiguiente()
	{
		return siguiente;
	}
};

#endif