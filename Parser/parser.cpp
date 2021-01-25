//
//  parser.cpp
//  lab3
//
//  Modified by Tarek Abdelrahman on 2020-10-04.
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018-2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>
#include <valarray>
#include <stdbool.h>
#include <stdlib.h> 

using namespace std;

#include "globals.h"
#include "Shape.h"

// This is the shape array, to be dynamically allocated
Shape** shapesArray;

// The number of shapes in the database, to be incremented 
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

void invalidCommand() {
    cout << "Error: invalid command" << endl;
}

void invalidArgument() {
    cout << "Error: invalid argument" << endl;
}

void invalidShapeName() {
    cout << "Error: invalid shape name" << endl;
}

void shapeNameExists(string name) {
    cout << "Error: shape " << name << " exists" << endl;
}

void shapeNameNotFound(string name) {
    cout << "Error: shape " << name << " not found" << endl;
}

void invalidShapeType() {
    cout << "Error: invalid shape type" << endl;
}

void invalidValue() {
    cout << "Error: invalid value" << endl;
}

void tooManyArgs() {
    cout << "Error: too many arguments" << endl;
}

void tooFewArgs() {
    cout << "Error: too few arguments" << endl;
}

void shapeArrayFull() {
    cout << "Error: shape array is full" << endl;
}

