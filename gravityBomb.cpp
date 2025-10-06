/***********************************************************************
 * Source File:
 *    GRAVITY BOMB
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a haste elixir item
 ***********************************************************************/

#include "gravityBomb.h"

GravityBomb::GravityBomb() : ExactorItem()
{
   itemID = 10;
   displayName = "Gravity Bomb";
   iconPath = "assets/icons/gravity_bomb.png";
   value = 256;
   magnitude = 300.0f;
   areaOfEffect = 6.0f;

   description = "Draws in enemies within " + std::to_string(static_cast<int>(areaOfEffect))
      + " meters, then deals " + std::to_string(static_cast<int>(magnitude))
      + " splash damage.";
}

void GravityBomb::use()
{
   std::cout << "You used a " << displayName << " and dealt "
      << magnitude << " damage to each sucked in enemies!" << std::endl;
}