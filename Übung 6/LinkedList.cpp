#include "stdafx.h"
#include "LinkedList.h"

//Linked List Member functions
CLinkedList::CLinkedList(){
    head = NULL;
}
CLinkedList::~CLinkedList(){
    node * current = head;
	node * nextPtr;
	while (current != NULL) {
		nextPtr = current->next;
		delete current;
		current = nextPtr;
	}
	head = NULL;
}
node * CLinkedList::getHead(void)
{
	return head;
}
void CLinkedList::add(CComponent * _cp){
	node *n = new node;
    n->data= _cp;
    n->next = head;
    head = n;
}
void CLinkedList::print(void){
    node *temp = new node;
    temp = head;
    while (temp!=NULL)
    {
        temp->data->print();
        temp = temp->next;
    }
	delete temp;
}
node * CLinkedList::find(CComponent * _cp){
    node *ptr = NULL;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data->getName() == _cp->getName()){
			return ptr;
		}
	}
	return NULL;
}
void CLinkedList::del(CComponent * _cp) {
	node **ptr = &head;
	while ((*ptr)->data != _cp) {
		ptr = &(*ptr)->next; 
	}
	*ptr = (*ptr)->next;
}

//Template Search function implementation including specific compare functions
template <typename T>
CComponent * search(bool (* fPtr)(CComponent *, T), T t2){
	CComponent * ptr;
	for (ptr = head; ptr != NULL; ptr = ptr->next){
		if (fPtr(ptr, t2)) return ptr;
	}
	return NULL;
}
bool nameSearch(CComponent * _comp1, string _name){
	return (_comp1->getName() == _name);
}
bool priceSearch(CComponent * _comp1, double _price){
	return (_comp1->getPrice() == _price);
}
bool positionSearch(CComponent * _comp1, CPoint _pos){
	return ((_comp1->getPosition.getX() == _pos.getX()) && (_comp1->getPosition.getY() == _pos.getY()));
}
