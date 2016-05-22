

#ifndef INDEX_H
#define	INDEX_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "Node.h"
#include "Element.h"

using namespace std;

template <class K, class V>class Index{
    int nbElements;
    Node<K,V> * nodes[];
public:
    Index();
    ~Index();
    Node<K, V>* getNode(K key);
    void addNode(K key);
    void deleteNode(K key);
    void addElement(Element<K, V> &element);
    void deleteElement(Element<K, V> &element);
    Node<K, V> & operator[](int i);
    void erase();
    void affiche();
    int algoInsert(int debut, int fin, K val);


};

// Constructeur par défaut

template <class K, class V> Index<K, V>::Index() {
    nbElements = 0;
    *nodes = new Node<K, V>[nbElements];

}

//Destructeur de la classe Index

template <class K, class V> Index<K, V>::~Index() {
    //erase();
    delete this;
}

template<class K, class V> void Index<K, V>::erase() {
    for (int i = 0; i < nbElements; i++)
        delete nodes[i];
    //delete []nodes;
}

// Retourne le noeud de clé=key

template <class K, class V> Node<K, V>* Index<K, V>::getNode(K key) {
	for (int i = 0; i < nbElements; i++){
		if (this->nodes[i]->getKey()==key){
			return nodes[i];
		}
	}
    return (new Node<K,V>());
}

template <class K, class V> int Index <K,V>::algoInsert (int debut, int fin, K val){
	int milieu;

  if (debut == fin)
    return debut;
  else
  {
    milieu=(debut+fin)/2; // division sur entiers
    if (nodes[milieu]->getKey() > val)
       return (algoInsert(debut,milieu,val));
    else
       return (algoInsert(milieu+1,fin,val));
  }
}


// Ajout du noeud dans l'indexe

template <class K, class V> void Index<K, V>::addNode(K key) {
	int position = this->algoInsert(0, nbElements,key);
	//cout << "POS " << position << endl;
	nbElements++;
	int saut = 0;
    Node<K, V> *temp[nbElements];

    for (int i = 0; i < nbElements; i++){
    	if(i==position){
    		temp[i]= new Node<K,V> (key);
    		saut = 1;
    	}
    	else
    		temp[i] = nodes[i-saut];

    }
   // delete [] *nodes;
    *nodes = new Node<K, V>[nbElements];

    for (int j = 0; j < nbElements; j++){

        nodes[j] = temp[j];

    }
}

// Suppression du noeud de l'index

template <class K, class V> void Index<K, V>::deleteNode(K key) {

    int saut = 0;
    int indexSuppr = -1;
    Node<K, V> *temp[nbElements];
    
    for (int i = 0; i < nbElements; i++)
    {
        temp[i] = nodes[i];
        //On teste si le node à supprimer existe
        if (nodes[i]->getKey()==key){
            cout<<"Suppression du node de clé "<< key << endl;
            indexSuppr = i;
            nbElements--;
        }
        
    }
    // Si
    if(indexSuppr == -1)
        cout<<"Node inconnu "<<endl;
    else
    {
        
        *nodes = new Node<K, V>[nbElements];
        
        for (int j = 0; j < nbElements; j++){
            if(j==indexSuppr){
                saut=1;
            }
            nodes[j] = temp[j+saut];
            
        }
    }



}

// Ajout de l'élément dans l'index

template <class K, class V> void Index<K, V>::addElement(Element<K, V> &element) {
int index = -1;

    // recherche de l'élément à ajouter
    for(int i = 0; i < nbElements; i++){

    	if(element.getKey() == nodes[i]->getKey()){

    		index = i;
    	}
    }
    //Element trouvé, on l'ajoute dans le noeud
    if (index!=-1) {
    	nodes[index]->addElement(element);

    }//Element non trouvé, on crée le noeud puis on l'ajoute
    else {
        this->addNode(element.getKey());
        this->getNode(element.getKey())->addElement(element);
    }

}

//Suppression de l'élément dans l'index

template <class K, class V> void Index<K, V>::deleteElement(Element<K, V> &element) {

    this->getNode(element.getKey())->deleteElement(element);
    if(this->getNode(element.getKey())->getNbElements()==0)
    {
        this->deleteNode(element.getKey());
    }
   
}

template<class K, class V> Node<K, V> & Index<K, V>::operator[](int i) {
    return nodes[i];
}

//Affichage du contenu de l'index

template <class K, class V> void Index<K, V>::affiche() {
    cout << "l'index contient" << " " << nbElements << " noeud(s)" << endl;
    cout << "              " << endl;
    for (int i = 0; i < nbElements; i++) {
        cout << "--------------"<<endl;
        cout << " Le noeud" << " " << i << " " << "contient " << nodes[i]->getNbElements() << " élément(s)" << endl;
        nodes[i]->affiche();
    }
    cout << "------------------------------" << endl;
}

#endif	/* INDEX_H */
