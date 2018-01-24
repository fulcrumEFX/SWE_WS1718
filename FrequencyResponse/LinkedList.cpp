#include "stdafx.h"
#include "LinkedList.h"

//Linked List Member functions
CLinkedList::CLinkedList(){
    head = NULL;
}
CLinkedList::~CLinkedList(){
    node* current = head;
	node* nextPtr;
	while (current != NULL) {
		nextPtr = current->next;
		delete current;
		current = nextPtr;
	}
	head = NULL;
}
node* CLinkedList::getHead(void)
{
	return head;
}
void CLinkedList::add(CComponent* _cp){
	node*n = new node;
    n->data= _cp;
    n->next = head;
    head = n;
}
node* CLinkedList::find(std::string _name){
    node* ptr = NULL;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data->getName() == _name){
			return ptr;
		}
	}
	return NULL;
}
void CLinkedList::del(CComponent* _cp) {
	node** ptr = &head;
	while ((*ptr)->data != _cp) {
		ptr = &(*ptr)->next; 
	}
	*ptr = (*ptr)->next;
}

CComplex CLinkedList::getComplexImpedance(double _omega, node* _head)
{
	double omega = _omega;
	node* head = _head;
	return wiringPtr->getComplexImpedance(omega, head);
}

void CLinkedList::setWiringPtr(CComplexImpedance * _wiring)
{
	wiringPtr = _wiring;
}

CComplexImpedance * CLinkedList::getWiringPtr(void)
{
	return wiringPtr;
}

//Template Search function implementation including specific compare functions
