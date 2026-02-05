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

	couches.push_back(Couche());
	couches[0].setState(1); // Active
}

Canevas::~Canevas() {
	reinitialiser();
}

Couche Canevas::getCouche(int index) const {
	return couches[index];
}

void Canevas::setCouche(const Couche& couche, int index) {
	if (index >= 0 && index < couches.size())
		couches[index] = couche;
}

int Canevas::getActiveLayerIndex() const {
	return activeLayerIndex;
}

void Canevas::setActiveLayerIndex(int index) {
	if (index >= 0 && index < couches.size()) {
		this->couches[activeLayerIndex].setState(2);
		this->couches[index].setState(1);

		activeLayerIndex = index;
	}
}

bool Canevas::reinitialiserCouche(int index) {
	if (index >= 0 && index < couches.size()) {
		bool returnValue = this->couches[index].reinitialiser();
		index == activeLayerIndex ? activerCouche(index) : 0;

		return returnValue;
	}
		
	return false;
}

int Canevas::getCouchesSize() const {
	return couches.size();
}

bool Canevas::ajouterCouche() {
	Couche nouvelleCouche;
	couches.push_back(nouvelleCouche);
	activerCouche(couches.size() - 1);

	return true;
}

bool Canevas::retirerCouche(int index) {
	if (index < 0 || index >= couches.size())
		return false;
	
	reinitialiserCouche(index);
	activerCouche(0);

	couches.remove(index);

	return true;
}

bool Canevas::activerCouche(int index) {
	if (index < 0 || index >= couches.size())
		return false;

	this->couches[index].setState(1); // Active
	this->couches[getActiveLayerIndex()].setState(2); // Inactive

	setActiveLayerIndex(index);

	return true;
}

bool Canevas::ajouterForme(Forme* const& p_forme) {
	if (p_forme == nullptr)
		return false;

	if (couches.size() == 0)
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

void Canevas::inverserCouches() {
	int size = this->getCouchesSize();

	for (int i = 0; i < size / 2; i++)
	{
		int j = size - 1 - i;

		Couche temp = this->getCouche(i);
		this->setCouche(this->getCouche(j), i);
		this->setCouche(temp, j);
	}
}

double Canevas::getAireTotale() {
	double totalAire = 0.0;
	
	for (int i = 0; i < couches.size(); i++)
		totalAire += this->couches[i].getAireTotale();

	return totalAire;
}

bool Canevas::translater(int deltaX, int deltaY) {
	return couches[activeLayerIndex].translateFormes(deltaX, deltaY);;
}

bool Canevas::reinitialiser() {
	for (int i = 0; i < couches.size(); i++) {
		if (!reinitialiserCouche(i))
			return false;
	}

	couches.clear();
	couches.push_back(Couche());
	couches[0].setState(1);

	return true;
}


void Canevas::afficher(ostream & s) {
	for (int i = 0; i < couches.size(); i++) {
		s << "----- Couche (" << i << ") -----" << endl;
		this->couches[i].afficher(s);
	}
}
