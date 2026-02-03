/********
 * Fichier: canevas.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe Canevas. La classe gère un
 *    tableau de couches en accord avec les spécifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef CANEVAS_H
#define CANEVAS_H

#include <iostream>
#include "vecteur.hpp"
#include "forme.h"
#include "couche.h"

using namespace std;

class Canevas
{
private:
	Vecteur<Couche> couches;
	int activeLayerIndex;

public:
	Canevas();
	~Canevas();

	Couche getCouche(int index) const;
	void setCouche(const Couche& couche, int index);

	int getActiveLayerIndex() const;
	void setActiveLayerIndex(int index);

	bool reinitialiser();
	bool reinitialiserCouche(int index);

	bool activerCouche(int index);
	int getCouchesSize() const;
	bool ajouterCouche();
	bool retirerCouche(int index);

	bool ajouterForme(Forme* const& p_forme);
	bool retirerForme(int index);
	double getAireTotale();
	bool translater(int deltaX, int deltaY);
	void afficher(ostream & s);
};

#endif
