#include "pch.h"
#include "ListaDeTarjetas.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DatosRandom.h"


void ListaDeTarjetas::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay Tarjetas registradas" << endl;
		system("pause");
		system("cls");
		return;
	}
	Nodo<Tarjeta*, nullptr>*  aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		cout << "ID: " << aux->getId() << endl;
		cout << aux->getDato()->descripcion() << endl << endl;
		cout << "----------------------" << endl;
		cout << endl;
		aux = aux->getSiguiente();
	}
	system("pause");
	system("cls");
}


void ListaDeTarjetas::agregarTarjeta()
{
	tm* FechaCreacion, * FechaCaducidad;
	bool activado;
	int Activado, idCuentaB, idCliente,CVV,Divisa,TipoTarjeta;
	string Codigo,NombreCliente,ApellidoCliente;
	double saldo = 0;
	cout << "Ingrese el id del Cliente: ";
	cin >> idCliente;
	cout << "Ingrese el id de la Cuenta Bancaria: ";
	cin >> idCuentaB;
	cout << "Ingrese el Codigo de la Tarjeta: ";
	cin >> Codigo;
	cout << "Ingrese el CVV de la Tarjeta: ";
	cin >> CVV;
	cout << "Ingrese si esta activada la tarjeta: ";
	cin >> Activado;
	cout << "Ingrese la Divisa de la tarjeta: \n";
	cout << "(1: Soles, 2:Dolares)";
	cin >> Divisa;
	cout << "Ingrese el Tipo de Tarjeta: \n";
	cout << "(1:Visa, 2:American Express)\n";
	cin >> TipoTarjeta;
	cout << "Ingrese el Nombre del Cliente de la Tarjeta: ";
	cin >> NombreCliente;
	cout << "Ingrese el Apellido del Cliente de la Tarjeta: ";
	cin >> ApellidoCliente;
	activado = Activado == 1 ? true : false;
	FechaCreacion = generar_fecha();
	FechaCaducidad = generar_fecha_expiracion_tarjeta();
	Tarjeta* nuevaTarjeta = new Tarjeta(Codigo,CVV,activado,TipoTarjeta,Divisa,saldo,FechaCreacion,FechaCaducidad, FechaCreacion->tm_mon, FechaCreacion->tm_year, FechaCaducidad->tm_mon, 
		FechaCaducidad->tm_year, NombreCliente,	ApellidoCliente,idCuentaB,idCliente);
	this->agregarAlFinal(nuevaTarjeta);
	escribirEnArchivo();
	cout << "Tarjeta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeTarjetas::agregarTarjetaPorCuentaBancaria(Nodo<CuentaBancaria*>*cuentaBancariaActual)
{
	tm* FechaCreacion, *FechaCaducidad;
	bool activado;
	int Activado, CVV, Divisa, TipoTarjeta;
	string Codigo;
	double saldo = 0;
	cout << "Ingrese el Codigo de la Tarjeta: ";
	cin >> Codigo;
	cout << "Ingrese el CVV de la Tarjeta: ";
	cin >> CVV;
	cout << "Ingrese si esta activada la tarjeta: ";
	cin >> Activado;
	cout << "Ingrese la Divisa de la tarjeta: \n";
	cout << "(1: Soles, 2:Dolares)";
	cin >> Divisa;
	cout << "Ingrese el Tipo de Tarjeta: \n";
	cout << "(1:Visa, 2:American Express)\n";
	cin >> TipoTarjeta;
	FechaCreacion = generar_fecha();
	FechaCaducidad = generar_fecha_expiracion_tarjeta();
	activado = Activado == 1 ? true : false;
	Tarjeta* nuevaTarjeta = new Tarjeta(Codigo, CVV, activado, TipoTarjeta, Divisa, saldo, FechaCreacion, FechaCaducidad,FechaCreacion->tm_mon,FechaCreacion->tm_year,FechaCaducidad->tm_mon,
	FechaCaducidad->tm_year,cuentaBancariaActual->getDato()->getNombreCliente(),cuentaBancariaActual->getDato()->getApellidoCliente(), cuentaBancariaActual->getId(), cuentaBancariaActual->getDato()->getIdCliente());
	this->agregarAlFinal(nuevaTarjeta);
	escribirEnArchivo();
	cout << "Tarjeta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeTarjetas::agregarTarjetaRandom()
{
	tm* FechaCreacion, * FechaCaducidad;
	bool activado;
	int idCuentaB, idCliente, CVV, Divisa, TipoTarjeta;
	string Codigo, NombreCliente, ApellidoCliente;
	double saldo=0;

	activado = random(0, 1);
	idCuentaB = random(0, 100);
	idCliente = random(0, 100);
	CVV = generar_CVV();
	Divisa = random(1, 3);
	TipoTarjeta = random(1, 3);
	Codigo = generar_CodigoTarjeta();
	FechaCreacion = generar_fecha();
	FechaCaducidad = generar_fecha_expiracion_tarjeta();
	NombreCliente = generar_nombre();
	ApellidoCliente = generar_apellido();

	Tarjeta* nuevaTarjeta = new Tarjeta(Codigo, CVV, activado, TipoTarjeta, Divisa, saldo, FechaCreacion, FechaCaducidad, FechaCreacion->tm_mon, FechaCreacion->tm_year, FechaCaducidad->tm_mon, FechaCaducidad->tm_year,
		NombreCliente, ApellidoCliente, 0, 0);
	this->agregarAlFinal(nuevaTarjeta);
	escribirEnArchivo();
	cout << "Tarjeta agregada correctamente.\n";
	system("pause");
	system("cls");
}


void ListaDeTarjetas::agregarTarjetaRandomPorCuentaBancaria(Nodo<CuentaBancaria*>*cuentaBancariaActual)
{
	tm* FechaCreacion, * FechaCaducidad;
	bool activado;
	int CVV, Divisa, TipoTarjeta;
	string Codigo;
	double saldo = 0;
	int FechaCreacion_mes, FechaCreacion_anio;

	activado = random(0, 1);
	CVV = generar_CVV();
	Divisa = random(1, 3);
	TipoTarjeta = random(1, 3);
	Codigo = generar_CodigoTarjeta();
	FechaCreacion = generar_fecha();
	FechaCreacion_mes = FechaCreacion->tm_mon;
	FechaCreacion_anio = FechaCreacion->tm_year;
	FechaCaducidad = generar_fecha_expiracion_tarjeta();

	Tarjeta* nuevaTarjeta = new Tarjeta(Codigo, CVV, activado, TipoTarjeta, Divisa, saldo, FechaCreacion, FechaCaducidad, FechaCreacion_mes,FechaCreacion_anio,FechaCaducidad->tm_mon,FechaCaducidad->tm_year,
	cuentaBancariaActual->getDato()->getNombreCliente(),cuentaBancariaActual->getDato()->getApellidoCliente(), cuentaBancariaActual->getId(), cuentaBancariaActual->getDato()->getIdCliente());
	this->agregarAlFinal(nuevaTarjeta);
	escribirEnArchivo();
	cout << "Tarjeta agregada correctamente.\n";
	system("pause");
	system("cls");
}


int ListaDeTarjetas::buscar(int id)
{
	Nodo<Tarjeta*, nullptr>*  aux = obtenerInicial();
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
	cout << "No se encontro la Tarjeta" << endl;
	return 0;
	system("pause");
	system("cls");
}

void ListaDeTarjetas::listarPorId(int id)
{
	Nodo<Tarjeta*>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getId() == id)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
		}
		aux = aux->getSiguiente();
	}
}

