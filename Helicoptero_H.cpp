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
