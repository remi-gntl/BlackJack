#include "carte.h"

Carte::Carte(Signe signe, Valeur valeur)
    : m_signe(signe), m_valeur(valeur) {}

int Carte::getValeur() const {
    // L'As vaut initialement 11 mais peut être ajusté
    return m_valeur;
}

string Carte::getSigneString() const {
    switch (m_signe) {
        case TREFLES: return "Trefles";
        case CARREAUX: return "Carreaux";
        case COEURS: return "Coeurs";
        case PIQUES: return "Piques";
        default: return "Inconnu";
    }
}

string Carte::getValeurString() const {
    switch (m_valeur) {
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return (m_valeur == VALET) ? "Valet" : (m_valeur == DAME) ? "Dame" : "Roi";
        case 11: return "As";
        default: return "Inconnue";
    }
}

void Carte::afficher() const {
    string couleur;

    // Couleur en fonction du signe
    if (m_signe == COEURS || m_signe == CARREAUX) {
        couleur = "\033[31m";  // Rouge
    } else {
        couleur = "\033[90m";  // Gris clair
    }

    // Afficher la carte avec la couleur appropriée
    cout << couleur << getValeurString() << " de " << getSigneString() << "\033[0m" << endl;
}
