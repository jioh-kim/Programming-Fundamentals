//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
#define NUM_KEYWORDS 6
#define NUM_TYPES 3

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool invalidName(string name) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (name == keyWordsList[i]) {
            return true;
        }
    }
    for (int i = 0; i < NUM_TYPES; i++) {
        if (name == shapeTypesList[i]) {
            return true;
        }
    }
    return false;
}

int nameExists(string name) {
    int value = 0;
    GroupNode* gCurrent = gList->getHead(); //group current
    ShapeNode* sCurrent = gCurrent->getShapeList()->getHead(); //shape current
    while (gCurrent != NULL) {
        sCurrent = gCurrent->getShapeList()->getHead();
        while (sCurrent != NULL) {
            if (sCurrent->getShape()->getName() == name) {
                return value = 1; //if shape is found
            }
            sCurrent = sCurrent->getNext();
        }
        gCurrent = gCurrent->getNext();
    }

    gCurrent = gList->getHead();
    while (gCurrent != NULL) {
        if (gCurrent->getName() == name) {
            return value = 2; // if group name is found
        }
        gCurrent = gCurrent->getNext();
    }
    return value = 0; // returns 0 if nothings found
}

int main() {
    // Create the groups list
    gList = new GroupList();

    // Create the pool group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS - 1]);
    gList->insert(poolGroup);
    // // create a pool shapelist and attach it to pool group
    // ShapeList* poolShapeList = new ShapeList();
    // poolGroup->setShapeList(poolShapeList);

    string line;
    string command;

    cout << "> "; // Prompt for input
    getline(cin, line); // Get a line from standard input

    while (!cin.eof()) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream(line);

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here

        if (command == keyWordsList[0]) { //shape
            string shapeName, shapeType;
            int xLocation, yLocation, xSize, ySize;

            lineStream >> shapeName;

            if (invalidName(shapeName)) {
                cout << "error: invalid name" << endl;
            } else if (nameExists(shapeName) != 0) {
                cout << "error: name " << shapeName << " exists" << endl;
            } else {
                lineStream >> shapeType >> xLocation >> yLocation >> xSize >> ySize;

                //                ShapeList* pList = new ShapeList();
                //                poolGroup->setShapeList(pList);
                //                ShapeNode* pNode = new ShapeNode();
                //                Shape* tempShape = new Shape(shapeName, shapeType, xLocation, xSize, yLocation, ySize);
                //                pNode->setShape(tempShape);
                //                pList->insert(pNode);

                Shape* myshape = new Shape(shapeName, shapeType, xLocation, xSize, yLocation, ySize);

                ShapeNode* shapenode = new ShapeNode();
                shapenode->setShape(myshape);
                shapenode->setNext(NULL);
                poolGroup->getShapeList()->insert(shapenode); //now shapenode is inserted to shapelist

                cout << shapeName << ": " << shapeType << " " << xLocation << " " << yLocation << " " << xSize << " " << ySize << endl;
                //                // to test
                //                cout << "testing" << endl;
                //                poolGroup->getShapeList()->getHead()->getShape()->draw();
            }


        } else if (command == keyWordsList[1]) { //group
            string groupName;
            lineStream >> groupName;

            if (invalidName(groupName)) {
                cout << "error: invalid name" << endl;
            } else if (nameExists(groupName) == 2) {
                cout << "error: name " << groupName << " exists" << endl;
            } else {
                cout << groupName << ": group" << endl;
                // new groupnode is created with the name of user input "groupName"
                GroupNode* groupnode = new GroupNode(groupName);
                gList->insert(groupnode);
            }


        } else if (command == keyWordsList[2]) { //move
            string shape, group;
            lineStream >> shape >> group;

            if (invalidName(shape) || invalidName(group)) {
                cout << "error: invalid name" << endl;
            } else if (nameExists(shape) != 1) {
                cout << "error: shape " << shape << " not found" << endl;
            } else if (nameExists(group) != 2) {
                cout << "error: name " << group << " not found" << endl;
            } else {
                GroupNode* gTemp = gList->getHead();
                ShapeNode* sTemp = gTemp->getShapeList()->getHead();
                ShapeNode* hold = NULL;
                // setting sTemp to the shape thats gonna be moved  
                while (gTemp != NULL) {
                    sTemp = gTemp->getShapeList()->getHead();
                    hold = gTemp->getShapeList()->find(shape);
                    if (hold != NULL) {
                        gTemp->getShapeList()->remove(shape);
                        break;
                    }
                    gTemp = gTemp->getNext();
                }

                // move the shape into the new group
                gTemp = gList->getHead();
                while (gTemp != NULL) {
                    if (gTemp->getName() == group) {
                        hold->setNext(NULL);
                        gTemp->getShapeList()->insert(hold);
                    }
                    gTemp = gTemp->getNext();
                }

                cout << "moved " << shape << " to " << group << endl;
            }

        } else if (command == keyWordsList[3]) { //delete
            string name;
            lineStream >> name;
            if (invalidName(name)) {
                cout << "error: invalid name" << endl;
            } else if (nameExists(name) == 0) {
                cout << "error: shape " << name << " not found" << endl;
            } else {
                GroupNode* group = gList->getHead();
                ShapeNode* shape = group->getShapeList()->getHead();
                GroupNode* gtemp = gList->getHead();
                ShapeNode* stemp;
                int counter = 0;
                while(gtemp != NULL){
                    stemp = gtemp->getShapeList()->find(name);
                    if(stemp != NULL){
                        counter = 1;
                        break;
                    } gtemp=gtemp->getNext();
                }

                while (group != NULL) {
                    if (group->getName() == name) {
                        counter = 2;
                    }
                    group = group->getNext();
                }

                //deleting a shape
                if (counter == 1) {
                    delete gtemp->getShapeList()->remove(name);
                    cout << name << ": deleted "<< endl;
                }
                // deleting a group
                if (counter == 2) {
                    GroupNode* gtemp = gList->getHead();
                    ShapeNode* stemp = NULL;
                    while (gtemp != NULL) {
                        if (gtemp->getName() == name) {
                            stemp = gtemp->getShapeList()->getHead();
                            poolGroup->getShapeList()->insert(stemp); // put it back to pool
                            gtemp->getShapeList()->setHead(NULL);
                            break;
                        }
                        gtemp = gtemp->getNext();
                    }
                    
                    delete gList->remove(name);
                    cout << name << ": deleted"<< endl;
                }
            }


        } else if (command == keyWordsList[4]) { //draw
            cout << "drawing:" << endl;
            gList->print();
        }


        // Once the command has been processed, prompt for the
        // next command
        cout << "> "; // Prompt for input
        getline(cin, line);

    } // End input loop until EOF.

    return 0;
}

