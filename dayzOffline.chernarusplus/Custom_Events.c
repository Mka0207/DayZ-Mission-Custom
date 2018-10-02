//Event system by mka0207@fwkzt.com

//How much time in secs before the mission items/ai are deleted.
int MISSION_RESET_INTERVAL = 150000;

//How much time in secs before the mission starts(must always be lower than misson_end).
float MISSION_DELAY_INTERVAL = 30;

//How much time in secs before the mission ends(must always be higher than mission_delay).
float MISSION_END_INTERVAL = 150;

//Defauls, don't touch.
float Mission_FloatTime = 0.0;
float Mission_EndTime = 0.0;
bool IsEventRunning = false;

//Create our neat flare!
void CreateFlareEnt(float x, float y, float z, float yaw, float pitch, float roll)
{
	if ( IsEventRunning )
	{
		ItemGrenade m_Flare;
		m_Flare = g_Game.CreateObject("RDG2SmokeGrenade_Black", Vector(x, y, z), false);
		m_Flare.SetOrientation(Vector(yaw, pitch, roll));
		
		//Turn the smoke on.
		m_Flare.GetCompEM().SwitchOn();	
	}
	else
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(CreateFlareEnt);
	}
}

//Clean up those spooky zombies!
void CleanUpZombies(float x, float y, float z, float radius)
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
				if ( z_ent.GetType() == "ZmbM_HunterOld_Autumn" )
				{
					GetGame().ObjectDelete(z_ent)
				}
			}
		}
	}
}

//The brain of our system.
void RandomEventTick(float timeslice)
{
	Mission_FloatTime += timeslice;
	
	if ( Mission_FloatTime > MISSION_DELAY_INTERVAL && !IsEventRunning )
	{
		Mission_FloatTime = 0;
		int Event_Chance = Math.RandomIntInclusive( 1, 2 );

		if ( Event_Chance == 1 )
		{
			Event_Cache_Cherno_GasStation();
		}

		if ( Event_Chance == 2 ) 
		{
			Event_Cache_Balota_ChurchFields();
		}
	}
	
	if ( Mission_FloatTime > MISSION_END_INTERVAL && IsEventRunning )
	{
		Mission_FloatTime = 0;
		GetGame().ChatPlayer( 1, "Gear Cache Completed!" )
		IsEventRunning = false;
	}
}

//Special contained event ( all custom to each area! )
void Event_Cache_Cherno_GasStation()
{
	if ( !IsEventRunning )
	{
		Barrel_ColorBase m_barrel;
		vector Barrel_Vect = "5811.6 8.96411 2164.76";
		vector Barrel_Axis = "96.2432 0 0";
		m_barrel = g_Game.CreateObject("Barrel_Blue", Barrel_Vect, false);
		m_barrel.SetOrientation(Barrel_Axis);
		
		Barrel_ColorBase m_barrel_g;
		vector BarrelG_Vect = "5823.28 8.96548 2170.91";
		vector BarrelG_Axis = "-122.941 0 0";
		m_barrel_g = g_Game.CreateObject("Barrel_Green", BarrelG_Vect, false);
		m_barrel_g.SetOrientation(BarrelG_Axis);
		
		Barrel_ColorBase m_barrel_y;
		vector BarrelY_Vect = "5823.83 8.96395 2162.67";
		vector BarrelY_Axis = "157.911 0 0";
		m_barrel_y = g_Game.CreateObject("Barrel_Yellow", BarrelY_Vect, false);
		m_barrel_y.SetOrientation(BarrelY_Axis);
		
		//Removal Timer for the flare ( sorta hacky way to make use of it ).
		CreateFlareEnt(5818.56, 8.98797, 2165.17, 2, -1.09999, -4.44645);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CreateFlareEnt, 6700, true, 5818.56, 8.98797, 2165.17, 2, -1.09999, -4.44645);
		
		//Zombies
		EntityAI m_zombie;
		float zombies_x;
		float zombies_y = 0;
		float zombies_z;

		int NUM_OF_EVENT_ZOMBIES = 50;
		for ( int i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
		{
			zombies_x = Math.RandomFloatInclusive(5797, 5869);
			zombies_z = Math.RandomFloatInclusive(2123, 2168);
			m_zombie = g_Game.CreateObject("ZmbM_HunterOld_Autumn", Vector(zombies_x, zombies_y, zombies_z), false, true );
		}
		
		//Cleanup
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CleanUpZombies, MISSION_RESET_INTERVAL, false, Math.RandomFloatInclusive(5797, 5869), 0, Math.RandomFloatInclusive(2123, 2168), 250.0);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel_g);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel_y);
		
		//Tell everyone the event is active.
		GetGame().ChatPlayer( 1, "Gear Cache Spotted!" );
		GetGame().ChatPlayer( 1, "East of Balota" );
		
		IsEventRunning = true;
	}	
}

//Special contained event ( all custom to each area! )
void Event_Cache_Balota_ChurchFields()
{
	if ( !IsEventRunning )
	{
		//Removal Timer for the flare ( sorta hacky way to make use of it ).
		vector Flare_Pos = "4259.18 8.31229 2773.94";
		vector Flare_Axis = "26.8815 2.5061 5.20263";
		CreateFlareEnt(4259.18, 8.31229, 2773.94, 26.8815, 2.5061, 5.20263);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CreateFlareEnt, 6700, true, 4259.18, 8.31229, 2773.94, 26.8815, 2.5061, 5.20263);

		//SeaChests
		ItemBase m_seachest_1;
		vector Chest1_Pos = "4258.03 8.07743 2771.52";
		vector Chest1_Axis = "0.3979 2.22964 -1.19725";
		m_seachest_1 = g_Game.CreateObject("SeaChest", Chest1_Pos, false);
		m_seachest_1.SetOrientation(Chest1_Axis);

		ItemBase m_seachest_2;
		vector Chest2_Pos = "4261.77 8.37863 2775.05";
		vector Chest2_Axis = "-135.114 -3.29099 1.27619";
		m_seachest_2 = g_Game.CreateObject("SeaChest", Chest2_Pos, false);
		m_seachest_2.SetOrientation(Chest2_Axis);

		ItemBase m_seachest_3;
		vector Chest3_Pos = "4256.82 8.21078 2776.04";
		vector Chest3_Axis = "125.984 3.03312 -0.153311";
		m_seachest_3 = g_Game.CreateObject("SeaChest", Chest3_Pos, false);
		m_seachest_3.SetOrientation(Chest3_Axis);
		
		//Zombies
		EntityAI m_zombie;
		float zombies_x;
		float zombies_y = 0;
		float zombies_z;
		
		int NUM_OF_EVENT_ZOMBIES = 50;
		for ( int i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
			zombies_x = Math.RandomFloatInclusive(4229, 4287);
			zombies_z = Math.RandomFloatInclusive(2710, 2845);
			m_zombie = g_Game.CreateObject("ZmbM_HunterOld_Autumn", Vector(zombies_x, zombies_y, zombies_z), false, true );
		}
		
		//Cleanup
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CleanUpZombies, MISSION_RESET_INTERVAL, false, Math.RandomFloatInclusive(5797, 5869), 0, Math.RandomFloatInclusive(2123, 2168), 250.0);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_seachest_1);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_seachest_2);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_seachest_3);
		
		//Tell everyone the event is active.
		GetGame().ChatPlayer( 1, "Gear Cache Spotted!" );
		GetGame().ChatPlayer( 1, "North West of Balota!" );
		
		IsEventRunning = true;
	}	
}