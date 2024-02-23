#pragma once
#include "Helicoptero_H.h"
#include "Helicoptero_IA.h"
#include "CampoDeBatalla.h"

void Agregar(CampoDeBatalla* nuevo) {
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
	} while (nombre.size() != 0);
	//pido Velocidad
	do {
		cout << "Ingrese la velocidad: ";
		cin >> Velocidad;
		if (Velocidad <= 99) {
			cout << "Velocidad no puede ser menor a 100";
		}
		else if (Velocidad >= 401) {
			cout << "Velocidad no puede ser mayor a 400";
		}
	} while (Velocidad <= 99 || Velocidad >= 401);
	//pido Resistencia
	do {
		cout << "Ingrese la resistencia: ";
		cin >> Resistencia;
		if (Resistencia <= 99) {
			cout << "Resistencia no puede ser menor a 100";
		}
		else if (Resistencia >= 201) {
			cout << "Resistencia no puede ser mayor a 200";
		}
	} while (Resistencia <= 99 || Resistencia >= 201);
	//pido Munición
	do {
		cout << "Ingrese la Munición: ";
		cin >> Municion;
		if (Municion <= 99) {
			cout << "Municion no puede ser menor a 5";
		}
		else if (Municion >= 201) {
			cout << "Municion no puede ser mayor a 30";
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
			cout << "1.Anti-bombas: ";
			cout << "2.Fulminante: ";
			cout << "3.Reforzado: ";
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
		nuevo->AgregarHelicóptero(new Helicoptero_H(nombre, Tipo_arma, Velocidad, Resistencia, Municion, tipo_misil));
		break;
	}
	case 2: {
		Tipo_arma = "Cohete";
		string Inteligencia_cohete = "";
		//pido la inteligencia
		int temp = 0;
		do {
			cout << "1.Principiante: ";
			cout << "2.Intermedio: ";
			cout << "3.Avanzado: ";
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
		nuevo->AgregarHelicóptero(new Helicoptero_IA(nombre, Tipo_arma, Velocidad, Resistencia, Municion, Inteligencia_cohete));
		break;
	}
	}
}

void MostrarInfo(CampoDeBatalla* nuevo) {
	nuevo->MostrarInformación();
}

void Simular() {

}

void menu() {
	CampoDeBatalla* nuevo = new CampoDeBatalla();
	bool seguir = 1;
	do {
		cout << "1.Agregar Helicopteros" << endl;
		cout << "2.Mostrar información de helicópteros" << endl;
		cout << "3.Simular Batalla" << endl;
		cout << "4.Salir" << endl;
		int opcion = 0;
		cin >> opcion;
		switch (opcion) {
		case 1: {
			Agregar(nuevo);
			break;
		}
		case 2: {
			MostrarInfo(nuevo);
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
