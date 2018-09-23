void OnSpawnCallback(PlayerBase player)
{
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
	
   //Set Hydration to full.
	player.GetStatWater().Set(1000);
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