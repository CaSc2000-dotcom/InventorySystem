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

/*********************************************
 * InventorySlot
 * Represents a single slot in the inventory, holding
 * a pointer to an Item and the quantity of that item.
 *********************************************/
struct InventorySlot
{
   Item* item;      // A pointer to the item's data
   int quantity;    // How many of this item are in the slot
};

/*********************************************
 * Inventory
 * A collection of items the player can use.
 * Manages adding, removing, and querying items.
 *********************************************/
class Inventory
{
public:
   // Constructors
   // Initialize the inventory with a given capacity (default is 8 slots)
   Inventory(int capacity = 8) : capacity(capacity) {}

   // Getters

   // Returns the maximum number of slots in the inventory
   int getCapacity() const { return capacity; }

   // Returns the current number of occupied slots
   int getSize() const { return slots.size(); }

   // Returns a constant reference to the vector of inventory slots
   const std::vector<InventorySlot>& getSlots() const { return slots; }

   // Returns true if the inventory is full (no more slots available)
   bool isFull() const { return slots.size() >= capacity; }

   // Returns true if the inventory is empty (no items)
   bool isEmpty() const { return slots.empty(); }

   // Returns a pointer to the item at the given index, or nullptr if out of bounds
   Item* getItemAt(int index) const { return (index >= 0 && index < slots.size()) ? slots[index].item : nullptr; }

   // Returns the quantity of the item at the given index, or 0 if out of bounds
   int getQuantityAt(int index) const { return (index >= 0 && index < slots.size()) ? slots[index].quantity : 0; }

   // Finds the index of the item with the given itemID, or -1 if not found
   int findItemIndex(int itemID) const;

   // Modifiers

   // Adds an item to the inventory. Returns true if successful.
   bool addItem(Item* newItem, int quantity = 1);

   // Removes a quantity of an item at the given index. Returns true if successful.
   bool removeItem(int index, int quantity = 1);

   // Removes all items from the inventory
   void clear();
   
   // Overloads the output stream operator to print the inventory contents
   friend std::ostream& operator<<(std::ostream& os, const Inventory& inv);

private:
   std::vector<InventorySlot> slots; // The slots holding items and their quantities
   int capacity;                     // The maximum number of slots in the inventory
   // Player* owner;                 // Pointer to the player who owns this inventory
};