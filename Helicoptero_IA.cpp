#include "Helicoptero_IA.h"

Helicoptero_IA::~Helicoptero_IA() {
	InteligenciaCohete = "";
}

Helicoptero_IA::Helicoptero_IA() {
}

Helicoptero_IA::Helicoptero_IA(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion, string InteligenciaCohete)
	:Helicoptero(Nombre, tipo_arma, Velocidad, Resistencia, Municion) {
	this->InteligenciaCohete = InteligenciaCohete;
}

double Helicoptero_IA::Atacar() {
	double DTotal = 0.0, DBase = 5.0, Dcohete = 0.0, Municion = 2.0, Velocidad = 1.0 + ((double)this->GetVelocidad() / 100.0);
	if (InteligenciaCohete == "Principiante") {
		Dcohete = 10.0;
	}
	else if (InteligenciaCohete == "Intermedio") {
		Dcohete = 15.0;
	}
	else if (InteligenciaCohete == "Avanzado") {
		Dcohete = 20.0;
	}
	DTotal = (DBase + (Dcohete * Municion)) * Velocidad;
	this->SetVelocidad(this->GetVelocidad() - 8);
	this->SetMunicion(this->GetMunicion() - 2);
	return DTotal;
}

string Helicoptero_IA::toString(){
	string temp = "";
	temp += "Nombre: ";
	temp += GetNombre();
	temp += "\n";
	temp += "Tipo de arma: ";
	temp += GetTipo_arma();
	temp += "\n";
	temp += "Velocidad: ";
	temp += GetVelocidad();
	temp += " km/h";
	temp += "\n";
	temp += "Resistencia: ";
	temp += GetResistencia();
	temp += "\n";
	temp += "Municion: ";
	temp += GetMunicion();
	temp += "\n";
	temp += "Inteligencia de cohete: ";
	temp += getInteligenciaCohete();
	temp += "\n";
	return temp;
}


string Helicoptero_IA::getInteligenciaCohete() {
	return InteligenciaCohete;
}

void Helicoptero_IA::setInteligenciaCohete(string InteligenciaCohete) {
	this->InteligenciaCohete = InteligenciaCohete;
}
