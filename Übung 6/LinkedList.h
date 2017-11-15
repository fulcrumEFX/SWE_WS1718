#pragma once

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
	/*void del(T _t);*/

};

template <typename T>
inline CLinkedList<T>::CLinkedList()
{
	head = NULL;
}

template <typename T>
inline CLinkedList<T>::~CLinkedList()
{
}

template <typename T>
inline void CLinkedList<T>::add(T _t)
{
	node *n = new node;				//neuen Node erstellen
	n->data = _t;					//data von neuem Node mit �bergebenen Daten f�llen
	n->next = head;					//next pointer auf n�chstes Element setzen
	head = n;						//head auf neuen Start der Liste setzen
}

template <typename T>
inline void CLinkedList<T>::print(void)
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
inline T * CLinkedList<T>::search(T _t)
{
	T *ptr;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data = _t)
			return ptr;
	}
	return NULL;
}
//
//template<typename T>
//inline void CLinkedList<T>::del(T _t)
//{
//	CLinkedList<T>.search(_t);
//	node **ptr = &head;			//Pointer to a pointer
//	while (ptr != _t) {
//		if (entry->data == _t)
//			ptr = &(*ptr)->next;
//		}
//	*ptr = _t->next;
//	
//}
//

