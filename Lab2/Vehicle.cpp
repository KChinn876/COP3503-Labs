//
// Created by Kidane Chinn on 9/14/22.
//
#include "Vehicle.h"

//Default constructor
Vehicle::Vehicle(){
   make = "COP3503";
   model = "Rust Bucket";
   year = 1900;
   price = 0;
   mileage = 0;
}
//Constructor
Vehicle::Vehicle(string make, string model, int year, float price, int mileage){
   this-> make = make;
   this-> model = model;
   this-> year = year;
   this-> price = price;
   this-> mileage = mileage;
}
//Print out vehicle details
void Vehicle::Display(){
   cout << year << " " << make << " " << model << " $" << price << " " << mileage << endl;
}
//Create and return year make model string
string Vehicle::GetYearMakeModel(){
   string strYear = to_string(year);
   string yearMakeModel = strYear + " " + make + " " + model;
   return yearMakeModel;
}
//Return price
float Vehicle::GetPrice(){
   return price;
}