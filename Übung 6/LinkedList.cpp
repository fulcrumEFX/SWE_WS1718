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
node * CLinkedList::find(string _name){
    node *ptr = NULL;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data->getName() == _name){
			return ptr;
		}
	}
	return NULL;
}
void CLinkedList::del(node * _cp) {
	node **ptr = &head;
	node *tmp = NULL;
	while ((*ptr) != _cp) {
		ptr = &(*ptr)->next; 
	}
	tmp = *ptr;
	*ptr = (*ptr)->next;
	delete tmp;
}
