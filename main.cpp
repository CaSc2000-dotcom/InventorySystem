// InventorySystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "inventory.h"
#include "item.h"
#include "flashFreeze.h"
#include "chainLightning.h"
#include "gravityBomb.h"
#include "hasteElixir.h"
#include "xpMagnet.h"
#include "ghostVeil.h"
#include "flimsyShield.h"
#include "healthPotion.h"
#include <iostream>

/*********************************************
 * Prints all available items and their stats
 *********************************************/
void printAllItems()
{
   HealthPotion hpot;
   std::cout << "\n" << hpot;

   FlimsyShield spot;
   std::cout << "\n" << spot;

   GhostVeil gveil;
   std::cout << "\n" << gveil;

   XPMagnet xpmag;
   std::cout << "\n" << xpmag;

   HasteElixir helix;
   std::cout << "\n" << helix;

   GravityBomb gbomb;
   std::cout << "\n" << gbomb;

   ChainLightning clight;
   std::cout << "\n" << clight;

   FlashFreeze ffreeze;
   std::cout << "\n" << ffreeze;
}

/*********************************************
 * Main function to run the inventory system
 *********************************************/
int main()
{
   std::cout << "---------------------------------------------\n";
   std::cout << ">>>> Caleb's Rinky-Dink Inventory System <<<<\n";
   std::cout << "---------------------------------------------\n";

   std::cout << "\nWelcome adventurer! Here is your standard issue \"Adventurer's Knapsack!\"\n"
             << "Take care not to lose it!\n";
   
   Inventory inventory;

   std::cout << "\n-> Inventory created.\n";

   size_t choice = -1;
   while (choice != 0)
   {
      std::cout << "\nWhat will you do? (Enter a number [0-5])\n"
                << "--------------------------------\n"
                << "1. View Adventurer's Knapsack contents\n"
                << "2. Add Item\n"
                << "3. Remove Item\n"
                << "4. Clear all Items\n"
                << "5. Display Items and Item stats\n"
                << "0. Quit\n"
                << "> ";
      std::cin >> choice;

      if (std::cin.fail()) {
         std::cout << "Invalid input. Please enter a number.\n";
         std::cin.clear(); // Clear the error flag
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
         continue; // Skip to the next iteration of the loop
      }

      switch (choice)
      {
         case 0:
         {
            std::cout << "Exiting the inventory system. Safe travels, adventurer!\n";
            break;
         }
         case 1:         
         {
            std::cout << "\nYour Adventurer's Knapsack contains:\n";
            std::cout << inventory << std::endl;
            break;
         }
         case 2:
         {
            std::cout << "\nChoose an item to add:\n"
                      << "1. Health Potion\n"
                      << "2. Flimsy Shield\n"
                      << "3. Ghost Veil\n"
                      << "4. XP Magnet\n"
                      << "5. Haste Elixir\n"
                      << "6. Gravity Bomb\n"
                      << "7. Chain Lightning\n"
                      << "8. Flash Freeze\n"
                      << "> ";
            int itemChoice;
            std::cin >> itemChoice;
            Item* newItem = nullptr;
            switch (itemChoice)
            {
               case 1: newItem = new HealthPotion();   break;
               case 2: newItem = new FlimsyShield();   break;
               case 3: newItem = new GhostVeil();      break;
               case 4: newItem = new XPMagnet();       break;
               case 5: newItem = new HasteElixir();    break;
               case 6: newItem = new GravityBomb();    break;
               case 7: newItem = new ChainLightning(); break;
               case 8: newItem = new FlashFreeze();    break;
               default:
                  std::cout << "Invalid choice.\n";
                  continue; // Skip adding item
            }
            if (newItem && inventory.addItem(newItem))
            {
               std::cout << newItem->getDisplayName() << " added to your Adventurer's Knapsack.\n";
            }
            else
            {
               std::cout << "Failed to add item.\n";
               delete newItem; // Clean up if not added
            }
            break;
         }
         case 3:
         {
            if (inventory.isEmpty())
            {
               std::cout << "Your Adventurer's Knapsack is empty! Add an item before removing one.\n";
               break;
            }
            std::cout << "\nChoose an item index to remove (0 to " << inventory.getSize() - 1 << "): ";
            int index;
            std::cin >> index;
            if (inventory.removeItem(index))
            {
               std::cout << "Item removed from your Adventurer's Knapsack.\n";
            }
            else
            {
               std::cout << "Failed to remove item. Check the index and try again.\n";
            }
            break;
         }
         case 4:
         {
            if (inventory.isEmpty())
            {
               std::cout << "Your Adventurer's Knapsack is already empty!\n";
               break;
            }
            inventory.clear();
            std::cout << "All items cleared from your Adventurer's Knapsack.\n";
            break;
         }
         case 5:
         {
            std::cout << "\nAvailable Items and their stats:\n";
            printAllItems();
            break;
         }
      }
   }
}