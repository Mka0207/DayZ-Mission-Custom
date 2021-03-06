#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Spawns.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Buildings.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Loadouts.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Adverts.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_CacheBase.c"

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
	ref CustomEventsSurvival curr_event;
	
	void CustomMission()
	{
		curr_event = new CustomEventsSurvival();
	}
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		TVectorArray Spawn_Location_Table = GetRandomSpawn();
		playerEnt = GetGame().CreatePlayer(identity, characterName, Spawn_Location_Table.GetRandomElement(), 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		player.RemoveAllItems();
		OnSpawnCallback(player);
	}
	
	override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
	{
		// note: player is now killed in db right after the actual kill happens 
		/* if (GetHive() && player)
		{
			GetHive().CharacterKill(player);
		} */
		if(player)
		{
			if (player.IsUnconscious() || player.IsRestrained())
			{
				// kill character
				player.SetHealth("", "", 0.0);
			}
		}
	}
	
	override void PlayerDisconnected(PlayerBase player, PlayerIdentity identity, string uid)
	{
		// Note: At this point, identity can be already deleted
		if (!player)
		{
			Print("[Logout]: Skipping player " + uid + ", already removed");
			return;
		}
		
		Print("[Logout]: Player " + uid + " finished");

		if (GetHive())
		{
			// save player
			player.Save();
			
			// unlock player in DB	
			GetHive().CharacterExit(player);		
		}
		
		//HandleBody(player);
		player.Delete();
		
		// remove player from server
		GetGame().DisconnectPlayer(identity, uid);
	}
	
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate( timeslice );
	
		//Custom
		curr_event.OnEventTick(timeslice);
		OnTickAdverts( timeslice );
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}