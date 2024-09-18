#pragma once
#include "Lista.h"
#include "CuentaBancaria.h"
#include "DatosRandom.h"
void test() {
	Lista<CuentaBancaria*>* CuentasBancarias = new Lista<CuentaBancaria*>;
	for (int i = 0; i < 100; i++) {
		CuentasBancarias->push_back(new CuentaBancaria(to_string(i), generar_DNI(),generar_nombre(), generar_TipoCuenta(), generar_fecha()));
		_sleep(10);
	}
	for (int i = 0; i < 100; i++) {
		cout<<CuentasBancarias->next()->descripcion();
	}
}