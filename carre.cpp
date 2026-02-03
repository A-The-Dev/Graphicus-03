/********
 * Fichier: carre.cpp
 * Auteurs: A. Samson
 * Date: 7 Janvier 2025
 * Description: Implémentation des méthodes des classes décrites dans carre.h
 *
 * Ce fichier ne fait pas partie de la distribution de Graphicus.
********/

#include "carre.h"

Carre::Carre(int x, int y, int t) {
	ancrage.x = x;
	ancrage.y = y;

	setTaille(t);
}

Carre::~Carre() {
	taille = 0;
}

double Carre::getTaille() {
	return taille;
}

void Carre::setTaille(double t) {
	if (t <= 0)
		cout << "Taille invalide. La taille doit être plus grande que zéro." << endl;
	else {
		taille = t;
		setLargeur(t);
		setHauteur(t);
	}
}

double Carre::aire() {
	return getTaille()*getTaille();
}

void Carre::afficher(ostream& s) {
	s << "Carre (x=" << this->getAncrage().x << ", y=" << this->getAncrage().y << ", t=" << getTaille() << ", aire=" << aire() << ")" << endl;
}
