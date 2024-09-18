#pragma once
#include "Lista.h"
#include "Canal.h"

class ListaDeCanales : public Lista<Canal*> 
{
public:
	void mostrar();
	void agregarCanal();
	void agregarCanalRandom();
	bool buscar(int id);
	void actualizarDatos(int id);
	void menu();
};
