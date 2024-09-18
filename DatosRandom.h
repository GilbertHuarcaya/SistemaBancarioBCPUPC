#pragma once
#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
using namespace System;
string generar_nombre() {
	Random r;
	string Nombres[20] = { "Fabian","Julio","Jose","Juan","Matias","Gabriel","Leonardo","Dyron","Gilbert","Carlos",
"Bastian","Benjamin","Alberto","Valentino","Zeus","Kevin","Oscar","Eduardo","Emilio","Wilmer" };
	string aux = Nombres[r.Next(0, 19)];
	return aux;
}
string generar_apellido() {
	Random r;
	string Apellidos[20] = { "Amaya","Quispe","Serrano","Puma","Poma","Alva","Lopez","Zapata","Gomez","Torres",
"de la Cruz","Godoy","Bueno","Diaz","Bustamante","Barranco","Rodriguez","Campos","Arenas","Hudson" };
	string aux = Apellidos[r.Next(0, 19)];
	return aux;
}
string generar_telefono() {
	Random r;
	long int aux = 901000000 + r.Next(111111, 899999) * 100;
	return to_string(aux);
}
string generar_email(string nombre, string apellido) {
	Random r;
	string mails[5] = { "@gmail.com","outlook.com","@yahoo.com","@upc.edu.pe","@hotmail.com" };
	return nombre + "_" + apellido + mails[r.Next(0, 4)];
}
string generar_fecha() {
	string fecha = "Hoy";
	//No esta bien implementado
	return fecha;
}
string generar_fecha_expiracion_tarjeta() {
	Random r;
	string aux = to_string(r.Next(1, 12)) + "/" + to_string(r.Next(28, 32));
	return aux;
}
string generar_DNI() {
	Random r;
	string aux;
	for (int i = 0; i < 8; i++) {
		aux.append(to_string(r.Next(0, 9)));
	}
	return aux;
}
string generar_CodigoTarjeta() {
	Random r;
	string aux;
	for (int i = 0; i < 16; i++) {
		aux.append(to_string(r.Next(0, 9)));
	}
	return aux;
}
string generar_CVV() {
	Random r;
	string aux=to_string(r.Next(111,999));
	return aux;
}
string generar_TipoCuenta() {
	Random r;
	string aux[2] = { "Soles","Dolares" };
	return aux[r.Next(0, 2)];
}