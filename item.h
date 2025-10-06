/***********************************************************************
 * Source File:
 *    ITEM
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Base class for representing an item in the game
 ***********************************************************************/

#pragma once

#include <string>

/*********************************************
 * ItemsType
 * Enumeration of all possible item types in the game.
 *********************************************/
enum ItemsType
{
   // PowerupItems
   INVULNERABLILITY, XP_MAGNET, HASTE, SHIELD,
   // ExactorItems
   GRAVITY, LIGHTNING, FREEZE,
   // PotionItems
   HEALTH,
   // Invalid type
   INVALID
};

/*********************************************
 * Item
 * A consumable usable by the player.
 * Base class for all item types, providing common properties and interface.
 *********************************************/
class Item
{
public:
   // Constructors
   // Initializes an item with optional parameters for all properties.
   Item(int itemID = -1, std::string displayName = "", std::string description = "",
        std::string iconPath = "", int value = -1, float magnitude = -1.0f) 
      : itemID(itemID), displayName(displayName), description(description), 
        iconPath(iconPath), value(value), magnitude(magnitude) {}
   virtual ~Item() {}

   // Getters
   // Returns the unique identifier for the item.
   int getItemID() const { return itemID; }

   // Returns the display name of the item.
   std::string getDisplayName() const { return displayName; }

   // Returns the description of the item.
   std::string getDescription() const { return description; }

   // Returns the file path to the item's icon.
   std::string getIconPath() const { return iconPath; }

   // Returns the value of the item (e.g., cost, worth).
   int getValue() const { return value; }

   // Returns the type of the item (must be implemented by derived classes).
   virtual ItemsType getType() const = 0;


   // Defines the item's effect when used (must be implemented by derived classes).
   virtual void use() = 0;

   // Overloads the output stream operator for displaying item information.
   friend std::ostream& operator<<(std::ostream& os, const Item& pt);

protected:
   int itemID;                // Unique identifier for the item
   std::string displayName;   // Name displayed to the player
   std::string description;   // Description of the item's effect
   std::string iconPath;      // Path to the item's icon image
   int value;                 // Value of the item (2048 game value)
   float magnitude;           // Magnitude of the item's effect (e.g., amount healed, damage dealt)
};

/*********************************************
 * PowerupItem
 * Item that provides a temporary buff to the player
 *********************************************/
class PowerupItem : public Item
{
public:
   PowerupItem(float duration = -1.0f)
      : duration(duration), Item() {
   }
protected:
   float duration;
};

/*********************************************
 * ExactorItem
 * Item that affects enemies in some way
 *********************************************/
class ExactorItem : public Item
{
public:
   ExactorItem(float areaOfEffect = -1.0f)
      : areaOfEffect(areaOfEffect), Item() {
   }
protected:
   float areaOfEffect;
};

/*********************************************
 * PotionItem
 * Item that provides a one-time benefit to the player
 *********************************************/
class PotionItem : public Item
{
public:
   PotionItem()
      : Item() {
   }
};