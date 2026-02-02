/********
 * Fichier: rectangle.h
 * Auteurs: A. Samson
 * Date: 7 Janvier 2025
 * Description: Déclaration de la classe Rectangle
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/

#pragma once

#include <iostream>
#include "forme.h"

using namespace std;

class Rectangle : public Forme {
private:
	double largeur;
	double hauteur;

public:
	Rectangle(int x = 0, int y = 0, int l = 1, int h = 1);
	~Rectangle();

	double getLargeur();
	void setLargeur(double l);
	double getHauteur();
	void setHauteur(double h);

	double aire() override;
	void afficher(ostream& s) override;
};