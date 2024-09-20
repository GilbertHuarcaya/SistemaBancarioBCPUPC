#ifndef __Lista_H__
#define __Lista_H__
#include "Nodo.h"
#include <iostream>
using namespace System;
using namespace std;

template<class T>
class Lista
{
private:
    int ultimoId;
    Nodo<T>* inicio;
    Nodo<T>* fin;
    Nodo<T>* actual; // Nuevo miembro para mantener el nodo actual
public:
    Lista()
    {
        this->ultimoId = 0;//Empieza con 0 elementos
        this->inicio = nullptr;
        this->fin = nullptr;
        this->actual = nullptr;
    }
    virtual ~Lista();
    bool esVacia(); // Comprueba si la lista est� vac�a
    void agregarAlInicio(T v); // Agrega al inicio un elem
    void agregarAlFinal(T v); // Agrega un elemento al final de la lista
    void agregarPos(T v, int pos); //Agrega en una posicion especifica de la lista
    void eliminar(int id); // Elimina un elemento de la lista por su id
    virtual int buscar(int id); // Busca un elemento en la lista por su id
    Nodo<T>* obtenerNodoPorId(int id);
    virtual void ordenar(); // Ordena la lista por el id
    void reemplazar(int id, T newVal); // Reemplaza un valor por otro en la lista por su id
    virtual void mostrar(); // Muestra la lista (m�todo virtual)
    Nodo<T>* obtenerPrimero(); // Obtiene el primer nodo de la lista
    Nodo<T>* obtenerSiguiente(); // Obtiene el siguiente nodo de la lista

};

template<class T>
Lista<T>::~Lista()
{
    while (!esVacia())
    {
        Nodo<T>* temp = inicio;
        inicio = inicio->getSiguiente();
        delete temp;
    }
}

template<class T>
bool Lista<T>::esVacia()
{
    return (inicio == nullptr);
}

template<class T>
void Lista<T>::agregarAlInicio(T v) 
{
    Nodo<T>* aux = new Nodo<T>(v,1);
    Nodo<T>* aux2 = nullptr;
    aux->setSiguiente(inicio);
    aux2 = aux->getSiguiente();
    while (aux2!=nullptr) {
        aux2->setId(aux2->getId() + 1);
        aux2 = aux2->getSiguiente();
    }
    inicio = aux;
    ultimoId++;
}

template<class T>
void Lista<T>::agregarAlFinal(T v)
{
	ultimoId = ultimoId + 1;
    int nuevoId = ultimoId;
    Nodo<T>* nodo = new Nodo<T>(v, nuevoId);
    if (esVacia())
    {
        inicio = nodo;
        fin = inicio;
    }
    else
    {
        fin->setSiguiente(nodo);
        fin = nodo;
    }
    nodo = nullptr;
}

template<class T>
void Lista<T>::eliminar(int id)
{
    if (esVacia())
    {
        return;
    }
    Nodo<T>* temp = inicio;
    Nodo<T>* prev = nullptr;
    while (temp != nullptr && temp->getId() != id)
    {
        prev = temp;
        temp = temp->getSiguiente();
    }
    if (temp == nullptr)
    {
        return;
    }
    if (temp == inicio)
    {
        inicio = inicio->getSiguiente();
    }
    else
    {
        prev->setSiguiente(temp->getSiguiente());
    }
    if (temp == fin)
    {
        fin = prev;
    }
    delete temp;
}

template<class T>
int Lista<T>::buscar(int id)
{
    Nodo<T>* temp = inicio;
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

template<class T>
Nodo<T>* Lista<T>::obtenerNodoPorId(int id)
{
    Nodo<T>* temp = inicio;
    while (temp != nullptr)
    {
        if (temp->getId() == id)
        {
            return temp;
        }
        temp = temp->getSiguiente();
    }
    return new Nodo<T>();
}

template<class T>
void Lista<T>::ordenar()
{
    if (esVacia())
    {
        return;
    }
    bool swapped;
    Nodo<T>* ptr1;
    Nodo<T>* lptr = nullptr;
    do
    {
        swapped = false;
        ptr1 = inicio;
        while (ptr1->getSiguiente() != lptr)
        {
            if (ptr1->getId() > ptr1->getSiguiente()->getId())
            {
                T temp = ptr1->getDato();
                ptr1->setDato(ptr1->getSiguiente()->getDato());
                ptr1->getSiguiente()->setDato(temp);
                int tempId = ptr1->getId();
                ptr1->setId(ptr1->getSiguiente()->getId());
                ptr1->getSiguiente()->setId(tempId);
                swapped = true;
            }
            ptr1 = ptr1->getSiguiente();
        }
        lptr = ptr1;
    } while (swapped);
}

template<class T>
void Lista<T>::reemplazar(int id, T newVal)
{
    Nodo<T>* temp = inicio;
    while (temp != nullptr)
    {
        if (temp->getId() == id)
        {
            temp->setDato(newVal);
        }
        temp = temp->getSiguiente();
    }
}

template<class T>
inline void Lista<T>::mostrar()
{
}

template<class T>
Nodo<T>* Lista<T>::obtenerPrimero()
{
    actual = inicio;
    return actual;
}

template<class T>
Nodo<T>* Lista<T>::obtenerSiguiente()
{
    if (actual != nullptr)
    {
        actual = actual->getSiguiente();
    }
    return actual;
}

template<class T>
void Lista<T >::agregarPos(T v, int pos) 
{
    /*Nodo<T>* nodo = new Nodo<T>(v, pos);
    Nodo<T>* aux = inicio;
    Nodo<T>* aux2 = nullptr;
    for (int i = 0; i < pos; i++) {
        aux2 = aux;
        aux = aux->getSiguiente();
    }
    aux2->setSiguiente(nodo);
    nodo->setSiguiente(aux);
    */
}

#endif
