/********
* Fichier: monInterface.cpp
* Auteurs: A. Samson
* Date: 02 février 2026
* Description: La classe MonInterface modifiée pour l'interface utilisateur GraphicusGUI.
*
********/

#include "monInterface.h"
#include "cercle.h"
#include "rectangle.h"
#include "carre.h"
#include <fstream>
#include <sstream>
#include <random>
#include <cstring>

MonInterface::MonInterface(const char* theName) : GraphicusGUI(theName) 
{
    canevas = new Canevas();
    generateRandomCanevas();
    updateInformations();
}

MonInterface::~MonInterface() 
{
    delete canevas;
}

string MonInterface::canevasToString() 
{
    ostringstream os;
    int nbCouches = canevas->getCouchesSize();

    for (int i = 0; i < nbCouches; i++) {
        Couche couche = canevas->getCouche(i);
        string state = couche.getState();

        // Determine layer state character
        char stateChar;
        if (state == "Initialisée") {
            stateChar = 'i';
        }
        else if (state == "Active") {
            stateChar = 'a';
        }
        else if (state == "Inactive") {
            stateChar = 'x';
        }
        else {
            stateChar = 'i';  // Default
        }

        os << "L " << stateChar << endl;

        // Add all forms in this layer
        Vecteur<Forme*> formes = couche.getFormes();
        for (int j = 0; j < formes.size(); j++) {
            Forme* forme = formes[j];
            if (forme != nullptr) {
                Coordonnee anc = forme->getAncrage();

                // Try to determine the type of forme using dynamic_cast
                if (Cercle* c = dynamic_cast<Cercle*>(forme)) {
                    os << "C " << anc.x << " " << anc.y << " " << c->getRayon() << endl;
                }
                else if (Carre* k = dynamic_cast<Carre*>(forme)) {
                    os << "K " << anc.x << " " << anc.y << " " << k->getTaille() << endl;
                }
                else if (Rectangle* r = dynamic_cast<Rectangle*>(forme)) {
                    os << "R " << anc.x << " " << anc.y << " " << r->getLargeur() << " " << r->getHauteur() << endl;
                }
            }
        }
    }

    return os.str();
}

void MonInterface::updateDisplay() 
{
    // Clear the current display
    effacer();

    // Generate command format from current canvas state
    string commands = canevasToString();

    // Display the canevas
    dessiner(commands.c_str());
}

