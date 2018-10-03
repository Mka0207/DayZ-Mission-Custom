modded class BleedingSourcesManager
{
	int times_hit = 0;
	override void ProcessHit(float damage, string component, string ammo, vector modelPos)
	{
		if( m_BleedingSources.Contains(component) )
		{
			return;
		}

		string ammo_type; 
		GetGame().ConfigGetText( "CfgAmmo " + ammo + " DamageApplied " + "type", ammo_type );
		
		//Make zombies instant kill humans.
		if(ammo_type == "Infected") 
		{
			if ( m_Player.IsAlive() )
			{
				m_Player.SetHealth("","", -1);
			}
		}
		
		//Make humans instant kill humans with melee!
		if(ammo_type == "Melee")
		{
			times_hit++
			if ( times_hit == 1 )
			{
				if(!m_Player.IsUnconscious())
				{
					m_Player.SetHealth("","Shock",0);
				}
			}
			else if ( times_hit >= 2 )
			{
				m_Player.SetHealth("","", -1);
				times_hit = 0;
			}
		}
		
		//m_Player.m_ModifiersManager.ActivateModifier(eModifiers.MDF_UNCONSCIOUSNESS);
	}
}


