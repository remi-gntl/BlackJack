#ifndef CARTE_H
#define CARTE_H

#include <iostream>
using namespace std;

class Carte {
public:
    enum Signe { TREFLES, CARREAUX, COEURS, PIQUES };
    enum Valeur { DEUX = 2, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF, DIX, VALET = 10, DAME = 10, ROI = 10, AS = 11 };

    Carte(Signe signe, Valeur valeur);

    int getValeur() const;
    string getSigneString() const;
    string getValeurString() const;
    void afficher() const;

private:
    Signe m_signe;
    Valeur m_valeur;
};

#endif
