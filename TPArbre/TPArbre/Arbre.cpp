#include <iostream>
#include "stdio.h"
#include "Arbre.h"

using namespace std;

//Constructeur
Arbre::Arbre()
{
	root = nullptr;
}

//Destructeur
Arbre::~Arbre()
{
}

//Accesseur
Node* Arbre::getRoot()
{
	return root;
}

//Placer une node
void Arbre::Placer(Node* noeud)
{
	Node* courant = root;
	Node* precedent = nullptr;

	//On vérifie si l'arbre est vide
	if (root == nullptr)
	{
		root = noeud;
		return;
	}

	//On cherche une place vide
	while (courant)
	{
		precedent = courant;
		if (noeud->data < courant->data)
			courant = courant->leftChild;
		else
			courant = courant->rightChild;
	}

	//On a trouvé une place libre, precedent pointe vers le parent de notre noeud a replacer
	if (noeud->data < precedent->data)
		precedent->leftChild = noeud;
	else
		precedent->rightChild = noeud;
}

//Ajouter une Node
void Arbre::Ajouter(int value)
{
	//création du noeud en mémoire
	Node* nouveau = new Node;
	nouveau->data = value;
	nouveau->leftChild = nullptr;
	nouveau->rightChild = nullptr;

	Placer(nouveau);
}

//Rechercher une node
Node* Arbre::Rechercher(int value)
{
	Node* courant = root;
	while (courant)
	{
		if (value == courant->data)
			return courant;
		else if (value < courant->data)
			courant = courant->leftChild;
		else
			courant = courant->rightChild;
	}
	return nullptr;
}

//Parcours préfixé
void Arbre::ParcoursPrefix(Node* noeud)
{
	if (noeud != nullptr) {

		// Traitement de la donnée
		//TreatNode(root->data);

		//Navigation récursive
		ParcoursPrefix(noeud->leftChild);
		ParcoursPrefix(noeud->rightChild);
	}
}

//Parcours Postfixé
void Arbre::ParcoursPostfix(Node* noeud)
{
	if (noeud != nullptr) {

		//Navigation récursive
		ParcoursPostfix(noeud->leftChild);
		ParcoursPostfix(noeud->rightChild);

		//Traitement de la donnée
		//TreatNode(root->data);
	}
}

int Arbre::NbNode(Node* racine)
{
	if (racine == nullptr)
		return 0;
	else
		return 1 + NbNode(racine->leftChild) + NbNode(racine->rightChild);
}

int Arbre::ProfondeurArbre(Node* racine, Arbre arbre)
{
	int profDroite, profGauche, profondeur;

	//si l'arbre est vide on retourne -1
	if (racine == nullptr)
	{
		profondeur = -1;
	}
	else
	{	
		//calcul de la profondeur du sous arbre droit
		profDroite = arbre.ProfondeurArbre(racine->rightChild, arbre);
		//calcul de la profondeur du sous arbre gauche
		profGauche = arbre.ProfondeurArbre(racine->leftChild, arbre);

		if (profDroite > profGauche)
			profondeur = profDroite;
		else
			profondeur = profGauche;
	}
	return profondeur;
}

//Supprimer une Node
void Arbre::Supprimer(Node* noeud)
{
	Node* droite = noeud->rightChild;
	Node* gauche = noeud->leftChild;
	Node* courant = root;

	if (noeud == root)
	{
		root = droite;
		if (gauche)
			Placer(gauche);
		delete noeud;
		return;
	}

	while (courant)
	{
		if (courant->rightChild == noeud || courant->leftChild == noeud)
			break;

		if (noeud->data >= courant->data)
			courant = courant->rightChild;
		else
			courant = courant->leftChild;
	}

	if (courant != nullptr)
	{
		//courant pointe maintenant vers le noeud précédent le noeud a supprimer
		if (courant->rightChild == noeud)
			courant->rightChild = droite;
		else
			courant->leftChild = droite;
		//on replace l'autre fils du noeud disparu
		if (gauche)
			Placer(gauche);
		//on libère l'objet noeud
		delete noeud;
	}
	
}

//Afficher l'arbre
void Arbre::Afficher(Node* racine)
{
	if (racine->leftChild)
		Afficher(racine->leftChild);
	cout << racine->data << endl;
	if (racine->rightChild)
		Afficher(racine->rightChild);
}