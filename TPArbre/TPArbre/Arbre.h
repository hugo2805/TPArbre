#pragma once
#include "Node.h"
class Arbre {

private:
    Node* root;
    int taille;

public:
    Arbre();
    ~Arbre();
    Node* getRoot();
    //Placer une node
    void Placer(Node* noeud);
    //Créer une node
    void Ajouter(int value);
    Node* Rechercher(int value);
    void Supprimer(Node* noeud);
    void Afficher(Node* racine);
};