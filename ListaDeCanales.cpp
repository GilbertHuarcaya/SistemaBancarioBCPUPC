#include "pch.h"
#include "ListaDeCanales.h"
#include <fstream>
#include "CuentaBancaria.h"

void ListaDeCanales::mostrar()
{
	if (this->esVacia())
	{
		cout << "No hay canales registrados" << endl;
		return;
	}
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
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


void ListaDeCanales::agregarCanal()
{
	string nombre, direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	tipoDeCanal = menuParaObtenerTipoDeCanal();

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::agregarCanalRandom()
{
	string nombre, direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	//canal aleatorio
	nombre = "Canal" + to_string(rand() % 100);
	direccion = "Direccion" + to_string(rand() % 100);
	ciudad = "Ciudad" + to_string(rand() % 100);
	distrito = "Distrito" + to_string(rand() % 100);
	departamento = "Departamento" + to_string(rand() % 100);
	int randomTipoDeCanal = rand() % 5 + 1;
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, randomTipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::agregarCanalPorTipo(ETipoDeCanal tipoDeCanal)
{
	string nombre, direccion, ciudad, distrito, departamento;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::agregarCanalPorNombre(string nombre)
{
	string direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	tipoDeCanal = menuParaObtenerTipoDeCanal();

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::agregarCanalPorDistrito(string distrito)
{
	string nombre, direccion, ciudad, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	tipoDeCanal = menuParaObtenerTipoDeCanal();

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::agregarCanalPorDepartamento(string departamento)
{
	string nombre, direccion, ciudad, distrito;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	int opcion;
	tipoDeCanal = menuParaObtenerTipoDeCanal();

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::agregarCanalPorCiudad(string ciudad)
{
	string nombre, direccion, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	tipoDeCanal = menuParaObtenerTipoDeCanal();

	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->agregarAlFinal(nuevoCanal);
	escribirEnArchivo();
	cout << "Canal agregado" << endl;
	system("pause");
	system("cls");

}


int ListaDeCanales::buscar(int id)
{
	NodoDobleEnlazado<Canal*, nullptr>* canal = obtenerNodoDobleEnlazadoPorId(id);
	if (canal->getId() != 0)
	{
		cout << endl;
		cout << "ID: " << canal->getId() << endl;
		cout << canal->getDato()->descripcion() << endl << endl;
		cout << "----------------------" << endl;
		cout << endl;
		system("pause");
		return canal->getId();
	}
	cout << "No se encontro el canal" << endl;
	system("pause");
	return 0;
}


int ListaDeCanales::buscarPorTipo(ETipoDeCanal tipoDeCanal)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getTipoDeCanal() == tipoDeCanal)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese tipo" << endl;
	}
	system("pause");
	return encontrados;
}


int ListaDeCanales::buscarPorNombre(string nombre)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getNombre() == nombre)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese nombre" << endl;
	}
	system("pause");
	return encontrados;
}


int ListaDeCanales::buscarPorDistrito(string distrito)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getDistrito() == distrito)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese distrito" << endl;
	}
	system("pause");
	return encontrados;
}


int ListaDeCanales::buscarPorDepartamento(string departamento)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getDepartamento() == departamento)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en ese Departamento" << endl;
	}
	system("pause");
	return encontrados;
}


int ListaDeCanales::buscarPorCiudad(string ciudad)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getCiudad() == ciudad)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal en esa Ciudad" << endl;
	}
	system("pause");
	return encontrados;
}


int ListaDeCanales::buscarPorActivo(bool activo)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	int encontrados = 0;
	while (aux != nullptr)
	{
		if (aux->getDato()->getActivo() == activo)
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
	if (encontrados == 0)
	{
		cout << "No se encontro ningun canal con ese estado" << endl;
	}
	system("pause");
	return encontrados;
}

