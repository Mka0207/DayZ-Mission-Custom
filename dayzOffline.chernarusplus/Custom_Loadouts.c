void OnSpawnCallback(PlayerBase player)
{
	//Clothing
	player.GetInventory().CreateInInventory( "AssaultBag_Black" );
	player.GetInventory().CreateInInventory( "M65Jacket_Black" );
	player.GetInventory().CreateInInventory( "BalaclavaMask_Blackskull" );
	player.GetInventory().CreateInInventory( "GorkaHelmet_Black" );
	player.GetInventory().CreateInInventory( "CargoPants_Black" );
	
	//Armbands
	player.GetInventory().CreateInInventory( "Armband_Black" );
	player.GetInventory().CreateInInventory( "Armband_Blue" );
	player.GetInventory().CreateInInventory( "Armband_Green" );
	player.GetInventory().CreateInInventory( "Armband_Orange" );
	player.GetInventory().CreateInInventory( "Armband_Pink" );
	player.GetInventory().CreateInInventory( "Armband_Red" );
	player.GetInventory().CreateInInventory( "Armband_Yellow" );
	player.GetInventory().CreateInInventory( "Armband_White" );
	
	//Melee
	EntityAI crow_barwep = player.GetInventory().CreateInInventory( "Crowbar" );
	player.SetQuickBarEntityShortcut(crow_barwep, 5, true); 
	
	//Extra Starting Gear
	EntityAI item_radio_ent;
	item_radio_ent = player.GetInventory().CreateInInventory( "PersonalRadio" );
	item_radio_ent.GetInventory().CreateAttachment( "Battery9V" );
	
	//player.GetInventory().CreateInInventory( "CombatKnife" );
	player.GetInventory().CreateInInventory( "SalineBagIV" );
	
	EntityAI item_bandage_ent;
	item_bandage_ent = player.GetInventory().CreateInInventory( "BandageDressing" );
	player.GetInventory().CreateInInventory( "BandageDressing" );
	player.GetInventory().CreateInInventory( "BandageDressing" );
	player.GetInventory().CreateInInventory( "BandageDressing" );
	
	EntityAI primarywep;
	int num = Math.RandomIntInclusive( 0, 5 );
	if (num == 0) {
		primarywep = DefaultClass_A( player ); 
	}
	if (num == 1) {                      
		primarywep = DefaultClass_B( player );
	}
	if (num == 2) {
		primarywep = DefaultClass_C( player ); 
	}
	if (num == 3) {
		primarywep = DefaultClass_D( player );
	}
	if (num == 4) {
		primarywep = DefaultClass_E( player ); 
	}
	if (num == 5) {
		primarywep = DefaultClass_F( player );
	}	

	player.PredictiveTakeEntityToHands(primarywep);
	player.SetQuickBarEntityShortcut(primarywep, 0, true);
	player.SetQuickBarEntityShortcut(item_bandage_ent, 3, true);
	
   //Set Hydration to full.
	player.GetStatWater().Set(1000);
}
	
EntityAI DefaultClass_A(PlayerBase player) //M4 Loadout
{
	//VEST
	player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
	
	//PRIMARY WEAPON
	EntityAI optic2_attach
	EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "M4A1" );
	wep_primary.GetInventory().CreateAttachment( "M4_RISHndgrd_Black" );
	wep_primary.GetInventory().CreateAttachment( "M4_MPBttstck_Black" );
	optic2_attach = wep_primary.GetInventory().CreateAttachment( "M68Optic" );
	optic2_attach.GetInventory().CreateAttachment( "Battery9V" );
	//itemEnt.GetInventory().CreateAttachment( "M4_Suppressor" ); OP!
	
	//MAGS
	EntityAI mag;
	mag = player.GetInventory().CreateInInventory( "Mag_STANAG_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_STANAG_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_STANAG_30Rnd" ); 
	
	player.SetQuickBarEntityShortcut(mag, 1, true);
	
	//SCOPES
	EntityAI optic_attach;
	optic_attach = player.GetInventory().CreateInInventory( "AcogOptic" );
	
	
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

