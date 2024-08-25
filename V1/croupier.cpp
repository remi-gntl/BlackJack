// croupier.cpp
#include "croupier.h"

Croupier::Croupier() : Joueur("Croupier") {}

bool Croupier::veutTirer() const {
    return getTotal() < 17;
}
