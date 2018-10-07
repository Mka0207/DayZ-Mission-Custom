//Event System by mka0207@fwkzt.com

class CustomEventsSurvival
{
	
	float Mission_FloatTime = 0.0;

	const float EVENT_START_INTERVAL = 120;
	const float EVENT_END_INTERVAL = 900;
	
	bool IsEventRunning = false;
	
	ref RandomEvent m_CurrentEvent = new RandomEvent();

	void CustomEventsSurvival()
	{
		Init();
	}
	
	void Init()
	{
		
	}
	
	void OnEventTick(float CurTime)
	{
		Mission_FloatTime += CurTime;
		
		if ( Mission_FloatTime > EVENT_START_INTERVAL && !IsEventRunning )
        {
			m_CurrentEvent.StartEvent();
			IsEventRunning = true;
			Mission_FloatTime = 0;
		}

		if ( Mission_FloatTime > EVENT_END_INTERVAL && IsEventRunning )
        {
            m_CurrentEvent.EndEvent();
			IsEventRunning = false;
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(m_CurrentEvent.AnnounceEvent);
			Mission_FloatTime = 0;
	    }
	}
}

class RandomEvent
{
	string selected_event;
	vector cleanup_vector;
	float cleanup_radius;
	int EVENT_NOTIFY_DELAY;
	int NUM_OF_EVENT_ZOMBIES;
	int LAST_EVENT_NUM = 0;
	int TimesAdverted = 0;

	//Make sure this stays correct.
	int MAX_NUM_OF_EVENTS = 5;

	bool FireOnlyOnce;
	bool NoCleanUp;

	ItemBase Item_1;
	ItemBase Item_2;
	ItemBase Item_3;
	ItemBase Item_4;

	vector Item_1_Pos;
	vector Item_2_Pos;
	vector Item_3_Pos;
	vector Item_4_Pos;

	vector Item_1_Axis;
	vector Item_2_Axis;
	vector Item_3_Axis;
	vector Item_4_Axis;

	void RandomEvent()
	{
		Init();
	}
	
	void Init()
	{

	}

	void AnnounceEvent(string EventLocation)
	{
		if ( EventLocation )
		{
			TimesAdverted = TimesAdverted + 1;
			
			if ( TimesAdverted == 1 )
			{
				GetGame().ChatPlayer( 1, "Gear Cache Sighted!" );
				GetGame().ChatPlayer( 1, EventLocation );
			}

			if ( TimesAdverted == 2 )
			{
				GetGame().ChatPlayer( 1, "Gear Cache is Active!" );
				GetGame().ChatPlayer( 1, EventLocation );
				GetGame().ChatPlayer( 1, "Ends in 12 mins!" );
			}
			else if ( TimesAdverted == 3 )
			{
				GetGame().ChatPlayer( 1, "Gear Cache is Active!" );
				GetGame().ChatPlayer( 1, EventLocation );
				GetGame().ChatPlayer( 1, "Ends in 9 mins!" );
			}
			else if ( TimesAdverted == 4 )
			{
				GetGame().ChatPlayer( 1, "Gear Cache is Active!" );
				GetGame().ChatPlayer( 1, EventLocation );
				GetGame().ChatPlayer( 1, "Ends in 6 mins!" );
			}
			else if ( TimesAdverted == 5 )
			{
				GetGame().ChatPlayer( 1, "Gear Cache is Active!" );
				GetGame().ChatPlayer( 1, EventLocation );
				GetGame().ChatPlayer( 1, "Ends in 3 mins!" );
			}
			else if ( TimesAdverted == 6 )
			{
				TimesAdverted = 0;
			}
		}
	}
	
