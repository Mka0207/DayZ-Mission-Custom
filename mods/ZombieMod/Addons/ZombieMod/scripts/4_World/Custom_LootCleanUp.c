//Loot CleanUp Script by mka0207@fwkzt.com.

//Loot CleanUp List - { Basically anything in this will be cleaned by the lootcleanup system! }
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

//OnTick should be happening every tick not every second!
//Look into using a timer for this system in the future.

//How many ticks before loot should be cleaned up.
protected int LOOT_CLEANUP_SECS = 15;

//default float, dont edit this.
protected float	m_LootCheckTimer = 0.0;

//How far in meters from the center of the player the cleaner should check.
protected float m_LootMeterRadius = 100.0;

void OnPlayerLootTick(PlayerBase player, float curTime)
{
	m_LootCheckTimer += curTime;	
	
	if ( m_LootCheckTimer > LOOT_CLEANUP_SECS )
	{
		//Reset the timer.
		m_LootCheckTimer = 0;
		
		//Establish our tables.
		ref array<Object> objects = new array<Object>;
		ref array<Object> objects_in_cone = new array<Object>;
		ref array<CargoBase> proxyCargos = new array<CargoBase>;
		
		//Check the players radius including cargos.
		GetGame().GetObjectsAtPosition( player.GetPosition(), m_LootMeterRadius, objects, proxyCargos );
		
		if ( GetGame() && objects )
		{
			if ( objects.Count() >= 1 )
			{
				for ( int i = 0; i < objects.Count(); i++ )
				{
					Object item = objects.Get( i );
					if ( item )
					{
						for( int i_d = 0; i_d < Loadout_List.Count(); i_d++ )
						{
							if ( item.GetType() == Loadout_List.Get(i_d) )
							{
								Print("[DEBUG] - Removed Item "+item.GetType() + " idx = " + i.ToString());
								//Print("[DEBUG] - Removed Item "+item.ClassName() + " idx = " + i.ToString());
							
								//Announce that we cleaned the world.
								GetGame().ChatPlayer( 0, "[Items_Cleaned] = "+objects.Count() );
								
								//Delete the items from the world and the table.
								GetGame().ObjectDelete(item);
								objects.Remove(i);
							}
							
							//Remove dead players that disconnected or that are AFK.
							if ( !player.IsAlive() )
							{
								// remove the body
								Print("[DEBUG] - Removed Player Body");
								player.Delete();	
							}
						}
					}
				}
			}
		}
		else
		{
			//Check if there is a table.
			Print("[DEBUG] - NO TABLE!");
		}
	}
}