//Advert System by mka0207@fwkzt.com

const float ADVERT_DELAY = 360;
float AdCheckTimer = 0.0;

TStringArray Timed_Adverts()
{
	return {
	"Contact Us @ discord.gg/npTNKeM",
	"Support Us @ fwkzt.com/donate",
	"Melee weapons KO on first hit!",
	"Bodies auto clean after 18 secs!",
	"Items auto clean after 3 mins!",
	"Maintained and developed by FWKZT.com",
	"Want to team up? Use Armbands!",
	"Occasional lag spikes are normal.",
	"Server Changelog posted on discord.",
	"Try NOT to spawn camp!",
	"Server restarts every 4-6 hours!"};
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