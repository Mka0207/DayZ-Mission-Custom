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
		num = Math.RandomIntInclusive(1, 20);
	}
	
	if ( player_count > MAX_PLAYERS ) 
	{
		num = Math.RandomIntInclusive(1, 37);
	} 
	
	// RANDOM BALOTA
	if (num == 1) 
	{                                
		x = 5301.58;
		y = 0;
		z = 2145.16;
	}
	// RANDOM BALOTA
	if (num == 2) 
	{                                
		x = 5318.98;
		y = 0;
		z = 2380.06;
	}
	// RANDOM BALOTA
	if (num == 3) 
	{                                
		x = 5292.79;
		y = 0;
		z = 2515.46;
	}
	// RANDOM BALOTA
	if (num == 4) 
	{                                
		x = 5028.18;
		y = 0;
		z = 2617.46;
	}
	// RANDOM BALOTA
	if (num == 5) 
	{                                
		x = 4834.36;
		y = 0;
		z = 2718.34;
	}
	// RANDOM BALOTA
	if (num == 6) 
	{                                
		x = 4803.65;
		y = 0;
		z = 2376.28;
	}
	// RANDOM BALOTA
	if (num == 7) 
	{                                
		x = 4700.32;
		y = 0;
		z = 2391.18;
	}
	
	// WEST BALOTA TREES
	if (num == 8) 
	{                                
		x = Math.RandomFloatInclusive(4219, 4341);
		y = 0;
		z = Math.RandomFloatInclusive(2508, 2557);
	}
	// NORTH BALOTA TREES
	if (num == 9) 	
	{                                
		x = Math.RandomFloatInclusive(4497, 4581);
		y = 0;
		z = Math.RandomFloatInclusive(2664, 2723);
	}
	if (num == 10) 
	// WEST AIRFIELD
	{														
		x = Math.RandomFloatInclusive(4750, 4783);
		y = 0;
		z = Math.RandomFloatInclusive(2605, 2654);
	}
	// SOUTH AIRFIELD
	if (num == 11) {                                 
		x = Math.RandomFloatInclusive(4713, 5097);
		y = 0;
		z = Math.RandomFloatInclusive(2252, 2409);
	}
	// EAST BALOTA
	if (num == 12) 
	{								    
		x = Math.RandomFloatInclusive(4558, 4738);
		y = 0;
		z = Math.RandomFloatInclusive(2281, 2353);
	}
	// SOUTHEAST AIRFIELD
	if (num == 13) 
	{								    
		x = Math.RandomFloatInclusive(5093, 5176);
		y = 0;
		z = Math.RandomFloatInclusive(2150, 2169);
	}
	// TANKER SPAWN
	if (num == 14)
	{								   
		x = 5455.35;
		y = 0;
		z = 2227.32;
	}
	// NORTH BALOTA AIRFIELD
	if (num == 15) 
	{								    
		x = Math.RandomFloatInclusive(5105, 5188);
		y = 0;
		z = Math.RandomFloatInclusive(2519, 2531);
	}
	
	/* TVectorArray BalotaSpawns = { 
		"5301.58 0 2145.16", "5381.36 0 2177.86", "5313.41 0 2265.02",
		"5318.98 0 2380.06", "5340 0 2354.04", "5301.24 0 2415.23",
		"5292.79 0 2515.46", "5261.81 0 2612.38", "5102.17 0 2622.19",
		"5028.18 0 2617.46", "5006.18 0 2743.86", "4907.14 0 2713.76",
		"4834.36 0 2718.34", "4754.1 0 2717.71", "4785.09 0 2644.92",
		"4803.65 0 2376.28", "4693.74 0 2449.97", "4774 0 2466.51",
		"4700.32 0 2391.18", "5187.12 0 2151.74", "5136.03 0 2142.11",
		"5057.23 0 2229.75", "5013.31 0 2260.38", "4925.72 0 2307.05",
		"4955.65 0 2351.09", "5019.05 0 2125.3", "4856.17 0 2301.47",
		"4560.32 0 2656.03", "4418.09 0 2693.72", "5193.02 0 2079.14" }; */
	
	// RANDOM BALOTA #1
	if (num == 16) 
	{								    
		x = 5057.23;
		y = 0;
		z = 2229.75;
	}
	
	// RANDOM BALOTA #2
	if (num == 17) 
	{								    
		x = 4955.65;
		y = 0;
		z = 2351.09;
	}
	
	// RANDOM BALOTA #3
	if (num == 18) 
	{								    
		x = 4560.32;
		y = 0;
		z = 2656.03;
	}
	
	// RANDOM BALOTA #4
	if (num == 19) 
	{								    
		x = 5381.36;
		y = 0;
		z = 2177.86;
	}
	
	// RANDOM BALOTA #5
	if (num == 20) 
	{								    
		x = 5006.18;
		y = 0;
		z = 2743.86;
	}
	
	//Random Electro #1
	if (num == 21) 
	{								    
		x = 10845.3;
		y = 0;
		z = 2701.37;
	}
	
	//Random Electro #2
	if (num == 22) 
	{								    
		x = 9479.41;
		y = 0;
		z = 1960.8;
	}
	
	//Random Electro #3
	if (num == 23) 
	{								    
		x = 10497.3;
		y = 0;
		z = 2016.5;
	}
	
	//Random Electro #4
	if (num == 24) 
	{								    
		x = 10214.1;
		y = 0;
		z = 2411.58;
	}
	
	//Random Electro #5
	if (num == 25) 
	{								    
		x = 10432.7;
		y = 0;
		z = 2047.76;
	}
	
	//Random Electro #5
	if (num == 26) 
	{								    
		x = 10627.1;
		y = 0;
		z = 2142.0;
	}
	
	//Random Electro #6
	if (num == 27) 
	{								    
		x = 9892.8;
		y = 0;
		z = 2174.3;
	}
	
	//Random Electro #7
	if (num == 28) 
	{								    
		x = 10341.1;
		y = 0;
		z = 2251.1;
	}
	
	//Random Electro #8
	if (num == 29) 
	{								    
		x = 10642.2;
		y = 0;
		z = 2472.2;
	}
	
	//Random Electro #9
	if (num == 30) 
	{								    
		x = 10686.5;
		y = 0;
		z = 2472.7;
	}

	//Random Electro #10
	if (num == 31) 
	{								    
		x = 9923.9;
		y = 0;
		z = 2023.6;
	}
	
	// ELECTRO APPLES
	if (num == 32) 
	{					  
		x = Math.RandomFloatInclusive(9868, 9927);
		y = 0;
		z = Math.RandomFloatInclusive(2232, 2310);
	}
	 // ELECTRO HAYBALES
	if (num == 33) 
	{					  
		x = Math.RandomFloatInclusive(9844, 9936);
		y = 0;
		z = Math.RandomFloatInclusive(2041, 2132);
	}
	// ELECTRO CHURCH
	if (num == 34) 
	{								
		x = Math.RandomFloatInclusive(10515, 10545);
		y = 0;
		z = Math.RandomFloatInclusive(2427, 2620);
	}
	//ELECTRO RANDOM #12
	if (num == 35) 
	{	
		x = Math.RandomFloatInclusive(9785, 9843);
		y = 0;
		z = Math.RandomFloatInclusive(2284, 2349);
	}
	//ELECTRO RANDOM #13
	if (num == 36) 
	{	
		x = Math.RandomFloatInclusive(9868, 9898);
		y = 0;
		z = Math.RandomFloatInclusive(2552, 2676);
	}
	//ELECTRO RANDOM #14
	if (num == 37) 
	{	
		x = Math.RandomFloatInclusive(10465, 10511);
		y = 0;
		z = Math.RandomFloatInclusive(2506, 2586);
	}
	
	return Vector(x, y, z);
}