/***********************************************************************
 * Source File:
 *    XP MAGNET
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents an xp magnet item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * XPMagnet
  * Grants the player temporary invulnerability when used
  *********************************************/
class XPMagnet : public PowerupItem
{
public:
   XPMagnet();

   ItemsType getType() const { return ItemsType::XP_MAGNET; }

   void use();
};