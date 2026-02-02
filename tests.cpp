/********
 * Fichier: tests.cpp
 * Auteurs: C.-A. Brunet
 * Date: 28 novembre 2025
 * Description: Implémentation des méthodes des classes décrites dans
 *    tests.h.  Ce fichier peut être adapté à vos besoins de tests.
 *
 * Ce fichier fait partie de la distribution de Graphicus.
********/

#include "tests.h"

void Tests::printTestResult(bool result) {
	if (result) {
		cout << GREEN << "PASSED" << RESET << endl << endl;
		passedTests++;
	}	
	else {
		cout << RED << "FAILED" << RESET << endl << endl;
		failedTests++;
	}
}

void Tests::printFinalResults() {
	cout << PURPLE << "===== TESTS SUMMARY =====" << RESET << endl;
	cout << GREEN << "Passed tests: " << passedTests << RESET << endl;
	cout << RED << "Failed tests: " << failedTests << RESET << endl;
	cout << YELLOW << "Total tests: " << passedTests + failedTests << RESET << endl;
	cout << PURPLE << "=========================" << RESET << endl;
}

void Tests::tests_unitaires_formes() {
	// Tests des formes géométriques
	tests_unitaires_cercle();
	tests_unitaires_rectangle();
	tests_unitaires_carre();
}

void Tests::tests_unitaires_vecteur() {
	cout << PURPLE << "===== TESTS UNITAIRES VECTEUR =====" << RESET << endl;

	printTestResult(instantiate_vecteurs());
	printTestResult(vecteur_push_back());
	printTestResult(vecteur_size());
	printTestResult(vecteur_is_empty());
	printTestResult(vecteur_resize());
	printTestResult(vecteur_clear());
	printTestResult(vecteur_print());

	cout << PURPLE << "===================================" << RESET << endl << endl;
}

void Tests::tests_unitaires_couche() {
	cout << PURPLE << "===== TESTS UNITAIRES COUCHE =====" << RESET << endl;

	printTestResult(instantiate_couches());
	printTestResult(get_couche_state());
	printTestResult(set_couche_state());
	printTestResult(add_forme_to_couche());
	printTestResult(remove_forme_from_couche());
	printTestResult(couche_total_area_calculation());
	printTestResult(translate_couche_formes());
	printTestResult(reinitialize_couche());

	cout << PURPLE << "===================================" << RESET << endl << endl;
}

void Tests::tests_unitaires_canevas() {
	cout << PURPLE << "===== TESTS UNITAIRES CANEVAS =====" << RESET << endl;

	printTestResult(instantiate_canevas());
	printTestResult(get_active_layer_index());
	printTestResult(set_active_layer_index());
	printTestResult(reinitialize_canevas());
	printTestResult(reinitialize_couche_in_canevas());
	printTestResult(activate_couche_in_canevas());
	printTestResult(add_forme_from_couche_in_canevas());
	printTestResult(remove_forme_from_couche_in_canevas());
	printTestResult(get_canevas_total_area());
	printTestResult(translate_canevas_formes());

	cout << PURPLE << "===================================" << RESET << endl << endl;
}

void Tests::tests_unitaires() {
	// Faire tous les tests unitaires
	tests_unitaires_formes();
	tests_unitaires_vecteur();
	tests_unitaires_couche();
	tests_unitaires_canevas();

	printFinalResults();
}

void Tests::tests_application() {
	// Faire tous les tests applicatifs
	tests_validation();

}

void Tests::tests_validation() {
	cout << PURPLE << "========= TESTS DE VALIDATION =========" << RESET << endl;

	Canevas can;

	cout << YELLOW << "Canevas initial:" << RESET << endl;
	can.afficher(cout);
	cout << endl;
	
	tests_val_part1(can);
	tests_val_part2(can);
	tests_val_part3(can);
	tests_val_part4(can);

	cout << PURPLE << "=========================================" << RESET << endl << endl;
}

