#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Spawns.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Buildings.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Loadouts.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Adverts.c"

void main()
{

	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 0.0 );
	weather.GetFog().SetLimits( 0.0 , 0.25 );

	weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
	weather.GetRain().SetForecastChangeLimits( 0.0, 0.0 );
	weather.GetFog().SetForecastChangeLimits( 0.15, 0.45 );

	weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
	weather.GetRain().SetForecastTimeLimits( 0 , 0 );
	weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( 0, 0, 0 );
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	weather.SetWindMaximumSpeed(15);
	weather.SetWindFunctionParams(0.1, 0.3, 50);
	
	AddBuildings();
}

class CustomMission: MissionServer
{	
	void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		//TVectorArray Spawn_Location_Table = GetRandomDMSpawnTable();
		//Spawn_Location_Table.GetRandomElement()
		playerEnt = GetGame().CreatePlayer(identity, characterName, GetRandomSpawn(), 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		OnSpawnCallback(player)
	}
	
	override void TickScheduler(float timeslice)
	{
		GetGame().GetWorld().GetPlayerList(m_Players);
		if( m_Players.Count() == 0 ) return;
		for(int i = 0; i < SCHEDULER_PLAYERS_PER_TICK; i++)
		{
			if(m_currentPlayer >= m_Players.Count() )
			{
				m_currentPlayer = 0;
			}
			//PrintString(m_currentPlayer.ToString());
			PlayerBase currentPlayer = PlayerBase.Cast(m_Players.Get(m_currentPlayer));
			
			currentPlayer.OnTick();
			m_currentPlayer++;
		}
		
		//Custom
		OnTickAdverts( timeslice );
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}