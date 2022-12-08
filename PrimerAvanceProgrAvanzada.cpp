#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <ctype.h>

using namespace std;

struct cajeroyadmin
{
	char usuario[50];
	char contra[50];
	char cajyadm[50];
	char comercio[50];
	cajeroyadmin* sig;
};

struct clientes
{
	char Usuario[50];
	char Comercio[50];
	char correoelectr[50];
	char compra[50];
	clientes* sig;
};

struct Promos
{
	char nombre[50];
	float descuento;
	float minim;
	char estado[10];
	Promos* sig;
};

struct consumo
{
	char Nombre[50];
	float Monto;
	float Total;
	consumo* sig;
};

char Cajero[50] = { "Cajero" };
char Admin[50] = { "Administrador" };
char Comercioo[50] = { "Comercio" };
char Activa[10] = { "Activa" };
char Inactiva[10] = { "Inactiva" };

cajeroyadmin* inicio = nullptr;
clientes* inicioclient = nullptr;
Promos* iniciopromo = nullptr;
consumo* inicioconsumo = nullptr;
cajeroyadmin* aux;
clientes* auxclient;
Promos* auxpromo;
consumo* auxconsumo;

void leerarch();
void altauser();
void deleteuser(char Nombre[50]);
void actuainfuser(char Nombre[50]);
void userlist();
void saveBiuser();
void leeruser();      //USUARIOS

void actuainfclientes(char Nombre[50]);
void deleteclientes(char Nombre[50]);
void saveBiclientes();                  //CLIENTES
void leerclientes();

void leerpromo();
void altapromo();
void deletepromo(char Nombre[50]);
void actuainfpromo(char Nombre[50]);
void promolist();
void saveBipromo();                      //PROMOCIONES

void leerconsumo();
void altaconsumo();
void consumolist();
void saveBiconsumo();                //CONSUMO


int opcion1 = 0;



void RegistrAdmin();
void InicioSes();
void InicSadmin();


struct admin
{

	string nombreuser, password;
	string fullnameadmin, alias;
	admin* sig;
};
admin* adminlist = nullptr;

int op;
int op2;

int main()
{
	int D = 0;
	leeruser();
	leerclientes();
	leerpromo();
	leerconsumo();
	string usuario;
	string pass;
	int i = 0;

inicio:
	char nombreuser[50];

	cout << "\t***BIENVENIDO POR FAVOR ESCOJA UNA OPCION***\n";
	cout << "\t1.Iniciar Sesion" << endl;
	cout << "\t2.Registrar Nuevo usuario" << endl;

	cin >> op;
	cin.ignore();
	switch (op)
	{
	case 1:
		InicSadmin();
		break;
	case 2:
		RegistrAdmin();
		return main();
		break;
	default:
		cout << "Vuelva cuando Quiera" << endl;
		return 0;
		break;
	}

}


void Registrar(admin*& lista, string usuario, string contrasena, string full, string alias) {
	admin* nuevo = new admin();
	int idaux;

	nuevo->nombreuser = usuario;
	nuevo->password = contrasena;
	nuevo->fullnameadmin = full;
	nuevo->alias = alias;

	admin* aux1 = lista;
	admin* aux2 = nullptr;
	while (aux1 != nullptr)
	{


		admin* aux1 = lista;
		admin* aux2 = nullptr;
		aux2 = aux1;
		aux1 = aux1->sig;
	}

	if (lista == aux1)
	{
		lista = nuevo;
	}
	else
	{
		aux2->sig = nuevo;
	}
	nuevo->sig = aux1;
	cout << "usuario registrado Exitosamente\n";
}

void loginAdmin(admin* lista, string usuario, string contrasena)
{

	bool is = false;
	admin* nuevo2 = new admin();
	nuevo2 = lista;
	while (nuevo2 != nullptr)
	{
		if (nuevo2->nombreuser == usuario and nuevo2->password == contrasena) {
			is = true;

		}
		nuevo2 = nuevo2->sig;
	}
	if (is == true)
	{
		cout << "INICIO DE SESION EXITOSO\n";
		InicioSes();
	}
	else
	{
		cout << "Lo sentimos Usuario o contasena incorecta, Por favor introduzca bien los datos" << endl;
	}
}string UserNameLog, passwordLog;

