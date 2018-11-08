# DayZ-Mission-Custom
Balota Deathmatch code. Includes gear caches.

Things not incuded;

- Modified script.pbo

How to fix Gear Caches :

Edit 4_World/Entities/Grenade_Base/RDG2SmokeGrenade_Black.c
Remove the Explode(); call and add 
  GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Delete, 1700, false);
After it.
