//Event system by mka0207@fwkzt.com

//How much time in secs before the mission items/ai are deleted.
int MISSION_RESET_INTERVAL = 90000;

//How much time in secs before the mission starts(must always be lower than misson_end).
float MISSION_DELAY_INTERVAL = 30;

//How much time in secs before the mission ends(must always be higher than mission_delay).
float MISSION_END_INTERVAL = 90;

//Defauls, don't touch.
float Mission_FloatTime = 0.0;
float Mission_EndTime = 0.0;
bool IsEventRunning = false;

//todo, figure out a way to streamline this for other missions for xyz pos/axis.
void CreateFlareEnt()
{
	if ( IsEventRunning )
	{
		ItemGrenade m_Flare;
		vector Flare_Pos = "5818.56 8.98797 2165.17";
		vector Flare_Axis = "2 -1.09999 -4.44645";
		m_Flare = g_Game.CreateObject("RDG2SmokeGrenade_Black", Flare_Pos, false);
		m_Flare.SetOrientation(Flare_Axis);
		
		//Turn the smoke on.
		m_Flare.GetCompEM().SwitchOn();	
	}
	else
	{
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(CreateFlareEnt);
	}
}
	
void RandomEventTick(float timeslice)
{
	Mission_FloatTime += timeslice;
	
	if ( Mission_FloatTime > MISSION_DELAY_INTERVAL && !IsEventRunning )
	{
		Mission_FloatTime = 0;
		int Event_Chance = 1; //Math.RandomIntInclusive( 1, 10 )
		if ( Event_Chance == 1 )
		{
			Event_Cache_Cherno_GasStation();
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
		CreateFlareEnt();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CreateFlareEnt, 6700, true);
		
		//Zombies
		EntityAI m_zombie;
		float zombies_x;
		float zombies_y = 0;
		float zombies_z;
		//vector Zvector = "5831.98 0 2164.67";
		for ( int i = 0; i < 7; i++ )
		{
			zombies_x = Math.RandomFloatInclusive(5797, 5869);
			zombies_z = Math.RandomFloatInclusive(2123, 2168);
			m_zombie = g_Game.CreateObject("ZmbM_HunterOld_Autumn", Vector(zombies_x, zombies_y, zombies_z), false, true );
		}
		
		//Cleanup
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(m_zombie.Delete, MISSION_RESET_INTERVAL, false);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel_g);
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel_y);
		
		//Tell everyone the event is active.
		GetGame().ChatPlayer( 1, "Gear Cache Active!" );
		GetGame().ChatPlayer( 1, "Sighted West of Cherno!" );
		
		IsEventRunning = true;
	}	
}