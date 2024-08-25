# Blackjack en C++

## Présentation du projet

Ce projet est un jeu de **Blackjack** codé en C++, jouable en ligne de commande. Le jeu suit les règles classiques du Blackjack, avec un joueur et un croupier qui tirent des cartes depuis un paquet mélangé. L'objectif est d'obtenir un total de points aussi proche que possible de 21 sans dépasser cette valeur.

### Fonctionnalités de la Version 1 (V1)

- **Affichage en couleur :** Les cartes sont affichées en fonction de leur couleur (rouge pour les Cœurs et Carreaux, gris pour les Piques et Trèfles).
  
- **Jeu classique de Blackjack :** 
  - Le joueur commence avec deux cartes.
  - Le croupier commence avec deux cartes, dont une cachée.
  - Le joueur peut décider de tirer des cartes supplémentaires ou de rester.
  - Le croupier tire automatiquement selon les règles classiques (doit tirer jusqu'à 16 inclus et rester à 17 ou plus).
    
- **Gestion des totaux et des busts :** 
  - Le total des points du joueur et du croupier est affiché.
  - Si le joueur dépasse 21, il perd automatiquement.
  - Si le croupier dépasse 21, le joueur gagne.
    
- **Option de rejouer :** 
  - Après chaque partie, le joueur a la possibilité de rejouer sans relancer le programme.
    
- **Interface améliorée :** 
  - Effacement du terminal entre chaque tour pour rendre le jeu plus fluide.
  - Mise en forme élégante des titres, des erreurs et des messages de victoire.

## Installation et utilisation

### Prérequis

- Un compilateur C++ (GCC, Clang, ou MSVC).
- Un terminal compatible avec les séquences d'échappement ANSI pour l'affichage en couleur (Linux, macOS, ou PowerShell sous Windows).

### Compilation

Pour compiler le projet, utilisez la commande suivante dans le terminal :

```bash
g++ -o blackjack main.cpp carte.cpp deck.cpp joueur.cpp croupier.cpp game-tools.cpp
```

Une fois compilé, lancez le jeu avec :
```bash
./blackjack
```

