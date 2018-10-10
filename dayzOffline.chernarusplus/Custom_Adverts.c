//Advert System by mka0207@fwkzt.com

const float ADVERT_DELAY = 120;
float AdCheckTimer = 0.0;

TStringArray Timed_Adverts()
{
	return {
	"Contact Us @ discord.gg/npTNKeM",
	"Support Us @ fwkzt.com/donate",
	"Melee weapons KO on first hit!",
	"Bodies and loot are automatically removed on a timer!",
	"Maintained and developed by FWKZT.com",
	"Want to team up? Use Armbands!",
	"Server Changelog posted on discord.",
	"If you ever suspect a hacker, don't hesitate to type 'Admin' in chat, we'll look into it.",
	"Try NOT to spawn camp!",
	"We are launching a survival server soon! Check our discord for info: discord.gg/npTNKeM",
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