void ListaDeCanales::ordenarPorNombre()
{
    if (this->esVacia())
    {
        cout << "No hay canales registrados" << endl;
        return;
    }

    bool intercambio = true;
    NodoDobleEnlazado<Canal*, nullptr>* actual;
    NodoDobleEnlazado<Canal*, nullptr>* siguiente = nullptr;

    while (intercambio)
    {
        intercambio = false;
        actual = this->obtenerInicial();

        while (actual->getSiguiente() != siguiente)
        {
            if (actual->getDato()->getNombre() > actual->getSiguiente()->getDato()->getNombre())
            {
				int tempId = actual->getId();
                Canal* temp = actual->getDato();
				actual->setId(actual->getSiguiente()->getId());
                actual->setDato(actual->getSiguiente()->getDato());
				actual->getSiguiente()->setId(tempId);
                actual->getSiguiente()->setDato(temp);
                intercambio = true;
            }
            actual = actual->getSiguiente();
        }
        siguiente = actual;
    }
	escribirEnArchivo();
    cout << "Canales ordenados por nombre" << endl;
    system("pause");
    system("cls");
}


void ListaDeCanales::actualizarDatos(int id)
{
	string nombre, direccion, ciudad, distrito, departamento;
	ETipoDeCanal tipoDeCanal;
	cout << "Ingrese el nombre del canal: ";
	cin >> nombre;
	cout << "Ingrese la direccion del canal: ";
	cin >> direccion;
	cout << "Ingrese la ciudad del canal: ";
	cin >> ciudad;
	cout << "Ingrese el distrito del canal: ";
	cin >> distrito;
	cout << "Ingrese el departamento del canal: ";
	cin >> departamento;
	tipoDeCanal = menuParaObtenerTipoDeCanal();
	Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, true, tipoDeCanal);
	this->modificarPorId(nuevoCanal, id);
	escribirEnArchivo();
	cout << "Canal actualizado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::menu()
{
	int opcion;
	int id;
	do
	{
		system("cls");
		cout << "1. Agregar canal" << endl;
		cout << "2. Mostrar canales" << endl;
		cout << "3. Buscar canal" << endl;
		cout << "4. Actualizar canal" << endl;
		cout << "5. Eliminar canal" << endl;
		cout << "6. Agregar canal random" << endl;
		cout << "7. Gestionar Por tipo" << endl;
		cout << "8. Ordenar Canales por Nombre\n";
		cout << "9. Ordenar Canales por Id\n";
		cout << "10. Activar todos los Canales\n";
		cout << "11. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			agregarCanal();
			cout << "Canal agregado" << endl;
			break;
		case 2:
			mostrar();
			break;
		case 3:
			cout << "Ingrese id a buscar: ";
			cin >> id;
			cout << this->buscar(id);
			break;
		case 4:
			cout << "Ingrese id a reemplazar: ";
			cin >> id;
			actualizarDatos(id);
			break;
		case 5:
			cout << "Ingrese id a eliminar: ";
			cin >> id;
			this->eliminarPorId(id);
			break;
		case 6:
			agregarCanalRandom();
			cout << "Canal agregado" << endl;
			break;
		case 7:
			menuDeGestion();
			break;
		case 8:
			ordenarPorNombre();
			break;
		case 9:
			ordenarPorId();
			escribirEnArchivo();
			cout << "Canales ordenados" << endl;
			system("pause");
			break;
		case 10: 
			activarTodosLosCanales(this->obtenerInicial());
			escribirEnArchivo();
			cout << "Canales activados" << endl;
			system("pause");
			break;
		case 11:
			cout << "Saliendo del menu de canales" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 11);
}


ETipoDeCanal ListaDeCanales::menuParaObtenerTipoDeCanal()
{
	int opcion;
	do {
		cout << "Ingrese el tipo de canal: " << endl;
		cout << "1. WEB" << endl;
		cout << "2. APP" << endl;
		cout << "3. VENTANILLA" << endl;
		cout << "4. AGENTE" << endl;
		cout << "5. YAPE" << endl;
		cout << "6. CAJERO" << endl;
		cin >> opcion;
	} while (opcion < 1 || opcion > 6);
	return (ETipoDeCanal)opcion;
}