	void CreateContainrItems(ItemBase item)
	{
		int RandomItemsChance = Math.RandomIntInclusive( 1, 4 );

		if ( RandomItemsChance == 1 )
		{
			EntityAI wep_attach_1;
			EntityAI wep_attach_2;
			EntityAI wep_M4A1 = item.GetInventory().CreateInInventory( "M4A1_Green" );

			wep_M4A1.GetInventory().CreateAttachment( "M4_CQBBttstck_Green" );
			wep_M4A1.GetInventory().CreateAttachment( "M4_MPHndgrd_Green" );
			wep_M4A1.GetInventory().CreateAttachment( "M4_Suppressor" );
			wep_M4A1.GetInventory().CreateAttachment( "GhillieAtt_Mossy" );
			wep_attach_1 = wep_M4A1.GetInventory().CreateAttachment( "AcogOptic" );
			wep_attach_1.GetInventory().CreateAttachment( "Battery9V" );

			item.GetInventory().CreateInInventory( "Mag_StanagCoupled_30Rnd" ); 
			item.GetInventory().CreateInInventory( "Mag_StanagCoupled_30Rnd" ); 
			item.GetInventory().CreateInInventory( "Mag_StanagCoupled_30Rnd" );

			item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 

			wep_attach_2 = item.GetInventory().CreateInInventory( "M68Optic" );
			wep_attach_2.GetInventory().CreateAttachment( "Battery9V" );
		}

		if ( RandomItemsChance == 2 )
		{
			item.GetInventory().CreateInInventory( "GhillieHood_Mossy" ); 
			item.GetInventory().CreateInInventory( "GhillieSuit_Mossy" );

			item.GetInventory().CreateInInventory( "Rangefinder" );
			item.GetInventory().CreateInInventory( "Binoculars" );
			item.GetInventory().CreateInInventory( "ImprovisedSuppressor" );
		}

		if ( RandomItemsChance == 3 )
		{
			EntityAI wep2_attack_1;
			EntityAI wep2_attack_2;
			EntityAI wep_AKM = item.GetInventory().CreateInInventory( "AKM" );
			wep_AKM.GetInventory().CreateAttachment( "AK_WoodBttstck_Camo" );
			wep_AKM.GetInventory().CreateAttachment( "AK_Bayonet" );
			wep_AKM.GetInventory().CreateAttachment( "AK_WoodHndgrd_Camo" );
			wep_AKM.GetInventory().CreateAttachment( "AK_Suppressor" );
			wep_AKM.GetInventory().CreateAttachment( "GhillieAtt_Mossy" );
			wep2_attack_1 = wep_AKM.GetInventory().CreateAttachment( "PSO1Optic" );
			wep2_attack_1.GetInventory().CreateAttachment( "Battery9V" );

			item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 
			item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 
			item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 

			item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 
			wep2_attack_2 = item.GetInventory().CreateInInventory( "KobraOptic" );
			wep2_attack_2.GetInventory().CreateAttachment( "Battery9V" );
		}

		if ( RandomItemsChance == 4 )
		{
			item.GetInventory().CreateInInventory( "GreatHelm" );
			item.GetInventory().CreateInInventory( "PressVest_Blue" );
		}
	}
	
	TStringArray GrabRandomZombieClass()
	{
		return {
		"ZmbM_Soldier", 
		"ZmbM_SoldierAlice", 
		"ZmbM_SoldierHelmet", 
		"ZmbM_SoldierVest", 
		"ZmbM_SoldierAliceHelmet", 
		"ZmbM_SoldierVestHelmet", 
		"ZmbM_HunterOld_Autumn", 
		"ZmbM_HunterOld_Spring", 
		"ZmbM_HunterOld_Summer", 
		"ZmbM_HunterOld_Winter"};
	}
	
	//Clean up those spooky zombies!
	void DoEventCleanUp(float x, float y, float z, float radius)
	{
		ref array<Object> Ev_Zombies = new array<Object>;
		GetGame().GetObjectsAtPosition( Vector(x,y,z), radius, Ev_Zombies, NULL );

		if ( GetGame() && Ev_Zombies )
		{
			if ( Ev_Zombies.Count() >= 1 ) 
			{
				for ( int i = 0; i < Ev_Zombies.Count(); i++ )
				{
					Object z_ent = Ev_Zombies.Get( i );

					//Zombies
					if ( z_ent.IsInherited(ZombieBase) )
					{
						GetGame().ObjectDelete(z_ent);
					}
					
					/* //Barrels
					if ( z_ent.IsInherited(Barrel_ColorBase) )
					{
						GetGame().ObjectDelete(z_ent);
					}
					
					//SeaChests
					if ( z_ent.GetType() == "SeaChest" )
					{
						GetGame().ObjectDelete(z_ent);
					} */
					
					//Remove Melee, Firearms, Clothing and all other items dropped.
					if ( z_ent.IsWeapon() || z_ent.IsClothing() || z_ent.IsMeleeWeapon() || z_ent.IsMagazine() )  //item.IsMan() && !item.IsAlive()
					{	
						//Print("[DEBUG] - Removed Item "+item.GetType() + " idx = " + i.ToString());
						GetGame().ObjectDelete(z_ent);
					}
				}
			}
		}
	}

