#include "pch.h"
#include "ListaDeCuentasBancarias.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DatosRandom.h"
#include "ListaDeTarjetas.h"
#include "ListaDeCanales.h"


void ListaDeCuentasBancarias::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay cuentasbancarias registradas" << endl;
		return;
	}
	Nodo<CuentaBancaria*, nullptr>*aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		cout << endl;
		cout << "ID: " << aux->getId() << endl;
		cout << aux->getDato()->descripcion() << endl << endl;
		cout << "----------------------" << endl;
		cout << endl;
		aux = aux->getSiguiente();
	}
	system("pause");
}


void ListaDeCuentasBancarias::agregarCuentaBancaria()
{
	tm* FechaCreacion;
	string Contrasenia, NombreCliente, ApellidoCliente;
	int idCliente, TipoCuenta,FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio;
	cout << "Ingrese el id del Cliente: ";
	cin >> idCliente;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el Nombre del cliente de la Cuenta Bancaria: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del cliente: ";
	cin >> ApellidoCliente;
	cout << "Ingrese el Tipo de Cuenta: \n";
	cout << "(1:CREDITO, 2:DEBITO, 3:OTRO)\n";
	cin >> TipoCuenta;
	FechaCreacion = generar_fecha();
	FechaCreacion_dia = FechaCreacion->tm_mday;
	FechaCreacion_mes = FechaCreacion->tm_mon;
	FechaCreacion_anio = FechaCreacion->tm_year;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion,
	FechaCreacion_dia, FechaCreacion_mes, FechaCreacion_anio, idCliente);
	this->agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeCuentasBancarias::agregarCuentaBancariaPorIdDelCliente(int idCliente)
{
	tm* FechaCreacion;
	string Contrasenia, NombreCliente, ApellidoCliente;
	int TipoCuenta, FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el Nombre del cliente de la Cuenta Bancaria: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del cliente: ";
	cin >> ApellidoCliente;
	cout << "Ingrese el Tipo de Cuenta: \n";
	cout << "(1:CREDITO, 2:DEBITO, 3:OTRO)\n";
	cin >> TipoCuenta;
	FechaCreacion = generar_fecha();
	FechaCreacion_dia = FechaCreacion->tm_mday;
	FechaCreacion_mes = FechaCreacion->tm_mon;
	FechaCreacion_anio = FechaCreacion->tm_year;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion,
	FechaCreacion_dia, FechaCreacion_mes, FechaCreacion_anio,idCliente);
	agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeCuentasBancarias::agregarCuentaBancariaPorCliente(Nodo<Cliente*>* clienteActual)
{
	tm* FechaCreacion;
	string Contrasenia;
	int TipoCuenta;
	cout << "Ingrese el Tipo de Cuenta: \n";
	cout << "(1:CREDITO, 2:DEBITO, 3:OTRO)\n";
	cin >> TipoCuenta;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	FechaCreacion = generar_fecha();
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, clienteActual->getDato()->getNombre(), clienteActual->getDato()->getApellido(),
	TipoCuenta, FechaCreacion, FechaCreacion->tm_mday,FechaCreacion->tm_mon,FechaCreacion->tm_year,clienteActual->getId(),0);
	agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeCuentasBancarias::agregarCuentaBancariaRandom()
{
	tm* FechaCreacion;
	string Contrasenia, NombreCliente, ApellidoCliente;
	int idCliente, TipoCuenta;

	Contrasenia = generar_telefono();
	NombreCliente = generar_nombre();
	ApellidoCliente = generar_nombre();
	FechaCreacion = generar_fecha();
	idCliente = 0;
	TipoCuenta = 1;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion, FechaCreacion->tm_mday,
	FechaCreacion->tm_mon,FechaCreacion->tm_year,idCliente,0);
	agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeCuentasBancarias::agregarCuentaBancariaRandomPorIdDeCliente(int idCliente)
{
	tm* FechaCreacion;
	string Contrasenia, NombreCliente, ApellidoCliente;
	int TipoCuenta, FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio;

	Contrasenia = generar_telefono();
	NombreCliente = generar_nombre();
	ApellidoCliente = generar_nombre();
	FechaCreacion = generar_fecha();
	FechaCreacion_dia = FechaCreacion->tm_mday;
	FechaCreacion_mes = FechaCreacion->tm_mon;
	FechaCreacion_anio = FechaCreacion->tm_year;
	TipoCuenta = 1;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, NombreCliente, ApellidoCliente, TipoCuenta, FechaCreacion,
	FechaCreacion_dia, FechaCreacion_mes, FechaCreacion_anio,idCliente);
	this->agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta agregada correctamente.\n";
	system("pause");
	system("cls");
}