void Tests::tests_val_part1(Canevas& c) {
	cout << GREEN << "----- Tests de validation partie 1 -----" << RESET << endl;

	cout << endl << BLUE << "----- Étape 1 -----" << RESET << endl;
	cout << YELLOW << "Activation de la couche 2." << RESET << endl;

	c.activerCouche(2);

	cout << YELLOW << "Création des formes suivantes :" << RESET << endl;

	Forme* cercle1 = new Cercle(0, 0, 5);
	Forme* carre1 = new Carre(4, 1, 6);
	Forme* rectangle1 = new Rectangle(2, 8, 3, 9);

	cercle1->afficher(cout);
	carre1->afficher(cout);
	rectangle1->afficher(cout);

	cout << YELLOW << "Ajout des formes au canevas." << RESET << endl;

	c.ajouterForme(cercle1);
	c.ajouterForme(carre1);
	c.ajouterForme(rectangle1);

	cout << endl << BLUE << "----- Étape 2 -----" << RESET << endl;
	cout << YELLOW << "Activation de la couche 1." << RESET << endl;

	c.activerCouche(1);

	cout << YELLOW << "Création de la forme suivante :" << RESET << endl;

	Forme* rectangle2 = new Rectangle(0, 0, 4, 2);

	rectangle2->afficher(cout);

	cout << YELLOW << "Ajout de la forme au canevas." << RESET << endl;

	c.ajouterForme(rectangle2);

	cout << endl << BLUE << "----- Étape 3 -----" << RESET << endl;
	cout << YELLOW << "Affichage du canevas:" << RESET << endl;

	c.afficher(cout);

	cout << endl << BLUE << "----- Étape 4 -----" << RESET << endl;
	cout << YELLOW << "Affichage de l'air du canevas:" << RESET << endl;
	cout << "Air totale: " << c.getAireTotale() << endl;

	cout << GREEN << "------------- Fin partie 1 -------------" << RESET << endl << endl;
}

void Tests::tests_val_part2(Canevas& c) {
	cout << GREEN << "----- Tests de validation partie 2 -----" << RESET << endl;

	cout << endl << BLUE << "----- Étape 5 -----" << RESET << endl;
	cout << YELLOW << "Activation de la couche 0." << RESET << endl;

	c.activerCouche(0);

	cout << YELLOW << "Création des formes suivantes :" << RESET << endl;

	Forme* rectangle1 = new Rectangle(0, 0, 1, 1);
	Forme* carre1 = new Carre(-1, -3, 1);
	Forme* cercle1 = new Cercle(0, 0, 2);

	rectangle1->afficher(cout);
	carre1->afficher(cout);
	cercle1->afficher(cout);

	cout << YELLOW << "Ajout des formes au canevas." << RESET << endl;

	c.ajouterForme(rectangle1);
	c.ajouterForme(carre1);
	c.ajouterForme(cercle1);

	cout << endl << BLUE << "----- Étape 6 -----" << RESET << endl;
	cout << YELLOW << "Activation de la couche 2." << RESET << endl;

	c.activerCouche(2);

	cout << YELLOW << "Translation des formes de la couche 2 de (x:4, y:3)." << RESET << endl;

	c.translater(4, 3);

	cout << endl << BLUE << "----- Étape 7 -----" << RESET << endl;
	cout << YELLOW << "Affichage du canevas:" << RESET << endl;

	c.afficher(cout);

	cout << endl << BLUE << "----- Étape 8 -----" << RESET << endl;
	cout << YELLOW << "Affichage de l'air du canevas:" << RESET << endl;
	cout << "Air totale: " << c.getAireTotale() << endl;

	cout << GREEN << "------------- Fin partie 2 -------------" << RESET << endl << endl;
}

void Tests::tests_val_part3(Canevas& c) {
	cout << GREEN << "----- Tests de validation partie 3 -----" << RESET << endl;

	cout << endl << BLUE << "----- Étape 9 -----" << RESET << endl;
	cout << YELLOW << "Activation de la couche 0." << RESET << endl;

	c.activerCouche(0);

	cout << YELLOW << "Retrait de la forme à l'index 1 de la couche active." << RESET << endl;

	c.retirerForme(1);

	cout << endl << BLUE << "----- Étape 10 -----" << RESET << endl;
	cout << YELLOW << "La couche 0 est déjà active." << RESET << endl;
	cout << YELLOW << "Retrait de la forme à l'index 0 de la couche active." << RESET << endl;

	c.retirerForme(0);

	cout << endl << BLUE << "----- Étape 11 -----" << RESET << endl;
	cout << YELLOW << "Activation de la couche 2." << RESET << endl;

	c.activerCouche(2);

	cout << YELLOW << "Réinitialisation de la couche 2." << RESET << endl;

	c.reinitialiserCouche(2);

	cout << endl << BLUE << "----- Étape 12 -----" << RESET << endl;
	cout << YELLOW << "Affichage du canevas:" << RESET << endl;

	c.afficher(cout);

	cout << endl << BLUE << "----- Étape 13 -----" << RESET << endl;
	cout << YELLOW << "Affichage de l'air du canevas:" << RESET << endl;
	cout << "Air totale: " << c.getAireTotale() << endl;

	cout << GREEN << "------------- Fin partie 3 -------------" << RESET << endl << endl;
}

