/*
 * File:   Node.h
 * Author: Ruben S
 *
 * Created on 27 mars 2015, 20:19
 */

#ifndef NODE_H
#define	NODE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include"Element.h"

using namespace std;

// Noeud contenant n éléments de type <K,V > avec la clé est de type K

template <class K, class V> class Node {
    K key;
    int nbElements;
    Element<K, V> * elements[];

public:

    Node(){

    	nbElements = 0;
    }

    Node(K _key) {
        key = _key;
        nbElements = 0;
        *elements = NULL;



    }

    ~Node() {
        //delete [] *elements;
        //delete this;
    }

    Element<K, V> & operator[](int i) {
        return elements[i];
    }

    Element<K, V> * getElement(V value) {
        for (int i = 0; i < nbElements; i++) {
            if (elements[i].getValue() == value){
            	return elements[i];
        }
        }

        return NULL;
        //else
        // return NULL;
    }

    int getNbElements() {
        return nbElements;
    }

    void addElement(Element<K, V> &element);
    void deleteElement(Element<K, V> &element);
    int algoInsert(int debut, int fin, V val);
    void affiche();

    K getKey() {
            return key;
        }
    Node<K, V>& operator=(const Node<K, V>& autre) {
        this->key = autre.key;
        this->nbElements = autre.nbElements;
        for(int i = 0; i< nbElements; i++)
        	this->elements[i]=autre.elements[i];
        return *this;
    }

};


template <class K, class V> int Node <K,V>::algoInsert (int debut, int fin, V val){
	int milieu;

  if (debut == fin)
    return debut;
  else
  {
    milieu=(debut+fin)/2; // division sur entiers
    if (elements[milieu]->getValue() > val)
       return (algoInsert(debut,milieu,val));
    else
       return (algoInsert(milieu+1,fin,val));
  }
}

//template <class T, class U> void Element<T, U>::affiche()

template <class K, class V> void Node<K, V>::deleteElement(Element<K, V> &element) {
	int saut = 0;
int indexSuppr = -1;
Element<K, V> *temp[nbElements];

    for (int i = 0; i < nbElements; i++)
    {
    	temp[i] = elements[i];
    	//On teste si l'élement à supprimer existe
       if (elements[i]->getKey()==element.getKey() && elements[i]->getValue()==element.getValue()){
    	   cout<<"Suppression de l'élément "<< element.getValue() << endl;
        	indexSuppr = i;
            nbElements--;
       }

    }
    // Si
    if(indexSuppr == -1)
    	cout<<"Element inconnu "<<endl;
    else
    {

    *elements = new Element<K, V>[nbElements];

    for (int j = 0; j < nbElements; j++){
    	if(j==indexSuppr){
    		saut=1;
    	}
        elements[j] = temp[j+saut];

    	}
    }


}

template <class K, class V> void Node<K, V>::addElement(Element<K, V> &element) {

	int position = this->algoInsert(0, nbElements,element.getValue());

	nbElements++;
	int saut = 0;
    Element<K, V> *temp[nbElements];

    for (int i = 0; i < nbElements; i++){
    	if(i==position){
    		temp[i]=&element;
    		saut = 1;
    	}
    	else
    		temp[i] = elements[i-saut];

    }

    *elements = new Element<K, V>[nbElements];

    for (int j = 0; j < nbElements; j++){
        elements[j] = temp[j];
        //cout << j << endl;
        //elements[j]->affiche();
    }



}


template <class K, class V> void Node<K,V>::affiche() {


	for( int i = 0 ; i<nbElements ; i++)
    cout << "clé: " << elements[i]->getKey() << ", " << "valeur: " << elements[i]->getValue() << endl;
}


#endif	/* NODE_H */