void ListaDeCanales::menuParaActualizarCanal(NodoDobleEnlazado<Canal*>* canal)
{
	int opcion;
	do
	{
		system("cls");
		cout << "1. Activar canal" << endl;
		cout << "2. Desactivar canal" << endl;
		cout << "3. Actualizar informacion del canal" << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion)
		{
		case 1:
			activarCanal(canal->getId());
			break;
		case 2:
			desactivarCanal(canal->getId());
			break;
		case 3:
			actualizarDatos(canal->getId());
			break;
		case 4:
			cout << "Saliendo del menu de actualizacion de canal" << endl;
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}
	} while (opcion != 4);
}


void ListaDeCanales::activarCanal(int id)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getId() == id)
		{
			aux->getDato()->setActivo(true);
			break;
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canal activado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::desactivarCanal(int id)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getId() == id)
		{
			aux->getDato()->setActivo(false);
			break;
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canal desactivado" << endl;
	system("pause");
	system("cls");
}

void ListaDeCanales::activarTodosLosCanales(NodoDobleEnlazado<Canal*>* canal)
{
    if (canal == nullptr)
    {
        return;
    }
    canal->getDato()->setActivo(true);
    activarTodosLosCanales(canal->getSiguiente());
}


void ListaDeCanales::escribirEnArchivo()
{
	ofstream file("Canales.csv");
	if (file.is_open()) {
		NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
		file << "Id,Nombre,Direccion,Ciudad,Distrito,Departamento,Activo,TipoDeCanal\n";

		while (aux != nullptr)
		{
			file << aux->getId() << ","
				<< aux->getDato()->getNombre() << ","
				<< aux->getDato()->getDireccion() << ","
				<< aux->getDato()->getCiudad() << ","
				<< aux->getDato()->getDistrito() << ","
				<< aux->getDato()->getDepartamento() << ","
				<< aux->getDato()->getActivo() << ","
				<< aux->getDato()->getTipoDeCanal() << "\n";

			aux = aux->getSiguiente();
		}
		file.close();
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}
}


void ListaDeCanales::cargarCanales() {
	ifstream file("Canales.csv"); // Open file to read

	if (file.is_open()) {
		string line;
		getline(file, line);//Ignora primera linea 
		while (getline(file, line)) {
			string nombre, direccion, ciudad, distrito, departamento, tipoDeCanal, activo;
			int id;
			int pos = 1;
			// ID,Nombre,Direccion,Ciudad,Distrito,Departamento,Activo,TipoDeCanal
			pos = line.find(",");
			id = stoi(line.substr(0, pos));
			line = line.substr(pos + 1);
			pos = line.find(",");
			nombre = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			direccion = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			ciudad = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			distrito = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			departamento = line.substr(0, pos);
			line = line.substr(pos + 1);
			pos = line.find(",");
			activo = line.substr(0, pos);
			line = line.substr(pos + 1);
			tipoDeCanal = line;

			//convertir string a int and do not use stoi
			ETipoDeCanal tipoDeCanalInt = WEB;
			if (tipoDeCanal == "1") {
				tipoDeCanalInt = VENTANILLA;
			}
			else if (tipoDeCanal == "2") {
				tipoDeCanalInt = AGENTE;
			}
			else if (tipoDeCanal == "3") {
				tipoDeCanalInt = WEB;
			}
			else if (tipoDeCanal == "4") {
				tipoDeCanalInt = APP;
			}
			else if (tipoDeCanal == "5") {
				tipoDeCanalInt = YAPE;
			}
			else if (tipoDeCanal == "6") {
				tipoDeCanalInt = CAJERO;
			}
			else {
				tipoDeCanalInt = OTROCANAL;
			}

			//convertir string a bool
			bool activoBool = activo == "1" ? true : false;

			
			Canal* nuevoCanal = new Canal(nombre, direccion, ciudad, distrito, departamento, activoBool, tipoDeCanalInt);
			agregaPorIdDesordenado(nuevoCanal, id);
			
		}

		file.close(); // Close the file
	}
	else {
		cout << "No se pudo abrir el archivo.\n";
	}

}


