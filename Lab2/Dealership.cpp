//
// Created by Kidane Chinn on 9/14/22.
//
#include "Dealership.h"

//Constructor
Dealership::Dealership(string name, unsigned int capacity){
   this-> name = name;
   this-> capacity = capacity;
}
//Behaviors
void Dealership::AddShowroom(Showroom s){
   if(showrooms.size() < capacity){
      showrooms.push_back(s);  
   }
   else{
      cout << "Dealership is full, can't add another showroom!" << endl;  
   }
}

float Dealership::GetAveragePrice(){
   vector<Vehicle> currList;
   float currPrice = 0;
   float totalPrice = 0;
   int numCars = 0;
   float avgPrice = 0;
   for(int i = 0; i < showrooms.size(); i++){
      currList = showrooms.at(i).GetVehicleList();
      for(int j = 0; j < currList.size(); j++){
         currPrice = currList.at(j).GetPrice();
         totalPrice += currPrice;
         numCars += 1;
      }
   }
   avgPrice = totalPrice / numCars;
   
   return avgPrice;
}
void Dealership::ShowInventory(){
   float avgPrice = 0.00;
   if(showrooms.size() == 0){
      cout << name << " is empty!" << endl;
   } 
   else{
      for(int i = 0; i < showrooms.size(); i++){
         showrooms.at(i).ShowInventory();
         cout << endl;
      }
      avgPrice = GetAveragePrice();
   }
   cout << "Average car price: $" << avgPrice;

}

