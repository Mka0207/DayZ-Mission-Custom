//Event system by mka0207@fwkzt.com

class Event
{
    //How much time in secs before each mission starts(must always be lower than misson_end).
    const float MISSION_DELAY_INTERVAL = 10;

    //How much time in secs to and see if all zombies have been killed so the mission will be forced to end.
    //const float MISSION_END_CHECK = 60;

    //How much time in secs before each mission ends(must always be higher than mission_delay).
    const float MISSION_END_INTERVAL = 60;

    //Basically the 'fat' version of the mission end interval, used for the cleanup timers.
    //const float MISSION_END_FAT = 60000;

    //Defauls, don't touch.
    float Mission_StartTime = 0.0;
    float Mission_FloatTime = 0.0;
    float Mission_EndTime = 0.0;
    bool IsEventRunning = false;

    //Sheduler
	float m_LastTick = -1;

    //Should be the number of events you have made in total.
    int NumberOfEvents = 1;

    //math used to get a random event.
    int Random_Selector = Math.RandomIntInclusive( 1, NumberOfEvents );

    int ZombiesLeftAlive;

    void Event()
	{	
		Init();
	}
	
	void Init()
	{	
        //
    }

   /*  int ReturnZombieCount(float x, float y, float z, float radius)
    {
        ref array<Object> Ev_Zombies = new array<Object>;
        GetGame().GetObjectsAtPosition( Vector(x,y,z), radius, Ev_Zombies, NULL );

        int zed_count = 0;

        if ( GetGame() && Ev_Zombies )
        {
            if ( Ev_Zombies.Count() >= 1 ) 
            {
                for ( int i = 0; i < Ev_Zombies.Count(); i++ )
                {
                    Object z_ent = Ev_Zombies.Get( i );
                    if ( z_ent.GetType() == "ZmbM_HunterOld_Autumn" )
                    {
                        //GetGame().ObjectDelete(z_ent);
                        zed_count++
                    }
                }
            }
        }

        return zed_count;
    } */

    ref Cherno_Gas_Station m_CurrentEvent_1; 
    ref Balota_Barn_Fields m_CurrentEvent_2; 

    //The brain of our system.
    void RandomEventTick(float timeslice)
    {
        Mission_FloatTime += timeslice;
        
        if ( Mission_FloatTime > MISSION_DELAY_INTERVAL && !IsEventRunning )
        {
            if ( Random_Selector == 1 )
            {
                m_CurrentEvent_1 = new Cherno_Gas_Station(); 
                m_CurrentEvent_1.StartMission();
            }

			if ( Random_Selector == 2 )
			{
                m_CurrentEvent_2 = new Balota_Barn_Fields();
                m_CurrentEvent_2.StartMission();
			}

            IsEventRunning = true;
			Mission_FloatTime = 0;
        }

        /* if ( IsEventRunning )
        {
            Mission_StartTime += timeslice;
        } */

        /* if ( Mission_StartTime > MISSION_END_CHECK )
        {
            Mission_StartTime = 0;
            vector AreaToCheck = m_CurrentEvent.Central_Mission_Pos;
            float x = m_CurrentEvent.Central_Mission_Pos[0];
            float y = m_CurrentEvent.Central_Mission_Pos[1];
            float z = m_CurrentEvent.Central_Mission_Pos[2];

            if ( ReturnZombieCount(x, y, z, 200.0) == 0 )
            {
               EndMission();
            }
        } */
        
        if ( Mission_FloatTime > MISSION_END_INTERVAL && IsEventRunning )
        {
            EndMission();
        }
    }

    void EndMission()
    {
        Mission_FloatTime = 0;
        GetGame().ChatPlayer( 0, "Mission Ended!" );
        IsEventRunning = false;
    }

}

class DefaultEvent extends Event
{
	//Chance of the event happening.
    int Event_Chance;

    //How many zombies should spawn on the event.
    int NUM_OF_EVENT_ZOMBIES;

    //How much time in secs before the ents are removed ( 1000 = 1 second ).
    int MISSION_RESET_INTERVAL = 60000;

    //Central Pos to check for zombie count.
    //vector Central_Mission_Pos;

    void DefaultEvent()
	{	
		Init();
	}
	
	void Init()
	{	
        //
    }

    void StartMission()
    {
       //Custom Stuff
    }
}

static void CreateFlareEnt(float x, float y, float z, float yaw, float pitch, float roll)
{
    ItemGrenade m_Flare;
    m_Flare = g_Game.CreateObject("RDG2SmokeGrenade_Black", Vector(x, y, z), false);
    m_Flare.SetOrientation(Vector(yaw, pitch, roll));
    
    //Turn the smoke on.
    m_Flare.GetCompEM().SwitchOn();	
}

static void DestroyFlareEnt()
{
    GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(CreateFlareEnt);
}

class Cherno_Gas_Station extends DefaultEvent
{

    override void Init()
	{	
        Event_Chance = 1;

        NUM_OF_EVENT_ZOMBIES = 5;

        //Central_Mission_Pos = Vector(5818.56, 8.98797, 2165.17);

        //MISSION_RESET_INTERVAL = 90000;
    }

    override void StartMission()
    {
       // super.StartMission();

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
        for ( int i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
        {
            g_Game.CreateObject("ZmbM_HunterOld_Autumn", Vector(Math.RandomFloatInclusive(5797, 5869), 0, Math.RandomFloatInclusive(2123, 2168)), false, true );
        }
        
        //Cleanup
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(DestroyFlareEnt, MISSION_RESET_INTERVAL, false);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel_g);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_barrel_y);
        
        //Tell everyone the event is active.
        GetGame().ChatPlayer( 0, "Mission Sighted!" );
        GetGame().ChatPlayer( 0, "East of Balota!" );
    }
}

class Balota_Barn_Fields extends DefaultEvent
{
	override void Init()
	{	
        Event_Chance = 2;

        NUM_OF_EVENT_ZOMBIES = 50;

        //Central_Mission_Pos = Vector(5818.56, 8.98797, 2165.17);

        //MISSION_RESET_INTERVAL = 60000;
    }
	
    override void StartMission()
    {
        //super.StartMission();

       //Removal Timer for the flare ( sorta hacky way to make use of it ).
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
        for ( int i = 0; i < NUM_OF_EVENT_ZOMBIES; i++ )
        {
            g_Game.CreateObject("ZmbM_HunterOld_Autumn", Vector(Math.RandomFloatInclusive(4229, 4287), 0, Math.RandomFloatInclusive(2710, 2845)), false, true );
        }
        
        //Cleanup
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_seachest_1);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_seachest_2);
        GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetGame().ObjectDelete, MISSION_RESET_INTERVAL, false, m_seachest_3);
        
        //Tell everyone the event is active.
        GetGame().ChatPlayer( 0, "Mission Spotted!" );
        GetGame().ChatPlayer( 0, "North West of Balota!" );
    }
}