#ifndef __NODO_H__
#define __NODO_H__

template<class T>
class Nodo
{
private:
	int id;
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo(T v, int id, Nodo<T>* sig = nullptr)
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

	void setSiguiente(Nodo<T>* s)
	{
		siguiente = s;
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