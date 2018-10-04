//Event system by mka0207@fwkzt.com

#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_CacheMissions.c"

class Event
{
    //How much time in secs before each mission starts(must always be lower than misson_end).
    const float MISSION_DELAY_INTERVAL = 300;

    //How much time in secs to and see if all zombies have been killed so the mission will be forced to end.
    //const float MISSION_END_CHECK = 60;

    //How much time in secs before each mission ends(must always be higher than mission_delay).
    const float MISSION_END_INTERVAL = 900;

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
    int NumberOfEvents = 5;

    int m_LastMission = 0;
    
    bool FireOnlyOnce = false;

    bool DebugMode = false;

    //int ZombiesLeftAlive;
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

	//Reference the objects here.
    ref Cherno_Gas_Station m_CurrentEvent_1; 
    ref Balota_Barn_Fields m_CurrentEvent_2; 
    ref Airfield_ZombieEvent m_CurrentEvent_3;
    ref Balota_Crash_NW m_CurrentEvent_4;
    ref Balota_Crash_NE m_CurrentEvent_5;

    //The brain of our system.
    void RandomEventTick(float timeslice)
    {
        Mission_FloatTime += timeslice;
        
        if ( Mission_FloatTime > MISSION_DELAY_INTERVAL && !IsEventRunning )
        {
            int Random_Selector = Math.RandomIntInclusive( 5, 5 );

            if ( Random_Selector == m_LastMission )
            {
                Mission_FloatTime = 0;
            }

            if ( Random_Selector == 1 )
            {
                m_CurrentEvent_1 = new Cherno_Gas_Station(); 
                m_CurrentEvent_1.StartMission();
                m_LastMission = Random_Selector;
                IsEventRunning = true;
                Mission_FloatTime = 0;
            }

            if ( Random_Selector == 2 )
            {
                m_CurrentEvent_2 = new Balota_Barn_Fields();
                m_CurrentEvent_2.StartMission();
                m_LastMission = Random_Selector;
                IsEventRunning = true;
                Mission_FloatTime = 0;
            }

            if ( Random_Selector == 3 && !FireOnlyOnce )
            {
                m_CurrentEvent_3 = new Airfield_ZombieEvent();
                m_CurrentEvent_3.StartMission();
                FireOnlyOnce = true;
                //IsEventRunning = true;
                Mission_FloatTime = 0;
            }
            
            if ( Random_Selector == 3 && FireOnlyOnce )
            {
                Mission_FloatTime = 0;
            }

            if ( Random_Selector == 4 )
            {
                m_CurrentEvent_4 = new Balota_Crash_NW();
                m_CurrentEvent_4.StartMission();
                m_LastMission = Random_Selector;
                IsEventRunning = true;
                Mission_FloatTime = 0;
            }

            if ( Random_Selector == 5 )
            {
                m_CurrentEvent_5 = new Balota_Crash_NE();
                m_CurrentEvent_5.StartMission();
                m_LastMission = Random_Selector;
                IsEventRunning = true;
                Mission_FloatTime = 0;
            }
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
        GetGame().ChatPlayer( 0, "Gear Cache in 5 mins!" );
        IsEventRunning = false;
    }

}

class DefaultEvent extends Event
{
	//Chance of the event happening.
    int Event_Chance;

    //How many zombies should spawn on the event.
    int NUM_OF_EVENT_ZOMBIES;

    //How much time in secs before the ents are removed, must match the misson_end interval. ( 1000 = 1 second ).
    int MISSION_RESET_INTERVAL = 900000;

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