/***********************************************************************
 * Source File:
 *    HEALTH POTION
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from Item, represents a health potion item
 ***********************************************************************/

#include "healthPotion.h"

HealthPotion::HealthPotion() : PotionItem()
{
   itemID = 30;
   displayName = "Health Potion";
   iconPath = "assets/icons/health_potion.png";
   value = 32;
   magnitude = 50.0f;

   description = "Restores " + std::to_string(static_cast<int>(magnitude)) + " health.";
}

void HealthPotion::use()
{
   std::cout << "You used a " << displayName << " and restored " << magnitude << " health!" << std::endl;
}
