// dealer.h
#ifndef CROUPIER_H
#define CROUPIER_H

#include "joueur.h"

class Croupier : public Joueur {
public:
    Croupier();

    bool veutTirer() const override;
};

#endif
