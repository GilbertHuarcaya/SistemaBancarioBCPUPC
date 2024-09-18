#pragma once
#include "pch.h"
#include <iostream>
#include <conio.h>
#include "Lista.h"
#include "Cliente.h"
#include <string>
#include <algorithm>
#include "Menu.h"
#include "ListaDeClientes.h"
#include "ListaCuentaB.h"

using namespace System;
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    mostrarMenuPrincipal();
    system("pause");
    return 0;
}