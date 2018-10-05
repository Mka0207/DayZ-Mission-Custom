#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_CacheStatics.c"

class Event
{
	
	float Mission_FloatTime = 0.0;

	const float EVENT_START_INTERVAL = 120;
	const float EVENT_END_INTERVAL = 900;
	
	bool IsEventRunning = false;
	
	ref RandomEvent m_CurrentEvent = new RandomEvent();

	void Event()
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
			m_CurrentEvent.StartEvent()
			IsEventRunning = true;
			Mission_FloatTime = 0;
		}

		if ( Mission_FloatTime > EVENT_END_INTERVAL && IsEventRunning )
        {
            m_CurrentEvent.EndEvent()
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
	bool FireOnlyOnce;
	bool NoCleanUp;

	void RandomEvent()
	{
		Init();
	}
	
	void Init()
	{

	}

	int TimesAdverted = 0;
	void AnnounceEvent(string EventLocation)
	{
		if ( EventLocation )
		{
			TimesAdverted = TimesAdverted + 1
			
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

	void StartEvent()
	{	
		int random_event_chance = Math.RandomIntInclusive( 1, 4 );
		int i;

		//Cherno Gas Station.
		if ( random_event_chance == 1 )
		{
			ItemBase m_barrel;
			vector Barrel_Vect = "5811.6 8.96411 2164.76";
			vector Barrel_Axis = "96.2432 0 0";
			m_barrel = g_Game.CreateObject("Barrel_Blue", Barrel_Vect, false);
			m_barrel.SetOrientation(Barrel_Axis);
			CreateContainrItems_1(m_barrel);

			ItemBase m_barrel_g;
			vector BarrelG_Vect = "5823.28 8.96548 2170.91";
			vector BarrelG_Axis = "-122.941 0 0";
			m_barrel_g = g_Game.CreateObject("Barrel_Green", BarrelG_Vect, false);
			m_barrel_g.SetOrientation(BarrelG_Axis);
			CreateContainrItems_2(m_barrel_g);

			ItemBase m_barrel_y;
			vector BarrelY_Vect = "5823.83 8.96395 2162.67";
			vector BarrelY_Axis = "157.911 0 0";
			m_barrel_y = g_Game.CreateObject("Barrel_Yellow", BarrelY_Vect, false);
			m_barrel_y.SetOrientation(BarrelY_Axis);
			CreateContainrItems_3(m_barrel_y);

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

			EVENT_NOTIFY_DELAY = 180000;
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Balota AirField NE Hill Across from ATC.
		if ( random_event_chance == 2 )
		{
			//SeaChests
			ItemBase m_heli_chest1;
			vector m_heli_chest1_Pos = "5495.72 44.9966 2201.6";
			vector m_heli_chest1_Axis = "147.388 -10.768 5.57808";
			m_heli_chest1 = g_Game.CreateObject("SeaChest", m_heli_chest1_Pos, false);
			m_heli_chest1.SetOrientation(m_heli_chest1_Axis);
			CreateContainrItems_1(m_heli_chest1);
	
			ItemBase m_heli_chest2;
			vector m_heli_chest2_Pos = "5496.89 45.62 2204.02";
			vector m_heli_chest2_Axis = "84.1955 2.90348 21.2722";
			m_heli_chest2 = g_Game.CreateObject("SeaChest", m_heli_chest2_Pos, false);
			m_heli_chest2.SetOrientation(m_heli_chest2_Axis);
			CreateContainrItems_2(m_heli_chest2);
	
			ItemBase m_heli_chest3;
			vector m_heli_chest3_Pos = "5491.84 44.5761 2201.03";
			vector m_heli_chest3_Axis = "16.4995 17.5878 -7.2719";
			m_heli_chest3 = g_Game.CreateObject("SeaChest", m_heli_chest3_Pos, false);
			m_heli_chest3.SetOrientation(m_heli_chest3_Axis);
			CreateContainrItems_3(m_heli_chest3);

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

			EVENT_NOTIFY_DELAY = 180000
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Balota Town NW Hill
		if ( random_event_chance == 3 )
			{
			//Barrels
			ItemBase m_Barrel_1;
			vector Bar1_Pos = "4721.31 65.67 2932.7";
			vector Bar1_Axis = "-50.52 4.11 -14.84";
			m_Barrel_1 = g_Game.CreateObject("Barrel_green", Bar1_Pos, false);
			m_Barrel_1.SetOrientation(Bar1_Axis);
			m_Barrel_1.Open();
			CreateContainrItems_1(m_Barrel_1)
	
			ItemBase m_Barrel_2;
			vector Bar2_Pos = "4720.49 66.05 2934.52";
			vector Bar2_Axis = "60.41 13.49 8.32";
			m_Barrel_2 = g_Game.CreateObject("Barrel_red", Bar2_Pos, false);
			m_Barrel_2.SetOrientation(Bar2_Axis);
			m_Barrel_2.Open();
			CreateContainrItems_2(m_Barrel_2);
	
			ItemBase m_Barrel_3;
			vector Bar3_Pos = "4718.26 66.0143 2935.42";
			vector Bar3_Axis = "-57.3 2.15 -15.21";
			m_Barrel_3 = g_Game.CreateObject("Barrel_blue", Bar3_Pos, false);
			m_Barrel_3.SetOrientation(Bar3_Axis);
			m_Barrel_3.Open();
			CreateContainrItems_3(m_Barrel_3);

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

			EVENT_NOTIFY_DELAY = 180000
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Balota_Barn_Fields West
		if ( random_event_chance == 4 )
		{
			//SeaChests
			ItemBase m_seachest_1;
			vector Chest1_Pos = "4258.03 8.07743 2771.52";
			vector Chest1_Axis = "0.3979 2.22964 -1.19725";
			m_seachest_1 = g_Game.CreateObject("SeaChest", Chest1_Pos, false);
			m_seachest_1.SetOrientation(Chest1_Axis);
			CreateContainrItems_1(m_seachest_1);

			ItemBase m_seachest_2;
			vector Chest2_Pos = "4261.77 8.37863 2775.05";
			vector Chest2_Axis = "-135.114 -3.29099 1.27619";
			m_seachest_2 = g_Game.CreateObject("SeaChest", Chest2_Pos, false);
			m_seachest_2.SetOrientation(Chest2_Axis);
			CreateContainrItems_2(m_seachest_2);

			ItemBase m_seachest_3;
			vector Chest3_Pos = "4256.82 8.21078 2776.04";
			vector Chest3_Axis = "125.984 3.03312 -0.153311";
			m_seachest_3 = g_Game.CreateObject("SeaChest", Chest3_Pos, false);
			m_seachest_3.SetOrientation(Chest3_Axis);
			CreateContainrItems_3(m_seachest_3);
			
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

			EVENT_NOTIFY_DELAY = 180000
			AnnounceEvent(selected_event);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(AnnounceEvent, EVENT_NOTIFY_DELAY, true, selected_event);
		}

		//Zombie Overrun Balota Airfield.
		/* if ( random_event_chance == 5 )
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
			
			//Tell everyone the event is active.
			GetGame().ChatPlayer( 1, "Zombie Horde Spotted!" );
			GetGame().ChatPlayer( 1, "Balota Airfield is overrun!" );
		} */
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

