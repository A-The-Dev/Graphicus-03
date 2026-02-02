/********
* Fichier: GraphicusGUI.cpp
* Auteurs: A. Samson
* Date: 02 février 2026
* Description: main pour Graphicus-03.
*
********/

#include <QApplication>
#include "tests.h"
#include "monInterface.h"

using namespace std;

int main( int argc, char ** argv ) {
	//Tests tests;

	//tests.tests_application();
	//tests.tests_unitaires();

	QApplication app(argc, argv);
	MonInterface gui("GraphicusGUI 1.1");

	return app.exec();
}
