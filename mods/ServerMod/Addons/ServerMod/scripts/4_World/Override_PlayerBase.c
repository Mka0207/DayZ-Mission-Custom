//Class that are modded to be overridden!
modded class PlayerBase extends ManBase
{	

	//How many ticks before bodies should be cleaned up.
	const float BODY_CLEANUP_SECS = 18;
	protected float	m_BodyCleanCheckTimer = 0.0;
	override void OnTick()
	{
		float deltaT = (GetGame().GetTime() - m_LastTick) / 1000;
		if ( m_LastTick < 0 )  deltaT = 0;//first tick protection
		m_LastTick = GetGame().GetTime();
		
		//Cleanup Script
		OnPlayerLootTick(this, deltaT);
		
		//Clean up dead bodies.
		if ( !IsAlive() )
		{
			m_BodyCleanCheckTimer += deltaT;
			if ( m_BodyCleanCheckTimer > BODY_CLEANUP_SECS ) 
			{
				Delete();
				//Print("[DEBUG] - Cleaned PlayerBase Body");
			}
		}
		//
		
		OnScheduledTick(deltaT);		
	}
	
	void logDeath(string s) {
		int hour = 0;
		int minute = 0;
		int second = 0;
		int year = 0;
		int month = 0;
		int day = 0;

		GetHourMinuteSecond(hour, minute, second);
		GetYearMonthDay(year, month, day);
		
		string combined = "["+year+"/"+month+"/"+day+" "+hour+":"+minute+":"+second+"]: "+s;
		
		if ( GetGame().IsServer() ) 
		{
			FileHandle file;
			
			string file_name = "\\damagelog";
			file_name = file_name + ".txt";

			file_name = "$profile:DamageLogs" + file_name;
			
			MakeDirectory("$profile:DamageLogs");
			
			if( !FileExist( file_name ) )
			{            
				file = OpenFile(file_name, FileMode.WRITE);
				if (file != 0)
				{
					FPrintln(file, "Time format [YYYY/MM/DD hh:mm:ss]");
					CloseFile(file);
				}
			}
			
			file = OpenFile(file_name, FileMode.APPEND);
			if (file != 0)
			{
				FPrintln(file, combined);
				CloseFile(file);
			}
		}
	}
	
	int humans_killed;
	override void EEKilled( Object killer )
	{
		//Print("EEKilled, you have died");
		
		//Remove the character after 18000 aka 18 secs.
		//GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.Delete, 18000, false);
		
		//Custom Code Begin
		//OnPlayerKilledByPlayer( this, killer );
		AddKillStreak(killer);
		
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
			//Logs
			PlayerBase pb_killer = PlayerBase.Cast(killer);
			if (pb_killer) {
				if ( pb_killer.humans_killed >= 45 )
				{
					logDeath("FOUND HACKER!");
					logDeath("STEAM ID 64 : "+pb_killer.GetIdentity().GetPlainId() );
					logDeath("Character Name : "+pb_killer.GetIdentity().GetName() );
					
					pb_killer.SetPosition( Vector( 0, 0, 0 ) );
					
					Param1<string> params2;
					params2 = new Param1<string>( "" );
					PlayerBase man2;
					if ( Class.CastTo(man2, killer) )
					{
						params2.param1 = "Stop Cheating!";
						man2.RPCSingleParam( ERPCs.RPC_USER_ACTION_MESSAGE, params2, true, man2.GetIdentity() );
					}
				}
				logDeath(this.GetIdentity().GetPlainId()+" ("+this.GetIdentity().GetName()+") killed by "+pb_killer.GetIdentity().GetPlainId()+"("+pb_killer.GetIdentity().GetName()+")" +" With "+pb_killer.humans_killed+" Kills!");
			} else {
				logDeath(this.GetIdentity().GetPlainId()+" ("+this.GetIdentity().GetName()+") killed by an unknown cause."+" With "+humans_killed+" Kills!");
			}
			//Logs End
			
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