bool ListaDeTarjetas::buscarPorIdDeCliente(int idCliente)
{
	int eoncontradas = 0;
	Nodo<Tarjeta*, nullptr>*  aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getIdCliente() == idCliente)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			eoncontradas++;
		}
		aux = aux->getSiguiente();
	}
	if (eoncontradas == 0)
	{
		cout << "No se encontro la Tarjeta" << endl;
		system("pause");
		system("cls");
		return false;
	}
	system("pause");
	system("cls");
	return true;
}


int ListaDeTarjetas::obtenerIdDeTarjetaPorIdDeCuentaBancaria(int idCuentaBancaria)
{
	int contador = 0;
	Nodo<Tarjeta*, nullptr>*  aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getIdCuentaBancaria() == idCuentaBancaria)
		{
			cout << endl;
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			contador++;
			system("pause");
			return aux->getId();
		}
		aux = aux->getSiguiente();
	}
	if(contador==0)
	{
		cout << "No se encontro la Cuenta Bancaria" << endl;
	}
	system("pause");
	return 0;
}

void ListaDeTarjetas::actualizarDatos(Nodo<Tarjeta*>* tarjeta)
{
	tm* FechaCreacion, * FechaCaducidad;
	bool activado;
	int Activado, CVV, Divisa, TipoTarjeta,FechaCreacion_mes,FechaCreacion_anio,FechaCaducidad_mes,FechaCaducidad_anio;
	string Codigo, NombreCliente, ApellidoCliente;
	double saldo = 0;
	cout << "Ingrese el nuevo codigo de la Tarjeta: ";
	cin >> Codigo;
	cout << "Ingrese el nuevo CVV de la Tarjeta: ";
	cin >> CVV;
	cout << "Ingrese la Divisa de la tarjeta: \n";
	cout << "(1: Soles, 2:Dolares)";
	cin >> Divisa;
	cout << "Ingrese el Tipo de Tarjeta: \n";
	cout << "(1:Visa, 2:American Express)\n";
	cin >> TipoTarjeta;
	activado = true;
	FechaCreacion = generar_fecha();
	FechaCaducidad = generar_fecha_expiracion_tarjeta();
	Tarjeta* nuevaTarjeta = new Tarjeta(Codigo, CVV, activado, TipoTarjeta, Divisa, saldo, FechaCreacion, FechaCaducidad,FechaCreacion->tm_mon,FechaCreacion->tm_year,
	FechaCaducidad->tm_mon,FechaCaducidad->tm_year,NombreCliente,ApellidoCliente,tarjeta->getDato()->getIdCuentaBancaria(),tarjeta->getDato()->getIdCliente());
	this->modificarPorId(nuevaTarjeta, tarjeta->getId());
	escribirEnArchivo();
	cout << "Se actualizo correctamente los datos.\n";
	system("pause");
	system("cls");
}


