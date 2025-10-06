/***********************************************************************
 * Source File:
 *    HASTE ELIXIR
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a haste elixir item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * HasteElixir
  * Grants the player temporary invulnerability when used
  *********************************************/
class HasteElixir : public PowerupItem
{
public:
   HasteElixir();

   ItemsType getType() const { return ItemsType::HASTE; }

   void use();
};