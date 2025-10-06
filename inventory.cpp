/***********************************************************************
 * Source File:
 *    INVENTORY
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Data structure to hold and manage a collection of items
 ***********************************************************************/

#include "inventory.h"
#include <iostream>

int Inventory::findItemIndex(int itemID) const
{
   for (size_t i = 0; i < slots.size(); ++i)
   {
      if (slots[i].item->getItemID() == itemID)
         return static_cast<int>(i);
   }
   return -1; // Not found
}

bool Inventory::addItem(Item* newItem, int quantity)
{
   for (auto& slot : slots)
   {
      if (slot.item->getItemID() == newItem->getItemID())
      {
         slot.quantity += quantity;
         return true;
      }
   }
   if (isFull())
      return false;
   slots.push_back({ newItem, quantity });
   return true;
}

bool Inventory::removeItem(int index, int quantity)
{
   for (size_t i = 0; i < slots.size(); ++i)
   {
      if (static_cast<int>(i) == index)
      {
         if (slots[i].quantity < quantity)
            return false;
         slots[i].quantity -= quantity;
         if (slots[i].quantity == 0)
            slots.erase(slots.begin() + i);
         return true;
      }
   }
   return false;
}

std::ostream& operator<<(std::ostream& os, const Inventory& inv)
{
   os << "================= Inventory =================\n";
   if (inv.slots.empty())
   {
      os << "Inventory is empty.\n";
   }
   else
   {
      for (size_t i = 0; i < inv.slots.size(); ++i)
      {
         os << "[" << i << "] " << inv.slots[i].item->getDisplayName()
            << " - Quantity: " << inv.slots[i].quantity << "\n";
      }
   }
   os << "Capacity: " << inv.getSize() << "/" << inv.getCapacity() << "\n";
   os << "=============================================\n";
   return os;
}
