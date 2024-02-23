#pragma once
#include "Helicoptero.h"
class Helicoptero_H:public Helicoptero {
private:
	string misil = "";
	// puede ser “Anti-bombas”, “Fulminante” o “Reforzado” 
public:
	Helicoptero_H();
	~Helicoptero_H();
	Helicoptero_H(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion,string misil);
	virtual double Atacar()override;
};

