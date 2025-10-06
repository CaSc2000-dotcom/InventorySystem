/***********************************************************************
 * Source File:
 *    ITEM
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Base class for representing an item in the game
 ***********************************************************************/

#include "item.h"
#include <iostream>

 /***********************************************************************
  * Overloads the output stream operator to display item information.
  * @param os The output stream.
  * @param item The inventory to display.
  * @return The output stream with item information.
  ***********************************************************************/
std::ostream& operator<<(std::ostream& out, const Item& item)
{
   out << "--------------------------------------------------\n"
       << item.displayName << " -- Value: " << item.value << "\n"
       << item.description << "\n"
       << "---\n"
       << "ItemID: " << item.itemID << " -- Icon Path: " << item.iconPath << "\n"
       << "--------------------------------------------------\n";
   return out;
}
