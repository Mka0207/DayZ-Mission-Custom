//Loot Cleanup By Mka0207.
int kill_base = 0;

modded class PlayerBase extends ManBase
{	
	const float TICK_TEST_CHECK = 250; //! in secs. test timer
	protected float	m_TestCheckTimer = 0.0;

	//Loadout List.
	ref TStringArray Loadout_List = {
		"M65Jacket_Black",
		"BalaclavaMask_Blackskull",
		"GorkaHelmet_Black",
		"CargoPants_Black",
		
		"Armband_Black",
		"Armband_Blue",
		"Armband_Green",
		"Armband_Orange",
		"Armband_Pink",
		"Armband_Red",
		"Armband_Yellow",
		
		"HighCapacityVest_Black",
		"M4_RISHndgrd_Black",
		"M4_MPBttstck_Black",
		
		"MP5k_StockBttstck",
		"MP5_PlasticHndgrd",
		
		"AK_WoodBttstck",
		"AK_WoodHndgrd",
		"KobraOptic",
		
		"ACOGOptic",
		"M68Optic",
		"FNP45_MRDSOptic",
		"PSO1Optic",
		"Battery9V",
		
		"Ammo_9x19",
		"Ammo_556x45",
		"Ammo_762x39",
		"Ammo_762x54",
		"Ammo_45ACP",
		"BallisticVest",

		"Mag_STANAG_30Rnd",
		"Mag_STANAGCoupled_30Rnd",
		"Mag_FNX45_15Rnd",
		"Mag_AKM_30Rnd",
		
		"Mag_MP5_30Rnd",
		"Crowbar",
		"BandageDressing",
		
		"PistolSuppressor",
		
		"AKM",
		"M4A1",
		"MP5K",
		"UMP45",
		"SVD",
		"UMP45",
		"Mosin9130",
		"FNX45"};
		
	override void OnTick()
	{
		float deltaT = (GetGame().GetTime() - m_LastTick) / 1000;
		if ( m_LastTick < 0 )  deltaT = 0;//first tick protection
		m_LastTick = GetGame().GetTime();

		//PrintString("deltaT: " + deltaT);
		//PrintString("at time: " + m_LastTick);
		OnScheduledTick(deltaT);		
		
		//custom begin
		
		m_TestCheckTimer += deltaT;	
		if ( m_TestCheckTimer > TICK_TEST_CHECK )
		{
			m_TestCheckTimer = 0;
			
			ref array<Object> objects = new array<Object>;
			ref array<Object> objects_in_cone = new array<Object>;
			ref array<CargoBase> proxyCargos = new array<CargoBase>;
			
			GetGame().GetObjectsAtPosition( GetPosition(), 100.0, objects, proxyCargos );
			
			if ( GetGame() && objects )
			{
				if ( objects.Count() >= 1 )
				{
					for ( int i = 0; i < objects.Count(); i++ )
					{
						Object item = objects.Get( i );
						if ( item )
						{
							for( int i_d = 0; i_d < Loadout_List.Count(); i_d++ )
							{
								if ( item.GetType() == Loadout_List.Get(i_d) )
								{
									Print("Removed Item "+item.GetType() + " idx = " + i.ToString());
									Print("Removed Item "+item.ClassName() + " idx = " + i.ToString());
								
									GetGame().ObjectDelete(item);
									objects.Remove(i);
								}
								
								if ( !this.IsAlive() )
								{
									// remove the body
									Print("Removed Player Body");
									this.Delete();	
								}
							}
						}
					}
				}
			}
			else
			{
				Print("NO TABLE!");
			}
		}
	}
	
	/* override void CheckDeath()
	{
		if( IsPlayerSelected() && !IsAlive() )
		{
			SimulateDeath(false);
			Event_OnPlayerDeath.Invoke( this );
			m_DeathCheckTimer.Stop();
		}
	} */
	
	//Prevent Weapons dropping after death to prevent lag. -mka
	override void EEKilled( Object killer )
	{
		int kill_add = kill_base++;
		Print("EEKilled, You Are Dead!");
		//GetGame().ChatPlayer( 0, "Kills : "+kill_add );
      
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

/* modded class ItemBase extends InventoryItem
{
	override void EEDelete(EntityAI parent)
	{
		Print( "Del Item!" );
		
		super.EEDelete(parent);
		PlayerBase player = PlayerBase.Cast( GetHierarchyRootPlayer() );
		if(player)
		{
			player.RemoveQuickBarEntityShortcut(this);
			OnInventoryExit(player);
		}
	}
} */