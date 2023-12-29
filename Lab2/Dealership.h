//
// Created by Kidane Chinn on 9/14/22.
//
#pragma once
#include "Showroom.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Dealership{
   vector<Showroom> showrooms;
   string name;
   int capacity;
public:
   //Constructor
   Dealership(string name = "Generic Dealership", unsigned int capacity = 0);
   //Behaviors
   void AddShowroom(Showroom s);
   float GetAveragePrice();
   void ShowInventory();
};