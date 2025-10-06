/***********************************************************************
 * Source File:
 *    FLIMSY SHIELD
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a flimsy shield item
 ***********************************************************************/

#include "flimsyShield.h"

FlimsyShield::FlimsyShield() : PowerupItem()
{
   itemID = 23;
   displayName = "Flimsy Shield";
   iconPath = "assets/icons/flimsy_shield.png";
   value = 16;
   magnitude = 75.0f;
   duration = 5.0f;

   description = "Grants " + std::to_string(static_cast<int>(magnitude)) + " shield for "
               + std::to_string(static_cast<int>(duration)) + " seconds.";
}

void FlimsyShield::use()
{
   std::cout << "You used a " << displayName << " and gained " << magnitude 
             << " shield for " << duration << " seconds!" << std::endl;
}
