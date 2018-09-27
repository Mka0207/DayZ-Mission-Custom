//Literally just commented out the following below, it stopped weapons from dropping off the player on death.

void DisableWeaponDrops(PlayerBase player, Object killer)
{
	if( player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
	{
		//Removed for now, Shouldnt bother anything,
		/* if( GetGame().GetPlayer() == player )
		{
			super.EEKilled( killer );
		} */
	/* if (GetHumanInventory().GetEntityInHands())
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() )); */
	}
	else if( player.GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)//server
	{
		if( player.GetBleedingManager() ) delete player.GetBleedingManager();
	/* if( GetHumanInventory().GetEntityInHands() )
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() )); */
	}
}