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

void Arbre::setRoot(Node* racine)
{
	this->root = racine;
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
		traitement(noeud);

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
		traitement(noeud);
	}
}

//Calcul du nombre de node de l'arbre
int Arbre::NbNode(Node* racine)
{
	if (racine == nullptr)
		return 0;
	else
		return 1 + NbNode(racine->leftChild) + NbNode(racine->rightChild);
}

int Arbre::ProfondeurArbre(Node* racine)
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
		profDroite = ProfondeurArbre(racine->rightChild);
		//calcul de la profondeur du sous arbre gauche
		profGauche = ProfondeurArbre(racine->leftChild);

		profondeur = 1 + (profGauche > profDroite ? profGauche : profDroite);
	}
	return profondeur;
}

//Traitement de la donnée
void Arbre::traitement(Node* noeud)
{
	cout << noeud->data << endl;
}

//Calcul du nombre de node dans le sous arbre gauche
int Arbre::NbNodeGauche(Node* racine)
{
	if (racine == nullptr)
		return 0;
	else
		return 1 + NbNodeGauche(racine->leftChild);
}

//Calcul du nombre de node dans le sous arbre droit
int Arbre::NbNodeDroite(Node* racine)
{
	if (racine == nullptr)
		return 0;
	else
		return 1 + NbNodeDroite(racine->rightChild);
}

//vérifie l'equilibrage de l'arbre
void Arbre::Equilibre(Node* racine)
{
	bool isEquilibre = false;
	while (isEquilibre == false)
	{
		int nDroite = NbNodeDroite(racine);
		int nGauche = NbNodeGauche(racine);
		cout << "verification de l'equilibrage de l'arbre" << endl;
		cout << "Gauche : " << nGauche << " noeuds, droite : " << nDroite << " noeuds" <<endl;
		int equi = nDroite - nGauche;
		//cout << equi << endl;
	
		if (equi >= -1 && equi <= 1)
		{
			cout << "l'arbre est equilibre" << endl;
			isEquilibre = true;
		}
		else
		{
			if (equi < -1)
				rotateDroite(racine);
		
			if (equi > 1)
				rotateGauche(racine);
		}
	}
}

//Rotation à droite
void Arbre::rotateDroite(Node* noeud)
{
	if (noeud != nullptr)
	{
		Node* Y = noeud;
		Node* X = noeud->leftChild;
		Node* B = nullptr;
		if (X != nullptr)
		{
			B = X->rightChild;
			setRoot(X);
			X->rightChild = Y;
		}
		Y->leftChild = B;
	}
}

//Rotation à gauche
void Arbre::rotateGauche(Node* noeud)
{
	if (noeud != nullptr)
	{
		Node* Y = noeud;
		Node* X = noeud->rightChild;
		Node* B = nullptr;
		if (X != nullptr)
		{
			B = X->leftChild;
			setRoot(X);
			X->leftChild = Y;
		}
		Y->rightChild = B;
	}
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