void Tests::tests_val_part4(Canevas& c) {
	cout << GREEN << "----- Tests de validation partie 4 -----" << RESET << endl;

	cout << endl << BLUE << "----- Étape 14 -----" << RESET << endl;
	cout << YELLOW << "Réinitialisation du canevas." << RESET << endl;

	c.reinitialiser();

	cout << endl << BLUE << "----- Étape 15 -----" << RESET << endl;
	cout << YELLOW << "Affichage du canevas:" << RESET << endl;

	c.afficher(cout);

	cout << endl << BLUE << "----- Étape 16 -----" << RESET << endl;
	cout << YELLOW << "Affichage de l'air du canevas:" << RESET << endl;
	cout << "Air totale: " << c.getAireTotale() << endl;

	cout << GREEN << "------------- Fin partie 4 -------------" << RESET << endl;
}

void Tests::tests_unitaires_cercle() {
	cout << PURPLE << "===== TESTS UNITAIRES CERCLE =====" << RESET << endl;

	printTestResult(instantiate_circles());
	printTestResult(get_circle_values());
	printTestResult(set_circle_values());
	printTestResult(circle_area_calculation());

	cout << PURPLE << "===================================" << RESET << endl << endl;
}

void Tests::tests_unitaires_rectangle() {
	cout << PURPLE << "===== TESTS UNITAIRES RECTANGLE =====" << RESET << endl;

	printTestResult(instantiate_rectangles());
	printTestResult(get_rectangle_values());
	printTestResult(set_rectangle_values());
	printTestResult(rectangle_area_calculation());

	cout << PURPLE << "===================================" << RESET << endl << endl;
}

void Tests::tests_unitaires_carre() {
	cout << PURPLE << "===== TESTS UNITAIRES CARRE =====" << RESET << endl;

	printTestResult(instantiate_squares());
	printTestResult(get_square_values());
	printTestResult(set_square_values());
	printTestResult(square_area_calculation());

	cout << PURPLE << "===================================" << RESET << endl << endl;
}

bool Tests::instantiate_circles() {
	cout << YELLOW << "----- Instantiate circles test -----" << RESET << endl;

	try {
		Cercle c1(0, 0, 10);
		Cercle c2(5, 5, 20);
		Cercle c3;

		c1.afficher(cout);
		c2.afficher(cout);
		c3.afficher(cout);

		return true;
	} catch (const exception&) {
		return false;
	}
}

bool Tests::get_circle_values() {
	cout << YELLOW << "----- Get circle values test -----" << RESET << endl;

	Cercle c1(0, 0, 10);
	c1.afficher(cout);

	if (c1.getRayon() != 10)
		return false;

	if (c1.getAncrage().x != 0 || c1.getAncrage().y != 0)
		return false;

	return true;
}

bool Tests::set_circle_values() {
	cout << YELLOW << "----- Set circle values test -----" << RESET << endl;

	Cercle c1(0, 0, 10);
	c1.afficher(cout);

	c1.setRayon(25);
	c1.afficher(cout);

	if (c1.getRayon() != 25)
		return false;

	c1.setRayon(-5); // Should print an error message
	c1.afficher(cout);

	if (c1.getRayon() != 25) // Radius should remain unchanged
		return false;

	return true;
}

bool Tests::circle_area_calculation() {
	cout << YELLOW << "----- Circle area calculation test -----" << RESET << endl;

	Cercle c1(0, 0, 10);
	c1.afficher(cout);

	double expected_area = 3.14159265358979323846 * 10 * 10;

	if (abs(c1.aire() - expected_area) > 0.0001)
		return false;

	c1.setRayon(5);
	c1.afficher(cout);

	expected_area = 3.14159265358979323846 * 5 * 5;

	if (abs(c1.aire() - expected_area) > 0.0001)
		return false;

	return true;
}

