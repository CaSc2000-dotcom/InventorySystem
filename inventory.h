/***********************************************************************
 * Source File:
 *    INVENTORY
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Data structure to hold and manage a collection of items
 ***********************************************************************/

#pragma once

#include "item.h"
#include <vector>

struct InventorySlot
{
   Item* item;      // A pointer to the item's data
   int quantity;    // How many of this item are in the slot
};

/*********************************************
 * Inventory
 * A collection of items the player can use
 *********************************************/
class Inventory
{
public:
   // Constructors
   Inventory(int capacity = 8) : capacity(capacity) {}

   // Getters
   int getCapacity() const { return capacity; }
   int getSize() const { return slots.size(); }
   const std::vector<InventorySlot>& getSlots() const { return slots; }
   bool isFull() const { return slots.size() >= capacity; }
   bool isEmpty() const { return slots.empty(); }
   Item* getItemAt(int index) const { return (index >= 0 && index < slots.size()) ? slots[index].item : nullptr; }
   int getQuantityAt(int index) const { return (index >= 0 && index < slots.size()) ? slots[index].quantity : 0; }
   int findItemIndex(int itemID) const;

   // Modifiers
   bool addItem(Item* newItem, int quantity = 1);
   bool removeItem(int index, int quantity = 1);
   void clear();
   
   friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);

private:
   std::vector<InventorySlot> slots;
   int capacity; 
   // Player* owner; // Pointer to the player who owns this inventory
};