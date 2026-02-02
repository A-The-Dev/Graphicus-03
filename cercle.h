/********
 * Fichier: cercle.h
 * Auteurs: A. Samson
 * Date: 7 Janvier 2025
 * Description: Déclaration de la classe Cercle
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/

#pragma once

#include <iostream>
#include "forme.h"

//Variable for Pi (precise enough and prevents the use of a library)
const double PI = 3.14159265358979323846;

using namespace std;

class Cercle : public Forme {
private:
	double rayon;

public:
	Cercle(int x = 0, int y = 0, double r = 1);
	~Cercle();

	double getRayon();
	void setRayon(double r);

	double aire() override;
	void afficher(ostream& s) override;
};