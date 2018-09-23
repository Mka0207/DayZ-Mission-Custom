//Custom Spawn system by Mka0207.

TVectorArray SelectedSpawn;
static TVectorArray GetRandomDMSpawnTable()
{
	int MaxNumOfSpawnAreas = 2;
	
	TVectorArray BalotaSpawns = { "5264.51 0 2609.22", "15017.8 0 13892.4" };
	TVectorArray ElectroSpawns = { "9892.8 0 2174.3", "10341.1 0 2251.1" };
	
	switch( Math.RandomInt( 0, MaxNumOfSpawnAreas ) ) 
	{
		case 0 :
			SelectedSpawn = BalotaSpawns;
		break;
		
		case 1 :
			SelectedSpawn = ElectroSpawns;
		break;
	}
	
	
	return SelectedSpawn;
}

