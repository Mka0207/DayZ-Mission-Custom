//Loot Cleaner By Mka0207.
//Moved to Addon Format.

/* const float TICK_TEST_CHECK = 120; //! in secs. test timer
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

ref TVectorArray Balota_Electro_Spawns = { 
"5301.58 0 2145.16", "5381.36 0 2177.86", "5313.41 0 2265.02",
"5318.98 0 2380.06", "5340 0 2354.04", "5301.24 0 2415.23",
"5292.79 0 2515.46", "5261.81 0 2612.38", "5102.17 0 2622.19",
"5028.18 0 2617.46", "5006.18 0 2743.86", "4907.14 0 2713.76",
"4834.36 0 2718.34", "4754.1 0 2717.71", "4785.09 0 2644.92",
"4803.65 0 2376.28", "4693.74 0 2449.97", "4774 0 2466.51",
"4700.32 0 2391.18", "5187.12 0 2151.74", "5136.03 0 2142.11",
"5057.23 0 2229.75", "5013.31 0 2260.38", "4925.72 0 2307.05",
"4955.65 0 2351.09", "5019.05 0 2125.3", "4856.17 0 2301.47",
"4560.32 0 2656.03", "4418.09 0 2693.72", "5193.02 0 2079.14",
"10428.4 0 2033.1", "10227.7 0 2197.9", "10095.2 0 2113.6",
"10074.6 0 2291.1", "10430.5 0 2699.8", "10691.1 0 2395.3",
"10713.7 0 2352.6", "10263.2 0 2018.3", "10557.6 0 2463.3",
"10375.5 0 2154.1", "10330.5 0 2294.5", "10078.4 0 2245.7",
"10364.9 0 2287.8", "10314.8 0 2221.1", "10361.0 0 2388.3",
"10373.0 0 2624.8", "9936.2 0 1944.8", "10517.6 0 2083.6",
"10725.1 0 2543.8", "9828.0 0 1949.1", "9869.5 0 1783.0",
"10677.4 0 2301.9", "10303.3  0 1967.9", "10402.0 0 1955.7"};

void CleanLootOnServer(float deltaT)
{
	m_TestCheckTimer += deltaT;	
	if ( m_TestCheckTimer > TICK_TEST_CHECK )
	{
		m_TestCheckTimer = 0;
		
		ref array<Object> objects = new array<Object>;
		ref array<Object> objects_in_cone = new array<Object>;
		ref array<CargoBase> proxyCargos = new array<CargoBase>;
		
		GetGame().GetObjectsAtPosition( Balota_Electro_Spawns.GetRandomElement(), 1500.0, objects, proxyCargos );
		
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
} */