/********
 * Fichier: canevas.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    canevas.h.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "canevas.h"

Canevas::Canevas() {
	activeLayerIndex = 0;
	couches[0].setState(1); // Active
}

Canevas::~Canevas() {
	reinitialiser();
}

Couche Canevas::getCouche(int index) const {
	return Couche();
}

void Canevas::setCouche(const Couche& couche, int index) {
	if (index >= 0 && index < MAX_COUCHES)
		couches[index] = couche;
}

int Canevas::getActiveLayerIndex() const {
	return activeLayerIndex;
}

void Canevas::setActiveLayerIndex(int index) {
	if (index >= 0 && index < MAX_COUCHES) {
		this->couches[activeLayerIndex].setState(2);
		this->couches[index].setState(1);

		activeLayerIndex = index;
	}
}

bool Canevas::reinitialiserCouche(int index) {
	if (index >= 0 && index < MAX_COUCHES) {
		bool returnValue = this->couches[index].reinitialiser();
		index == activeLayerIndex ? activerCouche(index) : 0;

		return returnValue;
	}
		
	return false;
}

bool Canevas::activerCouche(int index) {
	if (index < 0 || index >= MAX_COUCHES)
		return false;

	this->couches[index].setState(1); // Active
	this->couches[getActiveLayerIndex()].setState(2); // Inactive

	setActiveLayerIndex(index);

	return true;
}

bool Canevas::ajouterForme(Forme* const& p_forme) {
	if (p_forme == nullptr)
		return false;

	if (this->couches[getActiveLayerIndex()].getState() == STATES[1]) {
		return this->couches[getActiveLayerIndex()].addForme(p_forme);
	}

	return false;
}

bool Canevas::retirerForme(int index) {
	if (this->couches[getActiveLayerIndex()].getState() == STATES[1]) {
		Forme* const removedForme = this->couches[getActiveLayerIndex()].removeForme(index);

		if (removedForme != nullptr)
			return true;
	}

	return false;
}

double Canevas::getAireTotale() {
	double totalAire = 0.0;
	
	for (int i = 0; i < MAX_COUCHES; i++)
		totalAire += this->couches[i].getAireTotale();

	return totalAire;
}

bool Canevas::translater(int deltaX, int deltaY) {
	return couches[activeLayerIndex].translateFormes(deltaX, deltaY);;
}

bool Canevas::reinitialiser() {
	for (int i = 0; i < MAX_COUCHES; i++) {
		if (!reinitialiserCouche(i))
			return false;
	}

	return true;
}


void Canevas::afficher(ostream & s) {
	for (int i = 0; i < MAX_COUCHES; i++) {
		s << "----- Couche (" << i << ") -----" << endl;
		this->couches[i].afficher(s);
	}
}