	int random_event_chance = 0;
	void StartEvent()
	{	
		if ( random_event_chance == MAX_NUM_OF_EVENTS + 1 )
		{
			random_event_chance = 0;
		}
		random_event_chance++
		int i;

		//Cherno Gas Station.
		if ( random_event_chance == 1 )
		{
			Item_1_Pos = "5811.6 8.96411 2164.76";
			Item_2_Axis = "96.2432 0 0";
			Item_1 = g_Game.CreateObject("Barrel_Blue", Item_1_Pos, false);
			Item_1.SetOrientation(Item_1_Axis);
			CreateContainrItems(Item_1);

			Item_2_Pos = "5823.28 8.96548 2170.91";
			Item_2_Axis = "-122.941 0 0";
			Item_2 = g_Game.CreateObject("Barrel_Green", Item_2_Pos, false);
			Item_2.SetOrientation(Item_2_Axis);
			CreateContainrItems(Item_2);

			Item_3_Pos = "5823.83 8.96395 2162.67";
			Item_3_Axis = "157.911 0 0";
			Item_3 = g_Game.CreateObject("Barrel_Yellow", Item_3_Pos, false);
			Item_3.SetOrientation(Item_3_Axis);
			CreateContainrItems(Item_3);

			//Zombies
			NUM_OF_EVENT_ZOMBIES = 25;
			for ( i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
			{
				g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(5797, 5869), 0, Math.RandomFloatInclusive(2123, 2168)), false, true );
			}

			selected_event = "Gas Station near Cherno!";
			cleanup_vector = Vector( 5818.56, 8.98797, 2165.17 );
			cleanup_radius = 400.0
			NoCleanUp = false;
			LAST_EVENT_NUM = random_event_chance;

			EVENT_NOTIFY_DELAY = 180000;
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Balota AirField NE Hill Across from ATC.
		if ( random_event_chance == 2 )
		{
			//SeaChests
			Item_1_Pos = "5495.72 44.9966 2201.6";
			Item_1_Axis = "147.388 -10.768 5.57808";
			Item_1 = g_Game.CreateObject("SeaChest", Item_1_Pos, false);
			Item_1.SetOrientation(Item_1_Axis);
			CreateContainrItems(Item_1);
	
			Item_2_Pos = "5496.89 45.62 2204.02";
			Item_2_Axis = "84.1955 2.90348 21.2722";
			Item_2 = g_Game.CreateObject("SeaChest", Item_2_Pos, false);
			Item_2.SetOrientation(Item_2_Axis);
			CreateContainrItems(Item_2);
	
			Item_3_Pos = "5491.84 44.5761 2201.03";
			Item_3_Axis = "16.4995 17.5878 -7.2719";
			Item_3 = g_Game.CreateObject("SeaChest", Item_3_Pos, false);
			Item_3.SetOrientation(Item_3_Axis);
			CreateContainrItems(Item_3);

			//Zombies
			NUM_OF_EVENT_ZOMBIES = 25;
			for ( i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
			{
				g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(5483, 5535), 0, Math.RandomFloatInclusive(2215, 2256)), false, true );
			}

			selected_event = "Hill Across from ATC";
			cleanup_vector = Vector( 5495.72, 44.9966, 2201.6 );
			cleanup_radius = 400.0
			NoCleanUp = false;
			LAST_EVENT_NUM = random_event_chance;

			EVENT_NOTIFY_DELAY = 180000;
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Balota Town NW Hill
		if ( random_event_chance == 3 )
			{
			//Barrels
			Item_1_Pos = "4721.31 65.67 2932.7";
			Item_1_Axis = "-50.52 4.11 -14.84";
			Item_1 = g_Game.CreateObject("Barrel_green", Item_1_Pos, false);
			Item_1.SetOrientation(Item_1_Axis);
			Item_1.Open();
			CreateContainrItems(Item_1)
	
			Item_2_Pos = "4720.49 66.05 2934.52";
			Item_2_Axis = "60.41 13.49 8.32";
			Item_2 = g_Game.CreateObject("Barrel_red", Item_2_Pos, false);
			Item_2.SetOrientation(Item_2_Axis);
			Item_2.Open();
			CreateContainrItems(Item_2);

			Item_3_Pos = "4718.26 66.0143 2935.42";
			Item_3_Axis = "-57.3 2.15 -15.21";
			Item_3 = g_Game.CreateObject("Barrel_blue", Item_3_Pos, false);
			Item_3.SetOrientation(Item_3_Axis);
			Item_3.Open();
			CreateContainrItems(Item_3);

			//Zombies
			NUM_OF_EVENT_ZOMBIES = 25;
			for ( i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
			{
				g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(4720, 4822), 0, Math.RandomFloatInclusive(2812, 2915)), false, true );
			}

			selected_event = "Balota Town NW Hill";
			cleanup_vector = Vector( 4721.31, 65.67, 2932.7 );
			cleanup_radius = 400.0
			NoCleanUp = false;
			LAST_EVENT_NUM = random_event_chance;

			EVENT_NOTIFY_DELAY = 180000;
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Balota_Barn_Fields West
		if ( random_event_chance == 4 )
		{
			//SeaChests
			Item_1_Pos = "4258.03 8.07743 2771.52";
			Item_1_Axis = "0.3979 2.22964 -1.19725";
			Item_1 = g_Game.CreateObject("SeaChest", Item_1_Pos, false);
			Item_1.SetOrientation(Item_1_Axis);
			CreateContainrItems(Item_1);

			Item_2_Pos = "4261.77 8.37863 2775.05";
			Item_2_Axis = "-135.114 -3.29099 1.27619";
			Item_2 = g_Game.CreateObject("SeaChest", Item_2_Pos, false);
			Item_2.SetOrientation(Item_2_Axis);
			CreateContainrItems(Item_2);

			Item_3_Pos = "4256.82 8.21078 2776.04";
			Item_3_Axis = "125.984 3.03312 -0.153311";
			Item_3 = g_Game.CreateObject("SeaChest", Item_3_Pos, false);
			Item_3.SetOrientation(Item_3_Axis);
			CreateContainrItems(Item_3);

			//Zombies
			NUM_OF_EVENT_ZOMBIES = 30;
			for ( i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
			{
				g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(4229, 4287), 0, Math.RandomFloatInclusive(2710, 2845)), false, true );
			}

			selected_event = "Balota Town West Field!";
			cleanup_vector = Vector( 4258.03, 8.07743, 2771.52 );
			cleanup_radius = 400.0
			NoCleanUp = false;
			LAST_EVENT_NUM = random_event_chance;

			EVENT_NOTIFY_DELAY = 180000;
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Zombie Overrun Balota Airfield.
		if ( random_event_chance == 5 )
		{
			if ( !FireOnlyOnce )
			{
				//Zombies
				for ( i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
				{
					g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(5000, 5270), 0, Math.RandomFloatInclusive(2333, 2474)), false, true );
				}

				for ( int i_2 = 0; i_2 < NUM_OF_EVENT_ZOMBIES; i_2++ )
				{
					g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(5112, 5340), 0, Math.RandomFloatInclusive(2191, 2224)), false, true );
				}