void ListaDeTarjetas::activarPorId(int id) 
{
	Nodo<Tarjeta*>* aux = this->obtenerInicial();
	while (aux != nullptr) 
	{
		if (aux->getId() == id) {
			aux->getDato()->Activar();
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			cout << "Tarjeta activada\n";
			escribirEnArchivo();
			system("pause");
			system("cls");
			return;
		}
		aux = aux->getSiguiente();
	}
	cout << "Tarjeta no encontrada\n";
	system("pause");
	system("cls");
	return;
}


void ListaDeTarjetas::desactivarPorId(int id) 
{
	Nodo<Tarjeta*>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getId() == id) {
			aux->getDato()->Desactivar();
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			cout << "Tarjeta desactivada\n";
			escribirEnArchivo();
			system("pause");
			system("cls");
			return;
		}
		aux = aux->getSiguiente();
	}
	cout << "Tarjeta no encontrada\n";
	system("pause");
	system("cls");
	return;
}


void ListaDeTarjetas::listarTarjetasActivadas() 
{
	int contador = 0;
	Nodo<Tarjeta*>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getActivado()) {
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			contador++;
		}
		aux = aux->getSiguiente();
	}
	if(contador==0)
	{
		cout << "Tarjeta no encontrada\n";
	}
	system("pause");
	system("cls");
	return;
}


void ListaDeTarjetas::listarTarjetasDesactivadas() 
{
	int contador = 0;
	Nodo<Tarjeta*>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (!aux->getDato()->getActivado()) {
			cout << "ID: " << aux->getId() << endl;
			cout << aux->getDato()->descripcion() << endl << endl;
			cout << "----------------------" << endl;
			cout << endl;
			contador++;
		}
		aux = aux->getSiguiente();
	}
	if(contador==0)cout << "Tarjeta no encontrada\n";
	system("pause");
	system("cls");
	return;
}

