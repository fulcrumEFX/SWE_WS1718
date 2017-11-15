#pragma once

template <typename T>
class node {
public:
	node *next;
	T data;
};

template <typename T>
class CLinkedList
{
private:
	node<T> *head;
public:
	CLinkedList();
	~CLinkedList();
	void add(T _t);
	void print(void);
	node<T>* CLinkedList<T>::find(T _t);
	void CLinkedList<T>::del(T _t);
};

template <typename T>
inline CLinkedList<T>::CLinkedList()
{
	head = NULL;
}

template <typename T>
inline CLinkedList<T>::~CLinkedList()
{
	node<T> * current = head;
	while (current != NULL) {
		node<T> * next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

template <typename T>
inline void CLinkedList<T>::add(T _t)
{
	node<T> *n = new node<T>;
	n->data = _t;			
	n->next = head;	
	head = n;						
}

template <typename T>
inline void CLinkedList<T>::print(void)
{
	node<T> *temp = new node<T>;
	temp = head;
	while (temp != NULL)
	{
		temp->data.print();
		temp = temp->next;
	}
}

template <typename T>
inline node<T>* CLinkedList<T>::find(T _t)
{
	node<T> *ptr = NULL;
	for (ptr = head; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->data.getName() == _t.getName()){
			return ptr;
		}
	}
	return NULL;
}
template<typename T>
inline void CLinkedList<T>::del(T _t)
{
	node<T> *delPtr = find(_t);
	node<T> **ptr = &head;
	while ((*ptr)->next != delPtr) {
		ptr = &(*ptr)->next;
	}
	(*ptr)->next = delPtr->next;

}




//template <typename T>
//inline bool CLinkedList<T>::operator==(const CLinkedList<T> &rhs) const
//{
//	node<T> *lhsTemp = head;
//	node<T> *rhsTemp = rhs.head;
//	while (lhsTemp != NULL || rhsTemp != NULL)
//	{
//		if (lhsTemp != NULL && rhsTemp == NULL || lhsTemp == NULL && rhsTemp != NULL)
//			return false;
//		else if (lhsTemp->data != rhsTemp->data)
//			return false;
//		lhsTemp = lhsTemp->next;
//		rhsTemp = rhsTemp->next;
//	}
//	return true;
//}




