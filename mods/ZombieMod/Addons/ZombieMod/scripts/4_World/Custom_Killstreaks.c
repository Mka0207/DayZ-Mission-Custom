//Kill Streak Script by mka0207@fwkzt.com.

void AddKillStreak(Object killer)
{
	Param1<string> params;
	params = new Param1<string>( "" );
	PlayerBase man;
	if ( GetGame().IsServer() && Class.CastTo(man, killer) )
	{
		int kill_add = man.humans_killed++;
		params.param1 = "Kill Streak : "+kill_add;
		man.RPCSingleParam( ERPCs.RPC_USER_ACTION_MESSAGE, params, true, man.GetIdentity() );
	}
}