#pragma once
#include "Component.h"

class node {
public:
    node * next;
    CComponent * data;
};

class CLinkedList{
    private:
        node *head;
    public:
        CLinkedList();
        ~CLinkedList();
        void add(CComponent _cp);
        void print(void);
        node * find(CComponent _cp);
        void del(CComponent _cp);
        
};