#include <iostream>
#include "stdio.h"
#include "Arbre.h"

using namespace std;
Arbre::Arbre()
{
	root = nullptr;
	taille = 0;
}

Arbre::~Arbre()
{
}

Node* Arbre::getRoot()
{
	return root;
}

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
		if (noeud->data < noeud->data)
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

void Arbre::Ajouter(int value)
{
	//création du noeud en mémoire
	Node* nouveau = new Node;
	nouveau->data = value;
	nouveau->leftChild = nullptr;
	nouveau->rightChild = nullptr;

	Placer(nouveau);
}

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

	//courant pointe maintenant vers noeud précédent le noeud a supprimer
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

void Arbre::Afficher(Node* racine)
{
	if (racine->leftChild)
		Afficher(racine->leftChild);
	cout << racine->data << endl;
	if (racine->rightChild)
		Afficher(racine->rightChild);
}