void ListaDeCanales::menuDeGestion() {
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int opcion;
	do {
		system("cls");
		cout << "# Canales de Atencion\n";
		cout << "1. Gestionar Cajeros Autom�ticos\n";
		cout << "2. Gestionar Ventanillas\n";
		cout << "3. Gestionar Agentes\n";
		cout << "4. Gestionar Yape\n";
		cout << "5. Gestion de Plataforma Web\n";
		cout << "6. Gestion de Plataforma APP\n";
		cout << "7. Buscar y Gestionar canal\n";
		cout << "8. Volver\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			gestionarPorTipoLista(CAJERO, "CAJEROS");
			break;
		case 2:
			gestionarPorTipoLista(VENTANILLA, "VENTANILLAS");
			break;
		case 3:
			
			gestionarPorTipoLista(AGENTE, "AGENTES");
			break;
		case 4:
			
			gestionarPorTipoIndividual(YAPE, "YAPE");
			break;
		case 5:
			
			gestionarPorTipoIndividual(WEB, "WEB");
			break;
		case 6:
			
			gestionarPorTipoIndividual(APP, "APP");
			break;
		case 7:
			canal = obtenerCanal();
			if (canal->getDato()->getTipoDeCanal() == CAJERO ||
				canal->getDato()->getTipoDeCanal() == VENTANILLA ||
				canal->getDato()->getTipoDeCanal() == AGENTE) {
				gestionarPorTipoLista(canal->getDato()->getTipoDeCanal(), "CANAL");
			}
			else {
				gestionarPorTipoIndividual(canal->getDato()->getTipoDeCanal(), "CANAL");
			}
			break;
		case 8:
			break;
		default:

			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 8);
}


void ListaDeCanales::menuDeAcceso()
{
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int opcion;
	do {
		cout << "# Canales de Atencion\n";
		cout << "1. Acceder a Cajeros Autom�ticos\n";
		cout << "2. Acceder a Ventanillas\n";
		cout << "3. Acceder a Agentes\n";
		cout << "4. Acceder a Yape\n";
		cout << "5. Acceder a Plataforma Web\n";
		cout << "6. Acceder a Plataforma APP\n";
		cout << "7. Volver\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			filtrarYAccederAMenuPorTipo(CAJERO, "CAJEROS");
			break;
		case 2:
			filtrarYAccederAMenuPorTipo(VENTANILLA, "VENTANILLAS");
			break;
		case 3:
			filtrarYAccederAMenuPorTipo(AGENTE, "AGENTES");
			break;
		case 4:
			filtrarYAccederAMenuPorTipo(YAPE, "YAPE");
			break;
		case 5:
			filtrarYAccederAMenuPorTipo(WEB, "WEB");
			break;
		case 6:
			filtrarYAccederAMenuPorTipo(APP, "APP");
			break;
		case 7:
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 7);
}


void ListaDeCanales::menuDeAccesoPorCuentaBancariaParaCliente(Nodo<CuentaBancaria*>*cuentaBancaria)
{
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int opcion;
	do {
		system("cls");
		cout << "# Canales de Atencion\n";
		cout << "1. Acceder a Cajeros Autom�ticos\n";
		cout << "2. Acceder a Ventanillas\n";
		cout << "3. Acceder a Agentes\n";
		cout << "4. Acceder a Yape\n";
		cout << "5. Acceder a Plataforma Web\n";
		cout << "6. Acceder a Plataforma APP\n";
		cout << "7. Volver\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			filtrarYAccederAMenuPorTipo(CAJERO, "CAJEROS", cuentaBancaria);
			break;
		case 2:

			filtrarYAccederAMenuPorTipo(VENTANILLA, "VENTANILLAS", cuentaBancaria);
			break;
		case 3:

			filtrarYAccederAMenuPorTipo(AGENTE, "AGENTES", cuentaBancaria);
			break;
		case 4:
			filtrarYAccederAMenuPorTipo(YAPE, "YAPE", cuentaBancaria);
			break;
		case 5:
			filtrarYAccederAMenuPorTipo(WEB, "WEB", cuentaBancaria);
			break;
		case 6:
			filtrarYAccederAMenuPorTipo(APP, "APP", cuentaBancaria);
			break;
		case 7:
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 7);
}


