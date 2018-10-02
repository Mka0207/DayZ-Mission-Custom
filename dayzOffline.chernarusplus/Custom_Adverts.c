//Advert System by mka0207@fwkzt.com

const float ADVERT_DELAY = 360;
float AdCheckTimer = 0.0;

TStringArray Timed_Adverts()
{
	return {
	"Contact Us @ discord.gg/npTNKeM",
	"Support Us @ fwkzt.com/donate",
	"Watch out for random Cache Zones!",
	"Try NOT to spawn camp!",
	"Server restarts every 4 hours!"};
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