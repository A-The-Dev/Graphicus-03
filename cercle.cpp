/********
 * Fichier: cercle.cpp
 * Auteurs: A. Samson
 * Date: 7 Janvier 2025
 * Description: Implémentation des méthodes des classes décrites dans cercle.h
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/

#include "cercle.h"

Cercle::Cercle(int x, int y, double r) {
	ancrage.x = x;
	ancrage.y = y;

	setRayon(r);
}

Cercle::~Cercle() {
	rayon = 0;
}

double Cercle::getRayon() {
	return rayon;
}

void Cercle::setRayon(double r) {
	if (r <= 0)
		cout << "Rayon invalide. Le rayon doit être plus grand que zéro." << endl;
	else
		rayon = r;
}

double Cercle::aire() {
	return PI * (getRayon() * getRayon());
}

void Cercle::afficher(ostream& s) {
	cout << "Cercle (x=" << this->getAncrage().x << ", y=" << this->getAncrage().y << ", r=" << getRayon() << ", aire=" << aire() << ")" << endl;
}
