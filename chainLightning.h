/***********************************************************************
 * Source File:
 *    CHAIN LIGHTNING
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a chain lightning item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * ChainLightning
  * Deals damage to a target enemy and chains to nearby enemies
  *********************************************/
class ChainLightning : public ExactorItem
{
public:
   ChainLightning();

   ItemsType getType() const { return ItemsType::LIGHTNING; }

   void use();
};