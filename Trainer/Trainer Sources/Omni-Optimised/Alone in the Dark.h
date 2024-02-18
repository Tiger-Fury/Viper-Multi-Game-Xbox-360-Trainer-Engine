#include "common.h"

DWORD addr_ammoAitd = 0x8244E330;
DWORD Timer1_addrAitd = 0x82451BA8;
DWORD Timer2_addrAitd = 0x822AC200;

VOID Trainer494707D1()
{
	Prompt = XShowMessageBoxUI(0, L"https://www.t3fury.co.uk", L"Alone in the Dark + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

	SetDWORD(0x82451B14,0x7D7E5a14);
}


VOID Press494707D1( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Items RT(x4)\r\nInf Ammo LT(x4)\r\nFlashLight/Health Spray RB(x4)\r\nStop Critical Timer LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury r\n https://www.t3fury.co.uk", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Items Deactivated");
			SetDWORD(Timer1_addrAitd, 0x7D5E5050);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			SetDWORD(Timer1_addrAitd,0x7D5E5214);
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
			hNotify(L"Inf FlashLight/Health Spray Deactivated");
			SetDWORD(0x8244E4AC, 0xD01F0050);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf FlashLight/Health Spray Activated");
			SetDWORD(0x8244E4AC, NOPThis);
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
			SetDWORD(addr_ammoAitd,Addi_r11_FFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammoAitd, Addi_r11_1);
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

		if( InfTimer == TRUE )
		{
			hNotify(L"Stop Critical Timer");
			SetDWORD(0x823C11A8, 0xD01F012C);
			InfTimer = FALSE;
			Vibr01();

		}else{

			hNotify(L"Stop Critical Timer");
			SetDWORD(0x823C11A8, NOPThis);
			InfTimer = TRUE;
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
			SetDWORD(Timer1_addrAitd, 0x7D5E5050);
			SetDWORD(0x8244E4AC, 0xD01F0050);
			SetDWORD(addr_ammoAitd,Addi_r11_FFFF);
			SetDWORD(0x823C11A8, 0xD01F012C);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(Timer1_addrAitd, 0x7D5E5214);
			SetDWORD(0x8244E4AC, NOPThis);
			SetDWORD(addr_ammoAitd, Addi_r11_1);
			SetDWORD(0x823C11A8, NOPThis);
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

VOID Boot_494707D1()
{
	hNotify(L"Alone in the Dark");
	Sleep(25);

	Run_Input = Press494707D1;
	Run_Trainer = Trainer494707D1;

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