int main() {

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
        // (The first word use inputs is command bc that is the first string)

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here

        //maxShapes
        if (command == keyWordsList[1]) {

            if (lineStream.eof()) {
                tooFewArgs();
                goto jump;
            }

            lineStream >> max_shapes;
            
            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            } else if (lineStream.eof() != true){
                tooManyArgs();
                goto jump;
            } else {
                for (int j = 0; j < shapeCount; j++) {
                    delete shapesArray[j];
                    shapesArray[j] = nullptr;
                }
                    delete [] shapesArray;
                    shapesArray = nullptr;
                    shapeCount = 0;

                    shapesArray = new Shape* [max_shapes];
                    for (int i = 0; i < max_shapes; i++) {
                        shapesArray[i] = nullptr;
                    }
                cout << "New database: max shapes is " << max_shapes << endl;
            }
            
 


            //create
        } else if (command == keyWordsList[2]) {
            string shapeName, shapeType;
            int xLocation, yLocation, xSize, ySize;

            if (lineStream.eof()) {
                tooFewArgs();
            }

            // take in name of the shape
            lineStream >> shapeName;
            if (lineStream.fail()) {
                invalidArgument;
                goto jump;
            } else {
                int counter = 0;
                for (int i = 0; i < 7; i++) {
                    if (shapeName == keyWordsList[i]) {
                        invalidShapeName();
                        goto jump;
                        counter++;
                    }
                }
                for (int i = 0; i < 4; i++) {
                    if (shapeName == shapeTypesList[i]) {
                        invalidShapeName();
                        goto jump;
                        counter++;
                    }
                }
                if (counter == 0) {
                    for (int i = 0; i < shapeCount; i++) {
                        if ((shapesArray[i] != NULL) && (shapeName == shapesArray[i]->getName())) {
                            shapeNameExists(shapeName);
                            goto jump;
                        }
                    }
                }
            }
            
            if (lineStream.eof()) {
                tooFewArgs();
                goto jump;
            }


            // take in the shape type
            lineStream >> shapeType;
            bool invalidShapeTypeBool = true;

            if (lineStream.fail()) {
                invalidArgument;
                goto jump;
            } else {
                for (int i = 0; i < 4; i++) {
                    if (shapeType == shapeTypesList[i]) {
                        invalidShapeTypeBool = false;
                    }
                }
                if (invalidShapeTypeBool == true) {
                    invalidShapeType();
                    goto jump;
                }
            } 
            
            if(lineStream.eof()) {
                tooFewArgs();
                goto jump;
            }
            

            lineStream >> xLocation;
            if (lineStream.fail() && !lineStream.eof()){
                invalidArgument();
                goto jump;
            } else if (lineStream.eof()){
                tooFewArgs();
                goto jump;
            } else {
                if (xLocation < 0){
                    invalidValue();
                    goto jump;
                }
            }

            lineStream >> yLocation;
            if (lineStream.fail() && !lineStream.eof()){
                invalidArgument();
                goto jump;
            } else if (lineStream.eof()){
                tooFewArgs();
                goto jump;
            } else {
                if (yLocation < 0){
                    invalidValue();
                    goto jump;
                }
            }

            lineStream >> xSize;
            if (lineStream.fail() && !lineStream.eof()){
                invalidArgument();
                goto jump;
            } else if (lineStream.eof()){
                tooFewArgs();
                goto jump;
            } else {
                if (xSize < 0){
                    invalidValue();
                    goto jump;
                }
            }

            lineStream >> ySize;
            
            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            } else {
                if (ySize < 0){
                    invalidValue();
                    goto jump;
                }
            }

            // when the type is circle and x/y sizes are different, print an error statement
            if (shapeType == "circle" && (xSize != ySize)) {
                invalidValue();
                goto jump;
            }

            // check for too many arguments
            if (lineStream.eof() != true) {
                tooManyArgs();
                goto jump;
            }

            // check if the shape array is full
            if (shapeCount >= max_shapes) {
                shapeArrayFull();
                goto jump;
            }
            // if none of the error happens, it creates 

            shapesArray[shapeCount] = new Shape(shapeName, shapeType, xLocation, xSize, yLocation, ySize);
            shapeCount++;
            // print the created comment
            cout << "Created " << shapeName << ": " << shapeType << " " << xLocation << " " << yLocation << " " << xSize << " " << ySize << endl;

            //move  
        } else if (command == keyWordsList[3]) {
            string shapeName;
            int xLocation, yLocation;

            if (lineStream.eof()) {
                tooFewArgs();
                goto jump;
            }

            // take in shape name
            lineStream >> shapeName;

            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            }

            for (int i = 1; i < 7; i++) {
                if (shapeName == keyWordsList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }
            for (int i = 0; i < 4; i++) {
                if (shapeName == shapeTypesList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }

            // check if the shape Exists in the array
            bool shapeExists = false;
            for (int i = 0; i < shapeCount; i++) {
                if (shapesArray[i] != NULL && shapesArray[i]->getName() == shapeName) {
                    shapeExists = true;
                }
            }
            if (shapeExists == false) { // if the shape doesn't 
                shapeNameNotFound(shapeName); //prints the error statement
                goto jump;
            }

            // take in x location to move to
            lineStream >> xLocation;
            if (lineStream.fail()) {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else {
                if (xLocation < 0) {
                    invalidValue();
                    goto jump;
                }
            }

            // take in y location to move to
            lineStream >> yLocation;
            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            }

            // check for too many arguments
            if (lineStream.eof() != true) {
                tooManyArgs();
                goto jump;
            }

            for (int i = 0; i < shapeCount; i++) {
                if (shapesArray[i] != NULL && (shapesArray[i]->getName() == shapeName)) {
                    shapesArray[i]->setXlocation(xLocation);
                    shapesArray[i]->setYlocation(yLocation);
                }
            }

            cout << "Moved " << shapeName << " to " << xLocation << " " << yLocation << endl;

        //rotate
        } else if (command == keyWordsList[4]) { 
            string shapeName;
            int angle, locationInArray;

            // take in shape name
            lineStream >> shapeName;
            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            }

            for (int i = 1; i < 7; i++) {
                if (shapeName == keyWordsList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }
            for (int i = 0; i < 4; i++) {
                if (shapeName == shapeTypesList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }
                // if none of the error applies, now check if the shape Exists in the array
            bool shapeExists = false;
            for (int i = 0; i < max_shapes; i++) {
                if (shapesArray[i] != NULL && shapesArray[i]->getName() == shapeName) {
                    shapeExists = true;
                    i = locationInArray;
                }
            }
            if (shapeExists == false) { // if the shape doesn't 
                shapeNameNotFound(shapeName); //prints the error statement
                goto jump;
            }

            lineStream >> angle;
            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            } else { // if none of the error applies, check if the angle is in bound
                if ((angle < 0) || (angle > 360)) {
                    invalidValue();
                    goto jump;
                }
            }

            // check for too many arguments
            if (lineStream.eof() != true) {
                tooManyArgs();
                goto jump;
            }

            // change the rotation
            shapesArray[locationInArray]->setRotate(angle);
            cout << "Rotated " << shapeName << " by " << angle << " degrees" << endl;

            //draw
        } else if (command == keyWordsList[5]) {
            string shapeName;

            if (lineStream.eof()) {
                tooFewArgs();
                goto jump;
            }

            lineStream >> shapeName;

            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            }

            for (int i = 1; i < 7; i++) {
                if (shapeName == keyWordsList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }

            for (int i = 0; i < 4; i++) {
                if (shapeName == shapeTypesList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }

            if (shapeName == keyWordsList[0]) { // check if the user wants to draw all shapes
                cout << "Drew all shapes" << endl;
                for (int i = 0; i < shapeCount; i++) {
                    shapesArray[i] -> draw();
                }
                goto jump;
            }


            bool shapeExists = false;
            for (int i = 0; i < shapeCount; i++) {
                if (shapesArray[i] != NULL && shapesArray[i]->getName() == shapeName) {
                    shapeExists = true;
                    if (lineStream.eof() != true) {
                        tooManyArgs();
                        goto jump;
                    }
                    // draw the shape
                    cout << "Drew " << shapesArray[i]->getName() << ": " << shapesArray[i]->getType() << " " << shapesArray[i]->getXlocation() << " " << shapesArray[i]->getYlocation() << " " << shapesArray[i]->getXsize() << " " << shapesArray[i]->getYsize() << endl;
                    goto jump;
                }
            }
            if (shapeExists == false) { // if the shape doesn't exist, print the error statement
                shapeNameNotFound(shapeName);
                goto jump;
            }



        } else if (command == keyWordsList[6]) { //delete
            string shapeName;

            lineStream >> shapeName;

            if (lineStream.fail() || lineStream.peek() == '.') {
                if (lineStream.eof()) {
                    tooFewArgs();
                    goto jump;
                } else {
                    invalidArgument();
                    goto jump;
                }
            } else if ((lineStream.peek() > 0) && (lineStream.peek() != ' ')) {
                invalidArgument();
                goto jump;
            }

            for (int i = 1; i < 7; i++) {
                if (shapeName == keyWordsList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }

            for (int i = 0; i < 4; i++) {
                if (shapeName == shapeTypesList[i]) {
                    invalidShapeName();
                    goto jump;
                }
            }

            if (shapeName == keyWordsList[0]) { // check if the user wants to delete all shapes
                
                if (lineStream.eof() != true) {
                    tooManyArgs();
                    goto jump;
                }
                
                for (int i = 0; i < shapeCount; i++) {
                    if (shapesArray[i] != NULL) {
                        // delete all shape
                        delete shapesArray[i];
                        shapesArray[i] = nullptr;
                    }
                }
                
                shapeCount = 0;
                cout << "Deleted: all shapes" << endl;
                goto jump;


            } else { // if its not "all" delete specific array
                bool shapeExists = false;

                for (int i = 0; i < shapeCount; i++) {
                    if (shapesArray[i] != NULL && shapesArray[i]->getName() == shapeName) {
                        shapeExists = true;
                        // delete shape
                        delete shapesArray[i];
                        shapesArray[i] = nullptr;
                        cout << "Deleted shape " << shapeName << endl;
                        shapeCount--;
                        for (int j = i; j <= shapeCount; j++) {
                            shapesArray[j] = shapesArray[j + 1];
                        }
                        shapesArray[shapeCount + 1] = nullptr;
                    }
                    break;
                }
                if (shapeExists == false) {
                    // if the shape doesn't exist, print the error statement
                    shapeNameNotFound(shapeName);
                    goto jump;
                }
                if (lineStream.eof() != true) {
                    tooManyArgs();
                    goto jump;
                }
            }
        } else {
            invalidCommand();
        }

        // Once the command has been processed, prompt for the
        // next command
        jump:
        cout << "> "; // Prompt for input
        getline(cin, line);

    } // End input loop until EOF.

    return 0;
}

