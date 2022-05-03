#pragma once
#include "Node.h"
class Arbre {

private:
    Node* root;

public:
    //Constructeur
    Arbre();

    //Destructeur
    ~Arbre();

    //Accesseur
    Node* getRoot();

    //Placer une node
    void Placer(Node* noeud);

    //Ajouter une node
    void Ajouter(int value);

    //Supprimer une node
    void Supprimer(Node* noeud);

    //Affichge
    void Afficher(Node* racine);

    //Fonction de recherche d'une node
    Node* Rechercher(int value);

    //Parcours préfixé
    void ParcoursPrefix(Node* noeud);

    //Parcours Postfixé
    void ParcoursPostfix(Node* noeud);

    //Calcul du nombre de noeuds
    int NbNode();
    //calcul de la profondeur de l'arbre
    int ProfondeurArbre(Node* racine, Arbre arbre);

    //Vérifier si l'arbre est équilibré
};