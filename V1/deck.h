#ifndef DECK_H
#define DECK_H

#include "carte.h"
#include <vector>

class Deck {
public:
    Deck();
    void melange();
    Carte distribCarte();

private:
    vector<Carte> m_cartes;
};

#endif
