/***********************************************************************
 * Source File:
 *    ITEM
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Base class for representing an item in the game
 ***********************************************************************/

#include "item.h"

std::ostream& operator<<(std::ostream& out, const Item& item)
{
   out << "--------------------------------------------------\n"
       << "Name: " << item.displayName << " -- Value: " << item.value << "\n"
       << item.description << "\n"
       << "---\n"
       << "ItemID: " << item.itemID << " -- Icon Path: " << item.iconPath << "\n"
       << "--------------------------------------------------\n";
   return out;
}
