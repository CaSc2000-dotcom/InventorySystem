/***********************************************************************
 * Source File:
 *    FLIMSY SHIELD
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from Item, represents a Flimsy Shield item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * FlimsyShield
  * Grants the player a temporary shield when used
  *********************************************/
class FlimsyShield : public PowerupItem
{
public:
   FlimsyShield();

   ItemsType getType() const { return ItemsType::SHIELD; }

   void use();
};