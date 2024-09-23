#ifndef __NODO_H__
#define __NODO_H__

template<class T, T NADA = nullptr>
class Nodo
{
private:
	int id;
	T dato;
	Nodo<T, NADA>* siguiente;
public:
	Nodo(T v = NADA, int id = 0, Nodo<T, NADA>* sig = nullptr)
	{
		this->id = id;
		dato = v;
		siguiente = sig;
	}
	Nodo()
	{
		this->id = 0;
		dato = nullptr;
		siguiente = nullptr;
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

	void setSiguiente(Nodo<T, NADA>* s)
	{
		siguiente = s;
	}

	T getDato()
	{
		return dato;
	}

	Nodo<T, NADA>* getSiguiente()
	{
		return siguiente;
	}
};

#endif