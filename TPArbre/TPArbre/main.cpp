#include <iostream>
#include "stdio.h"
#include "Arbre.h"

using namespace std;


int main(){

	Arbre arbre;

	//Ajouter des éléments
	cout << "On cree de nouveaux noeuds" << endl;
	arbre.Ajouter(10);
	arbre.Ajouter(4);
	arbre.Ajouter(15);
	arbre.Ajouter(2);
	arbre.Ajouter(16);
	arbre.Ajouter(1);
	arbre.Ajouter(9);
	arbre.Ajouter(14);

	arbre.Afficher(arbre.getRoot());

	//Supprimer un element
	Node* n = arbre.Rechercher(9);
	cout << "on supprime l'element " << n->data << endl;
	arbre.Supprimer(n);
	
	arbre.Afficher(arbre.getRoot());

	//Calcul du nombre de Node
	int nb_node = arbre.NbNode(arbre.getRoot());
	cout << "l'arbre compte " << nb_node << " nodes" << endl;

	//Calcul de la profondeur
	int profondeur = arbre.ProfondeurArbre(arbre.getRoot(), arbre);
	cout << "l'arbre a une profondeur de " << profondeur << endl;

	return 0;
}