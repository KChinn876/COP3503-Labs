//
// Created by Kidane Chinn on 9/14/22.
//
#pragma once
#include "Vehicle.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Showroom{
    string name;
    vector<Vehicle> vehicles;
    int capacity;
public:
    //Default constructor
    Showroom(string name = "Unnamed Showroom", int capacity = 0);
    //Accessor
    vector<Vehicle> GetVehicleList();
    //Behaviors
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};