bool Tests::instantiate_rectangles() {
	cout << YELLOW << "----- Instantiate rectangles test -----" << RESET << endl;

	try {
		Rectangle r1(0, 0, 10, 20);
		Rectangle r2(5, 5, 15, 25);
		Rectangle r3;

		r1.afficher(cout);
		r2.afficher(cout);
		r3.afficher(cout);

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::get_rectangle_values() {
	cout << YELLOW << "----- Get rectangle values test -----" << RESET << endl;

	Rectangle r1(0, 0, 10, 20);
	r1.afficher(cout);

	if (r1.getLargeur() != 10 || r1.getHauteur() != 20)
		return false;

	if (r1.getAncrage().x != 0 || r1.getAncrage().y != 0)
		return false;

	return true;
}

bool Tests::set_rectangle_values() {
	cout << YELLOW << "----- Set rectangle values test -----" << RESET << endl;

	Rectangle r1(0, 0, 10, 20);
	r1.afficher(cout);

	r1.setLargeur(30);
	r1.setHauteur(40);
	r1.afficher(cout);

	if (r1.getLargeur() != 30 || r1.getHauteur() != 40)
		return false;

	r1.setLargeur(-5); // Should print an error message
	r1.afficher(cout);

	if (r1.getLargeur() != 30 || r1.getHauteur() != 40)
		return false;

	return true;
}

bool Tests::rectangle_area_calculation() {
	cout << YELLOW << "----- Rectangle area calculation test -----" << RESET << endl;

	Rectangle r1(0, 0, 10, 20);
	r1.afficher(cout);

	double expected_area = 10 * 20;

	if (r1.aire() != expected_area)
		return false;

	r1.setLargeur(5);
	r1.setHauteur(15);
	r1.afficher(cout);

	expected_area = 5 * 15;

	if (r1.aire() != expected_area)
		return false;

	return true;
}

bool Tests::instantiate_squares() {
	cout << YELLOW << "----- Instantiate squares test -----" << RESET << endl;

	try {
		Carre c1(0, 0, 10);
		Carre c2(5, 5, 20);
		Carre c3;

		c1.afficher(cout);
		c2.afficher(cout);
		c3.afficher(cout);

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::get_square_values() {
	cout << YELLOW << "----- Get square values test -----" << RESET << endl;

	Carre c1(0, 0, 10);
	c1.afficher(cout);

	if (c1.getTaille() != 10)
		return false;

	if (c1.getAncrage().x != 0 || c1.getAncrage().y != 0)
		return false;

	return true;
}

bool Tests::set_square_values() {
	cout << YELLOW << "----- Set square values test -----" << RESET << endl;

	Carre c1(0, 0, 10);
	c1.afficher(cout);

	c1.setTaille(25);
	c1.afficher(cout);

	if (c1.getTaille() != 25)
		return false;

	c1.setTaille(-5); // Should print an error message
	c1.afficher(cout);

	if (c1.getTaille() != 25) // Side length should remain unchanged
		return false;

	return true;
}

bool Tests::square_area_calculation() {
	cout << YELLOW << "----- Square area calculation test -----" << RESET << endl;

	Carre c1(0, 0, 10);
	c1.afficher(cout);

	double expected_area = 10 * 10;

	if (c1.aire() != expected_area)
		return false;

	c1.setTaille(5);
	c1.afficher(cout);

	expected_area = 5 * 5;

	if (c1.aire() != expected_area)
		return false;

	return true;
}

bool Tests::instantiate_vecteurs() {
	cout << YELLOW << "----- Vecteur instantiation test -----" << RESET << endl;

	try {
		Vecteur<int> v1;
		Vecteur<double> v2(5);
		Vecteur<string> v3;
		Vecteur<Forme*> v4(3);

		v1.print(cout);
		cout << endl;

		v2.print(cout);
		cout << endl;

		v3.print(cout);
		cout << endl;

		v4.print(cout);
		cout << endl;
		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::vecteur_push_back() {
	cout << YELLOW << "----- Vecteur push_back test -----" << RESET << endl;

	try {
		Vecteur<int> v1;
		v1.push_back(10);
		v1.push_back(20);
		v1.push_back(30);

		v1.print(cout);
		cout << endl;

		if (v1.size() != 3)
			return false;

		if (v1[0] != 10 || v1[1] != 20 || v1[2] != 30)
			return false;

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::vecteur_size() {
	cout << YELLOW << "----- Vecteur size test -----" << RESET << endl;

	Vecteur<int> v1;

	v1.print(cout);
	cout << endl;

	if (v1.size() != 0)
		return false;

	v1.push_back(10);

	v1.print(cout);
	cout << endl;

	if (v1.size() != 1)
		return false;

	return true;
}

bool Tests::vecteur_is_empty() {
	cout << YELLOW << "----- Vecteur is empty test -----" << RESET << endl;

	Vecteur<int> v1;

	v1.print(cout);
	cout << endl;

	if (!v1.isEmpty())
		return false;

	v1.push_back(10);

	v1.print(cout);
	cout << endl;

	if (v1.isEmpty())
		return false;

	return true;
}

bool Tests::vecteur_resize() {
	cout << YELLOW << "----- Vecteur resize test -----" << RESET << endl;

	Vecteur<int> v1;
	v1.push_back(10);

	v1.resize(5);

	v1.print(cout);
	cout << endl;

	if (v1.size() != 5)
		return false;

	v1.resize(2);

	v1.print(cout);
	cout << endl;

	if (v1.size() != 2)
		return false;

	return true;
}

bool Tests::vecteur_clear() {
	cout << YELLOW << "----- Vecteur clear test -----" << RESET << endl;

	Vecteur<int> v1;
	v1.push_back(10);

	v1.print(cout);
	cout << endl;

	v1.clear();

	v1.print(cout);
	cout << endl;

	if (v1.size() != 0)
		return false;

	return true;
}

bool Tests::vecteur_print() {
	cout << YELLOW << "----- Vecteur print test -----" << RESET << endl;

	try {
		Vecteur<int> v1;

		v1.push_back(10);
		v1.push_back(20);
		v1.push_back(30);

		v1.print(cout);
		cout << endl;

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::instantiate_couches() {
	cout << YELLOW << "----- Instantiate couches test -----" << RESET << endl;

	try {
		Couche c1;

		c1.afficher(cout);

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::get_couche_state() {
	cout << YELLOW << "----- Get couche state test -----" << RESET << endl;

	Couche c1;
	c1.afficher(cout);
	
	if (c1.getState() != STATES[0])
		return false;

	return true;
}

bool Tests::set_couche_state() {
	cout << YELLOW << "----- Set couche state test -----" << RESET << endl;

	Couche c1;

	c1.afficher(cout);

	if (!c1.setState(1)) // Set to Active 
		return false;

	c1.afficher(cout);

	if (c1.setState(0)) // Invalid transition from Active to Initialisée
		return false;

	return true;
}

bool Tests::add_forme_to_couche() {
	cout << YELLOW << "----- Add forme to couche test -----" << RESET << endl;

	Couche c1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);

	c1.afficher(cout);

	if (!c1.addForme(f1))
		return false;

	c1.afficher(cout);

	return true;
}

bool Tests::remove_forme_from_couche() {
	cout << YELLOW << "----- Remove forme from couche test -----" << RESET << endl;

	Couche c1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);
	Forme* f2 = new Cercle(5, 5, 15);

	c1.addForme(f1);
	c1.addForme(f2);

	c1.afficher(cout);

	Forme* removedForme = c1.removeForme(0);
	c1.afficher(cout);

	if (removedForme != f1 || removedForme == nullptr)
		return false;

	return true;
}

bool Tests::couche_total_area_calculation() {
	cout << YELLOW << "----- Couche total area calculation test -----" << RESET << endl;

	Couche c1;
	Forme* f1 = new Rectangle(0, 0, 10, 20); // Area = 200
	Forme* f2 = new Cercle(5, 5, 10);       // Area = 314.159...

	c1.addForme(f1);
	c1.addForme(f2);

	c1.afficher(cout);

	double expected_area = 200 + 3.14159265358979323846 * 10 * 10;

	if (abs(c1.getAireTotale() - expected_area) > 0.0001)
		return false;

	return true;
}

bool Tests::translate_couche_formes() {
	cout << YELLOW << "----- Translate couche formes test -----" << RESET << endl;

	Couche c1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);

	c1.setState(1); // Set to Active
	c1.addForme(f1);

	c1.afficher(cout);

	if (!c1.translateFormes(5, 10))
		return false;

	c1.afficher(cout);

	return true;
}

bool Tests::reinitialize_couche() {
	cout << YELLOW << "----- Reinitialize couche test -----" << RESET << endl;

	Couche c1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);

	c1.addForme(f1);

	c1.afficher(cout);

	if (!c1.reinitialiser())
		return false;

	c1.afficher(cout);

	return true;
}

bool Tests::instantiate_canevas() {
	cout << YELLOW << "----- Instantiate canevas test -----" << RESET << endl;

	try {
		Canevas can1;
		can1.afficher(cout);

		return true;
	}
	catch (const exception&) {
		return false;
	}
}

bool Tests::get_active_layer_index() {
	cout << YELLOW << "----- Get active layer index test -----" << RESET << endl;

	Canevas can1;

	can1.afficher(cout);

	can1.activerCouche(1);

	can1.afficher(cout);

	if (can1.getActiveLayerIndex() != 1)
		return false;

	return true;
}

bool Tests::set_active_layer_index() {
	cout << YELLOW << "----- Set active layer index test -----" << RESET << endl;

	Canevas can1;

	can1.afficher(cout);

	can1.setActiveLayerIndex(1);

	can1.afficher(cout);

	if (can1.getActiveLayerIndex() != 1)
		return false;

	return true;
}

bool Tests::reinitialize_canevas() {
	cout << YELLOW << "----- Reinitialize canevas test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);

	can1.ajouterForme(f1);

	can1.afficher(cout);

	if (!can1.reinitialiser())
		return false;

	can1.afficher(cout);

	return true;
}

bool Tests::reinitialize_couche_in_canevas() {
	cout << YELLOW << "----- Reinitialize couche in canevas test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);
	Forme* f2 = new Cercle(5, 5, 15);

	can1.ajouterForme(f1);
	can1.ajouterForme(f2);

	can1.afficher(cout);

	if (!can1.reinitialiserCouche(0))
		return false;

	can1.afficher(cout);

	return true;
}

bool Tests::activate_couche_in_canevas() {
	cout << YELLOW << "----- Activate couche in canevas test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);
	Forme* f2 = new Cercle(5, 5, 15);

	can1.afficher(cout);

	if (!can1.activerCouche(1))
		return false;

	can1.ajouterForme(f1);
	can1.ajouterForme(f2);

	can1.afficher(cout);

	return true;
}

bool Tests::add_forme_from_couche_in_canevas() {
	cout << YELLOW << "----- Add forme from couche in canevas test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);

	can1.afficher(cout);

	if (!can1.ajouterForme(f1))
		return false;

	can1.afficher(cout);

	return true;
}

bool Tests::remove_forme_from_couche_in_canevas() {
	cout << YELLOW << "----- Remove forme from couche in canevas test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);

	can1.ajouterForme(f1);
	can1.afficher(cout);

	if (!can1.retirerForme(0))
		return false;

	can1.afficher(cout);

	return true;
}

bool Tests::get_canevas_total_area() {
	cout << YELLOW << "----- Get canevas total area test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20); // Area = 200
	Forme* f2 = new Cercle(5, 5, 10);       // Area = 314.159...

	can1.ajouterForme(f1);
	can1.ajouterForme(f2);

	can1.afficher(cout);

	double expected_area = 200 + (3.14159265358979323846 * 10 * 10);

	if (abs(can1.getAireTotale() - expected_area) > 0.0001)
		return false;

	return true;
}

bool Tests::translate_canevas_formes() {
	cout << YELLOW << "----- Translate canevas formes test -----" << RESET << endl;

	Canevas can1;
	Forme* f1 = new Rectangle(0, 0, 10, 20);
	Forme* f2 = new Cercle(5, 5, 15);
	
	can1.ajouterForme(f1);
	can1.ajouterForme(f2);

	can1.afficher(cout);

	if (!can1.translater(5, 10))
		return false;

	can1.afficher(cout);

	if (can1.translater(0, 0))
		return false;

	return true;
}