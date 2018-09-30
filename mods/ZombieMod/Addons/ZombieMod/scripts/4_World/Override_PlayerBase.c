//Class that are modded to be overridden!

modded class PlayerBase extends ManBase
{	

	
	//How many ticks before bodies should be cleaned up.
	const float BODY_CLEANUP_SECS = 18;
	protected float	m_BodyCleanCheckTimer = 0.0;
	override void OnScheduledTick(float deltaTime)
	{
		//Custom Code Begin
		 if ( !IsAlive() )
		{
			m_BodyCleanCheckTimer += deltaTime;
			if ( m_BodyCleanCheckTimer > BODY_CLEANUP_SECS ) 
			{
				Delete();
				Print("[DEBUG] - Cleaned PlayerBase Body");
			}
		}
		
		//OnPlayerLootTick(this, deltaTime);
		
		if( !IsPlayerSelected() || !IsAlive() ) return;
		if( m_ModifiersManager ) m_ModifiersManager.OnScheduledTick(deltaTime);
		if( m_NotifiersManager ) m_NotifiersManager.OnScheduledTick();
		if( m_TrasferValues ) m_TrasferValues.OnScheduledTick(deltaTime);
		if( m_DisplayStatus ) m_DisplayStatus.OnScheduledTick();
	}
	
	int humans_killed;
	override void EEKilled( Object killer )
	{
		Print("EEKilled, you have died");
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
		//OnPlayerKilledByPlayer( this, killer )
		Param1<string> params;
		params = new Param1<string>( "" );
		PlayerBase man;
		if ( GetGame().IsServer() && Class.CastTo(man, killer) )
		{
			int kill_add = man.humans_killed++;
			params.param1 = "Kill Streak : "+kill_add;
			man.RPCSingleParam( ERPCs.RPC_USER_ACTION_MESSAGE, params, true, man.GetIdentity() );
		}
	}
} 