void RegistrAdmin()
{
	string nombrusuar, passs, nombrcomplete, alias;
	cout << "Introduzca nombre de usuario: " << endl;
	getline(cin, nombrusuar);
	cout << "\nintroduzca contrasena: " << endl;
	getline(cin, passs);
	cout << "\nIntroduzca  nombre completo: " << endl;
	getline(cin, nombrcomplete);
	cout << "Tntroduzca un Apodo o alias:" << endl;
	cin >> alias;
	cin.ignore();
	Registrar(adminlist, nombrusuar, passs, nombrcomplete, alias);

}

void InicSadmin()
{

	cout << "Introduzca el usuario: ";
	getline(cin, UserNameLog);
	cout << "Introduzca la contrasena: ";
	getline(cin, passwordLog);
	loginAdmin(adminlist, UserNameLog, passwordLog);

}

void InicioSes() {

	char nombreuser[50];
	int D = 0;
	int op;

	do {
		cout << "\t" << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "\t" << "----------------------------------***Bienvenido al Sistema***------------------------------------" << endl;
		cout << "\t" << "-                                                                                              - " << endl;
		cout << "\t" << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "\t" << "-                                      MENU DE OPCIONES                                         -" << endl;
		cout << "\t" << "-------------------------------------------------------------------------------------------------" << endl;
		cout << "\t" << "-     **USUARIOS Y CLIENTES**              **PROMOCIONES**                   **CONSUMO**        -" << endl;
		cout << "\t" << "-                                                                                               -" << endl;
		cout << "\t" << "-  1. Alta Usuarios o clientes          7.       Alta                 11.       Alta            -" << endl;
		cout << "\t" << "-  2.         Listado                   8.     Actualizar             12.      Listado          -" << endl;
		cout << "\t" << "-  3.    Actualizar Usuario             9.      Listado                                         -" << endl;
		cout << "\t" << "-  4.        Baja Usuario               10.       Baja                                          -" << endl;
		cout << "\t" << "-  5.    Actualizar Cliente                                                                     -" << endl;
		cout << "\t" << "-  6.      Baja Cliente                                                                         -" << endl;
		cout << "\t" << "-                                                                                               -" << endl;
		cout << "\t" << "-                                                                                               -" << endl;
		cout << "\t" << "-                                                                                --------------- " << endl;
		cout << "\t" << "-                                                                                | *13. Salir*  |" << endl;
		cout << "\t" << "-------------------------------------------------------------------------------------------------" << endl;
		cin >> opcion1;
		cin.ignore();
		switch (opcion1)
		{
		case 1:
			system("cls");
			altauser();
			break;

		case 2:
			system("cls");
			userlist();
			break;

		case 3:
			system("cls");
			cout << "Ingrese el nombre del Usuario: " << endl;
			cin.getline(nombreuser, 50);
			actuainfuser(nombreuser);
			break;

		case 4:
			system("cls");
			cout << "Ingrese el Nombre del Usuario a Eliminar" << endl;
			cin.getline(nombreuser, 50);
			deleteuser(nombreuser);
			break;

		case 5:
			system("cls");
			cout << "Ingrese el nombre del Cliente: " << endl;
			cin.getline(nombreuser, 50);
			actuainfclientes(nombreuser);
			break;

		case 6:
			system("cls");
			cout << "Ingrese el nombre del Cliente: " << endl;
			cin.getline(nombreuser, 50);
			deleteclientes(nombreuser);
			break;

		case 7:
			system("cls");
			altapromo();
			break;

		case 8:
			system("cls");
			cout << "Ingrese el nombre de la Promocion: " << endl;
			cin.getline(nombreuser, 50);
			actuainfpromo(nombreuser);
			break;
		case 9:
			system("cls");
			promolist();
			break;
		case 10:
			system("cls");
			cout << "Ingrese el nombre de la Promocion: " << endl;
			cin.getline(nombreuser, 50);
			deletepromo(nombreuser);
			break;

		case 11:
			system("cls");
			altaconsumo();
			break;

		case 12:
			system("cls");
			consumolist();
			break;

		case 13:
			saveBiuser();
			saveBiclientes();
			saveBipromo();
			saveBiconsumo();
			cout << "\n";
			cout << "***Informacion Guardada De Manera Exitosa**" << endl;
			D = 2;
			break;

		default:
			system("cls");
			cout << "OPCION NO VALIDA." << endl;
			system("pause");
			system("cls");
			InicioSes();
			break;
		}
	} while (D < 1);
	system("pause");

}