void MonInterface::updateInformations() 
{
    Informations info;

    // Get the actual number of layers from canevas
    info.nbCouches = canevas->getCouchesSize();
    info.coucheActive = canevas->getActiveLayerIndex();
    info.aireCanevas = canevas->getAireTotale();

    // Count total forms in canvas
    info.nbFormesCanevas = 0;
    for (int i = 0; i < info.nbCouches; i++) {
        Couche couche = canevas->getCouche(i);
        info.nbFormesCanevas += couche.getFormes().size();
    }

    // Get active layer information
    if (info.coucheActive >= 0 && info.coucheActive < info.nbCouches) {
        Couche activeCouche = canevas->getCouche(info.coucheActive);
        info.nbFormesCouche = activeCouche.getFormes().size();
        info.aireCouche = activeCouche.getAireTotale();

        // Get layer state
        string state = activeCouche.getState();
        strncpy(info.etatCouche, state.c_str(), 19);
        info.etatCouche[19] = '\0';

        // Get the active form using activeShapeIndex
        if (info.nbFormesCouche > 0) {
            info.formeActive = activeCouche.getActiveShapeIndex();
            Forme* activeForme = activeCouche.getFormeByIndex(info.formeActive);

            if (activeForme != nullptr) {
                Coordonnee ancrage = activeForme->getAncrage();
                info.coordX = ancrage.x;
                info.coordY = ancrage.y;
                info.aireForme = activeForme->aire();

                // Get form-specific information
                ostringstream formInfo;
                activeForme->afficher(formInfo);
                string formStr = formInfo.str();
                // Extract just the essential info (first line if multi-line)
                size_t newlinePos = formStr.find('\n');
                if (newlinePos != string::npos) {
                    formStr = formStr.substr(0, newlinePos);
                }
                strncpy(info.informationForme, formStr.c_str(), 49);
                info.informationForme[49] = '\0';
            }
            else {
                info.formeActive = -1;
                info.coordX = 0;
                info.coordY = 0;
                info.aireForme = 0.0;
                strcpy(info.informationForme, "");
            }
        }
        else {
            info.formeActive = -1;
            info.coordX = 0;
            info.coordY = 0;
            info.aireForme = 0.0;
            strcpy(info.informationForme, "");
        }
    }
    else {
        info.nbFormesCouche = 0;
        strcpy(info.etatCouche, "");
        info.aireCouche = 0.0;
        info.formeActive = -1;
        info.coordX = 0;
        info.coordY = 0;
        info.aireForme = 0.0;
        strcpy(info.informationForme, "");
    }

    setInformations(info);
}
void MonInterface::generateRandomCanevas() 
{
    canevas->reinitialiser();

    ostringstream os;
    random_device r;
    default_random_engine generator(r());
    uniform_int_distribution<int> coor(0, 300), dim(20, 100);

    os << "L x" << endl;  // Layer inactive
    os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
    os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
    os << "L a" << endl;  // Layer active
    os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
    os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
    os << "L x" << endl;
    os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
    os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
    os << "L x" << endl;
    os << "R " << coor(generator) << " " << coor(generator) << " " << dim(generator) << " " << dim(generator) << endl;
    os << "K " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;
    os << "C " << coor(generator) << " " << coor(generator) << " " << dim(generator) << endl;

    // Draw using the command format
    dessiner(os.str().c_str());
    updateInformations();
}

// Menu fichier
bool MonInterface::ouvrirFichier(const char* nom)
{
    ifstream fichier;
    string ligne;

    canevas->reinitialiser();

    fichier.open(nom); 
    if (!fichier) 
    { 
       messageErreur("Le fichier n’a pas pu être ouvert");
       return false; 
    }

    // ignore la première ligne puisqu'une couche demeure toujours dans le canevas après la réinitialisation
    getline(fichier, ligne);

    while (getline(fichier, ligne)) 
    {
        // Si la ligne est vide, on passe à la prochaine
        if (ligne.empty())
        {
            continue;
        }

        istringstream iss(ligne);

        char type; 
        iss >> type;

        if (type == 'L')
        {
            this->coucheAjouter();
            char etat_couche;
            iss >> etat_couche;
            //ajouter l'état de la couche
        }
        else if (type == 'R')
        {
            int x, y, l, h; 
            iss >> x >> y >> l >> h; 
            ajouterRectangle(x, y, l, h);
        }
        else if (type == 'K')
        {
            int x, y, t;
            iss >> x >> y >> t;
            ajouterCarre(x, y, t);
        }
        else if (type == 'C')
        {
            int x, y, c;
            iss >> x >> y >> c;
            ajouterCercle(x, y, c);
        }
    }

    updateDisplay();
    updateInformations();
    fichier.close();

    return true;
}

bool MonInterface::sauvegarderFichier(const char* nom)
{
    ofstream fichier;

    fichier.open(nom);
    if (!fichier.is_open()) 
    { 
        messageErreur("Le fichier n’a pas pu être sauvegardé");
        return false; 
    } 

    fichier << this->canevasToString();
    return true;
}

void MonInterface::reinitialiserCanevas()
{
    // Reset the canevas to empty state
    canevas->reinitialiser();
    
    message("Canevas réinitialisé");
    updateDisplay();
    updateInformations();
}

// Menu Canevas
void MonInterface::coucheAjouter()
{
    bool success = canevas->ajouterCouche();
    if (success) {
        message("Couche ajoutée");
        updateDisplay();
        updateInformations();
    }
    else {
        messageErreur("Erreur lors de l'ajout de la couche");
    }
}

