
//Prevent Weapons dropping after death to prevent lag. -mka
modded class PlayerBase extends ManBase
{	
	override void EEKilled( Object killer )
	{
		Print("EEKilled, You Are Dead!");
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			// @NOTE: this branch does not happen, EEKilled is called only on server
			if( GetGame().GetPlayer() == this )
			{
				super.EEKilled( killer );
			}
			/* if (GetHumanInventory().GetEntityInHands())
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() )); */
		}
		else if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)//server
		{
			if( GetBleedingManager() ) delete GetBleedingManager();
			/* if( GetHumanInventory().GetEntityInHands() )
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() )); */
		}
		
		if ( GetSoftSkillManager() )
		{
			delete GetSoftSkillManager();
		} 
		
		GetStateManager().OnPlayerKilled();
		
		// kill character in database
		if (GetHive())
		{
			GetHive().CharacterKill(this);
		}
	}
} 

modded class Hunger: ModifierBase
{	
	override void OnTick(PlayerBase player, float deltaT)
	{
		//Print( "Hunger is disabled" )
	}
}

modded class Thirst: ModifierBase
{	
	override void OnTick(PlayerBase player, float deltaT)
	{
		//Print( "Thirst is disabled" )
	}
}

modded class Temperature: ModifierBase
{	
	override void OnTick(PlayerBase player, float deltaT)
	{
		//Print( "Temperature is disabled" )
	}
}