void ListaDeCuentasBancarias::agregarCuentaBancariaRandomPorCliente(Nodo<Cliente*>* clienteActual) 
{
	tm* FechaCreacion;
	string Contrasenia;
	int TipoCuenta;
	TipoCuenta = random(1, 3);
	Contrasenia = generar_telefono();
	FechaCreacion = generar_fecha();
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, clienteActual->getDato()->getNombre(), clienteActual->getDato()->getApellido(),
	TipoCuenta, FechaCreacion, FechaCreacion->tm_mday,FechaCreacion->tm_mon, FechaCreacion->tm_year, clienteActual->getId(), 0);
	agregarAlFinal(nuevoCuentaBancaria);
	escribirEnArchivo();
	cout << "Cuenta Random agregada correctamente.\n";
	system("pause");
	system("cls");
}

int ListaDeCuentasBancarias::buscar(int id)
{
	Nodo<CuentaBancaria*, nullptr>*aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getId() == id)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			system("pause");
			system("cls");
			return aux->getId();
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro la Cuenta Bancaria" << endl;
	system("pause");
	system("cls");
	return 0;
}


void ListaDeCuentasBancarias::listarPorIdDeCliente(int idCliente)
{
	int encontrados = 0;
	Nodo<CuentaBancaria*, nullptr>*aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getIdCliente() == idCliente)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			encontrados++;
		}
		aux = aux->getSiguiente();
	}
	if (encontrados == 0) {
		cout << "No se encontro la Cuenta Bancaria" << endl;
	}
	system("pause");
}


int ListaDeCuentasBancarias::buscarPorIdDeTarjeta(int idTarjeta)
{
	Nodo<CuentaBancaria*, nullptr>*aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getIdTarjeta() == idTarjeta)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			system("pause");
			system("cls");
			return aux->getId();
		}
		aux = aux->getSiguiente();
	}
	cout << "No se encontro la Cuenta Bancaria" << endl;
	system("pause");
	system("cls");
	return 0;
}


void ListaDeCuentasBancarias::actualizarDatos(int id)
{
	Nodo<CuentaBancaria*>* aux;
	tm* FechaCreacion;
	string Contrasenia, NombreCliente, ApellidoCliente;
	int idCliente=0, TipoCuenta, FechaCreacion_dia, FechaCreacion_mes, FechaCreacion_anio;
	cout << "Ingrese la Contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el Nombre del cliente: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del cliente: ";
	cin >> ApellidoCliente;
	cout << "Ingrese el Tipo de Cuenta de la Cuenta Bancaria: \n";
	cout << "(1: CREDITO, 2: DEBITO, 3: OTRO";
	cin >> TipoCuenta;
	FechaCreacion = generar_fecha();
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia,  NombreCliente, ApellidoCliente,  TipoCuenta,  FechaCreacion,  idCliente,
	FechaCreacion_dia, FechaCreacion_mes, FechaCreacion_anio);
	modificarPorId(nuevoCuentaBancaria, id);
	escribirEnArchivo();
	cout << "Se reemplazo correctamente los datos.\n";
	system("pause");
	system("cls");
}

void ListaDeCuentasBancarias::actualizarDatosPorCliente(Nodo<Cliente*>* cliente, int id) 
{
	Nodo<CuentaBancaria*>* aux;
	tm* FechaCreacion;
	string Contrasenia, NombreCliente, ApellidoCliente;
	int idCliente = 0, TipoCuenta, FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio;
	cout << "Ingrese la nueva contrasenia de la Cuenta Bancaria: ";
	cin >> Contrasenia;
	cout << "Ingrese el nuevo Tipo de Cuenta de la Cuenta Bancaria: \n";
	cout << "(1: CREDITO, 2: DEBITO, 3: OTRO";
	cin >> TipoCuenta;
	FechaCreacion = generar_fecha();
	FechaCreacion_dia = FechaCreacion->tm_mday;
	FechaCreacion_mes = FechaCreacion->tm_mon;
	FechaCreacion_anio = FechaCreacion->tm_year;
	CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia, cliente->getDato()->getNombre(), cliente->getDato()->getApellido(), TipoCuenta,
	FechaCreacion, FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio,cliente->getId());
	modificarPorId(nuevoCuentaBancaria, id);
	escribirEnArchivo();
	cout << "Se reemplazo correctamente los datos.\n";
	system("pause");
	system("cls");
}

