#include "deck.h"
#include <algorithm>  // Pour std::shuffle
#include <random>     // Pour std::random_device et std::mt19937

Deck::Deck() {
    for (int signe = Carte::TREFLES; signe <= Carte::PIQUES; ++signe) {
        for (int valeur = Carte::DEUX; valeur <= Carte::AS; ++valeur) {
            m_cartes.push_back(Carte(static_cast<Carte::Signe>(signe), static_cast<Carte::Valeur>(valeur)));
        }
    }
    melange();
}

void Deck::melange() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_cartes.begin(), m_cartes.end(), g);
}

Carte Deck::distribCarte() {
    if (!m_cartes.empty()) {
        Carte carte = m_cartes.back();
        m_cartes.pop_back();
        return carte;
    } else {
        throw std::out_of_range("Le deck est vide!");
    }
}
