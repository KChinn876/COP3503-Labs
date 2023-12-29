//
// Created by Maddy Wirbel on 3/9/23.
//
#include "Shapes.h"

// SHAPE FUNCTIONS

Shape::~Shape(){

}

// 2D SHAPE FUNCTIONS

void Shape2D::ShowArea() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
}

bool Shape2D::operator>(const Shape2D &rhs) const{
    if(Area() > rhs.Area()){
        return true;
    }
    return false;
}

bool Shape2D::operator<(const Shape2D &rhs) const{
    if(Area() < rhs.Area()){
        return true;
    }
    return false;
}

bool Shape2D::operator==(const Shape2D &rhs) const{
    if(Area() == rhs.Area()){
        return true;
    }
    return false;
}

// SQUARE FUNCTIONS

Square::Square(){
    sideLength = 0;
}

Square::Square(float sideLength){
    this -> sideLength = sideLength;
}

float Square::Area() const{
    return (sideLength * sideLength);
}

string Square::GetName2D() const{
    return "Square";
}

void Square::Display() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
    cout << "Length of a side: " << sideLength << endl;
}

void Square::Scale(float scaleFactor){
    sideLength *= scaleFactor;
}


// TRIANGLE FUNCTIONS

Triangle::Triangle(){
    base = 0;
    height = 0;
}

Triangle::Triangle(float base, float height){
    this -> base = base;
    this -> height = height;
}

float Triangle::Area() const{
    return (0.5 * base * height);
}

float Triangle::ReturnBase() const{
    return base;
}

float Triangle::ReturnHeight() const{
    return height;
}

string Triangle::GetName2D() const{
    return "Triangle";
}

void Triangle::Display() const{
    cout << "The area of the " << GetName2D() << " is : " << Area() << endl;
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
}

void Triangle::Scale(float scaleFactor){
    base *= scaleFactor;
    height *= scaleFactor;
}

// CIRCLE FUNCTIONS

Circle::Circle(){
    radius = 0;
}

Circle::Circle(float radius){
    this -> radius = radius;
}

float Circle::Area() const{
    return (PI * (radius * radius));
}

float Circle::ReturnRadius() const{
    return radius;
}

string Circle::GetName2D() const{
    return "Circle";
}

void Circle::Display() const{
    cout << "The area of the " << GetName2D() << " is: " << Area() << endl;
    cout << "Radius: " << radius << endl;
}

void Circle::Scale(float scaleFactor){
    radius *= scaleFactor;
}

// 3D SHAPE FUNCTIONS

void Shape3D::ShowVolume() const{
    cout << "The volume of the " << GetName3D() << " is : " << Volume() << endl;
}

bool Shape3D::operator>(const Shape3D &rhs) const{
    if(Volume() > rhs.Volume()){
        return true;
    }
    return false;
}

bool Shape3D::operator<(const Shape3D &rhs) const{
    if(Volume() < rhs.Volume()){
        return true;
    }
    return false;
}

bool Shape3D::operator==(const Shape3D &rhs) const{
    if(Volume() == rhs.Volume()){
        return true;
    }
    return false;
}

// TRIANGULAR PYRAMID FUNCTIONS

TriangularPyramid::TriangularPyramid(){
    heightPyramid = 0;
}

TriangularPyramid::TriangularPyramid(float heightPyramid, float base, float height) : Triangle(base, height){
    this -> heightPyramid = heightPyramid;
    // don't have to declare the base and height of the pyramid because it will be inherited to the private
    // triangle class
}

float TriangularPyramid::Volume() const{
    return ((1.0 / 3.0) * Area() * heightPyramid);
}

string TriangularPyramid::GetName3D() const{
    return "TriangularPyramid";
}

void TriangularPyramid::Display() const{
    cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;
    cout << "The height is: " << heightPyramid << endl;
    cout << "The area of the Triangle is: " << Area() << endl;
    cout << "Base: " << ReturnBase() << endl;
    cout << "Height: " << ReturnHeight() << endl;
}

void TriangularPyramid::Scale(float scaleFactor){
    Triangle::Scale(scaleFactor); // must pass the scale factor to the inherited class
    heightPyramid *= scaleFactor;
}

// CYLINDER FUNCTIONS

Cylinder::Cylinder(){
    heightCylinder = 0;
}

Cylinder::Cylinder(float heightCylinder, float radius) : Circle(radius){
    this -> heightCylinder = heightCylinder;
}

float Cylinder::Volume() const{
    return (Area() * heightCylinder);
}

string Cylinder::GetName3D() const{
    return "Cylinder";
}

void Cylinder::Display() const{
    cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;
    cout << "The height is: " << heightCylinder << endl;
    cout << "The area of the Circle is: " << Area() << endl;
    cout << "Radius: " << ReturnRadius() << endl;
}

void Cylinder::Scale(float scaleFactor){
    Circle::Scale(scaleFactor); // must pass the scale factor to the inherited class
    heightCylinder *= scaleFactor;
}

// SPHERE FUNCTIONS

Sphere::Sphere(){
    radiusSphere = 0;
}

Sphere::Sphere(float radiusSphere) : Circle(radiusSphere){
    this -> radiusSphere = radiusSphere;
}

float Sphere::Volume() const{
    return ((4.0 / 3.0) * Area() * ReturnRadius());
}

string Sphere::GetName3D() const{
    return "Sphere";
}

void Sphere::Display() const{
    cout << "The volume of the " << GetName3D() << " is: " << Volume() << endl;
    cout << "The area of the Circle is: " << Area() << endl;
    cout << "Radius: " << ReturnRadius() << endl;
}

void Sphere::Scale(float scaleFactor){
    Circle::Scale(scaleFactor); // must pass the scale factor to the inherited class
    radiusSphere *= scaleFactor;
}
