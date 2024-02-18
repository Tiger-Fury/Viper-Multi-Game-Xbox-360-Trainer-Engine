#include "common.h"


VOID Trainer425307F5()
{
	Prompt = XShowMessageBoxUI(0, L"https://www.t3fury.co.uk", L"Wolfenstein The New Order + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

}


VOID Press425307F5( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Laser Cutter RB(x4)\r\nInf Ammo LT(x4)\r\nInf Armor LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\n https://www.t3fury.co.uk", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Health Deactivated");
			SetDWORD(0x82A548F4, 0xD01F0004);
			SetDWORD(0x82A54748, 0xD17F0004);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			SetDWORD(0x82A548F4, NOPThis);
			SetDWORD(0x82A54748, NOPThis);
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
			hNotify(L"Inf Laser Cutter Deactivated");
			SetDWORD(0x82D9D214, 0x917F0254);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Laser Cutter Activated");
			SetDWORD(0x82D9D214, NOPThis);
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
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(0x82D9422C,0x93C30010);
			SetDWORD(0x82D94268,0x93DF0010);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(0x82D9422C,NOPThis);
			SetDWORD(0x82D94268,NOPThis);
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

		if( NoWeight == TRUE )
		{
			hNotify(L"Inf Armor Deactivated");
			SetDWORD(0x82A5485C,0xD1BF000C);
			NoWeight = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Armor Activated");
			SetDWORD(0x82A5485C,NOPThis);
			NoWeight = TRUE;
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

		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(0x82A548F4, 0xD01F0004);
			SetDWORD(0x82A54748, 0xD17F0004);
			SetDWORD(0x82D9D214, 0x917F0254);
			SetDWORD(0x82D9422C,0x93C30010);
			SetDWORD(0x82D94268,0x93DF0010);
			SetDWORD(0x82A5485C,0xD1BF000C);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(0x82A548F4, NOPThis);
			SetDWORD(0x82A54748, NOPThis);
			SetDWORD(0x82D9D214, NOPThis);
			SetDWORD(0x82D9422C,NOPThis);
			SetDWORD(0x82D94268,NOPThis);
			SetDWORD(0x82A5485C,NOPThis);
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

VOID Boot_425307F5()
{
	hNotify(L"Wolfenstein: The New Order");
	Sleep(25);

	Run_Input = Press425307F5;
	Run_Trainer = Trainer425307F5;

	Quicklaunch1 = NullQuicklaunch1;
	Quicklaunch2 = NullQuicklaunch2;
	Quicklaunch3 = NullQuicklaunch3;
	Quicklaunch4 = NullQuicklaunch4;
	Quicklaunch5 = NullQuicklaunch5;
	Quicklaunch6 = NullQuicklaunch6;
	Quicklaunch7 = NullQuicklaunch7;
	Quicklaunch8 = NullQuicklaunch8;
	SetAddr = true;
}