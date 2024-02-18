#include "common.h"



DWORD AssaultH2buf[] = {0x39290001, 0x914B0D54};
DWORD AssaultH2Nukebuf[] = {0x39080001, 0x914B0D5C};
DWORD AssaultH2Skillbuf[] = {0x7D4A4A14, 0x914B0D50};
DWORD AssaultH2Grenbuf[] = {0x2B090000, 0x91771A40};


VOID Trainer584108C3()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3fury.co.uk", L"Assault Heroes 2 + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

}

VOID Press584108C3( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Lives RT(x4)\r\nInf Grenades RB(x4)\r\n30k Score LT(x4)\r\nInf Nukes LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Lives Deactivated");
			SetDWORD(/*0x82121014*/addr,0x914B0D54);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Lives Activated");
			SetDWORD(/*0x82121014*/addr,NOPThis);
			InfHealth = TRUE;
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

		if( OneHitKo == TRUE )
		{
			hNotify(L"Inf Nukes Deactivated");
			SetDWORD(/*0x82121014*/addr_Special, 0x914B0D5C);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Nukes Activated");
			SetDWORD(/*0x82121014*/addr_Special, NOPThis);
			OneHitKo = TRUE;
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

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Grenades Deactivated");
			SetDWORD(/*0x8211C4F8*/addr_Gren,0x91771A40);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenades Activated");
			SetDWORD(/*0x8211C4F8*/addr_Gren, NOPThis);
			InfAmmo = TRUE;
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

		if( InfGrenade == TRUE )
		{
			hNotify(L"30k Scores Deactivated");
			SetDWORD(/*0x8211E358*/addr_Skill, 0x7D6A5A14);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"30k Scores Activated");
			SetDWORD(/*0x8211E358*/addr_Skill, 0x39497530);
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
		SetDWORD(/*0x8211E358*/addr_Skill, 0x7D6A5A14);
		SetDWORD(/*0x8211C4F8*/addr_Gren,0x91771A40);
		SetDWORD(/*0x82121014*/addr_Special, 0x914B0D5C);
		SetDWORD(/*0x8211B554*/addr,0x914B0D54);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(/*0x8211E358*/addr_Skill, 0x39497530);
		SetDWORD(/*0x8211C4F8*/addr_Gren, NOPThis);
		SetDWORD(/*0x82121014*/addr_Special, NOPThis);
		SetDWORD(/*0x8211B554*/addr,NOPThis);
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
VOID Boot_584108C3()
{

	hNotify(L"Assault Heroes 2");
	Sleep(25);

	Run_Input = Press584108C3;
	Run_Trainer = Trainer584108C3;

	Quicklaunch1 = NullQuicklaunch1;
	Quicklaunch2 = NullQuicklaunch2;
	Quicklaunch3 = NullQuicklaunch3;
	Quicklaunch4 = NullQuicklaunch4;
	Quicklaunch5 = NullQuicklaunch5;
	Quicklaunch6 = NullQuicklaunch6;
	Quicklaunch7 = NullQuicklaunch7;
	Quicklaunch8 = NullQuicklaunch8;
	addr = GetAddr(0x82000000, 0x83000000, AssaultH2buf, 2, 1)+0x04;
	addr_Skill = GetAddr(0x82000000, 0x83000000, AssaultH2Skillbuf, 2, 1);
	addr_Special = GetAddr(0x82000000, 0x83000000, AssaultH2Nukebuf, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, AssaultH2Grenbuf, 2, 1)+ 0x04;
	SetAddr = true;
}