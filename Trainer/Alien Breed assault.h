#include "common.h"



DWORD AlienBassbuf[] = {0x419A007C, 0x817F02D8};
DWORD AlienBassbufAmmo[] = {0x817e0330, 0x815e032c};
DWORD AlienBassbufItem[] = {0x814B0650, 0x890a0261};

VOID __declspec(naked) AlienBassCheckHealth(VOID)
{ 


	__asm{
		lwz r11,2D8h(r31)

			mflr r14
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
	}

	if(InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x2D8) = 0x00000064;

	}
	Loadregs();



	__asm{

		cmpwi cr6,r11,0 
		ble cr6,br2
		lbz r11,90h(r31)

			mtlr r14
			lis r14,0x82e1   
			ori r14,r14,0xba7c
			mtctr r14
			bctr

br2:
		mtlr r14
			lis r14,0x82e1  
			ori r14,r14,0xbae4
			mtctr r14
			bctr

	}



}

VOID __declspec(naked) AlienBassCheckAmmo(VOID)
{ 


	__asm{
		lwz r10,32Ch(r30)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr2,r30
	}

	if(InfAmmo == TRUE)
	{
			*(DWORD*)(MYPtr2+0x32c) = 0x000003e7;

	}
	Loadregs();



	__asm{

		lwz r9,2E4h(r30)
		add r11,r10,r11
		lwz r8,61Ch(r31)

			mtlr r15
			lis r15,0x82e1    
			ori r15,r15,0x4e64
			mtctr r15
			bctr

	}



}

VOID __declspec(naked) AlienBassCheckItem(VOID)
{ 


	__asm{
		lbz r8,261h(r10)

			mflr r14
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r10
	}

	if(InfItems == TRUE)
	{
		*(DWORD*)(MYPtr1+0x264) = 0x00000063;

	}
	Loadregs();



	__asm{

		lfs fr30,268h(r10) 
		lfs fr29,26Ch(r10)
		std r8,50h(r1)

			mtlr r14
			lis r14,0x82e1
			ori r14,r14,0x9740
			mtctr r14
			bctr

	}



}

VOID AlienBassSetHooks()
{
	Caveme(addr_ammo,AlienBassCheckAmmo,15);
	Caveme(addr	,AlienBassCheckHealth,14);
	Caveme(addr_Items,AlienBassCheckItem,14);
	HooksSet = true;
}

VOID Trainer58410A22()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3fury.co.uk", L"Alien Breed 2: Assault + 3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		AlienBassSetHooks();
	}
}


VOID Press58410A22( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Items RB(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			InfHealth = TRUE;
			Vibr01();

		}
		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( InfItems == TRUE )
		{
			hNotify(L"Inf Items Deactivated");
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			InfItems = TRUE;
			Vibr01();

		}
		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			InfAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
{
	Sleep(500);

	if(ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		InfItems = FALSE;
		InfAmmo = FALSE;
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfItems = TRUE;
		InfAmmo = TRUE;
		InfHealth = TRUE;
		ALLCheats = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}

}
VOID Boot_58410A22()
{
	hNotify(L"Alien Breed 2: Assault");
	Sleep(25);

	Run_Input = Press58410A22;
	Run_Trainer = Trainer58410A22;

	Quicklaunch1 = NullQuicklaunch1;
	Quicklaunch2 = NullQuicklaunch2;
	Quicklaunch3 = NullQuicklaunch3;
	Quicklaunch4 = NullQuicklaunch4;
	Quicklaunch5 = NullQuicklaunch5;
	Quicklaunch6 = NullQuicklaunch6;
	Quicklaunch7 = NullQuicklaunch7;
	Quicklaunch8 = NullQuicklaunch8;
	addr = GetAddr(0x82E00000, 0x83000000, AlienBassbuf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x82A00000, 0x83000000, AlienBassbufAmmo, 2, 1)+ 0x04;
	addr_Items = GetAddr(0x82000000, 0x83000000, AlienBassbufItem, 2, 1)+ 0x04;

	SetAddr = true;
}