#include <iostream>
#include "stdio.h"
#include "Arbre.h"

using namespace std;


int main(){

	Arbre arbre;

	arbre.Ajouter(10);
	arbre.Ajouter(4);
	arbre.Ajouter(15);
	arbre.Ajouter(2);
	arbre.Ajouter(16);
	arbre.Ajouter(1);
	arbre.Ajouter(9);
	arbre.Ajouter(14);

	arbre.Afficher(arbre.getRoot());

	cout << "on supprime un element" << endl;
	Node* n = arbre.Rechercher(4);
	arbre.Supprimer(n);


	arbre.Afficher(arbre.getRoot());

	return 0;
}