#pragma once
#include "Component.h"

class node {
public:
	node * next;
	CComponent * data;
};

class CLinkedList{
protected:
	node *head = NULL;
public:
	CLinkedList();
    ~CLinkedList();
	node * getHead(void);
    void add(CComponent * _cp);
    void print(void);
    node * find(CComponent * _cp);
    void del(CComponent * _cp);
	/*CComplex getComplexImpedance(double _omega);*/
};