void AddBuildings()
{
	/*
	Appartment spawn
	*/	
	ItemBase m_apt;
    vector apt_pos;
    vector apt_dir;
   
    apt_pos[0] = 5239.7;
    apt_pos[1] = 17.5;
    apt_pos[2] = 2184.65;

	m_apt = g_Game.CreateObject("Land_Tenement_Small", apt_pos, false); 
	
	/*
	Crashed C130
	*/	
	ItemBase m_c130;
    vector c130_pos;
    vector c130_dir;
   
    c130_pos[0] = 5051.91;
    c130_pos[1] = 14;
    c130_pos[2] = 2414.31;
 
    c130_dir[0] = 90;
    c130_dir[1] = 0;
    c130_dir[2] = 20;

	m_c130 = g_Game.CreateObject("Land_Wreck_C130J", c130_pos, false);
	m_c130.SetOrientation(c130_dir);
	
	/*
	Scaffolding for the Airport building
	*/	
	ItemBase m_scf1;
    vector scf1_pos;
    vector scf1_dir;
   
    scf1_pos[0] = 4930.7;
    scf1_pos[1] = 12;
    scf1_pos[2] = 2489;
 
    scf1_dir[0] = 49;
    scf1_dir[1] = 0;
    scf1_dir[2] = 0;

	m_scf1 = g_Game.CreateObject("Land_Misc_Scaffolding", scf1_pos, false);
	m_scf1.SetOrientation(scf1_dir);
}

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

	AddBuildings();
}

class CustomMission: MissionServer
{	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	void addMags(PlayerBase player, string mag_type, int count)
	{
		if (count < 1)
			return;

		EntityAI mag;

		for (int i = 0; i < count; i++) {
			mag = player.GetInventory().CreateInInventory(mag_type);
		}

		player.SetQuickBarEntityShortcut(mag, 1, true);
	}
	
	EntityAI DefaultClass_A(PlayerBase player)
	{
		//VEST
		player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
		
		//PRIMARY WEAPON
		EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "M4A1" );
		wep_primary.GetInventory().CreateAttachment( "M4_RISHndgrd_Black" );
		wep_primary.GetInventory().CreateAttachment( "M4_MPBttstck_Black" );
		wep_primary.GetInventory().CreateAttachment( "ACOGOptic" );
		//itemEnt.GetInventory().CreateAttachment( "M4_Suppressor" ); OP!
		addMags( player, "Mag_STANAG_30Rnd", 3 );
		
		//SCOPES
		EntityAI optic_attach;
		optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
		optic_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//MAGS
		//player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" ); 
		//player.GetInventory().CreateInInventory( "Mag_STANAGCoupled_30Rnd" ); 
		
		//AMMO
		EntityAI extra_ammo;
		
		player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
		player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
		player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
		extra_ammo = player.GetInventory().CreateInInventory( "Ammo_556x45" ); 
		
		player.SetQuickBarEntityShortcut(extra_ammo, 2, true);
		