//USUARIOS y CLIENTES

void altauser()
{
	cout << "Que tipo de Usuario Quiere dar de alta. " << endl;
	cout << "1.- Administrador." << endl;
	cout << "2.- Cajero. " << endl;
	cout << "3.- Cliente." << endl;
	cin >> opcion1;
	cin.ignore();

	do
	{
		if (opcion1 == 1)
		{
			cajeroyadmin* Nuevo = new cajeroyadmin;
			cout << "Introduzca el Nombre del Administrador. " << endl;
			cin.getline(Nuevo->usuario, 50);

			cout << "Introduzca la Contrasena del Administrador. " << endl;
			cin.getline(Nuevo->contra, 50);

			if (inicio == nullptr)
			{
				inicio = new cajeroyadmin;
				aux = inicio;

				strcpy_s(aux->usuario, Nuevo->usuario);
				strcpy_s(aux->contra, Nuevo->contra);
				strcpy_s(aux->cajyadm, Admin);
				strcpy_s(aux->comercio, Comercioo);
				aux->sig = nullptr;

			}
			else
			{
				aux = inicio;
				while (aux->sig != nullptr)
				{
					aux = aux->sig;
				}

				aux->sig = new cajeroyadmin;
				aux = aux->sig;

				strcpy_s(aux->usuario, Nuevo->usuario);
				strcpy_s(aux->contra, Nuevo->contra);
				strcpy_s(aux->cajyadm, Admin);
				strcpy_s(aux->comercio, Comercioo);
				aux->sig = nullptr;
			}
		}

		else if (opcion1 == 2)
		{
			cajeroyadmin* Nuevo = new cajeroyadmin;
			cout << "Introduzca el Nombre del Cajero. " << endl;
			cin.getline(Nuevo->usuario, 50);

			cout << "Introduzca la Contrasena del Cajero. " << endl;
			cin.getline(Nuevo->contra, 50);

			if (inicio == nullptr)
			{
				inicio = new cajeroyadmin;
				aux = inicio;

				strcpy_s(aux->usuario, Nuevo->usuario);
				strcpy_s(aux->contra, Nuevo->contra);
				strcpy_s(aux->cajyadm, Cajero);
				strcpy_s(aux->comercio, Comercioo);
				aux->sig = nullptr;

			}
			else
			{
				aux = inicio;
				while (aux->sig != nullptr)
				{
					aux = aux->sig;
				}

				aux->sig = new cajeroyadmin;
				aux = aux->sig;

				strcpy_s(aux->usuario, Nuevo->usuario);
				strcpy_s(aux->contra, Nuevo->contra);
				strcpy_s(aux->cajyadm, Cajero);
				strcpy_s(aux->comercio, Comercioo);
				aux->sig = nullptr;
			}
		}

		else if (opcion1 == 3)
		{
			clientes* Nuevo = new clientes;
			cout << "Introduzca el Nombre del Cliente: " << endl;
			cin.getline(Nuevo->Usuario, 50);

			cout << "Introduzca el Correo Electronico: " << endl;
			cin.getline(Nuevo->correoelectr, 50);

			if (inicioclient == nullptr)
			{
				inicioclient = new clientes;
				auxclient = inicioclient;

				strcpy_s(auxclient->Usuario, Nuevo->Usuario);
				strcpy_s(auxclient->correoelectr, Nuevo->correoelectr);
				strcpy_s(auxclient->Comercio, Comercioo);
				auxclient->sig = nullptr;

			}
			else
			{
				while (auxclient->sig != nullptr)
				{
					auxclient = auxclient->sig;
				}

				auxclient->sig = new clientes;
				auxclient = auxclient->sig;

				strcpy_s(auxclient->Usuario, Nuevo->Usuario);
				strcpy_s(auxclient->correoelectr, Nuevo->correoelectr);
				strcpy_s(auxclient->Comercio, Comercioo);
				auxclient->sig = nullptr;
			}
		}

	} while (opcion1 < 1 || opcion1 > 3);

	system("Pause");
	system("cls");
}

