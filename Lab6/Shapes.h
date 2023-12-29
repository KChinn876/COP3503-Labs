//
// Created by Maddy Wirbel on 3/9/23.
//
#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const float PI = 3.14159f; // variable value of PI

class Shape{ // base class
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void Display() const = 0;
    virtual ~Shape();
};

class Shape2D : virtual public Shape{ // derived class from shape
public:
    virtual float Area() const = 0;
    void ShowArea() const;
    virtual string GetName2D() const = 0;
    bool operator>(const Shape2D &rhs) const;
    bool operator<(const Shape2D &rhs) const;
    bool operator==(const Shape2D &rhs) const;
};

class Square : virtual public Shape2D{
    float sideLength;
public:
    Square();
    Square(float sideLength);
    float Area() const;
    string GetName2D() const;
    void Display() const;
    void Scale(float scaleFactor);
};

class Triangle : virtual public Shape2D{
    float base;
    float height;
public:
    Triangle();
    Triangle(float base, float height);
    float Area() const;
    float ReturnBase() const;
    float ReturnHeight() const;
    string GetName2D() const;
    void Display() const;
    void Scale(float scaleFactor);
};

class Circle : virtual public Shape2D{
    float radius;
public:
    Circle();
    Circle(float radius);
    float Area() const;
    float ReturnRadius() const;
    string GetName2D() const;
    void Display() const;
    void Scale(float scaleFactor);
};

class Shape3D : virtual public Shape{ // derived class from shape
public:
    virtual float Volume() const = 0;
    void ShowVolume() const;
    virtual string GetName3D() const = 0;
    bool operator>(const Shape3D &rhs) const;
    bool operator<(const Shape3D &rhs) const;
    bool operator==(const Shape3D &rhs) const;
};


class TriangularPyramid : virtual public Shape3D, private Triangle{
    float heightPyramid;
public:
    TriangularPyramid();
    TriangularPyramid(float heightPyramid, float base, float height);
    float Volume() const;
    string GetName3D() const;
    void Display() const;
    void Scale(float scaleFactor);
};

class Cylinder : virtual public Shape3D, private Circle{
    float heightCylinder;
public:
    Cylinder();
    Cylinder(float heightCylinder, float radius);
    float Volume() const;
    string GetName3D() const;
    void Display() const;
    void Scale(float scaleFactor);
};

class Sphere : virtual public Shape3D, private Circle{
    float radiusSphere;
public:
    Sphere();
    Sphere(float radiusSphere);
    float Volume() const;
    string GetName3D() const;
    void Display() const;
    void Scale(float scaleFactor);
};