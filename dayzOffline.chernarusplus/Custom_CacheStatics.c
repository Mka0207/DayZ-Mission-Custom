//Event system by mka0207@fwkzt.com

//Clean up those spooky zombies!
static void DoEventCleanUp(float x, float y, float z, float radius)
{
	ref array<Object> Ev_Zombies = new array<Object>;
	GetGame().GetObjectsAtPosition( Vector(x,y,z), radius, Ev_Zombies, NULL );

	if ( GetGame() && Ev_Zombies )
	{
		if ( Ev_Zombies.Count() >= 1 ) 
		{
			for ( int i = 0; i < Ev_Zombies.Count(); i++ )
			{
				Object z_ent = Ev_Zombies.Get( i );

				//Zombies
                if ( z_ent.IsInherited(ZombieBase) )
				{
					GetGame().ObjectDelete(z_ent);
				}
				
				//Barrels
				if ( z_ent.IsInherited(Barrel_ColorBase) )
				{
					GetGame().ObjectDelete(z_ent);
				}
				
				//SeaChests
				if ( z_ent.GetType() == "SeaChest" )
				{
					GetGame().ObjectDelete(z_ent);
				}
			}
		}
	}
}

static TStringArray GrabRandomZombieClass()
{
    return {
    "ZmbM_Soldier", 
    "ZmbM_SoldierAlice", 
    "ZmbM_SoldierHelmet", 
    "ZmbM_SoldierVest", 
    "ZmbM_SoldierAliceHelmet", 
    "ZmbM_SoldierVestHelmet", 
    "ZmbM_HunterOld_Autumn", 
    "ZmbM_HunterOld_Spring", 
    "ZmbM_HunterOld_Summer", 
    "ZmbM_HunterOld_Winter"};
}

static void CreateContainrItems_1(ItemBase item)
{
    int RandomItemsChance = Math.RandomIntInclusive( 1, 2 );

    if ( RandomItemsChance == 1 )
    {
        EntityAI wep_attach_1;
        EntityAI wep_attach_2;
        EntityAI wep_M4A1 = item.GetInventory().CreateInInventory( "M4A1_Green" );

        wep_M4A1.GetInventory().CreateAttachment( "M4_CQBBttstck_Green" );
        wep_M4A1.GetInventory().CreateAttachment( "M4_MPHndgrd_Green" );
        wep_M4A1.GetInventory().CreateAttachment( "M4_Suppressor" );
        wep_M4A1.GetInventory().CreateAttachment( "GhillieAtt_Mossy" );
        wep_attach_1 = wep_M4A1.GetInventory().CreateAttachment( "AcogOptic" );
        wep_attach_1.GetInventory().CreateAttachment( "Battery9V" );

        item.GetInventory().CreateInInventory( "Mag_StanagCoupled_30Rnd" ); 
        item.GetInventory().CreateInInventory( "Mag_StanagCoupled_30Rnd" ); 
        item.GetInventory().CreateInInventory( "Mag_StanagCoupled_30Rnd" );

        item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 

        wep_attach_2 = item.GetInventory().CreateInInventory( "M68Optic" );
        wep_attach_2.GetInventory().CreateAttachment( "Battery9V" );
    }

    if ( RandomItemsChance == 2 )
    {
        item.GetInventory().CreateInInventory( "GhillieHood_Mossy" ); 
        item.GetInventory().CreateInInventory( "GhillieSuit_Mossy" );

        item.GetInventory().CreateInInventory( "Rangefinder" );
        item.GetInventory().CreateInInventory( "Binoculars" );
        item.GetInventory().CreateInInventory( "ImprovisedSuppressor" );
    }
}

static void CreateContainrItems_2(ItemBase item)
{
    int RandomItemsChance2 = Math.RandomIntInclusive( 1, 2 );

    if ( RandomItemsChance2 == 1 )
    {
        EntityAI wep2_attack_1;
        EntityAI wep2_attack_2;
        EntityAI wep_AKM = item.GetInventory().CreateInInventory( "AKM" );
        wep_AKM.GetInventory().CreateAttachment( "AK_WoodBttstck_Camo" );
        wep_AKM.GetInventory().CreateAttachment( "AK_Bayonet" );
        wep_AKM.GetInventory().CreateAttachment( "AK_WoodHndgrd_Camo" );
        wep_AKM.GetInventory().CreateAttachment( "AK_Suppressor" );
        wep_AKM.GetInventory().CreateAttachment( "GhillieAtt_Mossy" );
        wep2_attack_1 = wep_AKM.GetInventory().CreateAttachment( "PSO1Optic" );
        wep2_attack_1.GetInventory().CreateAttachment( "Battery9V" );

        item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 
        item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 
        item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 

        item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 
        wep2_attack_2 = item.GetInventory().CreateInInventory( "KobraOptic" );
        wep2_attack_2.GetInventory().CreateAttachment( "Battery9V" );
    }

    if ( RandomItemsChance2 == 2 )
    {
        item.GetInventory().CreateInInventory( "BallisticVest" );
        item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 
        item.GetInventory().CreateInInventory( "AK_Suppressor" );
        item.GetInventory().CreateInInventory( "M4_Suppressor" );
        item.GetInventory().CreateInInventory( "PistolSuppressor" );
        item.GetInventory().CreateInInventory( "ImprovisedSuppressor" );
    }
}

static void CreateContainrItems_3(ItemBase item)
{
    int RandomItemsChance3 = Math.RandomIntInclusive( 1, 4 );

    if ( RandomItemsChance3 == 1 )
    {
        EntityAI wep2_attack_1;
        EntityAI wep2_attack_2;
        EntityAI wep_AKM = item.GetInventory().CreateInInventory( "AKM" );
        wep_AKM.GetInventory().CreateAttachment( "AK_WoodBttstck_Camo" );
        wep_AKM.GetInventory().CreateAttachment( "AK_Bayonet" );
        wep_AKM.GetInventory().CreateAttachment( "AK_WoodHndgrd_Camo" );
        wep_AKM.GetInventory().CreateAttachment( "AK_Suppressor" );
        wep_AKM.GetInventory().CreateAttachment( "GhillieAtt_Mossy" );
        wep2_attack_1 = wep_AKM.GetInventory().CreateAttachment( "PSO1Optic" );
        wep2_attack_1.GetInventory().CreateAttachment( "Battery9V" );

        item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 
        item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 
        item.GetInventory().CreateInInventory( "Mag_AKM_Drum75Rnd" ); 

        item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 
        wep2_attack_2 = item.GetInventory().CreateInInventory( "KobraOptic" );
        wep2_attack_2.GetInventory().CreateAttachment( "Battery9V" );
    }

    if ( RandomItemsChance3 == 2 )
    {
        item.GetInventory().CreateInInventory( "BallisticVest" );
        item.GetInventory().CreateInInventory( "BallisticHelmet_Green" ); 
        item.GetInventory().CreateInInventory( "AK_Suppressor" );
        item.GetInventory().CreateInInventory( "M4_Suppressor" );
        item.GetInventory().CreateInInventory( "PistolSuppressor" );
        item.GetInventory().CreateInInventory( "ImprovisedSuppressor" );
    }

    if ( RandomItemsChance3 == 3 )
    {
        item.GetInventory().CreateInInventory( "GhillieHood_Mossy" ); 
        item.GetInventory().CreateInInventory( "GhillieSuit_Mossy" );
    }

    if ( RandomItemsChance3 == 4 )
    {
        item.GetInventory().CreateInInventory( "GreatHelm" );
        item.GetInventory().CreateInInventory( "PressVest_Blue" );
    }
}
