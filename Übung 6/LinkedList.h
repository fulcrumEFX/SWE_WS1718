#pragma once
#include "Component.h"

template <typename T>
class CLinkedList
{
private:
	struct node {
		node *next;
		T data;
	};
	node *head;
public:
	CLinkedList();
	~CLinkedList();
	void add(T _t);
	void print(void);
	T * search(T _t);
};

template <typename T>
CLinkedList<T>::CLinkedList()
{
	head = NULL;
}
template <typename T>
CLinkedList<T>::~CLinkedList()
{
}
template <typename T>
void CLinkedList<T>::add(T _t)
{
	node *n = new node;				//neuen Node erstellen
	n->data = _t;					//data von neuem Node mit �bergebenen Daten f�llen
	n->next = head;					//next pointer auf n�chstes Element setzen
	head = n;						//head auf neuen Start der Liste setzen
}
template <typename T>
void CLinkedList<T>::print(void)
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		temp->data.print();
		temp = temp->next;
	}
}
template <typename T>
T * CLinkedList<T>::search(T _t)
{
	CComponent *ptr;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{

	}
}

