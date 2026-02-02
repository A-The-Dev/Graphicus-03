/********
 * Fichier: tests.h
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Déclaration de la classe pour les tests de Graphicus.
 *    Ce fichier peut être adapté à vos besoins de tests.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "canevas.h"
#include "couche.h"
#include "vecteur.hpp"
#include "forme.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"

// Couleurs pour l'affichage des résultats
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string PURPLE = "\033[95m";
const string BLUE = "\033[94m";
const string RESET = "\033[0m";

using namespace std;

class Tests
{
private:
	int passedTests = 0;
	int failedTests = 0;

public:
	void printTestResult(bool result);
	void printFinalResults();

	// Méthodes pour les tests unitaires des classes
	void tests_unitaires_formes();
	void tests_unitaires_vecteur();
	void tests_unitaires_couche();
	void tests_unitaires_canevas();
	void tests_unitaires(); // Appel de tous les tests unitaires

	// Méthodes pour les tests unitaires applicatifs
	void tests_validation();
	void tests_val_part1(Canevas& c);
	void tests_val_part2(Canevas& c);
	void tests_val_part3(Canevas& c);
	void tests_val_part4(Canevas& c);
	void tests_application(); // Appel de tous les tests applicatifs

	// Méthodes pour les tests unitaires des classes héritées de Forme
	void tests_unitaires_cercle();
	void tests_unitaires_rectangle();
	void tests_unitaires_carre();

	// Méthodes pour les tests unitaires de la classe Cercle
	bool instantiate_circles();
	bool get_circle_values();
	bool set_circle_values();
	bool circle_area_calculation();

	// Méthodes pour les tests unitaires de la classe Rectangle
	bool instantiate_rectangles();
	bool get_rectangle_values();
	bool set_rectangle_values();
	bool rectangle_area_calculation();

	// Méthodes pour les tests unitaires de la classe Carré
	bool instantiate_squares();
	bool get_square_values();
	bool set_square_values();
	bool square_area_calculation();

	// Méthodes pour les tests unitaires de la classe Vecteur
	bool instantiate_vecteurs();
	bool vecteur_push_back();
	bool vecteur_size();
	//bool vecteur_capacity();
	bool vecteur_is_empty();
	bool vecteur_resize();
	bool vecteur_clear();
	bool vecteur_print();

	// Méthodes pour les tests unitaires de la classe Couche
	bool instantiate_couches();
	bool get_couche_state();
	bool set_couche_state();
	bool add_forme_to_couche();
	bool remove_forme_from_couche();
	bool couche_total_area_calculation();
	bool translate_couche_formes();
	bool reinitialize_couche();

	// Méthodes pour les tests unitaires de la classe Canevas
	bool instantiate_canevas();
	bool get_active_layer_index();
	bool set_active_layer_index();
	bool reinitialize_canevas();
	bool reinitialize_couche_in_canevas();
	bool activate_couche_in_canevas();
	bool add_forme_from_couche_in_canevas();
	bool remove_forme_from_couche_in_canevas();
	bool get_canevas_total_area();
	bool translate_canevas_formes();
};

#endif