void ListaDeCanales::filtrarYAccederAMenuPorTipo(ETipoDeCanal tipoDeCanal, string llave)
{
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int id;
	buscarPorTipo(tipoDeCanal);
	cout << "Ingrese el ID del canal: ";
	cin >> id;
	canal = obtenerNodoDobleEnlazadoPorId(id);
	if (canal->getId() != 0) {

		if (canal->getDato()->getActivo() == false) {
			cout << "El canal seleccionado no esta activo.\n";
			system("pause");
			system("cls");
			return;
		}
		if (canal->getDato()->getTipoDeCanal() == tipoDeCanal) {
			menuDeOperacionPorCanal(canal);
		}
		else {
			cout << "El canal seleccionado no es de tipo " << llave << ".\n";
			system("pause");
			system("cls");
		}
	}
	else {
		cout << "No se encontro el canal\n";
		system("pause");
		system("cls");
	}
}


void ListaDeCanales::filtrarYAccederAMenuPorTipo(ETipoDeCanal tipoDeCanal, string llave, Nodo<CuentaBancaria*>*cuentaBancaria)
{
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int id;
	buscarPorTipo(tipoDeCanal);
	cout << "Ingrese el ID del canal: ";
	cin >> id;
	canal = obtenerNodoDobleEnlazadoPorId(id);
	if (canal->getId() != 0) {
		if (canal->getDato()->getActivo() == false) {
			cout << "El canal seleccionado no esta activo.\n";
			system("pause");
			system("cls");
			return;
		}
		if (canal->getDato()->getTipoDeCanal() == tipoDeCanal) {
			menuDeOperacionPorCuentaBancariaYCanal(cuentaBancaria, canal);
		}
		else {
			cout << "El canal seleccionado no es de tipo " << llave << ".\n";
			system("pause");
			system("cls");
		}
	}
	else {
		cout << "No se encontro el canal\n";
		system("pause");
		system("cls");
	}
}


void ListaDeCanales::gestionarPorTipoLista(ETipoDeCanal tipoDeCanal, string llave)
{
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int opcion;
	int id;
	do {
		system("cls");
		cout << "1. Mostrar " << llave << "\n";
		cout << "2. A�adir " << llave << "\n";
		cout << "3. Editar " << llave << "\n";
		cout << "4. Eliminar " << llave << "\n";
		cout << "5. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			buscarPorTipo(tipoDeCanal);
			break;
		case 2:
			agregarCanalPorTipo(tipoDeCanal);
			break;
		case 3:
			buscarPorTipo(tipoDeCanal);

			cout << "Ingrese el ID del canal: ";
			cin >> id;
			canal = obtenerNodoDobleEnlazadoPorId(id);
			if (canal->getId() != 0) {
				if (canal->getDato()->getTipoDeCanal() == tipoDeCanal) {
					menuParaActualizarCanal(canal);
				}
				else {
					cout << "El canal seleccionado no es de tipo " << llave << ".\n";
					system("pause");
					system("cls");
				}
			}
			else {
				cout << "El canal seleccionado no existe. \n";
				system("pause");
				system("cls");
			}
			break;
		case 4:
			eliminarCanalPorTipo(tipoDeCanal);
			break;
		case 5:
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 5);
}


void ListaDeCanales::gestionarPorTipoIndividual(ETipoDeCanal tipoDeCanal, string llave)
{
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	int opcion;
	int id;
	do {
		system("cls");
		cout << "1. Ver Estado de " << llave << "\n";
		cout << "2. Editar Configuracion de " << llave << "\n";
		cout << "3. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");

		switch (opcion) {
		case 1:
			buscarPorTipo(tipoDeCanal);
			break;
		case 2:
			buscarPorTipo(tipoDeCanal);

			cout << "Ingrese el ID del canal: ";
			cin >> id;
			canal = obtenerNodoDobleEnlazadoPorId(id);
			if (canal->getId() != 0) {
				if (canal->getDato()->getTipoDeCanal() == tipoDeCanal) {
					menuParaActualizarCanal(canal);
				}
				else {
					cout << "El canal seleccionado no es de tipo " << llave << "\n";
					system("pause");
					system("cls");
				}
			}
			else {
				cout << "El canal seleccionado no existe. \n";
				system("pause");
				system("cls");
			}
			break;
		case 3:
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 3);
}


