/********
* Fichier: GraphicusGUI.cpp
* Auteurs: A. Samson
* Date: 02 février 2026
* Description: main pour Graphicus-03.
*
********/

#include <QApplication>
#include <windows.h>
#include "tests.h"
#include "monInterface.h"

using namespace std;

int main( int argc, char ** argv ) {
	SetConsoleOutputCP(CP_UTF8);

	Tests tests;

	tests.tests_application();
	tests.tests_unitaires();

	//QApplication app(argc, argv);
	//MonInterface gui("GraphicusGUI 1.1");

	system("pause");

	return 0; //app.exec();
}
