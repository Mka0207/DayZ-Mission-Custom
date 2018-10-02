//Class that are modded to be overridden!
modded class PlayerBase extends ManBase
{	
	override void OnTick()
	{
		float deltaT = (GetGame().GetTime() - m_LastTick) / 1000;
		if ( m_LastTick < 0 )  deltaT = 0;//first tick protection
		m_LastTick = GetGame().GetTime();
		
		//Cleanup Script
		OnPlayerLootTick(this, deltaT);
		//
		
		OnScheduledTick(deltaT);		
	}
	
	int humans_killed;
	override void EEKilled( Object killer )
	{
		Print("EEKilled, you have died");
		
		//Remove the character after 18000 aka 18 secs.
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Delete, 18000, false);
		
		if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT )
		{
			// @NOTE: this branch does not happen, EEKilled is called only on server
			if( GetGame().GetPlayer() == this )
			{
				super.EEKilled( killer );
			}

			if (GetHumanInventory().GetEntityInHands())
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() ));
		}
		else if( GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_SERVER)//server
		{
			if( GetBleedingManager() ) delete GetBleedingManager();
			if( GetHumanInventory().GetEntityInHands() )
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerDropEntity,1000,false,( GetHumanInventory().GetEntityInHands() )); 
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
		
		//Custom Code Begin
		//OnPlayerKilledByPlayer( this, killer );
		AddKillStreak(killer);
	}
	
	//Delete Extra Event stuff when picked up.
	void OnItemInventoryEnter(EntityAI item)
	{
		if ( item.IsKindOf( "Barrel_ColorBase" ) || item.ClassName() == "SeaChest" )
		{
			item.Delete();
		}
		CalculatePlayerLoad();
	}
} 