void deleteuser(char Nombre[50])
{
	aux = inicio;
	cajeroyadmin* auxant = nullptr;

	if (inicio == nullptr)
	{
		cout << "Lista vacia." << endl;
	}
	else
	{
		while (aux != nullptr and strcmp(aux->usuario, Nombre) != 0)
		{
			auxant = aux;
			aux = aux->sig;
		}
		if (aux == nullptr)
		{
			cout << "Lo sentimos Usuario no encontrado." << endl;
		}
		else
		{
			if (aux == inicio)
			{
				cout << "Usuario Encontrado con Exito: " << aux->usuario << endl;

				inicio = aux->sig;
				delete aux;
				aux = inicio;

				cout << "Usuario Eliminado Exitosamente." << endl;

			}
			else
			{

				cout << "Usuario Encontrado con Exito: " << aux->usuario << endl;
				auxant->sig = aux->sig;
				delete aux;
				aux = inicio;

				cout << "Usuario Eliminado Exitosamente. " << endl;

			}
		}
	}
	system("Pause");
	system("cls");
}

void actuainfuser(char Nombre[50])
{
	aux = inicio;

	if (inicio == nullptr)
	{
		cout << "Lista de Usuarios Vacia. " << endl;
	}
	else
	{
		while (aux != nullptr and strcmp(aux->usuario, Nombre) != 0)
		{
			aux = aux->sig;
		}
		if (aux == nullptr)
		{
			cout << "Usuario no encontrado." << endl;

		}
		else
		{
			cout << "Usuario Encontrado: " << aux->usuario << endl << endl;
			cout << "1.- Actualizar Nombre del Usuario." << endl;
			cout << "2.- Actualizar la Contrasena de Usuario." << endl;
			cin >> opcion1;
			cin.ignore();

			switch (opcion1)
			{
			case 1:
				cout << "Nombre del Usuario: " << aux->usuario << endl;
				cout << "Agregue el Nuevo Nombre del Usuario: " << endl;
				cin.getline(aux->usuario, 50);
				break;

			case 2:
				cout << "Contrasena: " << aux->contra << endl;
				cout << "Agregue la Nueva Contrasena: " << endl;
				cin.getline(aux->contra, 50);
				break;
			}
		}
	}
	system("Pause");
	system("cls");
}

void userlist()
{
	aux = inicio;

	if (inicio == nullptr)
	{
		cout << "No hay Usuarios registrados." << endl;
	}
	else
	{
		cout << "Cajeros y Administradores: " << endl;
		while (aux != nullptr)
		{
			cout << "NOMBRE: " << aux->usuario << endl;
			cout << "CONTRASENA: " << aux->contra << endl;
			cout << "COMERCIO: " << aux->comercio << endl;
			cout << "USUARIO TIPO: " << aux->cajyadm << endl << endl;
			aux = aux->sig;
		}
	}
	cout << endl;

	auxclient = inicioclient;

	if (inicioclient == nullptr)
	{
		cout << "No hay Clientes registrados." << endl;
	}
	else
	{
		cout << "Clientes: " << endl;
		while (auxclient != nullptr)
		{
			cout << "NOMBRE: " << auxclient->Usuario << endl;
			cout << "CORREO ELECTRONICO: " << auxclient->correoelectr << endl;
			cout << "COMERCIO: " << auxclient->Comercio << endl << endl;
			auxclient = auxclient->sig;
		}
	}

	system("Pause");
	system("cls");
}

