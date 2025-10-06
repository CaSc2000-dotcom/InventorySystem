/***********************************************************************
 * Source File:
 *    FLASH FREEZE
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents a flash freeze item
 ***********************************************************************/

#include "item.h"

 /*********************************************
  * FlashFreeze
  * All enemies in a radius are frozen in place for a duration
  *********************************************/
class FlashFreeze : public ExactorItem
{
public:
   FlashFreeze();

   ItemsType getType() const { return ItemsType::FREEZE; }

   void use();
};