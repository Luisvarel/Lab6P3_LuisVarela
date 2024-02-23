#include "Helicoptero_H.h"

Helicoptero_H::Helicoptero_H() {
}

Helicoptero_H::~Helicoptero_H() {
	misil = "";
}

Helicoptero_H::Helicoptero_H(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion, string misil)
	:Helicoptero(Nombre, tipo_arma, Velocidad, Resistencia, Municion) {
	this->misil = misil;
}

double Helicoptero_H::Atacar() {
	double DTotal = 0.0, DBase = 10.0, DMisil = 0.0, Municion=5.0, Velocidad= 1.0+((double)this->GetVelocidad()/100.0);
	if (misil == "Anti-bombas") {
		DMisil = 20.0;
	}else if (misil == "Fulminante") {
		DMisil = 30.0;
	}else if (misil == "Reforzado") {
		DMisil = 40.0;
	}
	DTotal = (DBase + (DMisil * Municion)) * Velocidad;
	this->SetVelocidad(this->GetVelocidad()-10);
	this->SetMunicion(this->GetMunicion()-5);
	return DTotal;
}

string Helicoptero_H::toString(){
	string temp="";
	temp+="Nombre: ";
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
	temp += "Tipo de misil: ";
	temp += getmisil();
	temp += "\n";
	return temp;
}

string Helicoptero_H::getmisil(){
	return misil;
}

void Helicoptero_H::setmisil(string misil){
	this->misil = misil;
}

