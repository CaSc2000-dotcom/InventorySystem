/***********************************************************************
 * Source File:
 *    GHOST VEIL
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a ghost veil item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * GhostVeil
  * Grants the player temporary invulnerability when used
  *********************************************/
class GhostVeil : public PowerupItem
{
public:
   GhostVeil();

   ItemsType getType() const { return ItemsType::INVULNERABLILITY; }

   void use();
};