void ListaDeTarjetas::ordenarMayorMenorSaldo()
{
	Nodo<Tarjeta*>* aux = obtenerPrimero();
	Nodo<Tarjeta*>* aux2;
	for (int i = 1; i <= getUltimoid(); i++)
	{
		aux2 = aux;
		for (int j = 1; j <= getUltimoid()-i; j++) {
			if (aux2 != nullptr)
			{
				if (aux2->getDato()->getSaldo() < aux2->getSiguiente()->getDato()->getSaldo())
				{
					int temp_id = aux2->getId();
					Tarjeta* tarj_aux = aux2->getDato();
					aux2->setId(aux2->getSiguiente()->getId());
					aux2->setDato(aux2->getSiguiente()->getDato());
					aux2->getSiguiente()->setId(temp_id);
					aux2->getSiguiente()->setDato(tarj_aux);
				}
				aux2 = aux2->getSiguiente();
			}
			else break;
		}
		aux = aux->getSiguiente();
	}
}

void ListaDeTarjetas::ordenarMenorMayorSaldo()
{
	Nodo<Tarjeta*>* aux = obtenerPrimero();
	Nodo<Tarjeta*>* aux2;
	for (int i = 1; i <= getUltimoid(); i++)
	{
		aux2 = aux;
		for (int j = 1; j <= getUltimoid() - i; j++) {
			if (aux2 != nullptr)
			{
				if (aux2->getDato()->getSaldo() > aux2->getSiguiente()->getDato()->getSaldo())
				{
					int temp_id = aux2->getId();
					Tarjeta* tarj_aux = aux2->getDato();
					aux2->setId(aux2->getSiguiente()->getId());
					aux2->setDato(aux2->getSiguiente()->getDato());
					aux2->getSiguiente()->setId(temp_id);
					aux2->getSiguiente()->setDato(tarj_aux);
				}
				aux2 = aux2->getSiguiente();
			}
			else break;
		}
		aux = aux->getSiguiente();
	}
}


void ListaDeTarjetas::menu()
{
	int opcion;
	int id;
	do
	{
		system("cls");
		cout << "1. Listar Tarjetas" << endl;
		cout << "2. Consultar Tarjeta" << endl;
		cout << "3. Activar Tarjeta" << endl;
		cout << "4. Desactivar Tarjeta" << endl;
		cout << "5. Listar Tarjetas Activas" << endl;
		cout << "6. Listar Tarjetas Desactivadas" << endl;
		cout << "7. Listar tarjetas de menor a mayor saldo" << endl;
		cout << "8. Listar tarjetas de mayor a menor saldo" << endl;
		cout << "9. Eliminar Tarjeta" << endl;
		cout << "10. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			mostrar();
			break;
		case 2:
			cout << "Ingrese id de la tarjeta a buscar: ";
			cin >> id;
			cout << this->buscar(id);
			break;
		case 3:
			cout << "Ingrese id de la tarjeta a activar: ";
			cin >> id;
			activarPorId(id);
			break;
		case 4:
			cout << "Ingrese id de la tarjeta a desactivar: ";
			cin >> id;
			desactivarPorId(id);
			break;
		case 5:
			listarTarjetasActivadas();
			break;
		case 6:
			listarTarjetasDesactivadas();
			break;
		case 7:
			ordenarMenorMayorSaldo();
			break;
		case 8:
			ordenarMayorMenorSaldo();
			break;
		case 9:
			cout << "Ingrese id a eliminar: ";
			cin >> id;
			this->eliminarPorId(id);
			break;
		case 10:
			cout << "Saliendo del menu de Tarjetas" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 10);
}


void ListaDeTarjetas::menuTarjetaIndividual(Nodo<Tarjeta*>*  tarjetaActual)
{
	int opcion;
	int id;
	do
	{
		system("cls");
		cout << "1. Ver datos de la Tarjeta de la Cuenta Bancaria" << endl;
		cout << "2. Actualizar datos de la Tarjeta de la Cuenta Bancaria" << endl;
		cout << "3. Validar si la tarjeta esta Vigente" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			cout << tarjetaActual->getDato()->descripcion() << endl;
			system("pause");
			break;
		case 2:
			actualizarDatos(tarjetaActual);
			break;
		case 3:
			cout << (tarjetaActual->getDato()->validateFechaCaducidad() ? "La tarjeta esta vigente" : "La tarjeta esta vencida") << endl;
			system("pause");
			break;
		case 4:
			cout << "Saliendo del menu de tarjeta" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 4);
}


