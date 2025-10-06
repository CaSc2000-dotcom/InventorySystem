/***********************************************************************
 * Source File:
 *    XP MAGNET
 * Author:
 *    Caleb Schmid
 * Summary:
 *    Derived from PowerupItem, represents an xp magnet item
 ***********************************************************************/

#include "xpMagnet.h"

XPMagnet::XPMagnet() : PowerupItem()
{
   itemID = 21;
   displayName = "XP Magnet";
   iconPath = "assets/icons/xp_magnet.png";
   value = 128;
   magnitude = 10.0f;
   duration = 5.0f;

   description = "XP in a radius of " + std::to_string(static_cast<int>(magnitude)) 
               + " meters is drawn to you for " + std::to_string(static_cast<int>(duration)) 
               + " seconds.";
}

void XPMagnet::use()
{
   std::cout << "You used a " << displayName << " and XP is being drawn to you for "
             << duration << " seconds!" << std::endl;
}
