//Buildings by Ficarra1002

static void AddBuildings()
{
	/*
	Appartment spawn
	
	ItemBase m_apt;
    vector apt_pos;
    vector apt_dir;
   
    apt_pos[0] = 5239.7;
    apt_pos[1] = 17.5;
    apt_pos[2] = 2184.65;

	m_apt = g_Game.CreateObject("Land_Tenement_Small", apt_pos, false); 
	
	*/	
	/*
    ATC Spawn, replaces appartment
    */	
	
	ItemBase m_atc;
    vector atc_pos;
    vector atc_dir;
   
    atc_pos[0] = 5239.7;
    atc_pos[1] = 25.5;
    atc_pos[2] = 2184.65;
 
    atc_dir[0] = 66;
    atc_dir[1] = 0;
    atc_dir[2] = 0;
 
	
	m_atc = g_Game.CreateObject("Land_Mil_ATC_Big", atc_pos, false);
	m_atc.SetOrientation(atc_dir);
	
	
	/*
	Crashed C130
	*/	
	ItemBase m_c130;
    vector c130_pos;
    vector c130_dir;
   
    c130_pos[0] = 5051.91;
    c130_pos[1] = 14;
    c130_pos[2] = 2414.31;
 
    c130_dir[0] = 90;
    c130_dir[1] = 0;
    c130_dir[2] = 20;

	m_c130 = g_Game.CreateObject("Land_Wreck_C130J", c130_pos, false);
	m_c130.SetOrientation(c130_dir);
	
	/*
	Scaffolding for the Airport building
	*/	
	ItemBase m_scf1;
    vector scf1_pos;
    vector scf1_dir;
   
    scf1_pos[0] = 4930.7;
    scf1_pos[1] = 12;
    scf1_pos[2] = 2489;
 
    scf1_dir[0] = 49;
    scf1_dir[1] = 0;
    scf1_dir[2] = 0;

	m_scf1 = g_Game.CreateObject("Land_Misc_Scaffolding", scf1_pos, false);
	m_scf1.SetOrientation(scf1_dir);
}