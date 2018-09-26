//Loot Cleaner By Mka0207.

const float TICK_TEST_CHECK = 60; //! in secs. test timer
protected float	m_TestCheckTimer = 0.0;

//Loadout List.
ref TStringArray Loadout_List = {
"M65Jacket_Black",
"BalaclavaMask_Blackskull",
"GorkaHelmet_Black",
"CargoPants_Black",

"Armband_Black",
"Armband_Blue",
"Armband_Green",
"Armband_Orange",
"Armband_Pink",
"Armband_Red",
"Armband_Yellow",

"HighCapacityVest_Black",
"M4_RISHndgrd_Black",
"M4_MPBttstck_Black",

"MP5k_StockBttstck",
"MP5_PlasticHndgrd",

"AK_WoodBttstck",
"AK_WoodHndgrd",
"KobraOptic",

"ACOGOptic",
"M68Optic",
"FNP45_MRDSOptic",
"PSO1Optic",
"Battery9V",

"Ammo_9x19",
"Ammo_556x45",
"Ammo_762x39",
"Ammo_762x54",
"Ammo_45ACP",
"BallisticVest",

"Mag_STANAG_30Rnd",
"Mag_STANAGCoupled_30Rnd",
"Mag_FNX45_15Rnd",
"Mag_AKM_30Rnd",

"Mag_MP5_30Rnd",
"Crowbar",
"BandageDressing",

"PistolSuppressor",

"AKM",
"M4A1",
"MP5K",
"UMP45",
"SVD",
"UMP45",
"Mosin9130",
"FNX45"};

void CleanLootOnServer(float deltaT)
{
	m_TestCheckTimer += deltaT;	
	if ( m_TestCheckTimer > TICK_TEST_CHECK )
	{
		m_TestCheckTimer = 0;
		
		ref array<Object> objects = new array<Object>;
		ref array<Object> objects_in_cone = new array<Object>;
		ref array<CargoBase> proxyCargos = new array<CargoBase>;
		
		GetGame().GetObjectsAtPosition( Vector(4988.71, 0, 2439.76), 5000.0, objects, proxyCargos );
		
		if ( GetGame() && objects )
		{
			for ( int i = 0; i < objects.Count(); i++ )
			{
				Object item = objects.Get( i );
				if ( item )
				{
					for( int i_d=0; i_d < Loadout_List.Count(); i_d++ )
					{
						if ( item.GetType() == Loadout_List.Get(i_d) )
						{
							Print("Removed Item "+item.GetType() + " idx = " + i.ToString());
							Print("Removed Item "+item.ClassName() + " idx = " + i.ToString());
						
							GetGame().ObjectDelete(item);
							objects.Remove(i);
						}
					}
				}
			}
		}
		else
		{
			Print("NO TABLE!");
		}
	}
}