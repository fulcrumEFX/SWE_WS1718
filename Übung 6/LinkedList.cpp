#include "stdafx.h"
#include "LinkedList.h"


CLinkedList::CLinkedList()
{
	head = NULL;
}

CLinkedList::~CLinkedList()
{
}

void CLinkedList::addNode(CComponent _component)		
{
	node *n = new node;				//neuen Node erstellen
	n->data = _component;			//data von neuem Node mit übergebenen Daten füllen
	n->next = head;					//next pointer auf nächstes Element setzen
	head = n;						//head auf neuen Start der Liste setzen
}

void CLinkedList::print(void)
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		temp->data.print();
		temp = temp->next;
	}
}