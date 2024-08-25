/**
 * Jeu de Blackjack en C++
 *
 * Un jeu de Blackjack simple, où le joueur affronte un croupier. 
 * Le jeu inclut l'affichage en couleur et la gestion des tours.
 * 
 * Auteur: Rémi GENTIL
 * Version: 1.0
 * Date: 25/08/2024
 *
 * Github: https://github.com/remi-gntl
 */

#include "deck.h"
#include "joueur.h"
#include "croupier.h"
#include <iostream>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

// Effacer le terminal
void effacerTerminal() {
    system(CLEAR);  
}

// Afficher le titre du jeu avec des étoiles et de la couleur jaune
void afficherTitreJeu() {
    cout << "\033[33m";  // Couleur jaune pour le titre
    cout << "*********************************" << endl;
    cout << "*                               *" << endl;
    cout << "*        JEU DE BLACKJACK       *" << endl;
    cout << "*                               *" << endl;
    cout << "*********************************" << endl;
    cout << "\033[0m";  // Réinitialiser les couleurs
}

// Afficher l'état des mains du joueur et du croupier avec les totaux actuels
void afficherEtat(const Joueur& joueur, const Croupier& croupier, bool cacherCarteCroupier = true) {
    cout << "\n\033[36m--- Main du joueur ---\033[0m" << endl;
    joueur.showHand();
    cout << "\033[34mTotal: " << joueur.getTotal() << "\033[0m" << endl;

    cout << "\n\033[36m--- Main du Croupier ---\033[0m" << endl;
    if (cacherCarteCroupier) {
        croupier.showFirstCard();
        cout << "[Carte cachée]" << endl;
    } else {
        croupier.showHand();
    }
}

// Demander au joueur s'il veut rejouer
bool rejouer() {
    char choix;
    cout << "\n\033[33mVoulez-vous rejouer? (o/n): \033[0m";
    cin >> choix;
    return (choix == 'o' || choix == 'O');
}

// Fonction principale pour jouer une partie de Blackjack
void jouerUnePartie() {
    Deck deck;
    Joueur joueur("Joueur 1");
    Croupier croupier;

    effacerTerminal();
    afficherTitreJeu();  // Afficher le titre du jeu

    // Distribution initiale de 2 cartes au joueur et au croupier
    joueur.ajtCarte(deck.distribCarte());
    joueur.ajtCarte(deck.distribCarte());
    croupier.ajtCarte(deck.distribCarte());
    croupier.ajtCarte(deck.distribCarte());

    // Afficher l'état initial des mains
    afficherEtat(joueur, croupier);

    // Tour du joueur
    char decision;
    while (!joueur.isBusted()) {
        cout << "\n\033[33mVoulez-vous tirer une carte ? (o/n): \033[0m";
        cin >> decision;

        effacerTerminal();  // Effacer le terminal mais garder les informations clés

        if (decision == 'o' || decision == 'O') {
            joueur.ajtCarte(deck.distribCarte());
            
            // Afficher l'état actuel après tirage de carte
            afficherEtat(joueur, croupier);

            // Vérification si le joueur dépasse 21
            if (joueur.isBusted()) {
                cout << "\n\033[31mLe joueur a busté! Le croupier gagne!\033[0m\n";
                return;
            }
        } else if (decision == 'n' || decision == 'N') {
            break;  // Le joueur décide de rester
        } else {
            // Afficher à nouveau les mains du joueur et du croupier en cas de saisie invalide
            cout << "\n\033[31mChoix invalide. Veuillez entrer 'o' pour oui ou 'n' pour non.\033[0m" << endl;
            afficherEtat(joueur, croupier);
        }
    }

    // Révéler la deuxième carte du croupier
    effacerTerminal();
    afficherEtat(joueur, croupier, false);  // Révéler la main complète du croupier
    cout << "\033[34mTotal du croupier: " << croupier.getTotal() << "\033[0m" << endl;

    // Tour du croupier
    while (!croupier.isBusted() && croupier.veutTirer()) {
        croupier.ajtCarte(deck.distribCarte());

        effacerTerminal();
        afficherEtat(joueur, croupier, false);  // Afficher l'état après chaque carte tirée par le croupier
        cout << "\033[34mTotal du croupier: " << croupier.getTotal() << "\033[0m" << endl;
    }

    // Déterminer le gagnant si le croupier ne dépasse pas 21
    if (croupier.isBusted()) {
        cout << "\n\033[32mLe croupier a busté! Le joueur gagne!\033[0m\n";
    } else {
        if (croupier.getTotal() > joueur.getTotal()) {
            cout << "\n\033[31mLe croupier a gagné!\033[0m\n";
        } else if (croupier.getTotal() < joueur.getTotal()) {
            cout << "\n\033[32mLe joueur a gagné!\033[0m\n";
        } else {
            cout << "\n\033[33mÉgalité!\033[0m\n";
        }
    }
}

int main() {
    bool continuer = true;

    while (continuer) {
        jouerUnePartie();  // Lancer une partie de Blackjack
        continuer = rejouer();  // Demander si le joueur veut rejouer
        if (continuer) {
            effacerTerminal();  // Effacer l'écran pour recommencer une nouvelle partie
        }
    }

    cout << "\n\033[33mAu revoir!\033[0m\n";
    return 0;
}
