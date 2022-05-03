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
	arbre.Ajouter(17);
	arbre.Ajouter(18);
	arbre.Ajouter(19);

	arbre.Afficher(arbre.getRoot());

	//Supprimer un element
	Node* n = arbre.Rechercher(9);
	cout << "on supprime l'element " << n->data << endl;
	arbre.Supprimer(n);
	
	arbre.Afficher(arbre.getRoot());

	//parcours prefixe
	cout << "Parcours Prefixe :" << endl;
	arbre.ParcoursPrefix(arbre.getRoot());

	//parcours postfixe
	cout << "Parcours Postfixe :" << endl;
	arbre.ParcoursPostfix(arbre.getRoot());

	//Calcul du nombre de Node
	int nb_node = arbre.NbNode(arbre.getRoot());
	cout << "l'arbre compte " << nb_node << " nodes" << endl;

	//Calcul de la profondeur
	int profondeur = arbre.ProfondeurArbre(arbre.getRoot());
	cout << "l'arbre a une profondeur de " << profondeur << endl;

	arbre.Equilibre(arbre.getRoot());

	//parcours prefixe
	cout << "Parcours Prefixe :" << endl;
	arbre.ParcoursPrefix(arbre.getRoot());

	//parcours postfixe
	cout << "Parcours Postfixe :" << endl;
	arbre.ParcoursPostfix(arbre.getRoot());

	return 0;
}