void ListaDeCanales::menuDeOperacionPorCanal(NodoDobleEnlazado<Canal*>* canal)
{
	int opcion;
	do {
		system("cls");
		cout << "# OPERACIONES\n";
		cout << "1. Hacer una operacion\n";
		cout << "2. Volver\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			//TODO agregar menu de operacion
			break;
		case 2:
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 2);
}


void ListaDeCanales::menuDeOperacionPorCuentaBancariaYCanal(Nodo<CuentaBancaria*>* cuentaBancaria, NodoDobleEnlazado<Canal*>* canal)
{
	int opcion;
	do {
		system("cls");
		cout << "# OPERACIONES\n";
		cout << "1. Hacer una operacion\n";
		cout << "2. Volver\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			//TODO agregar menu de operacion
			break;
		case 2:
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 2);
}


NodoDobleEnlazado<Canal*>* ListaDeCanales::obtenerCanal()
{
	int opcion;
	NodoDobleEnlazado<Canal*, nullptr>* canal;
	string Nombre, Ciudad, Distrito, Departamento;
	ETipoDeCanal tipoDeCanal;
	do {
		system("cls");
		cout << "# Elegir Canal\n";
		cout << "1. Buscar Por Nombre \n";
		cout << "2. Buscar Por Distrito \n";
		cout << "3. Buscar Por Departamento \n";
		cout << "4. Buscar Por Ciudad \n";
		cout << "5. Buscar Por Tipo \n";
		cout << "6. Buscar canales Activos \n";
		cout << "7. Seleccione esta opcion si ya sabe cual es el id del canal que desea seleccionar\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			cout << "Ingresa el Nombre";
			cin >> Nombre;
			buscarPorNombre(Nombre);
			break;
		case 2:
			cout << "Ingresa el Distrito";
			cin >> Distrito;
			buscarPorDistrito(Distrito);
			break;

		case 3:
			cout << "Ingresa el Departamento";
			cin >> Departamento;
			buscarPorDepartamento(Departamento);
			break;

		case 4:
			cout << "Ingresa la Ciudad";
			cin >> Ciudad;
			buscarPorCiudad(Ciudad);
			break;

		case 5:
			tipoDeCanal = menuParaObtenerTipoDeCanal();
			buscarPorTipo(tipoDeCanal);
			break;

		case 6:
			buscarPorActivo(true);
			break;

		case 7: 
			break;
		default:
			cout << "Opcion no v�lida. Intente de nuevo.\n";
		}
	} while (opcion != 7);


	int id;
	do {
		cout << "Ingrese el ID del canal: ";
		cin >> id;
		canal = obtenerNodoDobleEnlazadoPorId(id);
	} while (canal->getId() == 0);

	return canal;
}


void ListaDeCanales::eliminarCanal(int id)
{
	this->eliminarPorId(id);
	escribirEnArchivo();
	cout << "Canal eliminado" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::eliminarCanalPorTipo(ETipoDeCanal tipoDeCanal)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getTipoDeCanal() == tipoDeCanal)
		{
			this->eliminarPorId(aux->getId());
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canales eliminados" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::eliminarCanalPorNombre(string nombre)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getNombre() == nombre)
		{
			this->eliminarPorId(aux->getId());
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canales eliminados" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::eliminarCanalPorDistrito(string distrito)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getDistrito() == distrito)
		{
			this->eliminarPorId(aux->getId());
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canales eliminados" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::eliminarCanalPorDepartamento(string departamento)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getDepartamento() == departamento)
		{
			this->eliminarPorId(aux->getId());
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canales eliminados" << endl;
	system("pause");
	system("cls");
}


void ListaDeCanales::eliminarCanalPorCiudad(string ciudad)
{
	NodoDobleEnlazado<Canal*, nullptr>* aux = this->obtenerInicial();
	while (aux != nullptr)
	{
		if (aux->getDato()->getCiudad() == ciudad)
		{
			this->eliminarPorId(aux->getId());
		}
		aux = aux->getSiguiente();
	}
	escribirEnArchivo();
	cout << "Canales eliminados" << endl;
	system("pause");
	system("cls");
}