void MonInterface::coucheRetirer()
{
    int activeIndex = canevas->getActiveLayerIndex();
    if (activeIndex >= 0) {
        bool success = canevas->retirerCouche(activeIndex);
        if (success) {
            message("Couche retirée");
            updateDisplay();
            updateInformations();
        }
        else {
            messageErreur("Erreur lors de la suppression de la couche");
        }
    }
    else {
        messageErreur("Aucune couche active");
    }
}

// Menu Formes
void MonInterface::retirerForme()
{
    if (canevas->getCouchesSize() <= 0) {
        messageErreur("Aucune couche n'existe!");
        return;
    }

    if (canevas->getActiveLayerIndex() < 0) {
        messageErreur("Aucune couche active");
        return;
    }

    Couche activeCouche = canevas->getCouche(canevas->getActiveLayerIndex());
    int nbFormes = activeCouche.getFormes().size();

    if (nbFormes > 0) {
		int shapeIndex = activeCouche.getActiveShapeIndex();

        bool success = canevas->retirerForme(shapeIndex);
        if (success) {
            message("Forme retirée");
            updateDisplay();
            updateInformations();
        }
        else {
            messageErreur("Erreur lors du retrait de la forme");
        }
    }
    else {
        messageErreur("Aucune forme dans la couche active");
    }
}

// Menu navigation - Couches
void MonInterface::couchePremiere()
{
    bool success = canevas->activerCouche(0);
    if (success) {
        message("Première couche activée");
        updateDisplay();
        updateInformations();
    }
    else {
        messageErreur("Impossible d'activer la première couche");
    }
}

void MonInterface::couchePrecedente()
{
    int currentIndex = canevas->getActiveLayerIndex();
    if (currentIndex > 0) {
        bool success = canevas->activerCouche(currentIndex - 1);
        if (success) {
            message("Couche précédente activée");
            updateDisplay();
            updateInformations();
        }
        else {
            messageErreur("Erreur lors de l'activation de la couche précédente");
        }
    }
    else {
        messageErreur("Déjà à la première couche");
    }
}

void MonInterface::coucheSuivante()
{
    int currentIndex = canevas->getActiveLayerIndex();
    int maxIndex = canevas->getCouchesSize() - 1;

    if (currentIndex < maxIndex) {
        bool success = canevas->activerCouche(currentIndex + 1);
        if (success) {
            message("Couche suivante activée");
            updateDisplay();
            updateInformations();
        }
        else {
            messageErreur("Erreur lors de l'activation de la couche suivante");
        }
    }
    else {
        messageErreur("Déjà à la dernière couche");
    }
}

void MonInterface::coucheDerniere()
{
    int lastIndex = canevas->getCouchesSize() - 1;

    bool success = canevas->activerCouche(lastIndex);
    if (success) {
        message("Dernière couche activée");
        updateDisplay();
        updateInformations();
    }
    else {
        messageErreur("Impossible d'activer la dernière couche");
    }
}

// Menu navigation - Formes
void MonInterface::formePremiere()
{
    int activeLayerIndex = canevas->getActiveLayerIndex();
    if (activeLayerIndex < 0) {
        messageErreur("Aucune couche active");
        return;
    }

    Couche activeCouche = canevas->getCouche(activeLayerIndex);
    if (activeCouche.getFormes().size() > 0) {
        activeCouche.setActiveShapeIndex(0);
        canevas->setCouche(activeCouche, activeLayerIndex);
        message("Première forme sélectionnée");
        updateInformations();
    }
    else {
        messageErreur("Aucune forme dans la couche active");
    }
}

