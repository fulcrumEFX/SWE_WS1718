#pragma once
#include "Component.h"
#include "Resistor.h"
#include "Capacitor.h"
#include "Inductor.h"
#include "node.h"
#include "ComplexImpedance.h"



class CLinkedList : public node{
protected:
	node* head = NULL;
	CComplexImpedance* wiringPtr = NULL;
public:
	CLinkedList();
    ~CLinkedList();
	node* getHead(void);
	void setWiringPtr(CComplexImpedance* _wiring);
	CComplex getComplexImpedance(double _omega, node* _head);
	CComplexImpedance* getWiringPtr(void);

	void add(CComponent * _cp);
	node* find(std::string _name);
	void del(CComponent * _cp);

	template <typename T>
	node* search(bool (* fPtr)(node*, T), T t2){
		node* searchPtr;
		for (searchPtr = head; searchPtr != NULL; searchPtr = searchPtr->next){
			if (fPtr(searchPtr, t2)) return searchPtr;
		}
		return NULL;
	}
};
inline bool nameSearch(node* _node1, std::string _name){
	return (_node1->data->getName() == _name);
}
inline bool priceSearch(node* _node1, double _price){
	return (_node1->data->getPrice() == _price);
}
inline bool positionSearch(node* _node1, CPointy _pos){
	return ((_node1->data->getPosition().getX() == _pos.getX()) && (_node1->data->getPosition().getY() == _pos.getY()));
}