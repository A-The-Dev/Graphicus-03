/********
* Fichier: monInterface.h
* Auteurs: A. Samson
* Date: 02 février 2026
* Description: La classe MonInterface modifiée pour l'interface utilisateur GraphicusGUI.
*
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

    // Menu Fichier
    virtual bool ouvrirFichier(const char* nom) override;
    virtual bool sauvegarderFichier(const char* nom) override;

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

    // mode pile
    virtual void modePileChange(bool mode) override;

    // Overrides from base class
    virtual void coucheTranslater(int deltaX, int deltaY) override;
    virtual void ajouterCercle(int x, int y, int r) override;
    virtual void ajouterRectangle(int x, int y, int l, int h) override;
    virtual void ajouterCarre(int x, int y, int t) override;
};
#endif // MONINTERFACE_H
