/***********************************************************************
 * Source File:
 *    ITEM
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Base class for representing an item in the game
 ***********************************************************************/

#pragma once

#include <iostream>
#include <string>

enum ItemsType
{
   INVULNERABLILITY, XP_MAGNET, HASTE,
   GRAVITY, LIGHTNING, FREEZE,
   HEALTH, SHIELD,
   INVALID
};

/*********************************************
 * Item
 * A consumable usable by the player
 *********************************************/
class Item
{
public:
   // Constructors
   Item(int itemID = -1, std::string displayName = "", std::string description = "",
        std::string iconPath = "", int value = -1, float magnitude = -1.0f) 
      : itemID(itemID), displayName(displayName), description(description), 
        iconPath(iconPath), value(value), magnitude(magnitude) {}
   virtual ~Item() {}

   // Getters
   int getItemID() const { return itemID; }
   std::string getDisplayName() const { return displayName; }
   std::string getDescription() const { return description; }
   std::string getIconPath() const { return iconPath; }
   int getValue() const { return value; }

   virtual ItemsType getType() const = 0;

   virtual void use() = 0;

   friend std::ostream& operator<<(std::ostream& os, const Item& pt);

protected:
   int itemID;
   std::string displayName;
   std::string description;
   std::string iconPath;
   int value;
   float magnitude;
};

/*********************************************
 * PowerupItem
 * Item that provides a temporary buff to the player
 *********************************************/
class PowerupItem : public Item
{
public:
   PowerupItem(float duration = -1.0f) 
             : duration(duration), Item() {}
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
             : areaOfEffect(areaOfEffect), Item() {}
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
      : Item() {}
};
