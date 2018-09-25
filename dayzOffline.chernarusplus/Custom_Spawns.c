//Custom Spawn system by Mka0207 & Pandas & Nonlin.

TVectorArray SelectedSpawn;
static vector GetRandomSpawn()
{
	float x = Math.RandomFloatInclusive(4560, 5301);
	float y = 0;
	float z = Math.RandomFloatInclusive(2145, 2307);
	
	if (!(x > 5144 && x < 5185)) //TOP RIGHT AND TOP LEFT
	{
		if (!(z < 2619 && z > 2297)) //BOTTOM LEFT AND TOP LEFT
		{
			if (!(x < 4900 && x > 4874)) //BOTTOM LEFT AND BOTTOM RIGHT
			{
				if (!(z < 2597 && z > 2268)) //BOTTOM RIGHT AND TOP RIGHT
				{
					return Vector(x, y, z);;
				}
				else
				{
					return GetRandomSpawn();
				}
			}
			else
			{
				return GetRandomSpawn();
			}
		}
		else
		{
			return GetRandomSpawn();
		}
	}
	else
	{
		return GetRandomSpawn();
	}
}