void ListaDeCuentasBancarias::menu()
{
	int aux;
	int opcion;
	int id;
	do
	{
		system("cls");
		cout << "1. Listar Cuentas Bancarias" << endl;
		cout << "2. Consultar Cuenta Bancaria" << endl;
		cout << "3. Eliminar Cuenta Bancaria" << endl;
		cout << "4. Listar Cuentas Bancarias por Id del Cliente" << endl;
		cout << "5. Listar Cuentas Bancarias por Tipo de Cuenta:" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			mostrar();
			break;
		case 2:
			cout << "Ingrese id de la Cuenta Bancaria a buscar: ";
			cin >> id;
			cout << this->buscar(id);
			break;
		case 3:
			cout << "Ingrese id de la Cuenta Bancaria a eliminar: ";
			cin >> id;
			this->eliminarPorId(id);
			break;
		case 4:
			cout << "Ingrese el id del cliente: ";
			cin >> id;
			listarPorIdDeCliente(id);
			break;
		case 5:
		{
			ETipoCuenta TipoCuentaEnum;
			cout << "Ingrese el tipo de cuenta que desea buscar: \n";
			cout << "(1: DEBITO, 2:CREDITO, 3: OTRO)\n";
			cin >> aux;
			switch (aux) {
			case 1:
				TipoCuentaEnum = DEBITO;
				break;
			case 2:
				TipoCuentaEnum = CREDITO;
				break;
			default:
				TipoCuentaEnum = OTRACUENTA;
				break;
			}
			buscarPorTipoCuenta(TipoCuentaEnum);
			break;
		}
		case 6:
			cout << "Saliendo del menu de cuentas bancarias" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 6);
}