void leeruser()
{
	ifstream Usuarios;
	Usuarios.open("Usuarios.bin", ios::in | ios::binary);

	aux = inicio;
	if (Usuarios.is_open())
	{
		cajeroyadmin* Info = new cajeroyadmin;
		while (!Usuarios.read((char*)Info, sizeof(cajeroyadmin)).eof()) {
			while (aux != nullptr and aux->sig != nullptr)
			{
				aux = aux->sig;
			}
			if (aux == nullptr)
			{
				inicio = Info;
				inicio->sig = nullptr;
				aux = inicio;
			}
			else
			{
				aux->sig = Info;
				aux = aux->sig;
				aux->sig = nullptr;
			}
			Info = new cajeroyadmin;
		}
		Usuarios.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO " << endl;
		system("pause");
	}

}

void saveBiuser()
{
	aux = inicio;

	ofstream Usuarios;
	Usuarios.open("Usuarios.bin", ios::out | ios::binary | ios::trunc);

	if (Usuarios.is_open())
	{
		while (aux != nullptr)
		{
			Usuarios.write((char*)aux, sizeof(cajeroyadmin));
			aux = aux->sig;
		}

		Usuarios.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO." << endl;
		system("pause");
	}
}

void deleteclientes(char Nombre[50])
{
	auxclient = inicioclient;
	clientes* auxantC = nullptr;

	if (inicioclient == nullptr)
	{
		cout << "Lo sentimos No hay Clientes Registrados." << endl;
	}
	else
	{
		while (auxclient != nullptr and strcmp(auxclient->Usuario, Nombre) != 0)
		{
			auxantC = auxclient;
			auxclient = auxclient->sig;
		}
		if (auxclient == nullptr)
		{
			cout << "Lo sentimos Cliente no Encontrado" << endl;
		}
		else
		{
			if (auxclient == inicioclient)
			{
				inicioclient = auxclient->sig;

				delete auxclient;

				auxclient = inicioclient;

				cout << "Cliente Eliminado." << endl;
			}
			else
			{


				auxantC->sig = auxclient->sig;

				delete auxclient;

				auxclient = inicioclient;

				cout << "Cliente Eliminado. " << endl;
			}
		}
	}
	system("Pause");
	system("cls");
}

void actuainfclientes(char Nombre[50])
{
	auxclient = inicioclient;

	if (inicioclient == nullptr)
	{
		cout << "Lo sentimos No hay clientes registrados. " << endl;

	}
	else
	{
		while (auxclient != nullptr and strcmp(auxclient->Usuario, Nombre) != 0)
		{
			auxclient = auxclient->sig;
		}
		if (auxclient == nullptr)
		{
			cout << "Lo sentimos Cliente no encontrado" << endl;
		}
		else
		{
			cout << "Cliente encontrado: " << auxclient->Usuario << endl;
			cout << "1.- Actualizar Nombre del Cliente." << endl;
			cout << "2.- Actualizar el Correo Electronico del Cliente. " << endl;
			cin >> opcion1;
			cin.ignore();

			switch (opcion1)
			{
			case 1:
				cout << "Nombre del Cliente: " << auxclient->Usuario << endl;
				cout << "Agregue el Nuevo Nombre del Cliente: " << endl;
				cin.getline(auxclient->Usuario, 50);
				cout << ":::Informacion actualizada Exitosamente:::" << endl;
				break;

			case 2:
				cout << "Correo Electronico: " << auxclient->correoelectr << endl;
				cout << "Agregue el Nuevo Correo Electronico: " << endl;
				cin.getline(auxclient->correoelectr, 50);
				cout << ":::Informacion actualizada Exitosamente:::" << endl;
				break;

			}
		}
	}
	system("Pause");
	system("cls");
}

