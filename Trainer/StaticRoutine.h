//#################Show Trainer#########################
UINT32 (*XamGetCurrentTitleId)(void);

static void Statics(){
	while (1){
	if(0x58411233 == XamGetCurrentTitleId())//alan wake AN			
		if (InfHealth == TRUE)
		{
			SetDWORD(0xDF7361A8, 0x3f800000);

		} 
	if(0x415608C3 == XamGetCurrentTitleId())//CoDBlops2
		if (maxcashzm == TRUE)
		{
			SetDWORD(0x83556FD8, 0x000f4240);
		}  

		if (ALLCheats2 == TRUE)
		{
			SetDWORD(0x8353F5EC, 0x01000000);

		} 
	if(0x41560855 == XamGetCurrentTitleId())//CoDBlops
		if (Max_Cash == TRUE)
		{
		 	SetDWORD(0x82DC33B4,0x77359400);
		 
		} 
	if(0x4156081C == XamGetCurrentTitleId())//CoDwaw
		if (Max_Cash == TRUE)
		{
			SetDWORD(0x82ABCCBC, 0x77359400);

		} 
	if(0x415608FC == XamGetCurrentTitleId())//CoDGhosts
		if (InfHealth == TRUE)
		{
			SetDWORD(0x8321FDEC,0x00000064);
			SetDWORD(0x83379DA8,0x00000064);
		} 
	if(0x415607E6 == XamGetCurrentTitleId())//CoDMW
		if (InfHealth == TRUE)
		{
			SetDWORD(0x828E1C2C, 0x00000064);
		}  
	if(0x415608CB == XamGetCurrentTitleId())//CoDMW3
		if (InfHealth == TRUE)
		{
			SetDWORD(0x82F666B0, 0x00000064);
		}   
		if (Max_Cash == TRUE)
		{
			SetDWORD(0x82F666B0, Max_IT);
		}
		Sleep(10); 
	}
}

