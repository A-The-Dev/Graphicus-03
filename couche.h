/********
 * Fichier: couche.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe pour une couche dans un
 *    canevas. La classe Couche gère un vecteur de pointeurs de formes
 *    géométriques en accord avec les spécifications de Graphicus.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/
#pragma once

#include "vecteur.hpp"
#include "forme.h"

const string STATES[] = { "Initialisée", "Active", "Inactive" };

class Couche
{
private:
	Vecteur<Forme*> formes;
	string currentState; // Peut prendre les valeurs "Initialisée", "Active" ou "Inactive"

	int activeShapeIndex;

public:
	// Classe à compléter
	Couche();
	~Couche();

	string getState() const;
	bool setState(int id);

	int getActiveShapeIndex() const;
	void setActiveShapeIndex(int index);

	Vecteur<Forme*> getFormes() const;
	Forme* getFormeByIndex(int index) const;
	bool addForme(Forme* const& f);
	Forme* removeForme(int index);

	double getAireTotale() const;
	bool translateFormes(int deltaX, int deltaY);
	bool reinitialiser();
	void afficher(ostream& s) const;

};
