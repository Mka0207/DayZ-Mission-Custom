//Advert System by mka0207@fwkzt.com

const float ADVERT_DELAY = 360;
float AdCheckTimer = 0.0;

TStringArray Timed_Adverts()
{
	return {
	"Join our discord @ discord.gg/npTNKeM",
	"Keep Us Alive @ fwkzt.com/donate",
	"Suggestions? Post them on our discord!",
	"Restarts happen without warning!"};
}

void OnTickAdverts( float timeslice )
{
	//Advert Custom Code
	AdCheckTimer += timeslice;
	if ( AdCheckTimer > ADVERT_DELAY )
	{
		AdCheckTimer = 0;
		GetGame().ChatPlayer( 0, Timed_Adverts().GetRandomElement() );
	}
}