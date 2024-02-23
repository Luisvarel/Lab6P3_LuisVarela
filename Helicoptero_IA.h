#pragma once
#include "Helicoptero.h"
class Helicoptero_IA:public Helicoptero {
private:
	string InteligenciaCohete = "";
	// puede ser “Principiante”, “Intermedio” o “Avanzado” 
public:
	~Helicoptero_IA();
	Helicoptero_IA();
	Helicoptero_IA(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion,string InteligenciaCohete);
	virtual double Atacar()override;
	virtual string toString()override;
	//get y set de InteligenciaCohete
	string getInteligenciaCohete();
	void setInteligenciaCohete(string InteligenciaCohete);
};

