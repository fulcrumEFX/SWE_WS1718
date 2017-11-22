#include "LinkedList.h"

CLinkedList::CLinkedList(){
    head = NULL;
}
CLinkedList::~CLinkedList(){
    node * current = head;
	while (current != NULL) {
		node * next = current->next;
		delete current;
		current = next;
	}
	head = NULL;
}
void CLinkedList::add(CComponent * _cp){
    node *n = new node;
    n->data= _cp;
    n->next = *_cp;
    head = n;
}

void CLinkedList::print(void){
    node *temp = new node;
    temp = head;
    while (temp!=NULL)
    {
        temp->data.print();
        temp = temp->next;
    }
}
node * find(CComponent * _cp){
    node *ptr = NULL;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data.getName() == *_cp.getName()){
			return ptr;
		}
	}
	return NULL;
}