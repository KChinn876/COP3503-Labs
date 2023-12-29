//
// Created by Kidane Chinn on 9/14/22.
//
#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle{
   string make;
   string model; 
   int year;
   float price;
   int mileage;
public: 
   //Default constructor
   Vehicle();
   //Constructor
   Vehicle(string make, string model, int year, float price, int mileage);
   //Print out vehicle details
   void Display();
   //Create and return year make model string
   string GetYearMakeModel();
   //Return price
   float GetPrice();
};