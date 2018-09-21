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

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	weather.SetWindMaximumSpeed(15);
	weather.SetWindFunctionParams(0.1, 0.3, 50);
}

class CustomMission: MissionServer
{	

	PlayerBase m_oPlayer;
	
	void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}
	
	vector GetCursorPos()
	{
		vector rayStart = GetGame().GetCurrentCameraPosition();
		vector rayEnd = rayStart + GetGame().GetCurrentCameraDirection() * 10000;
		vector hitPos;
		vector hitNormal;
		int hitComponentIndex;
		DayZPhysics.RaycastRV(rayStart, rayEnd, hitPos, hitNormal, hitComponentIndex, NULL, NULL, m_oPlayer);

		return hitPos;
	}
	
	/* override void OnKeyPress( int key )
	{
		super.OnKeyPress(key);
		
		if ( key == KeyCode.KC_N )
		{
			TStringArray attArr = {
			"CivSedanWheel","CivSedanWheel","CivSedanWheel","CivSedanWheel",
			"CarBattery","CarRadiator","EngineBelt","SparkPlug","CivSedanHood",
			"CivSedanTrunk","CivSedanDoors_Driver","CivSedanDoors_CoDriver",
			"CivSedanDoors_BackLeft","CivSedanDoors_BackRight",
			}; 
			
			EntityAI oCar = EntityAI.Cast( GetGame().CreateObject( "CivilianSedan", GetCursorPos(), false, true ) );
			
			for (int j = 0; j < attArr.Count(); j++) { oCar.GetInventory().CreateAttachment( attArr.Get(j) ); }
			
			oCar.SetAllowDamage( false );
		}
	} */
	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
/*
		player.RemoveAllItems();

		EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
*/
		//Remove vanilla default clothing.
		player.RemoveAllItems()
		
		EntityAI itemEnt;
		ItemBase itemBs;
		
		/* itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(4);
		SetRandomHealth(itemEnt); */

		/* itemEnt = player.GetInventory().CreateInInventory("RoadFlare");
		itemBs = ItemBase.Cast(itemEnt) */;
		
		//Starter Clothing
		itemEnt = player.GetInventory().CreateInInventory( "M65Jacket_Black" );
		itemEnt = player.GetInventory().CreateInInventory( "BallisticHelmet_Black" );
		itemEnt = player.GetInventory().CreateInInventory( "CargoPants_Black" );
		
		switch ( Math.RandomInt(0, 5) ) {
			case 0:
				//M4A1
				itemEnt = player.GetInventory().CreateInInventory( "M4A1_Black" );
				//itemEnt.GetInventory().CreateAttachment( "M4_Suppressor" );
				itemEnt.GetInventory().CreateAttachment( "M4_RISHndgrd_Black" );
				itemEnt.GetInventory().CreateAttachment( "M4_MPBttstck_Black" );
				itemEnt.GetInventory().CreateAttachment( "ACOGOptic" );
				
				itemEnt = player.GetInventory().CreateInInventory( "M68Optic" );
				itemEnt.GetInventory().CreateAttachment( "Battery9V" );
				
				player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" ); 
				player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" ); 
				
				player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
				player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
				player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
				player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
				
				//EXTRA
				itemEnt = player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
			break;
			case 1:
				//MOSIN
				itemEnt = player.GetInventory().CreateInInventory( "Mosin9130" );
				//itemEnt.GetInventory().CreateAttachment( "Mosin_Compensator" );
				itemEnt.GetInventory().CreateAttachment( "PUScopeOptic" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				
				//FNX
				itemEnt = player.GetInventory().CreateInInventory( "FNX45" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				
				//EXTRA
				itemEnt = player.GetInventory().CreateInInventory( "BallisticVest" );
			break;
			case 2:
				//SVD
				itemEnt = player.GetInventory().CreateInInventory( "SVD" );
				itemEnt.GetInventory().CreateAttachment( "PSO1Optic" );
				//auto oMag = player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
				player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
				player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
				player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
				player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				player.GetInventory().CreateInInventory( "Ammo_762x54" );
				//player.GetWeaponManager().AttachMagazine( oMag ); 
				
				//FNX
				itemEnt = player.GetInventory().CreateInInventory( "FNX45" );
				itemEnt.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				
				//Extra
				itemEnt = player.GetInventory().CreateInInventory( "HighCapacityVest_Black" )
				itemEnt = player.GetInventory().CreateInInventory( "Battery9V" )
			break;
			case 3:
				//MPK
				itemEnt = player.GetInventory().CreateInInventory( "MP5K" );
				itemEnt.GetInventory().CreateAttachment( "MP5_PlasticHndgrd" );
				itemEnt.GetInventory().CreateAttachment( "MP5k_StockBttstck" );
				
				itemEnt = player.GetInventory().CreateInInventory( "M68Optic" );
				itemEnt.GetInventory().CreateAttachment( "Battery9V" );
				
				player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
				player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
				player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
				
				player.GetInventory().CreateInInventory( "Ammo_9x19" );
				player.GetInventory().CreateInInventory( "Ammo_9x19" );
				player.GetInventory().CreateInInventory( "Ammo_9x19" );
				
				//FNX
				itemEnt = player.GetInventory().CreateInInventory( "FNX45" );
				itemEnt.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				itemEnt = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
				
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				itemEnt = player.GetInventory().CreateInInventory( "Ammo_45ACP" );
				
				//Clothing
				itemEnt = player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
			break;
			case 4:
				
				//AKM
				itemEnt = player.GetInventory().CreateInInventory( "AKM" );
				itemEnt.GetInventory().CreateAttachment( "AK_WoodBttstck" );
				itemEnt.GetInventory().CreateAttachment( "AK_WoodHndgrd" );
				itemEnt.GetInventory().CreateAttachment( "KobraOptic" );

				player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
				player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
				player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
				
				player.GetInventory().CreateInInventory( "Ammo_762x39" );
				player.GetInventory().CreateInInventory( "Ammo_762x39" );
				player.GetInventory().CreateInInventory( "Ammo_762x39" );
				
				//Clothing & Gear
				itemEnt = player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
				itemEnt = player.GetInventory().CreateInInventory( "PSO1Optic" );
				itemEnt.GetInventory().CreateAttachment( "Battery9V" );
			break
		}
		
		//Armbands
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Black" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Blue" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Green" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Orange" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Pink" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Red" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_White" );
		itemEnt = player.GetInventory().CreateInInventory( "Armband_Yellow" );
		
		//Extra Starting Gear
		itemEnt = player.GetInventory().CreateInInventory( "PersonalRadio" );
		itemEnt.GetInventory().CreateAttachment( "Battery9V" );
		//itemEnt = player.GetInventory().CreateInInventory( "CombatKnife" ); Make instant kill later then uncomment.
		itemEnt = player.GetInventory().CreateInInventory( "SalineBagIV" );
		itemEnt = player.GetInventory().CreateInInventory( "BandageDressing" );

		//  player.LocalTakeEntityToHands( itemEnt );
       // player.SetQuickBarEntityShortcut( itemEnt, 0, true ); 
	   
	   //Set Hydration to full.
		player.GetStatWater().Set(1000);
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}