void ListaDeCuentasBancarias::menuCuentasBancariasPorCliente(Nodo<Cliente*>* clienteActual)
{
	Nodo<CuentaBancaria*>* cuentaBancariaActual;
	int opcion;
	int idCuentaBancaria;

	do
	{
		system("cls");
		cout << "1. Agregar una Cuenta Bancaria al Cliente" << endl;
		cout << "2. Agregar Cuenta Bancaria Random al Cliente" << endl;
		cout << "3. Mostrar las Cuentas Bancarias del Cliente" << endl;
		cout << "4. Acceder a la Cuenta Bancaria del Cliente" << endl;
		cout << "5. Eliminar una Cuenta Bancaria del Cliente" << endl;
		cout << "6. Actualizar Datos de una Cuenta Bancaria del cliente" << endl;
		cout << "7. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCuentaBancariaPorCliente(clienteActual);
			break;
		case 2:
			agregarCuentaBancariaRandomPorCliente(clienteActual);
			break;
		case 3:
			listarPorIdDeCliente(clienteActual->getId());
			break;
		case 4:
			listarPorIdDeCliente(clienteActual->getId());
			cout << "Ingrese id de la cuenta bancaria: ";
			cin >> idCuentaBancaria;
			cuentaBancariaActual = obtenerNodoPorId(idCuentaBancaria);
			if (cuentaBancariaActual->getId() != 0) {
				if (cuentaBancariaActual->getDato()->getIdCliente() == clienteActual->getId()) {
					menuCuentaBancariaParaCliente(cuentaBancariaActual);
				}
				else {
					cout << "Esta cuenta no pertenece al cliente actual" << endl;
				}
			} 
			else {
				cout << "No existe esta cuenta" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Ingrese id de la cuenta bancaria a eliminar: ";
			cin >> idCuentaBancaria;
			cuentaBancariaActual = obtenerNodoPorId(idCuentaBancaria);
			if (cuentaBancariaActual->getId() != 0) {

				if (cuentaBancariaActual->getDato()->getIdCliente() == clienteActual->getId()) {
					eliminarPorId(idCuentaBancaria);
				}
				else {
					cout << "No se puede eliminar una Cuenta Bancaria de otro cliente" << endl;
				}
			}
			else {
				cout << "No existe esta cuenta" << endl;
			}
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Ingrese id de la cuenta bancaria para actualizar sus datos: \n";
			cin >> idCuentaBancaria;
			cuentaBancariaActual = obtenerNodoPorId(idCuentaBancaria);
			if (cuentaBancariaActual->getId() > 0) {
				if (cuentaBancariaActual->getDato()->getIdCliente() == clienteActual->getId()) {
					actualizarDatosPorCliente(clienteActual, idCuentaBancaria);
				}
				else cout << "No se puede modificar los datos de una Cuenta Bancaria de otro cliente\n";
			}
			else cout << "No se encontro la Cuenta Bancaria"<<endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Saliendo del menu de clientes" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 7);
}


void ListaDeCuentasBancarias::menuCuentaBancariaIndividual(Nodo<CuentaBancaria*>* cuentaBancariaActual)
{
	ListaDeTarjetas* listaTarjetas = new ListaDeTarjetas();
	listaTarjetas->cargarTarjetas();
	ListaDeCanales* listaCanales = new ListaDeCanales();
	listaCanales->cargarCanales();
	int opcion;
	int idCuentaBancaria;
	int idTarjeta;
	Nodo<Tarjeta*, nullptr>*  tarjetaActual;
	if (cuentaBancariaActual->getDato()->getIdTarjeta() != 0) {
		do
		{
			system("cls");
			cout << "1. Acceder a la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "2. Mostrar la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "3. Eliminar la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "4. Renovar la Tarjeta de la Cuenta Bancaria" << endl;
			cout << "5. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			system("cls");
			switch (opcion)
			{
			case 1:			
				tarjetaActual = listaTarjetas->obtenerNodoPorId(cuentaBancariaActual->getDato()->getIdTarjeta());
				if (tarjetaActual->getId() != 0) {
					listaTarjetas->menuTarjetaIndividual(tarjetaActual);
				}
				else {
					cout << "No se encontro la tarjeta" << endl;
				}
				break;
			case 2:
				listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
				break;
			case 3:
				cuentaBancariaActual->getDato()->setIdTarjeta(0);
				system("pause");
				system("cls");
				return;
				break;
			case 4:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() != 0) {
					listaTarjetas->agregarTarjetaPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta renovada" << endl;
				}
				else {
					cout << "Ya tienes una tarjeta asociada a esta cuenta bancaria" << endl;
				}
				break;
			case 5:
				cout << "Saliendo del menu de Cuentas Bancarias" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 5);
	}
	else {
		do
		{
			system("cls");
			cout << "1. Agregar una Tarjeta" << endl;
			cout << "2. Agregar una Tarjeta Random" << endl;
			cout << "3. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			system("cls");
			switch (opcion)
			{
			case 1:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() == 0) {
					listaTarjetas->agregarTarjetaPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta agregada" << endl;
				}
				else {
					cout << "La Cuenta Bancaria ya tiene  una tarjeta asociada" << endl;

				}
				system("pause");
				system("cls");
				return;
				break;
			case 2:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() == 0) {
					listaTarjetas->agregarTarjetaRandomPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta agregada" << endl;
				}
				else {
					cout << "La Cuenta Bancaria ya tiene  una tarjeta asociada" << endl;
				}
				system("pause");
				system("cls");
				return;
				break;
			case 3:
				cout << "Saliendo del menu de cuenta bancaria" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 3);
	}

}


void ListaDeCuentasBancarias::menuCuentaBancariaParaCliente(Nodo<CuentaBancaria*>* cuentaBancariaActual)
{
	ListaDeTarjetas* listaTarjetas = new ListaDeTarjetas();
	listaTarjetas->cargarTarjetas();
	ListaDeCanales* listaCanales = new ListaDeCanales();
	listaCanales->cargarCanales();
	int opcion;
	int idCuentaBancaria;
	int idTarjeta;
	Nodo<Tarjeta*>*  tarjetaActual;
	if (cuentaBancariaActual->getDato()->getIdTarjeta() != 0) {
		do
		{
			system("cls");
			cout << "1. Acceder a la Tarjeta" << endl;
			cout << "2. Eliminar la Tarjeta" << endl;
			cout << "3. Renovar la Tarjeta" << endl;
			cout << "4. Acceder a un Canal para iniciar una Operacion" << endl;
			cout << "5. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			system("cls");
			switch (opcion)
			{
			case 1:
				tarjetaActual = listaTarjetas->obtenerNodoPorId(cuentaBancariaActual->getDato()->getIdTarjeta());
				if (tarjetaActual->getId() != 0) {
					listaTarjetas->menuTarjetaIndividual(tarjetaActual);
				}
				else {
					cout << "No se encontro la tarjeta" << endl;
				}
				break;
			case 2:
				cuentaBancariaActual->getDato()->setIdTarjeta(0);
				system("pause");
				system("cls");
				return;
				break;
			case 3:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() != 0) {
					listaTarjetas->agregarTarjetaPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta renovada" << endl;
				}
				else {
					cout << "Ya tienes una tarjeta asociada a esta cuenta bancaria" << endl;
				}
				break;
			case 4:
				listaCanales->menuDeAccesoPorCuentaBancariaParaCliente(cuentaBancariaActual);
				return;
				break;
			case 5:
				cout << "Saliendo del menu de Cuentas Bancarias" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 5);
	}
	else {
		do
		{
			system("cls");
			cout << "1. Agregar una Tarjeta" << endl;
			cout << "2. Agregar una Tarjeta Random" << endl;
			cout << "3. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			system("cls");
			switch (opcion)
			{
			case 1:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() == 0) {
					listaTarjetas->agregarTarjetaPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta agregada" << endl;
				}
				else {
					cout << "Ya tienes una tarjeta asociada a esta cuenta bancaria" << endl;
					//Agrega de nuevo el id de la tarjeta a la cuenta bancaria
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
				}
				system("pause");
				system("cls");
				return;
				break;
			case 2:
				if (cuentaBancariaActual->getDato()->getIdTarjeta() == 0) {
					listaTarjetas->agregarTarjetaRandomPorCuentaBancaria(cuentaBancariaActual);
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
					escribirEnArchivo();
					cout << "Tarjeta agregada" << endl;
				}
				else {
					cout << "Ya tienes una tarjeta asociada a esta Cuenta Bancaria" << endl;
					//Agrega de nuevo el id de la tarjeta a la cuenta bancaria
					idTarjeta = listaTarjetas->obtenerIdDeTarjetaPorIdDeCuentaBancaria(cuentaBancariaActual->getId());
					cuentaBancariaActual->getDato()->setIdTarjeta(idTarjeta);
				}
				system("pause");
				system("cls");
				return;
				break;
			case 3:
				cout << "Saliendo del menu de Cuenta Bancaria" << endl;
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 3);
	}
}


void ListaDeCuentasBancarias::escribirEnArchivo()
{
	ofstream file("CuentasBancarias.csv");
	if (file.is_open()) {
		Nodo<CuentaBancaria*>* aux = this->obtenerInicial();
		file << "Id,NombreCliente,ApellidoCliente,IdCliente,idTarjeta,TipoCuenta,Contrasenia,FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_Anio\n"; // Header
		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getNombreCliente() << ","
				<< aux->getDato()->getApellidoCliente() << ","
				<< aux->getDato()->getIdCliente() << ","
				<< aux->getDato()->getIdTarjeta() << ","
				<< aux->getDato()->getTipoCuenta() << ","
				<< aux->getDato()->getContrasenia() << ","
				<< aux->getDato()->getFechaCreacion_dia() << ","
				<<aux->getDato()->getFechaCreacion_mes()<<","
				<<aux->getDato()->getFechaCreacion_anio()<<"\n";
			aux = aux->getSiguiente();
		}
		file.close();
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}
}


