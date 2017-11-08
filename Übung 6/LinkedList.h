#pragma once
#include "Component.h"

class CLinkedList
{
private:
	struct node {
		node *next;
		CComponent data;
	};
	node *head;
public:
	CLinkedList();
	~CLinkedList();
	void addNode(CComponent _component);
	void print(void);
};