void MonInterface::formePrecedente()
{
    int activeLayerIndex = canevas->getActiveLayerIndex();
    if (activeLayerIndex < 0) {
        messageErreur("Aucune couche active");
        return;
    }

    Couche activeCouche = canevas->getCouche(activeLayerIndex);
    int currentShapeIndex = activeCouche.getActiveShapeIndex();

    if (activeCouche.getFormes().size() == 0) {
        messageErreur("Aucune forme dans la couche active");
        return;
    }

    if (currentShapeIndex > 0) {
        activeCouche.setActiveShapeIndex(currentShapeIndex - 1);
        canevas->setCouche(activeCouche, activeLayerIndex);
        message("Forme précédente sélectionnée");
        updateInformations();
    }
    else {
        messageErreur("Déjà à la première forme");
    }
}

void MonInterface::formeSuivante()
{
    int activeLayerIndex = canevas->getActiveLayerIndex();
    if (activeLayerIndex < 0) {
        messageErreur("Aucune couche active");
        return;
    }

    Couche activeCouche = canevas->getCouche(activeLayerIndex);
    int currentShapeIndex = activeCouche.getActiveShapeIndex();
    int nbFormes = activeCouche.getFormes().size();

    if (nbFormes == 0) {
        messageErreur("Aucune forme dans la couche active");
        return;
    }

    if (currentShapeIndex < nbFormes - 1) {
        activeCouche.setActiveShapeIndex(currentShapeIndex + 1);
        canevas->setCouche(activeCouche, activeLayerIndex);
        message("Forme suivante sélectionnée");
        updateInformations();
    }
    else {
        messageErreur("Déjà à la dernière forme");
    }
}

void MonInterface::formeDerniere()
{
    int activeLayerIndex = canevas->getActiveLayerIndex();
    if (activeLayerIndex < 0) {
        messageErreur("Aucune couche active");
        return;
    }

    Couche activeCouche = canevas->getCouche(activeLayerIndex);
    int nbFormes = activeCouche.getFormes().size();

    if (nbFormes > 0) {
        activeCouche.setActiveShapeIndex(nbFormes - 1);
        canevas->setCouche(activeCouche, activeLayerIndex);
        message("Dernière forme sélectionnée");
        updateInformations();
    }
    else {
        messageErreur("Aucune forme dans la couche active");
    }
}

// mode pile
void MonInterface::modePileChange(bool mode)
{
    canevas->inverserCouches();

    updateDisplay();
    updateInformations();

    if (mode == true)
    {
        message("Mode pile activé");
    }
    else {
        message("Mode pile désactivé");
    }
}

// Other overrides
void MonInterface::coucheTranslater(int deltaX, int deltaY)
{
    bool success = canevas->translater(deltaX, deltaY);
    if (success) {
        message("Couche translatée");
        updateDisplay();
        updateInformations();
    }
    else {
        messageErreur("Erreur lors de la translation (couche doit être active)");
    }
}

void MonInterface::ajouterCercle(int x, int y, int r)
{
    Forme* cercle = new Cercle(x, y, r);
    bool success = canevas->ajouterForme(cercle);

    if (success) {
        message("Cercle ajouté");
        updateDisplay();
        updateInformations();
    }
    else {
        delete cercle;
        messageErreur("Erreur lors de l'ajout du cercle");
    }
}

void MonInterface::ajouterRectangle(int x, int y, int l, int h)
{
    Forme* rectangle = new Rectangle(x, x, l, h);
    bool success = canevas->ajouterForme(rectangle);

    if (success) {
        message("Rectangle ajouté");
        updateDisplay();
        updateInformations();
    }
    else {
        delete rectangle;
        messageErreur("Erreur lors de l'ajout du rectangle");
    }
}

void MonInterface::ajouterCarre(int x, int y, int t)
{
    Forme* carre = new Carre(x, y, t);
    bool success = canevas->ajouterForme(carre);

    if (success) {
        message("Carré ajouté");
        updateDisplay();
        updateInformations();
    }
    else {
        delete carre;
        messageErreur("Erreur lors de l'ajout du carré");
    }
}