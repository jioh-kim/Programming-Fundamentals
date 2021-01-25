//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

#include "Shape.h"
#include "ShapeNode.h"
#include "ShapeList.h"
#include <iostream>
using namespace std;

ShapeList::ShapeList() {
    head = nullptr;
}

ShapeList::~ShapeList() {
    ShapeNode* current;
    while (head != NULL) {
        current = head;
        head = current->getNext();
        delete current;
    }
}

ShapeNode* ShapeList::getHead() const {
    return head;
}

void ShapeList::setHead(ShapeNode* ptr) {
    head = ptr;
}

ShapeNode* ShapeList::find(string name) const {
    ShapeNode* current = head;
    while (current != NULL) {
        if (current->getShape()->getName() == name) {
            return current;
        } current = current->getNext();
    }
    if (head == NULL){
        return NULL;
    } else {
        return current;
    }
}

// inserts the node pointed to by s at the end of the list
// s should never be nullptr

void ShapeList::insert(ShapeNode* s) {
    if (head == nullptr) { //check if the list is empty
        head = s;
        //s->setNext(nullptr);
    } else { //if the list isnt empty
        ShapeNode* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(s);
        //s->setNext(nullptr);
    }
}
// removes the node with the shape called name 
// returns a pointer to the removed node or
// nullptr is a node with name does not exist

ShapeNode* ShapeList::remove(string name) {
    ShapeNode* current = head;
    ShapeNode* previous = NULL;

    if (current == NULL) { // if the list is empty
        return NULL; // "current" is currently NULL
    }
    while (current != NULL) {
        if (current->getShape()->getName() == name) {
            break;
        }
        previous = current; //what previous is pointing is what current is pointing
        current = current->getNext();
    }
    if (current == NULL) {
        return NULL; // if no node was found
    }
    if (previous == NULL) {
        head = current->getNext();
        return current;
    }
    previous->setNext(current->getNext()); //setting what previous is pointing to the next of current so we can remove current
    //current->setNext(NULL);
    return current;
}



// prints the list

void ShapeList::print() const {
    ShapeNode* current = head; //goes through the list and at each node, call print() from shapeNode
    while (current != NULL) {
        current->print();
        current = current->getNext();
    }
}


