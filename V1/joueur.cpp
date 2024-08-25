#include "joueur.h"
#include <iostream>
using namespace std;

Joueur::Joueur(const string& name) : m_nom(name) {}

void Joueur::ajtCarte(const Carte& card) {
    m_hand.push_back(card);
}

int Joueur::getTotal() const {
    int total = 0;
    int nombreAs = 0;

    for (const Carte& carte : m_hand) {
        int valeurCarte = carte.getValeur();

        if (valeurCarte == 11) {  // Si c'est un As
            nombreAs++;
            total += 11;
        } else {
            total += valeurCarte;
        }
    }

    while (total > 21 && nombreAs > 0) {
        total -= 10;
        nombreAs--;
    }

    return total;
}

bool Joueur::isBusted() const {
    return getTotal() > 21;
}

void Joueur::showHand() const {
    for (const Carte& carte : m_hand) {
        carte.afficher();
    }
}

void Joueur::showFirstCard() const {
    if (!m_hand.empty()) {
        m_hand.front().afficher();
    }
}

bool Joueur::veutTirer() const {
    return false; // Par défaut, retourner false. Peut être modifié par stratégie.
}
