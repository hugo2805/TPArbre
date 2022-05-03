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

    //Mutateur
    void setRoot(Node* racine);

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
    int NbNode(Node* racine);
    //calcul de la profondeur de l'arbre
    int ProfondeurArbre(Node* racine);

    // fonction de traitement de la donnée
    void traitement(Node* noeud);

    //Calcul du nombre de noeuds du sous arbre gauche
    int NbNodeGauche(Node* racine);

    //Calcul du nombre de noeuds du sous arbre droit
    int NbNodeDroite(Node* racine);

    //Vérifier si l'arbre est équilibré
    void Equilibre(Node* racine);

    //Rotation à droite
    void rotateDroite(Node* noeud);

    //Rotation à gauche
    void rotateGauche(Node* noeud);
};