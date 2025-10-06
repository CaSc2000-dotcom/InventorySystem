/***********************************************************************
 * Source File:
 *    HASTE ELIXIR
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents an xp magnet item
 ***********************************************************************/

#include "hasteElixir.h"

HasteElixir::HasteElixir() : PowerupItem()
{
   itemID = 22;
   displayName = "Haste Elixir";
   iconPath = "assets/icons/haste_elixir.png";
   value = 64;
   magnitude = 1.3f;
   duration = 7.0f;

   description = "Grants a boost of " + std::to_string(static_cast<int>(magnitude))
      + "x movement haste for " + std::to_string(static_cast<int>(duration))
      + " seconds.";
}

void HasteElixir::use()
{
   std::cout << "You used a " << displayName << " and now move faster for "
      << duration << " seconds!" << std::endl;
}
