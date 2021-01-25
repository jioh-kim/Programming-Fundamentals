//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Shape.h"
#include "Triangle.h"
#include <cmath>

// Build a triangle object
Triangle::Triangle(string n, float xcent, float ycent, float X1, float Y1, float X2, float Y2, float X3, float Y3):Shape(n, xcent, ycent) {
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
    x3 = X3;
    y3 = Y3;
}


Triangle::~Triangle() {
    // Nothing to do
}

// Accessor
float Triangle::getx1() const {
    return x1;
}
float Triangle::getx2() const {
    return x2;
}
float Triangle::getx3() const {
    return x3;
}
float Triangle::gety1() const {
    return y1;
}
float Triangle::gety2() const {
    return y2;
}
float Triangle::gety3() const {
    return y3;
}


// Mutator
void Triangle::setx1(float number){
    x1 = number;
}
void Triangle::setx2(float number){
    x2 = number;
}
void Triangle::setx3(float number){
    x3 = number;
}
void Triangle::sety1(float number){
    y1 = number;
}
void Triangle::sety2(float number){
    y2 = number;
}
void Triangle::sety3(float number){
    y3 = number;
}


void Triangle::draw() const {
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    // Print the information
    cout << "triangle: " << name << " "
        << x_centre << " " << y_centre << " "
        << x1 << " " << y1 << " " 
        << x2 << " " << y2 << " " 
        << x3 << " " << y3 << " " 
        << computeArea() << endl;
}

float Triangle::computeArea() const {
    return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)) / 2; // add triangle calculation
}

Shape* Triangle::clone() const {
    return (new Triangle(*this));
}


