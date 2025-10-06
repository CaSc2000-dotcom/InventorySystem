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

/***********************************************************************
 * Finds the index of the item with the given itemID in the inventory.
 * @param itemID The unique identifier of the item to search for.
 * @return The index of the item if found, otherwise -1.
 ***********************************************************************/
int Inventory::findItemIndex(int itemID) const
{
   for (size_t i = 0; i < slots.size(); ++i)
   {
      if (slots[i].item->getItemID() == itemID)
         return static_cast<int>(i);
   }
   return -1; // Not found
}

/***********************************************************************
 * Adds an item to the inventory. If the item already exists, increases its quantity.
 * @param newItem Pointer to the item to add.
 * @param quantity The number of items to add.
 * @return True if the item was added or updated successfully, false if inventory is full.
 ***********************************************************************/
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

/***********************************************************************
 * Removes a specified quantity of an item at the given index.
 * If the quantity reaches zero, removes the item from the inventory.
 * @param index The index of the item to remove.
 * @param quantity The number of items to remove.
 * @return True if the item was removed or updated successfully, false otherwise.
 ***********************************************************************/
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

/***********************************************************************
 * Removes all items from the inventory, clearing all slots.
 ***********************************************************************/
void Inventory::clear()
{
   slots.clear();
}

/***********************************************************************
 * Overloads the output stream operator to display the inventory contents.
 * @param os The output stream.
 * @param inv The inventory to display.
 * @return The output stream with inventory information.
 ***********************************************************************/
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
   os << "Capacity: " << inv.getSize() << "/" << inv.getCapacity();
   if (inv.isFull())
      os << "\t\t[!] All slots utilized";
   os << "\n=============================================\n";
   return os;
}
