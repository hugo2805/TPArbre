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

    //Parcours pr�fix�
    void ParcoursPrefix(Node* noeud);

    //Parcours Postfix�
    void ParcoursPostfix(Node* noeud);

    //Calcul du nombre de noeuds
    int NbNode();
    //calcul de la profondeur de l'arbre
    int ProfondeurArbre(Node* racine, Arbre arbre);

    //V�rifier si l'arbre est �quilibr�
};