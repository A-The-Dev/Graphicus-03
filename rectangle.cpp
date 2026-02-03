/********
 * Fichier: rectangle.cpp
 * Auteurs: A. Samson
 * Date: 7 Janvier 2025
 * Description: Implémentation des méthodes des classes décrites dans rectangle.h
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/

#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int h) {
	ancrage.x = x;
	ancrage.y = y;

	setLargeur(l);
	setHauteur(h);
}

Rectangle::~Rectangle() {
	largeur = 0;
	hauteur = 0;
}

double Rectangle::getLargeur() {
	return largeur;
}

void Rectangle::setLargeur(double l) {
	if (l <= 0)
		cout << "Largeur invalide. La largeur doit être plus grande que zéro." << endl;
	else
		largeur = l;
}

double Rectangle::getHauteur() {
	return hauteur;
}

void Rectangle::setHauteur(double h) {
	if (h <= 0)
		cout << "Hauteur invalide. La hauteur doit être plus grande que zéro." << endl;
	else
		hauteur = h;
}

double Rectangle::aire() {
	return getLargeur()*getHauteur();
}

void Rectangle::afficher(ostream& s) {
	s << "Rectangle (x=" << this->getAncrage().x << ", y=" << this->getAncrage().y << ", l=" << getLargeur() << ", h=" << getHauteur() << ", aire=" << aire() << ")" << endl;
}
