#include "Helicoptero_H.h"

Helicoptero_H::Helicoptero_H(){
}

Helicoptero_H::~Helicoptero_H(){ 
	misil = "";
}

Helicoptero_H::Helicoptero_H(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion, string misil)
:Helicoptero( Nombre,  tipo_arma,  Velocidad,  Resistencia,  Municion){
	this->misil = misil;
}
