#pragma once
#include "Helicoptero_H.h"
#include "Helicoptero_IA.h"
#include "CampoDeBatalla.h"
CampoDeBatalla* nuevo = new CampoDeBatalla();
void Agregar() {
	int opcion = 0;
	string nombre = "", Tipo_arma = "";
	int  Velocidad = 0, Resistencia = 0, Municion = 0;
	do {
		cout << "1.H" << endl;
		cout << "2.IA" << endl;
		cin >> opcion;
	} while (opcion <= 0 || opcion >= 3);
	//pido nombre
	do {
		cout << "Ingrese nombre: ";
		cin >> nombre;
	} while (nombre.size() == 0);
	//pido Velocidad
	do {
		cout << "Ingrese la velocidad: ";
		cin >> Velocidad;
		if (Velocidad <= 99) {
			cout << "Velocidad no puede ser menor a 100" << endl;
		}
		else if (Velocidad >= 401) {
			cout << "Velocidad no puede ser mayor a 400" << endl;
		}
	} while (Velocidad <= 99 || Velocidad >= 401);
	//pido Resistencia
	do {
		cout << "Ingrese la resistencia: ";
		cin >> Resistencia;
		if (Resistencia <= 99) {
			cout << "Resistencia no puede ser menor a 100" << endl;
		}
		else if (Resistencia >= 201) {
			cout << "Resistencia no puede ser mayor a 200" << endl;
		}
	} while (Resistencia <= 99 || Resistencia >= 201);
	//pido Munición
	do {
		cout << "Ingrese la Munición: ";
		cin >> Municion;
		if (Municion <= 99) {
			cout << "Municion no puede ser menor a 5"<<endl;
		}
		else if (Municion >= 201) {
			cout << "Municion no puede ser mayor a 30" << endl;
		}
	} while (Municion <= 4 || Municion >= 31);
	//switch
	switch (opcion) {
	case 1: {
		Tipo_arma = "Misil";
		string tipo_misil = "";
		int temp = 0;
		//pido tipo de misil
		do {
			cout << "1.Anti-bombas: " << endl;
			cout << "2.Fulminante: " << endl;
			cout << "3.Reforzado: " << endl;
			cin >> temp;
		} while (temp <= 0 || temp >= 4);
		if (temp == 1) {
			tipo_misil = "Anti-bombas";
		}
		else if (temp == 2) {
			tipo_misil = "Fulminante";
		}
		else if (temp == 3) {
			tipo_misil = "Reforzado";
		}
		nuevo->AgregarHelicoptero(new Helicoptero_H(nombre, Tipo_arma, Velocidad, Resistencia, Municion, tipo_misil));
		break;
	}
	case 2: {
		Tipo_arma = "Cohete";
		string Inteligencia_cohete = "";
		//pido la inteligencia
		int temp = 0;
		do {
			cout << "1.Principiante: " << endl;
			cout << "2.Intermedio: " << endl;
			cout << "3.Avanzado: " << endl;
			cin >> temp;
		} while (temp <= 0 || temp >= 4);
		if (temp == 1) {
			Inteligencia_cohete = "Principiante";
		}
		else if (temp == 2) {
			Inteligencia_cohete = "Fulminante";
		}
		else if (temp == 3) {
			Inteligencia_cohete = "Avanzado";
		}
		nuevo->AgregarHelicoptero(new Helicoptero_IA(nombre, Tipo_arma, Velocidad, Resistencia, Municion, Inteligencia_cohete));
		break;
	}
	}
}

void MostrarInfo() {
	nuevo->MostrarInformacion();
}

void Simular() {
	int size = nuevo->tam();
	int num1 = 0;
	int num2 = 0;
	do{
		cout << "Seleccione el primer helicoptero para batalla:";
		cin >> num1;
	} while (num1 <= size);
	do {
		cout << "Seleccione el segundo helicoptero para batalla:";
		cin >> num2;
	} while (num2 <= size);
	nuevo->SimularBatalla(num1, num2);
}

void menu() {
	bool seguir = 1;
	do {
		cout << "1.Agregar Helicopteros" << endl;
		cout << "2.Mostrar informacion de helicopteros" << endl;
		cout << "3.Simular Batalla" << endl;
		cout << "4.Salir" << endl;
		int opcion = 0;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			Agregar();
			break;
		}
		case 2: {
			MostrarInfo();
			break;
		}
		case 3: {
			Simular();
			break;
		}
		case 4: {
			seguir = 0;
			break;
		}
		default:
			cout << "Error" << endl;
			break;
		}
	} while (seguir);
}

int main() {
	menu();
}