		return wep_primary;
		
	}
	
	EntityAI DefaultClass_B(PlayerBase player)
	{
		//VEST
		player.GetInventory().CreateInInventory( "BallisticVest" );
		
		//SECONDARY WEAPON
		EntityAI secondarywep;
		secondarywep = player.GetInventory().CreateInInventory( "Mosin9130" );
		secondarywep.GetInventory().CreateAttachment( "PUScopeOptic" );
		player.SetQuickBarEntityShortcut(secondarywep, 1, true);
		
		//SCOPES
		EntityAI optic_attach;
		EntityAI optic2_attach;
		
		optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
		optic_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//PRIMARY WEAPON
		EntityAI attach_extra;
		EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "FNX45" );
		optic2_attach = wep_primary.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
		optic2_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//MAGS
		EntityAI secondarymag;
		secondarymag = player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		player.SetQuickBarEntityShortcut(secondarymag, 4, true);
		
		//AMMO
		EntityAI extra_ammo;
		
		player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		extra_ammo = player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		
		player.SetQuickBarEntityShortcut(extra_ammo, 2, true);
		
		return wep_primary;
		
	}
	
	EntityAI DefaultClass_C(PlayerBase player)
	{
		//VEST
		player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
		
		//PRIMARY WEAPON
		EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "UMP45" );
		wep_primary.GetInventory().CreateAttachment("PistolSuppressor");
		addMags(player, "Mag_UMP_25Rnd", 3);
		
		//SCOPES
		EntityAI optic_attach;
		EntityAI optic2_attach;
		
		optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
		optic_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//SECONDARY WEAPON
		EntityAI attach_extra;
		EntityAI secondarywep = player.GetHumanInventory().CreateInInventory( "FNX45" );
		optic2_attach = secondarywep.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
		optic2_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//MAGS
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		
		//AMMO
		EntityAI extra_ammo;
		
		player.GetInventory().CreateInInventory( "Ammo_45ACP" ); 
		player.GetInventory().CreateInInventory( "Ammo_45ACP" ); 
		player.GetInventory().CreateInInventory( "Ammo_45ACP" ); 
		player.GetInventory().CreateInInventory( "Ammo_45ACP" ); 
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		
		player.SetQuickBarEntityShortcut(extra_ammo, 2, true);
		
		return wep_primary;
		
	}
	
	EntityAI DefaultClass_D(PlayerBase player)
	{
		//VEST
		player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
		
		//PRIMARY WEAPON
		EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "SVD" );
		wep_primary.GetInventory().CreateAttachment("PSO1Optic");
		addMags(player, "Mag_SVD_10Rnd", 6);
		
		//SCOPES
		EntityAI optic_attach;
		EntityAI optic2_attach;
		
		optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
		optic_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//SECONDARY WEAPON
		EntityAI attach_extra;
		EntityAI secondarywep = player.GetHumanInventory().CreateInInventory( "FNX45" );
		optic2_attach = secondarywep.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
		optic2_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//MAGS
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		
		//AMMO
		EntityAI extra_ammo;
		
		extra_ammo = player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x54" ); 
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		
		player.SetQuickBarEntityShortcut(extra_ammo, 2, true);
		
		return wep_primary;
		
	}
	
	EntityAI DefaultClass_E(PlayerBase player)
	{
		//VEST
		player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
		
		//PRIMARY WEAPON
		EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "MP5K" );
		wep_primary.GetInventory().CreateAttachment("MP5_PlasticHndgrd");
		wep_primary.GetInventory().CreateAttachment("MP5k_StockBttstck");
		addMags(player, "Mag_MP5_30Rnd", 4);
		
		//SCOPES
		EntityAI optic_attach;
		EntityAI optic2_attach;
		
		optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
		optic_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//SECONDARY WEAPON
		EntityAI attach_extra;
		EntityAI secondarywep = player.GetHumanInventory().CreateInInventory( "FNX45" );
		optic2_attach = secondarywep.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
		optic2_attach.GetInventory().CreateAttachment( "Battery9V" );
		
		//MAGS
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		player.GetInventory().CreateInInventory( "Mag_FNX45_15Rnd" );
		
		//AMMO
		EntityAI extra_ammo;
		
		extra_ammo = player.GetInventory().CreateInInventory( "Ammo_9x19" ); 
		player.GetInventory().CreateInInventory( "Ammo_9x19" ); 
		player.GetInventory().CreateInInventory( "Ammo_9x19" ); 
		player.GetInventory().CreateInInventory( "Ammo_9x19" ); 
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		player.GetInventory().CreateInInventory( "Ammo_45ACP" );
		
		player.SetQuickBarEntityShortcut(extra_ammo, 2, true);
		
		return wep_primary;
		
	}
	
	EntityAI DefaultClass_F(PlayerBase player)
	{
		//VEST
		player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
		
		//PRIMARY WEAPON
		EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "AKM" );
		wep_primary.GetInventory().CreateAttachment("AK_WoodBttstck");
		wep_primary.GetInventory().CreateAttachment("AK_WoodHndgrd");
		wep_primary.GetInventory().CreateAttachment("KobraOptic");
		addMags(player, "Mag_AKM_30Rnd", 6);
		
		//SCOPES
		EntityAI optic_attach;
		EntityAI optic2_attach;
		
		optic_attach = player.GetInventory().CreateInInventory( "PSO1Optic" );
		optic_attach.GetInventory().CreateAttachment( "Battery9V" );

		//AMMO
		EntityAI extra_ammo;
		
		extra_ammo = player.GetInventory().CreateInInventory( "Ammo_762x39" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x39" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x39" ); 
		player.GetInventory().CreateInInventory( "Ammo_762x39" ); 
		
		player.SetQuickBarEntityShortcut(extra_ammo, 2, true);
		
		return wep_primary;
		
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		//Remove vanilla default clothing.
		player.RemoveAllItems()
		
		//EntityClass vars
		//EntityAI itemEntity;
		//ItemBase itemBs;
		
		//Clothing
		player.GetInventory().CreateInInventory( "M65Jacket_Black" );
		player.GetInventory().CreateInInventory( "BallisticHelmet_Black" );
		player.GetInventory().CreateInInventory( "CargoPants_Black" );
		
		//Armbands
		//player.GetInventory().CreateInInventory( "Armband_White" );
		player.GetInventory().CreateInInventory( "Armband_Black" );
		player.GetInventory().CreateInInventory( "Armband_Blue" );
		player.GetInventory().CreateInInventory( "Armband_Green" );
		player.GetInventory().CreateInInventory( "Armband_Orange" );
		player.GetInventory().CreateInInventory( "Armband_Pink" );
		player.GetInventory().CreateInInventory( "Armband_Red" );
		player.GetInventory().CreateInInventory( "Armband_Yellow" );
		
		//Extra Starting Gear
		EntityAI item_radio_ent;
		item_radio_ent = player.GetInventory().CreateInInventory( "PersonalRadio" );
		item_radio_ent.GetInventory().CreateAttachment( "Battery9V" );
		
		//Knife = player.GetInventory().CreateInInventory( "CombatKnife" ); Make instant kill later then uncomment.
		player.GetInventory().CreateInInventory( "SalineBagIV" );
		
		EntityAI item_bandage_ent;
		item_bandage_ent = player.GetInventory().CreateInInventory( "BandageDressing" );
		
		EntityAI primarywep;
		switch ( Math.RandomInt( 0, 6 ) ) 
		{
			case 0 : 
				primarywep = DefaultClass_A( player ); 
			break;
			
			case 1 : 
				primarywep = DefaultClass_B( player ); 
			break;
			
			case 2 : 
				primarywep = DefaultClass_C( player ); 
			break;
			
			case 3 : 
				primarywep = DefaultClass_D( player ); 
			break;
			
			case 4 : 
				primarywep = DefaultClass_E( player ); 
			break;
			
			case 5 : 
				primarywep = DefaultClass_F( player ); 
			break;
		} 
		
		player.PredictiveTakeEntityToHands(primarywep);
		player.SetQuickBarEntityShortcut(primarywep, 0, true);
		player.SetQuickBarEntityShortcut(item_bandage_ent, 3, true);
		
		//AttachMag
		//auto load_mag = player.GetInventory().CreateInInventory( "Mag_STANAG_30Rnd" );
		//EntityAI entity_in_hands = player.GetHumanInventory().GetEntityInHands();
		//EntityAI quickBarEntity = player.GetQuickBarEntity(1);

		//player.GetWeaponManager().AttachMagazine( load_mag );
		//player.ReloadWeapon( primarywep, load_mag );	
		
		//EntityAI magazine_ent = player.GetMagazineToReload( primarywep );
		//player.ReloadWeapon( primarywep, quickBarEntity );
		
		/* Magazine mag;
		Class.CastTo( mag, load_mag );
		player.GetWeaponManager().AttachMagazine( mag ); */
		
	   //Set Hydration to full.
		player.GetStatWater().Set(1000);
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}