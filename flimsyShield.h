/***********************************************************************
 * Source File:
 *    FLIMSY SHIELD
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a flimsy shield item
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