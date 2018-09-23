#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Spawns.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Buildings.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Custom_Loadouts.c"

void main()
{
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.0 , 0.25 );

	weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
	weather.GetRain().SetForecastChangeLimits( 0.0, 0.1 );
	weather.GetFog().SetForecastChangeLimits( 0.15, 0.45 );

	weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
	weather.GetRain().SetForecastTimeLimits( 600 , 600 );
	weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );

	/* weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0); */
	
	weather.GetOvercast().Set( 0, 0, 0 );
	weather.GetRain().Set( 0, 0, 0 );
	weather.GetFog().Set( 0, 0, 0 ); 
	
	weather.SetWindMaximumSpeed(17);
	weather.SetWindFunctionParams(0.1, 0.3, 50);

	//Custom Stuff
	AddBuildings();
}

//Create Random Spawn Locations!
TVectorArray Spawn_Location_Table = GetRandomDMSpawnTable();

class CustomMission: MissionServer
{	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		
		playerEnt = GetGame().CreatePlayer(identity, characterName, Spawn_Location_Table.GetRandomElement(), 0, "NONE"); //Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		//Remove vanilla default clothing.
		player.RemoveAllItems();
		
		//Run our callback.
		OnSpawnCallback(player);
	}
	
	override void OnClientRespawnEvent(PlayerIdentity identity, PlayerBase player)
	{
		// note: player is now killed in db right after the actual kill happens 
		/*if (GetHive() && player)
		{
			GetHive().CharacterKill(player);
		}*/
		
		if(player)
		{
			if (player.IsUnconscious() || player.IsRestrained())
			{
				// kill character
				player.SetHealth("", "", 0.0);
			}
			
			// remove the body after disconnect for deathmatch.
			player.Delete();
		}
	}
	
	override void HandleBody(PlayerBase player)
	{
		if (player.IsAlive() && !player.IsRestrained() && !player.IsUnconscious())
		{
			// remove the body
			player.Delete();	
		}
		else if (player.IsUnconscious() || player.IsRestrained())
		{
			// kill character
			player.SetHealth("", "", 0.0);
			
			// remove the body after disconnect for deathmatch.
			player.Delete();
		}
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}