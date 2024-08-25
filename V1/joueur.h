// joueur.h
#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#include <vector>

class Joueur {
public:
    Joueur(const string& name);

    void ajtCarte(const Carte& card);
    int getTotal() const;
    bool isBusted() const;
    virtual bool veutTirer() const;

    void showHand() const;
    void showFirstCard() const;

protected:
    string m_nom;
    vector<Carte> m_hand;
};

#endif