void ListaDeCuentasBancarias::cargarCuentasBancarias() {
	ifstream file("CuentasBancarias.csv"); // Abre archivo
	if (file.is_open()) {
		string line;
		getline(file, line);//Ignora primera linea 
		while (getline(file, line)) {
			tm* FechaCreacion = generar_fecha();
			int id, IdCliente, idTarjeta, TipoCuenta,FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio;
			string Contrasenia,NombreCliente, ApellidoCliente;
			int pos = 1;
			//Id,NombreCliente,ApellidoCliente,IdCliente,idTarjeta,TipoCuenta,Contrasenia,FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_Anio
			pos = line.find(",");
			id = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			NombreCliente = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			ApellidoCliente = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			IdCliente = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			idTarjeta = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			TipoCuenta = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			Contrasenia = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCreacion_dia = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCreacion_mes = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCreacion_anio = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			FechaCreacion->tm_mday = FechaCreacion_dia;
			FechaCreacion->tm_mon = FechaCreacion_mes;
			FechaCreacion->tm_year = FechaCreacion_anio;
			CuentaBancaria* nuevoCuentaBancaria = new CuentaBancaria(Contrasenia,NombreCliente,ApellidoCliente,TipoCuenta,FechaCreacion,
			FechaCreacion_dia,FechaCreacion_mes,FechaCreacion_anio,IdCliente,idTarjeta);
			agregaPorIdDesordenado(nuevoCuentaBancaria, id);
		}
		file.close(); // Cierra archivo
		cout << "Cuentas cargadas correctamente.\n";
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}

}


void ListaDeCuentasBancarias::buscarPorTipoCuenta(ETipoCuenta tipoDeCuenta) {
	Nodo<CuentaBancaria*, nullptr>*aux = this->obtenerInicial();
	while (aux != nullptr) {
		if (aux->getDato()->getTipoCuenta() == tipoDeCuenta) {
			cout << endl;
			cout << "ID: " << aux->getId()<<endl;
			cout << aux->getDato()->descripcion() << endl;
		}
		aux = aux->getSiguiente();
		cout << "Cuenta(s) Bancaria(s) encontrada(s)\n";
		return;
	}
	cout << "No se encontro ninguna Cuenta Bancaria\n";
}