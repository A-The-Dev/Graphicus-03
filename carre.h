/********
 * Fichier: carre.h
 * Auteurs: A. Samson
 * Date: 7 Janvier 2025
 * Description: Déclaration de la classe Carre
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/

#pragma once

#include <iostream>
#include "rectangle.h"

using namespace std;

class Carre : public Rectangle {
private:
	double taille;

public:
	Carre(int x = 0, int y = 0, int t = 1);
	~Carre();

	double getTaille();
	void setTaille(double t);

	double aire() override;
	void afficher(ostream& s) override;
};