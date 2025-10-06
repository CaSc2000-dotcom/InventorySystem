// InventorySystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "item.h"
#include "flashFreeze.h"
#include "chainLightning.h"
#include "gravityBomb.h"
#include "hasteElixir.h"
#include "xpMagnet.h"
#include "ghostVeil.h"
#include "flimsyShield.h"
#include "healthPotion.h"
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

   GhostVeil gveil;
   std::cout << "\n" << gveil << std::endl;
   gveil.use();

   XPMagnet xpmag;
   std::cout << "\n" << xpmag << std::endl;
   xpmag.use();

   HasteElixir helix;
   std::cout << "\n" << helix << std::endl;
   helix.use();

   GravityBomb gbomb;
   std::cout << "\n" << gbomb << std::endl;
   gbomb.use();

   ChainLightning clight;
   std::cout << "\n" << clight << std::endl;
   clight.use();

   FlashFreeze ffreeze;
   std::cout << "\n" << ffreeze << std::endl;
   ffreeze.use();
}