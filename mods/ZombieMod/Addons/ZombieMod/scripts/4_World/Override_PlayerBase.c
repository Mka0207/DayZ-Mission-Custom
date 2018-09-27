//Class that are modded to be overridden!

modded class PlayerBase extends ManBase
{	
	override void OnTick()
	{
		//Vanilla DayZ Code Start ->
		float deltaT = (GetGame().GetTime() - m_LastTick) / 1000;
		if ( m_LastTick < 0 )  deltaT = 0;
		m_LastTick = GetGame().GetTime();

		OnScheduledTick(deltaT);	
		//Vanilla DayZ Code End ->|
		
		//Custom Code Begin
		OnPlayerLootTick(this, deltaT)
	}
	
	//Prevent Weapons dropping after death to prevent lag. -mka
	override void EEKilled( Object killer )
	{
		//Vanilla Print.
		Print("EEKilled, You Are Dead!");
		
		//Custom Code Begin
		OnPlayerKilledByPlayer( this, killer )
		DisableWeaponDrops( this, killer )
		
		//Vanilla DayZ Code Start ->
		if ( GetSoftSkillManager() )
		{
			delete GetSoftSkillManager();
		} 
		
		GetStateManager().OnPlayerKilled();

		if (GetHive())
		{
			GetHive().CharacterKill(this);
		}
		//Vanilla DayZ Code End ->|
	}
} 