void leerclientes()
{
	ifstream Clientes;
	Clientes.open("Clientes.bin", ios::in | ios::binary);

	auxclient = inicioclient;
	if (Clientes.is_open())
	{
		clientes* InfoC = new clientes;
		while (!Clientes.read((char*)InfoC, sizeof(clientes)).eof()) {
			while (auxclient != nullptr and auxclient->sig != nullptr)
			{
				auxclient = auxclient->sig;
			}
			if (auxclient == nullptr)
			{
				inicioclient = InfoC;
				inicioclient->sig = nullptr;
				auxclient = inicioclient;
			}
			else
			{
				auxclient->sig = InfoC;
				auxclient = auxclient->sig;
				auxclient->sig = nullptr;
			}
			InfoC = new clientes;
		}
		Clientes.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO " << endl;
		system("pause");
	}
}

void saveBiclientes() {
	auxclient = inicioclient;

	ofstream Clientes;
	Clientes.open("Clientes.bin", ios::out | ios::binary | ios::trunc);

	if (Clientes.is_open())
	{
		while (auxclient != nullptr)
		{
			Clientes.write((char*)auxclient, sizeof(clientes));
			auxclient = auxclient->sig;
		}

		Clientes.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO." << endl;
		system("pause");
	}
}

//Promos

void altapromo()
{
	Promos* Nuevo = new Promos;


	cout << "Ingrese  nombre de la Promocion: " << endl;
	cin.getline(Nuevo->nombre, 50);

	cout << "Introduzca el descuento en la Promocion: " << endl;
	cin >> Nuevo->descuento;
	cin.ignore();

	cout << "Ingrese el Monto minimo para la Promocion: " << endl;
	cin >> Nuevo->minim;
	cin.ignore();

	cout << "1.- Promocion Activa " << endl;
	cout << "2.- Promocion Inactiva" << endl;
	cin >> opcion1;
	cin.ignore();

	if (iniciopromo == nullptr)
	{
		iniciopromo = new Promos;
		auxpromo = iniciopromo;

		strcpy_s(auxpromo->nombre, Nuevo->nombre);
		auxpromo->descuento = Nuevo->descuento;
		auxpromo->minim = Nuevo->minim;

		if (opcion1 == 1)
		{
			strcpy_s(auxpromo->estado, Activa);
		}
		if (opcion1 == 2)
		{
			strcpy_s(auxpromo->estado, Inactiva);
		}
		auxpromo->sig = nullptr;
	}
	else
	{
		auxpromo = iniciopromo;
		while (auxpromo->sig != nullptr)
		{
			auxpromo = auxpromo->sig;
		}
		auxpromo->sig = new Promos;
		auxpromo = auxpromo->sig;

		strcpy_s(auxpromo->nombre, Nuevo->nombre);
		auxpromo->descuento = Nuevo->descuento;
		auxpromo->minim = Nuevo->minim;
		if (opcion1 == 1)
		{
			strcpy_s(auxpromo->estado, Activa);
		}
		if (opcion1 == 2)
		{
			strcpy_s(auxpromo->estado, Inactiva);
		}
		auxpromo->sig = nullptr;
	}

	system("Pause");
	system("cls");
}

void deletepromo(char Nombre[50])
{
	auxpromo = iniciopromo;
	Promos* auxantP = nullptr;

	if (iniciopromo == nullptr)
	{
		cout << "Lista de Promociones vacia." << endl;
	}
	else
	{
		while (auxpromo != nullptr and strcmp(auxpromo->nombre, Nombre) != 0)
		{
			auxantP = auxpromo;
			auxpromo = auxpromo->sig;
		}
		if (auxpromo == nullptr)
		{
			cout << "Lo sentimos Promocion no Encontrada" << endl;
		}
		else
		{
			if (auxpromo == iniciopromo)
			{
				iniciopromo = auxpromo->sig;

				delete auxpromo;

				auxpromo = iniciopromo;

				cout << ":::Promocion Borrada:::" << endl;
			}
			else
			{
				auxantP->sig = auxpromo->sig;

				delete auxpromo;

				auxpromo = iniciopromo;

				cout << ":::Promocion Borrada:::" << endl;
			}
		}
	}
	system("Pause");
	system("cls");
}

