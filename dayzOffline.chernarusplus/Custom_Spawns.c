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

	if (player_count <=30 ) {
		num = Math.RandomIntInclusive(1, 9);
	}
	
	if (player_count > 30 ) {
		num = Math.RandomIntInclusive(1, 18);
	}
	

	if (num == 1) {                                // WEST BALOTA TREES
		x = Math.RandomFloatInclusive(4219, 4341);
		y = 0;
		z = Math.RandomFloatInclusive(2508, 2557);
	}
	if (num == 2) {                                // NORTH BALOTA TREES
		x = Math.RandomFloatInclusive(4497, 4581);
		y = 0;
		z = Math.RandomFloatInclusive(2664, 2723);
	}
	if (num == 3) {									// WEST AIRFIELD					
		x = Math.RandomFloatInclusive(4750, 4783);
		y = 0;
		z = Math.RandomFloatInclusive(2605, 2654);
	}
	if (num == 4) {                                 // SOUTH AIRFIELD
		x = Math.RandomFloatInclusive(4713, 5097);
		y = 0;
		z = Math.RandomFloatInclusive(2252, 2409);
	}
	if (num == 5) {								    // EAST BALOTA
		x = Math.RandomFloatInclusive(4558, 4738);
		y = 0;
		z = Math.RandomFloatInclusive(2281, 2353);
	}
	if (num == 6) {								    // SOUTHEAST AIRFIELD
		x = Math.RandomFloatInclusive(5093, 5176);
		y = 0;
		z = Math.RandomFloatInclusive(2150, 2169);
	}
	if (num == 7) {								    // AIRFIELD COAST SPAWN
		x = Math.RandomFloatInclusive(5267, 5283);
		y = 0;
		z = Math.RandomFloatInclusive(1949, 1968);
	}
	if (num == 8) {								    // TANKER SPAWN
		x = Math.RandomFloatInclusive(5376, 5383);
		y = 0;
		z = Math.RandomFloatInclusive(2179, 2195);
	}
	if (num == 9) {								    // NORTH BALOTA AIRFIELD
		x = Math.RandomFloatInclusive(5105, 5188);
		y = 0;
		z = Math.RandomFloatInclusive(2519, 2531);
	}
	if (num > 9 && num < 13) {					   // ELECTRO APPLES
		x = Math.RandomFloatInclusive(9868, 9927);
		y = 0;
		z = Math.RandomFloatInclusive(2232, 2310);
	}
	if (num > 12 && num < 16) {					   // ELECTRO HAYBALES
		x = Math.RandomFloatInclusive(9844, 9936);
		y = 0;
		z = Math.RandomFloatInclusive(2041, 2132);
	}
	if (num > 15) {								   // ELECTRO CHURCH
		x = Math.RandomFloatInclusive(10515, 10545);
		y = 0;
		z = Math.RandomFloatInclusive(2427, 2620);
	}

	return Vector(x, y, z);
}