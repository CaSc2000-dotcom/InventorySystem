/***********************************************************************
 * Source File:
 *    FLASH FREEZE
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a flash freeze item
 ***********************************************************************/

#include "flashFreeze.h"
#include <iostream>

FlashFreeze::FlashFreeze() : ExactorItem()
{
   itemID = 12;
   displayName = "Flash Freeze";
   iconPath = "assets/icons/flash_freeze.png";
   value = 64;
   magnitude = 7.0f;
   areaOfEffect = 20.0f;

   description = "Freezes all enemies in a " 
               + std::to_string(static_cast<int>(areaOfEffect)) 
               + " meter radius for " 
               + std::to_string(static_cast<int>(magnitude)) 
               + " seconds.";
}

void FlashFreeze::use()
{
   std::cout << "You used " << displayName << " and froze all enemies in a " 
             << areaOfEffect << " meter radius for " 
             << magnitude << " seconds!" 
             << std::endl;
}