				for ( int i_3 = 0; i_3 < NUM_OF_EVENT_ZOMBIES; i_3++ )
				{
					g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(4900, 5090), 0, Math.RandomFloatInclusive(2560, 2920)), false, true );
				}

				NoCleanUp = true;
				FireOnlyOnce = true;
				
				//Tell everyone the event is active.
				GetGame().ChatPlayer( 1, "Zombie Horde Spotted!" );
				GetGame().ChatPlayer( 1, "Balota Airfield is overrun!" );
			}
			else
			{
				//Airfield Chest Alternate.
				Item_1_Pos = "5097.79 9.50848 2360.05";
				Item_1_Axis = "-178.671 -0.47595 0.783043";
				Item_1 = g_Game.CreateObject("Barrel_Red", Item_1_Pos, false);
				Item_1.SetOrientation(Item_1_Axis);
				CreateContainrItems(Item_1);

				Item_2_Pos = "5105.22 9.50898 2351";
				Item_2_Axis = "-169.157 -0.593875 0.664015";
				Item_2 = g_Game.CreateObject("Barrel_Green", Item_2_Pos, false);
				Item_2.SetOrientation(Item_2_Axis);
				CreateContainrItems(Item_2);

				Item_3_Pos = "5114.63 9.49881 2360.64";
				Item_3_Axis = "173.049 -0.186891 2.2534";
				Item_3 = g_Game.CreateObject("Barrel_Yellow", Item_3_Pos, false);
				Item_3.SetOrientation(Item_3_Axis);
				CreateContainrItems(Item_3);
				
				//Zombies
				NUM_OF_EVENT_ZOMBIES = 30;
				for ( i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
				{
					g_Game.CreateObject(GrabRandomZombieClass().GetRandomElement(), Vector(Math.RandomFloatInclusive(4229, 4287), 0, Math.RandomFloatInclusive(2710, 2845)), false, true );
				}

				selected_event = "Balota Airfield!";
				cleanup_vector = Vector( 5097.79, 9.50848, 2360.05 );
				cleanup_radius = 400.0
				NoCleanUp = false;
				LAST_EVENT_NUM = random_event_chance;

				EVENT_NOTIFY_DELAY = 180000;
				AnnounceEvent(selected_event);
				GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
			}
		}
	}

	void CleanUp()
	{
		if ( NoCleanUp == true ) return;
		
		DoEventCleanUp( cleanup_vector[0], cleanup_vector[1], cleanup_vector[2], cleanup_radius )
	}

	void EndEvent()
	{
		CleanUp();
		GetGame().ChatPlayer( 1, "Gear Cache Expired!" );
		GetGame().ChatPlayer( 1, "Next Gear Cache in 2 mins!" );
	}
}

