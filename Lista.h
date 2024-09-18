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
        this->ultimoId = 1;
        this->inicio = nullptr;
        this->fin = nullptr;
        this->actual = nullptr;
    }
    bool esVacia(); // Comprueba si la lista está vacía
    void agregarAlFinal(T v); // Agrega un elemento al final de la lista
    void eliminar(int id); // Elimina un elemento de la lista por su id
    virtual bool buscar(int id); // Busca un elemento en la lista por su id
    void ordenar(); // Ordena la lista por el id
    void reemplazar(int id, T newVal); // Reemplaza un valor por otro en la lista por su id
    void actualizar(int id, T newVal); // Actualiza un valor por otro en la lista por su id
    virtual void mostrar(); // Muestra la lista (método virtual)
    Nodo<T>* obtenerPrimero(); // Obtiene el primer nodo de la lista
    Nodo<T>* obtenerSiguiente(); // Obtiene el siguiente nodo de la lista

};

template<class T>
bool Lista<T>::esVacia()
{
    return (inicio == nullptr);
}

template<class T>
void Lista<T>::agregarAlFinal(T v)
{
    int nuevoId = ultimoId++;
    Nodo<T>* nodo = new Nodo<T>(v, nuevoId);
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
    while (temp != nullptr && temp->id != id)
    {
        prev = temp;
        temp = temp->siguiente;
    }
    if (temp == nullptr)
    {
        return;
    }
    if (temp == inicio)
    {
        inicio = inicio->siguiente;
    }
    else
    {
        prev->siguiente = temp->siguiente;
    }
    if (temp == fin)
    {
        fin = prev;
    }
    delete temp;
}

template<class T>
bool Lista<T>::buscar(int id)
{
    Nodo<T>* temp = inicio;
    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            return true;
        }
        temp = temp->siguiente;
    }
    return false;
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
        while (ptr1->siguiente != lptr)
        {
            if (ptr1->id > ptr1->siguiente->id)
            {
                T temp = ptr1->dato;
                ptr1->dato = ptr1->siguiente->dato;
                ptr1->siguiente->dato = temp;
                int tempId = ptr1->id;
                ptr1->id = ptr1->siguiente->id;
                ptr1->siguiente->id = tempId;
                swapped = true;
            }
            ptr1 = ptr1->siguiente;
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
        if (temp->id == id)
        {
            temp->dato = newVal;
        }
        temp = temp->siguiente;
    }
}

template<class T>
void Lista<T>::actualizar(int id, T newVal)
{
    Nodo<T>* temp = inicio;
    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            temp->dato = newVal;
        }
        temp = temp->siguiente;
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
        actual = actual->siguiente;
    }
    return actual;
}

#endif
