//============================================================================
// Name        : parsing.cpp
// Author      : Ruben S.
// Version     :
// Copyright   : Your copyright notice
// Description : C++ Project
//============================================================================

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include"Element.h"
#include "Node.h"

#include "Index.h"
using namespace std;

/*
 *
 */
template<class K, class V> void parser1(Index<K,V> *ind, int selection){
    string ligne;
    string delimiter = ";";
    string key;
    string value;
    int cpt = 0;
    
    ifstream fichier("/Users/mac/noteprenom.txt", ios::in); // on ouvre en lecture
    
    if (fichier) // si l'ouverture a fonctionné
    {
        
        while (getline(fichier, ligne)) // tant que l'on peut mettre la ligne dans "contenu"
        {
            
            
            //On supprime les espaces
            ligne.erase( remove( ligne.begin(), ligne.end(), ' ' ), ligne.end() );
            key = ligne.substr(0, ligne.find(delimiter));
            value = ligne.substr(ligne.find(delimiter)+1, ligne.size());
        
            ind->addElement(*(new Element<K, V>(stoi(key), value)));
 
            cpt++;
            
        }
        
        fichier.close();
        
        
        ind->affiche();
                                        //ind->deleteElement(*(new Element<K,V>("6", "Ahmed")));
        //ind->affiche();
        
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}

template<class K, class V> void parser2(Index<K,V> *ind, int selection){
    string ligne;
    string delimiter = ";";
    string key;
    string value;
    int cpt = 0;
    
    ifstream fichier("/Users/mac/noteprenom.txt", ios::in); // on ouvre en lecture
    
    if (fichier) // si l'ouverture a fonctionné
    {
        
        while (getline(fichier, ligne)) // tant que l'on peut mettre la ligne dans "contenu"
        {
            
            //On supprime les espaces
            ligne.erase( remove( ligne.begin(), ligne.end(), ' ' ), ligne.end() );
            key = ligne.substr(0, ligne.find(delimiter));
            value = ligne.substr(ligne.find(delimiter)+1, ligne.size());
 
            ind->addElement(*(new Element<K, V>(key, value)));
                    
            cpt++;
            
        }
        
        fichier.close();
        
        
        ind->affiche();
        //ind->deleteElement(*(new Element<K,V>("6", "Ahmed")));
        //ind->affiche();
        
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}

template<class K, class V> void parser3(Index<K,V> *ind, int selection){
    string ligne;
    string delimiter = ";";
    string key;
    string value;
    int cpt = 0;
    
    ifstream fichier("/Users/mac/noteprenom.txt", ios::in); // on ouvre en lecture
    
    if (fichier) // si l'ouverture a fonctionné
    {
        
        while (getline(fichier, ligne)) // tant que l'on peut mettre la ligne dans "contenu"
        {
            
            
            //On supprime les espaces
            ligne.erase( remove( ligne.begin(), ligne.end(), ' ' ), ligne.end() );
            key = ligne.substr(0, ligne.find(delimiter));
            value = ligne.substr(ligne.find(delimiter)+1, ligne.size());
            
            ind->addElement(*(new Element<K, V>(stoi(key), stoi(value))));
            
            cpt++;
            
        }
        
        fichier.close();
        
        
        ind->affiche();
        //ind->deleteElement(*(new Element<K,V>("6", "Ahmed")));
        //ind->affiche();
        
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}


int main(int argc, char** argv) {
//Element<int, string> *elts[10];


int selection;
string nom_fichier;


cout << "Simulation C++ Index – Nodes - Elements" << endl;
cout << endl;
cout << " 1 ->> Fichier 1: IndexNotePrenom.txt" << endl;
cout << " 2 ->> Fichier 2" << endl;
cout << " 3 ->> Fichier 3" << endl;
cout << endl;
cout << endl;
cout << "Entrer un numéro de fichier à traiter : ";
//while(selection !=1 || selection !=2 || selection !=3)
cin>>selection;
cout << endl;
switch (selection) {
    case 1:
    {
        cout << "Lecture de IndexNotePrenom.txt" << endl;
        nom_fichier = "IndexNotePrenom.txt";
        parser1(new Index<int, string>(), selection);

    }
        break;
    case 2:
    {
        cout << "Lecture fichier 2" << endl;
        nom_fichier = "IndexNotePrenom.txt";
        parser2(new Index<string, string>(), selection);    }
    	break;
    case 3:
    {
        cout << "Lecture fichier 3" << endl;
        nom_fichier = "IndexNotePrenom.txt";
        parser3(new Index<int, int>(), selection);    }
        break;
    default: cout << "selection invalide" << endl;


}
cout << endl;
cout << endl;
cout << endl;


	return 0;
}


