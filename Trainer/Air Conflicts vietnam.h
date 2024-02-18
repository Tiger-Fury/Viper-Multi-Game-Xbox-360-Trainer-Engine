#include "common.h"


DWORD AConVbuf[] = {0x41820370, 0xC01A0000};
DWORD AConVbufAmmo[] = {0x812B0064, 0x3929FFFF};
DWORD AConVbufGren[] = {0x817D0000, 0x396BFFFF};
DWORD AConVbufAfter[] = {0x4BF13A31, 0xC01F0000};

VOID __declspec(naked) ACVietCheckHealth(VOID)
{ 


	__asm{
		lfs fr0,0(r26)
			mflr r3
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r26

	}

	if( InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1) = 0x46E55900;			
	}

	Loadregs();



	__asm{

		fcmpu cr6,fr0,fr28
		blt cr6,br2
		add r10,r31,r15

			mtlr r3

br2:
		lis r3,0x821e  
			ori r3,r3,0x0eec
			mtctr r3
			bctr

	}



}

VOID AConVSetHooks()
{
	Caveme(addr,ACVietCheckHealth,3);
	HooksSet = true;
}

VOID Trainer413307D9()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3fury.co.uk", L"Air Conflicts Vietnam + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		AConVSetHooks();
	}
}


VOID Press413307D9( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf AfterBurner RB(x4)\r\nInf Cannon LT(x4)\r\nInf Flares LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( OneHitKo == TRUE )
		{
			hNotify(L"Inf AfterBurner Deactivated");
			SetDWORD(addr_After,0xEC000828);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf AfterBurner Activated");
			SetDWORD(addr_After,NOPThis);
			OneHitKo = TRUE;
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
			hNotify(L"Inf Cannon Deactivated");
			SetDWORD(addr_ammo,0x3929FFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Cannon Activated");
			SetDWORD(addr_ammo,0x39290000);
			InfAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( InfGrenade == TRUE )
		{
			hNotify(L"Inf Flares Deactivated");
			SetDWORD(addr_Gren,0x396BFFFF);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Flares Activated");
			SetDWORD(addr_Gren,0x396B0000);
			InfGrenade = TRUE;
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
		SetDWORD(addr_After,0xEC000828);
		SetDWORD(addr_ammo,0x3929FFFF);
		SetDWORD(addr_Gren,0x396BFFFF);
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_After,NOPThis);
		SetDWORD(addr_ammo,0x39290000);
		SetDWORD(addr_Gren,0x396B0000);
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
VOID Boot_413307D9()
{
	hNotify(L"Air Conflicts Vietnam");
	Sleep(25);

	Run_Input = Press413307D9;
	Run_Trainer = Trainer413307D9;

	Quicklaunch1 = NullQuicklaunch1;
	Quicklaunch2 = NullQuicklaunch2;
	Quicklaunch3 = NullQuicklaunch3;
	Quicklaunch4 = NullQuicklaunch4;
	Quicklaunch5 = NullQuicklaunch5;
	Quicklaunch6 = NullQuicklaunch6;
	Quicklaunch7 = NullQuicklaunch7;
	Quicklaunch8 = NullQuicklaunch8;

	addr = GetAddr(0x82000000, 0x83000000, AConVbuf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, AConVbufAmmo, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x821B0140, 0x83000000, AConVbufGren, 2, 1)+ 0x04;
	addr_After = GetAddr(0x821B0B7C, 0x83000000, AConVbufAfter, 2, 1)+ 0x08;
	SetAddr = true;
}