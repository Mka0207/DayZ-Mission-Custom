//Custom Spawn system by Mka0207 & Pandas & Nonlin.

static vector GetRandomSpawn()
{
	ref array<Man> player_list = new array<Man>;
	GetGame().GetWorld().GetPlayerList(player_list);
	int player_count = player_list.Count();
	player_count++;

	int num;
	
	float x;
	float y;
	float z;

	int MAX_PLAYERS = 25;
	if ( player_count <= MAX_PLAYERS ) 
	{
		num = Math.RandomIntInclusive(1, 9);
	}
	
	if ( player_count > MAX_PLAYERS ) 
	{
		num = Math.RandomIntInclusive(1, 18);
	}

	// WEST BALOTA TREES
	if (num == 1) 
	{                                
		x = Math.RandomFloatInclusive(4219, 4341);
		y = 0;
		z = Math.RandomFloatInclusive(2508, 2557);
	}
	// NORTH BALOTA TREES
	if (num == 2) 	
	{                                
		x = Math.RandomFloatInclusive(4497, 4581);
		y = 0;
		z = Math.RandomFloatInclusive(2664, 2723);
	}
	if (num == 3) 
	// WEST AIRFIELD
	{														
		x = Math.RandomFloatInclusive(4750, 4783);
		y = 0;
		z = Math.RandomFloatInclusive(2605, 2654);
	}
	// SOUTH AIRFIELD
	if (num == 4) {                                 
		x = Math.RandomFloatInclusive(4713, 5097);
		y = 0;
		z = Math.RandomFloatInclusive(2252, 2409);
	}
	// EAST BALOTA
	if (num == 5) 
	{								    
		x = Math.RandomFloatInclusive(4558, 4738);
		y = 0;
		z = Math.RandomFloatInclusive(2281, 2353);
	}
	// SOUTHEAST AIRFIELD
	if (num == 6) 
	{								    
		x = Math.RandomFloatInclusive(5093, 5176);
		y = 0;
		z = Math.RandomFloatInclusive(2150, 2169);
	}
	// AIRFIELD COAST SPAWN
	if (num == 7) 
	{								    
		x = Math.RandomFloatInclusive(5267, 5283);
		y = 0;
		z = Math.RandomFloatInclusive(1949, 1968);
	}
	// TANKER SPAWN
	if (num == 8)
	{								   
		x = Math.RandomFloatInclusive(5376, 5383);
		y = 0;
		z = Math.RandomFloatInclusive(2179, 2195);
	}
	// NORTH BALOTA AIRFIELD
	if (num == 9) 
	{								    
		x = Math.RandomFloatInclusive(5105, 5188);
		y = 0;
		z = Math.RandomFloatInclusive(2519, 2531);
	}
	// ELECTRO APPLES
	if (num > 9 && num < 13) 
	{					  
		x = Math.RandomFloatInclusive(9868, 9927);
		y = 0;
		z = Math.RandomFloatInclusive(2232, 2310);
	}
	 // ELECTRO HAYBALES
	if (num > 12 && num < 15) 
	{					  
		x = Math.RandomFloatInclusive(9844, 9936);
		y = 0;
		z = Math.RandomFloatInclusive(2041, 2132);
	}
	// ELECTRO CHURCH
	if (num == 15) 
	{								
		x = Math.RandomFloatInclusive(10515, 10545);
		y = 0;
		z = Math.RandomFloatInclusive(2427, 2620);
	}
	//ELECTRO RANDOM #1
	if (num == 16) 
	{	
		x = Math.RandomFloatInclusive(9785, 9843);
		y = 0;
		z = Math.RandomFloatInclusive(2284, 2349);
	}
	//ELECTRO RANDOM #2
	if (num == 17) 
	{	
		x = Math.RandomFloatInclusive(9868, 9898);
		y = 0;
		z = Math.RandomFloatInclusive(2552, 2676);
	}
	//ELECTRO RANDOM #3
	if (num == 18) 
	{	
		x = Math.RandomFloatInclusive(10477, 10526);
		y = 0;
		z = Math.RandomFloatInclusive(2523, 2598);
	}

	return Vector(x, y, z);
}