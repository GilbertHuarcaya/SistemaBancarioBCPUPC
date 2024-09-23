#pragma once
#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
using namespace System;

inline string generar_nombre() {
	Random r;
	string Nombres[20] = { "Fabian","Julio","Jose","Juan","Matias","Gabriel","Leonardo","Dyron","Gilbert","Carlos",
"Bastian","Benjamin","Alberto","Valentino","Zeus","Kevin","Oscar","Eduardo","Emilio","Wilmer" };
	string aux = Nombres[r.Next(0, 19)];
	return aux;
}

inline string generar_apellido() {
	Random r;
	string Apellidos[20] = { "Amaya","Quispe","Serrano","Puma","Poma","Alva","Lopez","Zapata","Gomez","Torres",
"de la Cruz","Godoy","Bueno","Diaz","Bustamante","Barranco","Rodriguez","Campos","Arenas","Hudson" };
	string aux = Apellidos[r.Next(0, 19)];
	return aux;
}

inline string generar_telefono() {
	Random r;
	long int aux = 901000000 + r.Next(111111, 899999) * 100;
	return to_string(aux);
}

inline string generar_email(string nombre, string apellido) {
	Random r;
	string mails[5] = { "@gmail.com","outlook.com","@yahoo.com","@upc.edu.pe","@hotmail.com" };
	return nombre + "_" + apellido + mails[r.Next(0, 4)];
}

inline tm* generar_fecha() {
	time_t tiempo;
	tm* tiempo_actual;
	time(&tiempo);
	tiempo_actual = localtime(&tiempo);
	return tiempo_actual;
}

inline string fecha_str(tm* tiempo_actual) 
{
	auto calculadora_tiempo = [](const tm* tiempo)->string
		{
			string mes[12] = { "Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic" };
			string resultado(mes[tiempo->tm_mon] + "/" + to_string(tiempo->tm_year-100));
			return resultado;
		};
	return calculadora_tiempo(tiempo_actual);
}

inline string fecha_str_CB(tm* tiempo_actual)
{
	auto calculadora_tiempo = [](const tm* tiempo)->string
		{
			string mes[12] = { "Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic" };
			string resultado(to_string(tiempo->tm_mday)+ " " + mes[tiempo->tm_mon] + " " + to_string(1900+tiempo->tm_year));
			return resultado;
		};
	return calculadora_tiempo(tiempo_actual);
}

inline tm* generar_fecha_expiracion_tarjeta() 
{
	_sleep(1000);
	Random r;
	time_t tiempo;
	tm* tiempo_actual;
	time(&tiempo);
	tiempo_actual = localtime(&tiempo);
	tiempo_actual->tm_year += r.Next(3, 10);
	tiempo_actual->tm_mon = r.Next(0, 11);
	return tiempo_actual;
}

inline string generar_DNI() {
	Random r;
	string aux;
	for (int i = 0; i < 8; i++) {
		aux.append(to_string(r.Next(0, 9)));
	}
	return aux;
}

inline string generar_CodigoTarjeta() {
	Random r;
	string aux;
	for(int j=0;j<4;j++){
		for (int i = 0; i < 4; i++) {
			aux.append(to_string(r.Next(1, 9)));
			_sleep(10);
		}
		if (j != 3) {
			// no coloca espacio al final de la tarjeta
			aux.append(" ");
		}
	}
	return aux;
}

inline int generar_CVV() {
	Random r;
	return r.Next(111,999);
}

inline string generar_TipoCuenta() {
	Random r;
	string aux[2] = { "Soles","Dolares" };
	return aux[r.Next(0, 2)];
}

inline int random(int a, int b) {
	Random r;
	return r.Next(a, b);
}

inline string generar_Direccion(int fase = 1,string total="") {
	if (fase == 0)
	{
		Random r;
		string aux[4] = { "Jiron","Manzana","Calle","Avenida" };
		fase++;
		total += aux[r.Next(0, 4)]+" ";
		return generar_Direccion(fase, total);
	}
	else if(fase<10)
	{
		Random r;
		string vocales[5] = { "a","e","i","o","u" };
		string consonantes[10] = { "b","m","n","r","s","t","h","g","l","t" };
		if (fase % 2 == 0)
		{
			total += vocales[r.Next(0, 5)];
		}
		else
		{
			total += consonantes[r.Next(0, 10)];
		}
		fase++;
		return generar_Direccion(fase,total);
	}
	else {
		return total;
	}
}