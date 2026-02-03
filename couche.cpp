/********
 * Fichier: couche.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    couche.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "couche.h"

// Implémentation à faire...
Couche::Couche() {
	currentState = STATES[0]; // Initialisée
}

Couche::~Couche() {
	reinitialiser();
}

string Couche::getState() const {
	return currentState;
}

bool Couche::setState(int id) {
	if (id > 0 && id <= 2) {
		currentState = STATES[id];
		return true;
	}

	return false;
}

Vecteur<Forme*> Couche::getFormes() const {
	return formes;
}

Forme* Couche::getFormeByIndex(int index) const {
	if (index >= 0 && index < formes.size())
		return formes[index];
	
	return nullptr;
}

bool Couche::addForme(Forme *const &f) {
	if (currentState == STATES[0]) // Initialisée
		setState(2); // Inactive

	if (f != nullptr) {
		formes.push_back(f);
		return true;
	}

	return false;
}

Forme* Couche::removeForme(int index) {
	if (index >= 0 && index < formes.size()) {
		Forme* removedForme = formes[index];
		Vecteur<Forme*> newFormes;

		for (int i = 0; i < formes.size(); i++) {
			if (i != index) {
				newFormes.push_back(formes[i]);
			}
		}

		formes = newFormes;
		return removedForme;
	}

	return nullptr;
}

double Couche::getAireTotale() const {
	double totalAire = 0.0;

	for (int i = 0; i < formes.size(); i++) 
		totalAire += formes[i]->aire();

	return totalAire;
}

bool Couche::translateFormes(int deltaX, int deltaY) {
	if ((deltaX == 0 && deltaY == 0) || currentState != STATES[1])
		return false;

	for (int i = 0; i < formes.size(); i++)
		formes[i]->translater(deltaX, deltaY);

	return true;
}

bool Couche::reinitialiser() {
	try {
		formes.clear();
		currentState = STATES[0]; // Initialisée

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

void Couche::afficher(ostream& s) const {
	s << "État: " << currentState << endl;

	if (currentState == STATES[0] || formes.size() < 1) {
		s << "Couche: vide" << endl;
	} 
	else {
		for (int i = 0; i < formes.size(); i++)
			formes[i]->afficher(s);
	}
}