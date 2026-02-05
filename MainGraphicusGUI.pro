TEMPLATE     = vcapp
TARGET       = MainGraphicusGUI
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h vecteur.hpp canevas.h couche.h coordonnee.h forme.h rectangle.h carre.h cercle.h
SOURCES     += monInterface.cpp MainGraphicusGUI.cpp canevas.cpp couche.cpp forme.cpp rectangle.cpp carre.cpp cercle.cpp
INCLUDEPATH += GraphicusGUI
LIBS        += GraphicusGUI/graphicusGUI.lib
QT          += widgets
