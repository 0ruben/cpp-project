/*
 * File:   Element.h
 * Author: Ruben S
 *
 * Created on 27 mars 2015, 20:19
 */

#ifndef ELEMENT_H
#define	ELEMENT_H
#include <iostream>
using namespace std;

template <class K, class V>class Element {
    K key;
    V value;
public:

    Element() {
    }

   /* ~Element() {
        delete this;
    }*/

    Element<K, V>& operator=(const Element<K, V>& autre) {
        this->key = new K(autre.key);
        this->value = new V(autre.value);

        return *this;
    }

    Element(K _key, V _value) {
        key = _key;
        value = _value;
    }
    
    

    Element(Element<K,V> &element){
    	*this = element;
    }

    void affiche();

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }

};

template <class K, class V> void Element<K, V>::affiche() {
    cout << "clé: " << getKey() << ", " << "valeur: " << getValue() << endl;
}
#endif	/* ELEMENT_H */
