#include "Helicoptero.h"

Helicoptero::~Helicoptero() {
	Nombre = "";
	tipo_arma = "";
	Velocidad = 0;
	Resistencia = 0;
	Municion = 0;
}

Helicoptero::Helicoptero() {
}

Helicoptero::Helicoptero(string Nombre, string tipo_arma, int Velocidad, double Resistencia, int Municion) {
	this->Nombre = Nombre;
	this->tipo_arma = tipo_arma;
	this->Velocidad = Velocidad;
	this->Resistencia = Resistencia;
	this->Municion = Municion;
}

string Helicoptero::GetNombre() {
	return Nombre;
}
void Helicoptero::SetNombre(string Nombre) {
	this->Nombre = Nombre;
}

string Helicoptero::GetTipo_arma() {
	return tipo_arma;
}

int Helicoptero::GetVelocidada() {
	return Velocidad;
}

void Helicoptero::SetVelocidad(int Velocidad) {
	this->Velocidad = Velocidad;
}

double Helicoptero::GetResistencia() {
	return Resistencia;
}

void Helicoptero::SetResistencia(double Resistencia) {
	this->Resistencia = Resistencia;
}

int Helicoptero::GetMunicion() {
	return Municion;
}

void Helicoptero::SetMunicion(int Municion) {
	this->Municion = Municion;
}

void Helicoptero::SetTipo_arma(string tipo_arma) {
	this->tipo_arma = tipo_arma;
}