void actuainfpromo(char Nombre[50])
{
	auxpromo = iniciopromo;

	if (iniciopromo == nullptr)
	{
		cout << "Lista de Promociones Vacia." << endl;
	}
	else
	{
		while (auxpromo != nullptr and strcmp(auxpromo->nombre, Nombre) != 0)
		{
			auxpromo = auxpromo->sig;
		}
		if (auxpromo == nullptr)
		{
			cout << "No se encontro  Promocion." << endl;
		}
		else
		{
			cout << "Promocion Encontrada: " << auxpromo->nombre << endl;
			cout << "1.- Actualizar Nombre. " << endl;
			cout << "2.- Actualizar Descuento. " << endl;
			cout << "3.- Actualizar Monto Minimo. " << endl;
			cout << "4.- Actualizar Validacion. " << endl;
			cin >> opcion1;
			cin.ignore();

			switch (opcion1)
			{
			case 1:
				cout << "Nombre: " << auxpromo->nombre << endl;
				cout << "Agregue Nuevo Nombre: " << endl;
				cin.getline(auxpromo->nombre, 50);
				break;

			case 2:
				cout << "Descuento: " << auxpromo->descuento << endl;
				cout << "Agregue Nuevo Descuento: " << endl;
				cin >> auxpromo->descuento;
				cin.ignore();
				break;

			case 3:
				cout << "Monto Minimo: " << auxpromo->minim << endl;
				cout << "Agregue Nuevo Monto Minimo: " << endl;
				cin >> auxpromo->minim;
				cin.ignore();
				break;

			case 4:
				cout << "Estatus Actual: " << auxpromo->estado << endl;
				cout << "Elija el Nuevo Estatus: " << endl;
				cout << "1.- Activa." << endl;
				cout << "2.- Inactiva." << endl;
				cin >> opcion1;
				cin.ignore();

				if (opcion1 == 1)
				{
					strcpy_s(auxpromo->estado, Activa);
				}
				if (opcion1 == 2)
				{
					strcpy_s(auxpromo->estado, Inactiva);
				}
			}
		}
	}
	system("Pause");
	system("cls");
}

void promolist()
{
	auxpromo = iniciopromo;

	if (iniciopromo == nullptr)
	{
		cout << "Lista de Promociones Vacia. " << endl;
	}
	else
	{
		while (auxpromo != nullptr)
		{
			cout << "NOMBRE: " << auxpromo->nombre << endl;
			cout << "DESCUENTO: " << auxpromo->descuento << endl;
			cout << "MONTO MINIMO: " << auxpromo->minim << endl << endl;

			auxpromo = auxpromo->sig;
		}
	}

	system("Pause");
	system("cls");
}

void leerpromo()
{

	ifstream Promociones;
	Promociones.open("Promociones.bin", ios::in | ios::binary);
	auxpromo = iniciopromo;
	if (Promociones.is_open())
	{
		auxpromo = iniciopromo;
		Promos* InfoP = new Promos;
		while (!Promociones.read((char*)InfoP, sizeof(Promos)).eof()) {
			while (auxpromo != nullptr and auxpromo->sig != nullptr)
			{
				auxpromo = auxpromo->sig;
			}
			if (auxpromo == nullptr)
			{
				iniciopromo = InfoP;
				iniciopromo->sig = nullptr;
				auxpromo = iniciopromo;
			}
			else
			{
				auxpromo->sig = InfoP;
				auxpromo = auxpromo->sig;
				auxpromo->sig = nullptr;
			}
			InfoP = new Promos;
		}
		Promociones.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO " << endl;
		system("pause");
	}
}

void saveBipromo() {
	auxpromo = iniciopromo;

	ofstream Promociones;
	Promociones.open("Promociones.bin", ios::out | ios::binary | ios::trunc);

	if (Promociones.is_open())
	{
		while (auxpromo != nullptr)
		{
			Promociones.write((char*)auxpromo, sizeof(Promos));
			auxpromo = auxpromo->sig;
		}

		Promociones.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO." << endl;
		system("pause");
	}

}

