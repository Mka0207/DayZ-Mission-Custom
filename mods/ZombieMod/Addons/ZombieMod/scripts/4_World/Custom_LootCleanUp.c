//Loot CleanUp Script by mka0207@fwkzt.com.

//OnTick should be happening every tick not every second!
//Look into using a timer for this system in the future.

//How many ticks before loot should be cleaned up.
const float LOOT_CLEANUP_SECS = 15;

//default float, dont edit this.
protected float	m_LootCheckTimer = 0.0;

//How far in meters from the center of the player the cleaner should check.
protected float m_LootMeterRadius = 90.0;

//How many items were cleaned.
int total_cleaned = 0;

void OnPlayerLootTick(PlayerBase player, float curTime)
{
	//Set the CustomTimer float to the CurTime float and add CurTime to it.
	m_LootCheckTimer += curTime;	
	
	//If the current time is great than the loot cleanup max secs.
	if ( m_LootCheckTimer > LOOT_CLEANUP_SECS )
	{
		//Reset the timer.
		m_LootCheckTimer = 0;
		
		//Establish our tables.
		ref array<Object> objects = new array<Object>;
		ref array<CargoBase> proxyCargos = new array<CargoBase>;
		
		//Check the players radius including cargos.
		GetGame().GetObjectsAtPosition( player.GetPosition(), m_LootMeterRadius, objects, proxyCargos );
		
		if ( GetGame() && objects )
		{
			for ( int i = 0; i < objects.Count(); i++ )
			{
				//Handle Loot
				Object item = objects.Get( i );
				if ( item ) //item.IsInventoryItem()
				{
					//Don't remove barrels or buildings.
					if ( item.IsKindOf( "Barrel_ColorBase" ) )
					{	
						continue;
					}
					
					/* if ( item.IsBuilding() )
					{
						continue;
					} */
					
					/* 	if ( item.IsEntityAI() )
					{
						continue;
					} */
					
					//Don't remove players or ai.
					/* if ( item.IsMan() )
					{	
						continue;
					} */
					
					if ( item.GetType() == "SeaChest" )
					{
						continue;
					}
					
					//Remove Melee, Firearms, Clothing and all other items dropped.
					if ( item.IsWeapon() || item.IsClothing() || item.IsMeleeWeapon() || item.IsMagazine() )
					{	
						if ( objects.Count() >= 1 )
						{
							Print("[DEBUG] - Removed Item "+item.GetType() + " idx = " + i.ToString());
							total_cleaned = total_cleaned + 1;
							GetGame().ObjectDelete(item);
						}
					}
				}
			}
		
			//Announce that we cleaned the world.
			GetGame().ChatPlayer( 0, "[Items_Cleaned] = "+total_cleaned );
			
			//Rest how many we cleaned.
			total_cleaned = 0;
		}
		else
		{
			//Check if there is a table.
			Print("[DEBUG] - NO TABLE!");
		}

	}
}