/***********************************************************************
 * Source File:
 *    GRAVITY BOMB
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a haste elixir item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * GravityBomb
  * Draws in enemies within a radius, then deals splash damage
  *********************************************/
class GravityBomb : public ExactorItem
{
public:
   GravityBomb();

   ItemsType getType() const { return ItemsType::GRAVITY; }

   void use();
};