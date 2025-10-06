// InventorySystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "item.h"
#include "healthPotion.h"
#include "flimsyShield.h"
#include <iostream>

int main()
{
   std::cout << "---------------------------------------------" << std::endl;
   std::cout << ">>>> Caleb's Rinky-Dink Inventory System <<<<" << std::endl;
   std::cout << "---------------------------------------------" << std::endl;

   HealthPotion hpot;
   std::cout << "\n" << hpot << std::endl;
   hpot.use();

   FlimsyShield spot;
   std::cout << "\n" << spot << std::endl;
   spot.use();
}