//Consumo

void altaconsumo()
{
	consumo* Nuevo = new consumo;
	float desc;

	cout << "Ingrese la Compra: " << endl;
	cin.getline(Nuevo->Nombre, 50);

	cout << "Ingrese el Monto: " << endl;
	cin >> Nuevo->Monto;

	Nuevo->Total = Nuevo->Monto;
	auxpromo = iniciopromo;

	if (iniciopromo == nullptr)
	{

	}
	else
	{
		auxpromo = iniciopromo;
		while (auxpromo != nullptr and Nuevo->Monto >= auxpromo->minim)
		{
			if (strcmp(auxpromo->estado, Activa) == 0)
			{
				desc = auxpromo->descuento / 100;
				desc = 1 - desc;
				Nuevo->Total = Nuevo->Monto * desc;
				auxpromo = auxpromo->sig;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
	}

	if (inicioconsumo == nullptr)
	{
		inicioconsumo = new consumo;
		auxconsumo = inicioconsumo;

		strcpy_s(auxconsumo->Nombre, Nuevo->Nombre);
		auxconsumo->Monto = Nuevo->Monto;
		auxconsumo->Total = Nuevo->Total;

		auxconsumo->sig = nullptr;
	}
	else
	{
		auxconsumo = inicioconsumo;
		while (auxconsumo->sig != nullptr)
		{
			auxconsumo = auxconsumo->sig;
		}
		auxconsumo->sig = new consumo;

		auxconsumo = auxconsumo->sig;

		strcpy_s(auxconsumo->Nombre, Nuevo->Nombre);
		auxconsumo->Monto = Nuevo->Monto;
		auxconsumo->Total = Nuevo->Total;

		auxconsumo->sig = nullptr;
	}
	system("Pause");
	system("cls");
}

void consumolist()
{
	auxconsumo = inicioconsumo;

	if (inicioconsumo == nullptr)
	{
		cout << "Lista de compras vacia. " << endl;
	}
	else
	{
		while (auxconsumo != nullptr)
		{
			cout << "COMPRA: " << auxconsumo->Nombre << endl;
			cout << "MONTO: " << auxconsumo->Monto << endl;
			cout << "TOTAL: " << auxconsumo->Total << endl;
			auxconsumo = auxconsumo->sig;

		}
	}
	system("Pause");
	system("cls");
}

void leerconsumo()
{
	auxconsumo = inicioconsumo;
	ifstream Compras;
	Compras.open("Compras.bin", ios::in | ios::binary);

	if (Compras.is_open())
	{
		auxconsumo = inicioconsumo;
		consumo* InfoCR = new consumo;
		while (!Compras.read((char*)InfoCR, sizeof(consumo)).eof()) {
			while (auxconsumo != nullptr and auxconsumo->sig != nullptr)
			{
				auxconsumo = auxconsumo->sig;
			}
			if (auxconsumo == nullptr)
			{
				inicioconsumo = InfoCR;
				inicioconsumo->sig = nullptr;
				auxconsumo = inicioconsumo;
			}
			else
			{
				auxconsumo->sig = InfoCR;
				auxconsumo = auxconsumo->sig;
				auxconsumo->sig = nullptr;
			}
			InfoCR = new consumo;
		}
		Compras.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO " << endl;
		system("pause");
	}
}

void saveBiconsumo() {
	auxconsumo = inicioconsumo;

	ofstream Compras;
	Compras.open("Compras.bin", ios::out | ios::binary | ios::trunc);

	if (Compras.is_open())
	{
		while (auxconsumo != nullptr)
		{
			Compras.write((char*)auxconsumo, sizeof(consumo));
			auxconsumo = auxconsumo->sig;
		}

		Compras.close();
	}
	else
	{
		cout << "ERROR AL ABRIR EL ARCHIVO." << endl;
		system("pause");
	}
}