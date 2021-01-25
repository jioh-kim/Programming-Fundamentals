//
//  Rectangle.h
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include <string>
using namespace std;


// This class implements the rectangle Shape objects.
// ECE244 Student: Write the definition of the class here.

#include "Shape.h"

class Rectangle : Shape {
private:
    float width;                  
    float height;

public:
    // Constructor
    Rectangle (string name, float xcent, float ycent, float w, float h);
    
    // Destructor
    virtual ~Rectangle();
    
    // Accessor
    float getWidth() const;       // Returns the radius of the circle
    float getHeight() const;       

    // Mutator
    void setWidth(float r);       // Sets the radius of the circle
    void setHeight(float h);

    // Utility methods
    virtual void draw() const;     // Draws thye circle; for the assignment it
                                   // prints the information of the circle
    
    virtual float computeArea() const;   // Computes the area of the circle
    
    virtual Shape* clone() const;  // Clones the object
};


#endif /* Rectangle_h */


