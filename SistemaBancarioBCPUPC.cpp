#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Lista.h"
#include "Cliente.h"
#include <string>
#include <algorithm>
#include "Menu.h"

using namespace System;
using namespace std;

void registrar_cliente(Lista<Cliente*>& l, int i) {
    string num(1, i + '0');
    l.push_back(new Cliente("nombre " + num, "dir " + num, "telefono " + num, num));
}

void mostrar_clientes(Lista<Cliente*> l) {
    cout << "Clientes:\n";
    Cliente* elem;

    do {
        elem = l.next();
        cout << elem->descripcion() << endl;

    } while (!l.esVacia());
}

int main()
{
    srand(time(0));
    mostrarUsuarios();
    return 0;
}