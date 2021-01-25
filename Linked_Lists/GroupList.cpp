//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include "GroupNode.h"
#include "GroupList.h"
using namespace std;

GroupList::GroupList(){
    head = nullptr;
}

GroupList::~GroupList(){
    GroupNode* current;
    while (head != NULL){
        current = head;
        head = current->getNext();
        delete current;
    }
}

GroupNode* GroupList::getHead() const{
    return head;
}

void GroupList::setHead(GroupNode* ptr){
    head = ptr;
}

void GroupList::insert(GroupNode* s){
    if (head == nullptr){ //check if the list is empty
        head = s;
        s->setNext(nullptr);
    } else { //if the list isnt empty
        GroupNode* current = head;   
        while(current->getNext() != nullptr){
            current = current->getNext();
        }
        current->setNext(s);
        s->setNext(nullptr);
    }
}

GroupNode* GroupList::remove(string name){
    GroupNode* current = head;
    GroupNode* previous = NULL;

    if (current == NULL) { // if the list is empty
        return NULL; // "current" is currently NULL
    }
    while (current != NULL) {
        if (current->getName() == name) {
            break;
        }
        previous = current; //what previous is pointing is what current is pointing
        current = current->getNext();
    }
    if (current == NULL) {
        return NULL; // if no node was found
    }
    if (current == head) {
        head = head->getNext();
        return current;
    }
    previous->setNext(current->getNext()); //setting what previous is pointing to the next of current so we can remove current
    current->setNext(NULL);
    return current;
}

void GroupList::print() const{
    GroupNode* current = head; //goes through the list and at each node, call print() from groupNode
    while(current != NULL){
        current->print();
        current = current->getNext();
    }
}