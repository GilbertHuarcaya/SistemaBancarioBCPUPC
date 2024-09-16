#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Lista.h"
#include "Cliente.h"
#include <string>
#include <algorithm>

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
    Lista<Cliente*> l;
    for (int i = 0; i < 11; i++) {
        registrar_cliente(l, i + 1);
    }
    mostrar_clientes(l);
    system("pause");
    return 0;
}