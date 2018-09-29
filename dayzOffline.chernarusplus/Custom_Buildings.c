//Buildings by Ficarra1002

void AddBuildings()
{

	//EntityAI m_survivortest;
	//m_survivortest = g_Game.CreateObject("SurvivorM_Mirek", "5380.59 0 2170.23", false, true )
	
    //ATC Spawn, replaces appartment
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
	
	//ACT North East AF
	ItemBase m_atc_ne;
	vector atc_ne_pos;
	vector atc_ne_dir;
   
	atc_ne_pos[0] = 12176.6;
	atc_ne_pos[1] = 155.84;
	atc_ne_pos[2] = 12633.2;
 
	atc_ne_dir[0] = -66;
	atc_ne_dir[1] = 0;
	atc_ne_dir[2] = 0;
 
	
	m_atc_ne = g_Game.CreateObject("Land_Mil_ATC_Big", atc_ne_pos, false);
	m_atc_ne.SetOrientation(atc_ne_dir);
	
	//Crashed C130
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
	
	
	//Scaffolding for the Airport building 
	
	/* ItemBase m_scf1;
    vector scf1_pos;
    vector scf1_dir;
   
    scf1_pos[0] = 4929.32;
    scf1_pos[1] = 11.95;
    scf1_pos[2] = 2487.09;
 
    scf1_dir[0] = 49;
    scf1_dir[1] = 0;
    scf1_dir[2] = 0;

	m_scf1 = g_Game.CreateObject("Land_Misc_Scaffolding", scf1_pos, false);
	m_scf1.SetOrientation(scf1_dir); */
	
	//Stairs to the roofs of housing blocks in elektro
	
	ItemBase m_scf2;
    vector scf2_pos;
    vector scf2_dir;
   
    scf2_pos[0] = 10396.3;
    scf2_pos[1] = 6.9456;
    scf2_pos[2] = 2305.37;
 
    scf2_dir[0] = -39.000015;
    scf2_dir[1] = 0;
    scf2_dir[2] = 0;

	m_scf2 = g_Game.CreateObject("Land_Castle_Stairs", scf2_pos, false);
	m_scf2.SetOrientation(scf2_dir);
	
	
	//Ramp from lower roof to roof you can't easily jump to
	
	
	ItemBase m_rmp1;
    vector rmp1_pos;
    vector rmp1_dir;
   
    rmp1_pos[0] = 10397.7;
    rmp1_pos[1] = 16.0457;
    rmp1_pos[2] = 2315.91;
 
    rmp1_dir[0] = -33;
    rmp1_dir[1] = 0;
    rmp1_dir[2] = -31;

	m_rmp1 = g_Game.CreateObject("Land_BusStop_City", rmp1_pos, false);
	m_rmp1.SetOrientation(rmp1_dir);
	
	
	//New building acting as bridge. Doesn't look right, WIP. 
	
	ItemBase m_bld1;
    vector bld1_pos;
    vector bld1_dir;
   
    bld1_pos[0] = 10445.2;
    bld1_pos[1] = 13.5101;
    bld1_pos[2] = 2299.81;
 
    bld1_dir[0] = -35;
    bld1_dir[1] = 0;
    bld1_dir[2] = 0;  //Possibly -3.46, but I think that was just user error on my logging. If it's ugly, change. 

	m_bld1 = g_Game.CreateObject("Land_HouseBlock_2F6", bld1_pos, false);
	m_bld1.SetOrientation(bld1_dir);
	
	
	//Catwalk made of boat to bridge two buildings. To be replaced with better looking model
	
	ItemBase m_cat1;
    vector cat1_pos;
    vector cat1_dir;
   
    cat1_pos[0] = 10451.9;
    cat1_pos[1] = 17.739;
    cat1_pos[2] = 2340.81;
 
    cat1_dir[0] = 34;
    cat1_dir[1] = 3;
    cat1_dir[2] = -25;

	m_cat1 = g_Game.CreateObject("Land_Boat_Small3", cat1_pos, false);
	m_cat1.SetOrientation(cat1_dir);
	
	
	//Battery for Elektro PA system. 
	
	ItemBase m_bat1;
    vector bat1_pos;
    vector bat1_dir;
   
    bat1_pos[0] = 10210.2;
    bat1_pos[1] = 25.5689;
    bat1_pos[2] = 2288;
 
    bat1_dir[0] = 140.72;
    bat1_dir[1] = -1;
    bat1_dir[2] = -0.43;

	m_bat1 = g_Game.CreateObject("CarBattery", bat1_pos, false);
	m_bat1.SetOrientation(bat1_dir);
	
}