EntityAI DefaultClass_B(PlayerBase player) //Mosin Loadout
{
	//VEST
	//player.GetInventory().CreateInInventory( "BallisticVest" ); use as event item.
	player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
	
	//PRIMARY WEAPON
	EntityAI wep_primary;
	wep_primary = player.GetHumanInventory().CreateInHands( "Mosin9130" );
	wep_primary.GetInventory().CreateAttachment( "PUScopeOptic" );
	
	//SCOPES
	EntityAI optic_attach;
	EntityAI optic2_attach;
	
	//SECONDARY WEAPON
	EntityAI attach_extra;
	EntityAI secondarywep = player.GetHumanInventory().CreateInInventory( "FNX45" );
	optic2_attach = secondarywep.GetInventory().CreateAttachment( "FNP45_MRDSOptic" );
	optic2_attach.GetInventory().CreateAttachment( "Battery9V" );
	player.SetQuickBarEntityShortcut(secondarywep, 2, true);
	
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
	
	player.SetQuickBarEntityShortcut(extra_ammo, 1, true);
	
	return wep_primary;
	
}

EntityAI DefaultClass_C(PlayerBase player) //UMP Loadout
{
	//VEST
	player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
	
	//PRIMARY WEAPON
	EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "UMP45" );
	wep_primary.GetInventory().CreateAttachment("PistolSuppressor");
	
	//MAGS
	EntityAI mag;
	mag = player.GetInventory().CreateInInventory( "Mag_UMP_25Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_UMP_25Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_UMP_25Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_UMP_25Rnd" ); 
	
	player.SetQuickBarEntityShortcut(mag, 1, true);
	
	//SCOPES
	EntityAI optic_attach;
	EntityAI optic2_attach;
	
	optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
	optic_attach.GetInventory().CreateAttachment( "Battery9V" );
	
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

EntityAI DefaultClass_D(PlayerBase player) //SVD Loadout
{
	//VEST
	player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
	
	//PRIMARY WEAPON
	EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "SVD" );
	wep_primary.GetInventory().CreateAttachment("PSO1Optic");
	
	//MAGS
	EntityAI mag;
	mag = player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_SVD_10Rnd" ); 
	
	player.SetQuickBarEntityShortcut(mag, 1, true);
	
	//SCOPES
	EntityAI optic_attach;
	EntityAI optic2_attach;
	
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

EntityAI DefaultClass_E(PlayerBase player) //MP5 Loadout
{
	//VEST
	player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
	
	//PRIMARY WEAPON
	EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "MP5K" );
	wep_primary.GetInventory().CreateAttachment("MP5_PlasticHndgrd");
	wep_primary.GetInventory().CreateAttachment("MP5k_StockBttstck");
	
	//MAGS
	EntityAI mag;
	mag = player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_MP5_30Rnd" ); 
	
	player.SetQuickBarEntityShortcut(mag, 1, true);
	
	//SCOPES
	EntityAI optic_attach;
	EntityAI optic2_attach;
	
	optic_attach = player.GetInventory().CreateInInventory( "M68Optic" );
	optic_attach.GetInventory().CreateAttachment( "Battery9V" );
	
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

EntityAI DefaultClass_F(PlayerBase player) //AKM Loadout
{
	//VEST
	player.GetInventory().CreateInInventory( "HighCapacityVest_Black" );
	
	//PRIMARY WEAPON
	EntityAI wep_primary = player.GetHumanInventory().CreateInHands( "AKM" );
	wep_primary.GetInventory().CreateAttachment("AK_WoodBttstck");
	wep_primary.GetInventory().CreateAttachment("AK_WoodHndgrd");
	wep_primary.GetInventory().CreateAttachment("KobraOptic");
	
	//MAGS
	EntityAI mag;
	mag = player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
	player.GetInventory().CreateInInventory( "Mag_AKM_30Rnd" ); 
	
	player.SetQuickBarEntityShortcut(mag, 1, true);
	
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