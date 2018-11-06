//Disabled as they arent needed yet in death-match.

/* modded class StaminaHandler 
{
    override void Update(float deltaT) { return; }
} */

modded class Hunger: ModifierBase
{	
	override void OnTick(PlayerBase player, float deltaT)
	{
		//Print( "[DEBUG] : Hunger is disabled" )
	}
}

modded class Thirst: ModifierBase
{	
	override void OnTick(PlayerBase player, float deltaT)
	{
		//Print( "[DEBUG] : Thirst is disabled" )
	}
}

modded class Temperature: ModifierBase
{	
	override void OnTick(PlayerBase player, float deltaT)
	{
		//Print( "[DEBUG] : Temperature is disabled" )
	}
}