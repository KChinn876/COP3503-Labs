//
// Created by Kidane Chinn on 9/14/22.
//
#include "Showroom.h"

//Default constructor
Showroom::Showroom(string name, int capacity){
   this-> name = name;
   this-> capacity = capacity;
}
//Accessor
vector<Vehicle> Showroom::GetVehicleList(){
   return vehicles;
}
//Behaviors
void Showroom::AddVehicle(Vehicle v){
   string description = "empty";
   if(vehicles.size() < capacity){
      vehicles.push_back(v);  
   }
   else{
      description = v.GetYearMakeModel();
      cout << "Showroom is full! Cannot add " << description << endl;  
   }
}
void Showroom::ShowInventory(){
   if(vehicles.size() == 0){
      cout << name << " is empty!" << endl;
   } 
   else{
      cout << "Vehicles in " << name << endl;
      for(int i = 0; i < vehicles.size(); i++){
         vehicles.at(i).Display();  
      }
   }
}
float Showroom::GetInventoryValue(){
   float currPrice = 0;
   float totalPrice = 0;
   for(int i = 0; i < vehicles.size(); i++){
      currPrice = vehicles.at(i).GetPrice(); 
      totalPrice += currPrice;
   }
   
   return totalPrice;
}