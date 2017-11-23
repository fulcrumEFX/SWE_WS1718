#include "stdafx.h"
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
        (*temp->data).print();
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
	
	//delete ptr;
	*ptr = (*ptr)->next;
}

//CComplex CLinkedList::getComplexImpedance(double _omega)
//{
//	CComplex result;
//	CComplex temp;
//	node *ptr = head;
//	while (ptr->next != NULL) {
//		temp.setReal(ptr->data->getReal());
//		temp.setImag(ptr->data->getImag(_omega));
//		result = result + temp;
//		ptr = ptr->next;
//	}
//	return result;
//}
