#pragma once
#include "Component.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"

class node {
public:
	node * next;
	CComponent * data;
};

class CLinkedList{
protected:
	node *head = NULL;
public:
	CLinkedList();
    ~CLinkedList();
	node * getHead(void);
    void add(CComponent * _cp);
    void print(void);
    node * find(string _name);
    void del(CComponent * _cp);
	/*CComplex getComplexImpedance(double _omega);*/

	template <typename T>
	node * search(bool (* fPtr)(node *, T), T t2){
		node * searchPtr;
		for (searchPtr = head; searchPtr != NULL; searchPtr = searchPtr->next){
			if (fPtr(searchPtr, t2)) return searchPtr;
		}
		return NULL;
	}
};
inline bool nameSearch(node * _node1, string _name){
	return (_node1->data->getName() == _name);
}
inline bool priceSearch(node * _node1, double _price){
	return (_node1->data->getPrice() == _price);
}
inline bool positionSearch(node * _node1, CPointy _pos){
	return ((_node1->data->getPosition().getX() == _pos.getX()) && (_node1->data->getPosition().getY() == _pos.getY()));
}