//Stable Custom Spawn SYS by mka0207@fwkzt.com.

//Enable this to spawn in one area.
protected bool Spawn_LocalDebug = false;

TVectorArray SelectedSpawn;
static TVectorArray GetRandomDMSpawnTable()
{
	if ( Spawn_LocalDebug )
	{
		TVectorArray Debug_Spawns = { "5395.36 0 2180.86", "5381.36 0 2177.86" };
		Print( "[DEBUG] - LOCAL SPAWNS ENABLED!" )
		SelectedSpawn = Debug_Spawns;
		return SelectedSpawn;
	} 
	else
	{
		int MaxNumOfSpawnAreas = 2;
		
		TVectorArray BalotaSpawns = { 
			"5301.58 0 2145.16", "5381.36 0 2177.86", "5313.41 0 2265.02",
			"5318.98 0 2380.06", "5340 0 2354.04", "5301.24 0 2415.23",
			"5292.79 0 2515.46", "5261.81 0 2612.38", "5102.17 0 2622.19",
			"5028.18 0 2617.46", "5006.18 0 2743.86", "4907.14 0 2713.76",
			"4834.36 0 2718.34", "4754.1 0 2717.71", "4785.09 0 2644.92",
			"4803.65 0 2376.28", "4693.74 0 2449.97", "4774 0 2466.51",
			"4700.32 0 2391.18", "5187.12 0 2151.74", "5136.03 0 2142.11",
			"5057.23 0 2229.75", "5013.31 0 2260.38", "4925.72 0 2307.05",
			"4955.65 0 2351.09", "5019.05 0 2125.3", "4856.17 0 2301.47",
			"4560.32 0 2656.03", "4418.09 0 2693.72", "5193.02 0 2079.14" };
		
		TVectorArray ElectroSpawns = { 
			"9892.8 0 2174.3", "10341.1 0 2251.1", "10241.1 0 1962.1",
			"10233.8 0 2152.2", "10233.8 0 2152.2", "10344.2 0 2540.2",
			"9874.4 0 2009.3", "10637.5 0 2575.6", "9905.1 0 2209.9",
			"10428.4 0 2033.1", "10227.7 0 2197.9", "10095.2 0 2113.6",
			"10074.6 0 2291.1", "10430.5 0 2699.8", "10691.1 0 2395.3",
			"10713.7 0 2352.6", "10263.2 0 2018.3", "10557.6 0 2463.3",
			"10375.5 0 2154.1", "10330.5 0 2294.5", "10078.4 0 2245.7",
			"10364.9 0 2287.8", "10314.8 0 2221.1", "10361.0 0 2388.3",
			"10373.0 0 2624.8", "9936.2 0 1944.8", "10517.6 0 2083.6",
			"10725.1 0 2543.8", "9828.0 0 1949.1", "9869.5 0 1783.0",
			"10677.4 0 2301.9", "10303.3  0 1967.9", "10402.0 0 1955.7",
			"10315.8 0 2173.7", "9830.3 0 1826.4", "10273.5 0 2328.6",
			"9963.6 0 2029.9", "9921.6 0 2120.3", "10016.6 0 2214.2",
			"10013.0 0 2247.2", "10107.8 0 2335.4", "9893.6 0 1896.3",
			"9953.9 0 1795.4", "9983.6 0 1937.3", "9895.2 0 1958.3",
			"9825.3 0 1786.8", "10132.1 0 2237.3", "10408.0 0 1895.7",
			"9859.2 0 1905.0", "10301.1 0 2057.6", "10648.3 0 2214.0",
			"10344.0 0 2330.5", "10335.3 0 2413.0", "10642.2 0 2472.2",
			"10686.5 0 2472.7", "10088.5 0 2189.0", "10271.2 0 2383.9",
			"10171.5 0 2357.3", "10376.8 0 2022.6", "10476.1 0 2668.3",
			"10341.8 0 2501.2", "10587.7 0 2602.0", "10088.2 0 2153.2",
			"10225.9 0 2460.7", "10280.3 0 2209.4", "10318.8 0 2456.2",
			"9923.9 0 2023.6", "10321.9 0 2361.0", "10239.4 0 2357.0",
			"9981.2 0 2193.8", "10712.0 0 2439.5", "9942.2 0 2073.0" };
		
		switch( Math.RandomIntInclusive( 0, MaxNumOfSpawnAreas ) ) 
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
}

//Experimental Spawn SYS-TO BE IMPROVED...
//Created by Mka0207, Pandas & Nonlin.
/*
	static vector GetRandomSpawn()
	{
		float x;
		float y;
		float z;

		int num = Math.RandomInt(1, 5);

		if (num == 1) {                                // BALOTA TOWN SPAWN
			x = Math.RandomFloatInclusive(4300, 4800);
			y = 0;
			z = Math.RandomFloatInclusive(2300, 2700);
		}
		if (num == 2) {                                // COSTAL TREELINE SPAWN
			x = Math.RandomFloatInclusive(4700, 5200);
			y = 0;
			z = Math.RandomFloatInclusive(2000, 2200);
		}
		if (num == 3) {
			x = Math.RandomFloatInclusive(5280, 5400); // NORTHERN WOODS SPAWN
			y = 0;
			z = Math.RandomFloatInclusive(2100, 2250);
		}
		if (num == 4) {
			x = Math.RandomFloatInclusive(5300, 5450); // ATC SPAWN
			y = 0;
			z = Math.RandomFloatInclusive(2250, 2350);
		}
		if (num == 5) {
			x = Math.RandomFloatInclusive(5350, 5600); // APARTMENTS SPAWN
			y = 0;
			z = Math.RandomFloatInclusive(2500, 2700);
		}
		return Vector(x, y, z);
		Print(GetRandomSpawn());
	}

*/