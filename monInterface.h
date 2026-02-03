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
#include "canevas.h"

class MonInterface : public GraphicusGUI
{
private:
    Canevas* canevas;

    string canevasToString();
    void updateDisplay();
    void updateInformations();
    void generateRandomCanevas();

public:
    MonInterface(const char* theName = nullptr);
    virtual ~MonInterface();

    // Menu Canevas
    virtual void reinitialiserCanevas() override;
    virtual void coucheAjouter() override;
    virtual void coucheRetirer() override;

    // Menu Formes
    virtual void retirerForme() override;

    // Menu navigation
    virtual void couchePremiere() override;
    virtual void couchePrecedente() override;
    virtual void coucheSuivante() override;
    virtual void coucheDerniere() override;
    virtual void formePremiere() override;
    virtual void formePrecedente() override;
    virtual void formeSuivante() override;
    virtual void formeDerniere() override;

    // Overrides from base class
    virtual void coucheTranslater(int deltaX, int deltaY) override;
    virtual void ajouterCercle(int x, int y, int r) override;
    virtual void ajouterRectangle(int x, int y, int l, int h) override;
    virtual void ajouterCarre(int x, int y, int t) override;
};
#endif // MONINTERFACE_H
