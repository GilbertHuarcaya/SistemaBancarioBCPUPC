#pragma once

template<class T, T NADA = nullptr>
class NodoDobleEnlazado
{
private:
	int id;
	T dato;
	NodoDobleEnlazado<T, NADA>* siguiente;
	NodoDobleEnlazado<T, NADA>* anterior;
public:
	NodoDobleEnlazado(T v = NADA, int id = 0, NodoDobleEnlazado<T, NADA>* sig = nullptr, NodoDobleEnlazado<T, NADA>* ant = nullptr)
	{
		this->id = id;
		dato = v;
		siguiente = sig;
		anterior = ant;
	}
	NodoDobleEnlazado()
	{
		this->id = 0;
		dato = nullptr;
		siguiente = nullptr;
		anterior = nullptr;
	}

	int getId()
	{
		return id;
	}

	void setId(int i)
	{
		this->id = i;
	}

	void setDato(T d)
	{
		dato = d;
	}

	void setSiguiente(NodoDobleEnlazado<T, NADA>* s)
	{
		siguiente = s;
	}

	void setAnterior(NodoDobleEnlazado<T, NADA>* a)
	{
		anterior = a;
	}

	T getDato()
	{
		return dato;
	}

	NodoDobleEnlazado<T, NADA>* getSiguiente()
	{
		return siguiente;
	}

	NodoDobleEnlazado<T, NADA>* getAnterior()
	{
		return anterior;
	}
};
