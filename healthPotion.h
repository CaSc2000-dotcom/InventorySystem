/***********************************************************************
 * Source File:
 *    HEALTH POTION
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from Item, represents a health potion item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * HealthPotion
  * Heals the player when used
  *********************************************/
class HealthPotion : public PotionItem
{
public:
   HealthPotion();

   ItemsType getType() const { return ItemsType::HEALTH; }

   void use();
};