/***********************************************************************
 * Source File:
 *    GHOST VEIL
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a ghost veil item
 ***********************************************************************/

#include "ghostVeil.h"
#include <iostream>

GhostVeil::GhostVeil() : PowerupItem()
{
   itemID = 20;
   displayName = "Ghost Veil";
   iconPath = "assets/icons/ghost_veil.png";
   value = 256;
   magnitude = 1.0f;
   duration = 10.0f;

   description = "Grants invulnerability for " 
               + std::to_string(static_cast<int>(duration)) + " seconds.";
}

void GhostVeil::use()
{
   std::cout << "You used a " << displayName << " and gained invulnerability for "
             << duration << " seconds!" << std::endl;
}