void ListaDeTarjetas::escribirEnArchivo()
{
	ofstream file("Tarjetas.csv");
	if (file.is_open()) {
		Nodo<Tarjeta*>* aux = this->obtenerInicial();
		file << "Id,Codigo,CVV,Saldo,NombreCliente,ApellidoCliente,TipoTarjeta,Divisa,Activado,FechaCreacion_mes,FechaCreacion_anio,FechaCaducidad_mes,FechaCaducidad_anio,IdCliente,IdCuentaBancaria\n"; // Header
		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getCodigo() << ","
				<< aux->getDato()->getCVV() << ","
				<< aux->getDato()->getSaldo() << ","
				<< aux->getDato()->getNombreCliente() << ","
				<< aux->getDato()->getApellidoCliente() << ","
				<< aux->getDato()->getTipoTarjeta() << ","
				<< aux->getDato()->getDivisa() << ","
				<< aux->getDato()->getActivado_int() << ","
				<< aux->getDato()->getFechaCreacion_mes() << ","
				<< aux->getDato()->getFechaCreacion_anio()<<","
				<< aux->getDato()->getFechaCaducidad_mes()<<","
				<< aux->getDato()->getFechaCaducidad_anio()<<","
				<< aux->getDato()->getIdCliente() << ","
				<< aux->getDato()->getIdCuentaBancaria() << "\n";
			aux = aux->getSiguiente();
		}
		file.close();
		system("cls");
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
		system("pause");
		system("cls");
	}
}


void ListaDeTarjetas::cargarTarjetas() {
	ifstream file("Tarjetas.csv"); // Abre archivo
	if (file.is_open()) {
		string line;
		getline(file, line);//Ignora primera linea 
		while (getline(file, line)) {
			bool activado;
			tm* FechaCreacion, * FechaCaducidad;
			int id, Activado, idCuentaB, idCliente, CVV, Divisa, TipoTarjeta, FechaCreacion_mes, FechaCreacion_anio,
			FechaCaducidad_mes,FechaCaducidad_anio;
			string Codigo, NombreCliente, ApellidoCliente;
			double saldo;
			int pos = 1;
			// Id,Codigo,CVV,Saldo,NombreCliente,ApellidoCliente,TipoTarjeta,Divisa,Activado,FechaCreacion_mes,FechaCreacion_anio,
			// FechaCaducidad_mes,FechaCaducidad_anio,IdCliente,NombreCliente,TipoCuenta
			pos = line.find(",");
			id = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			Codigo = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			CVV = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			saldo = stod(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			NombreCliente = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			ApellidoCliente = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			TipoTarjeta = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			Divisa = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			Activado = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCreacion_mes = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCreacion_anio = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCaducidad_mes = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			FechaCaducidad_anio = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			idCliente = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			idCuentaB = stoi(line.substr(0, pos));
			activado = Activado == 1 ? true : false;
			FechaCreacion = generar_fecha();
			FechaCreacion->tm_year = FechaCreacion_anio;
			FechaCreacion->tm_mon = FechaCaducidad_mes;
			FechaCaducidad = generar_fecha_expiracion_tarjeta();
			FechaCaducidad->tm_year = FechaCaducidad_anio;
			FechaCaducidad->tm_mon = FechaCaducidad_mes;
			Tarjeta* nuevaTarjeta = new Tarjeta(Codigo, CVV, activado, TipoTarjeta, Divisa, saldo, FechaCreacion, FechaCaducidad,FechaCreacion_mes,
				FechaCreacion_anio,FechaCaducidad_mes,FechaCaducidad_anio,NombreCliente,ApellidoCliente, idCuentaB, idCliente);
			agregaPorIdDesordenado(nuevaTarjeta, id);
		}
		file.close(); // Cierra archivo
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
		system("pause");
		system("cls");
	}

}