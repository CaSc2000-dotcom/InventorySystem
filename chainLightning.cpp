/***********************************************************************
 * Source File:
 *    CHAIN LIGHTNING
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a chain lightning item
 ***********************************************************************/

#include "chainLightning.h"

ChainLightning::ChainLightning() : ExactorItem()
{
   itemID = 11;
   displayName = "Chain Lightning";
   iconPath = "assets/icons/chain_lightning.png";
   value = 128;
   magnitude = 500.0f;
   areaOfEffect = 5.0f;

   description = "Deals " + std::to_string(static_cast<int>(magnitude))
               + " damage to a target enemy and chains to " 
               + std::to_string(static_cast<int>(areaOfEffect))
               + " nearby enemies.";
}

void ChainLightning::use()
{
   std::cout << "You used " << displayName << " and dealt "
             << magnitude << " damage to the target enemy and "
             << areaOfEffect << " chained enemies!" 
             << std::endl;
}