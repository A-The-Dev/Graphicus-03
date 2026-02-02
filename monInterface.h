/********
* Fichier: monInterface.h
* Auteurs: C.-A. Brunet
* Date: 10 janvier 2024
* Description: La classe MonInterface teste l'interface utilisateur GraphicusGUI.
*
* Copyright 2024 Département de génie électrique et génie informatique
*                Université de Sherbrooke  
********/

#ifndef MONINTERFACE_H
#define MONINTERFACE_H

#include "graphicusGUI.h"

class MonInterface : public GraphicusGUI
{
public:
	MonInterface(const char *theName = nullptr);
	virtual void reinitialiserCanevas();
};

#endif // MONINTERFACE_H
