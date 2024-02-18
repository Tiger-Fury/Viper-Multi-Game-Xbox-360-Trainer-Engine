#include "common.h"

DWORD Weaponselect = 0x83551CAC;
DWORD AmmoPoke = 0x0000001e;
DWORD ksPoke = 0x00000001;


VOID Trainer415608C3()
{
	Prompt = XShowMessageBoxUI(0, L"https://www.t3fury.co.uk", L"Black Ops 2 TU17 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	
}

VOID Press415608C3( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All SP Cheats Dpad Up(x4)\r\nAll Zombie Cheats Dpad Right(x4)\r\nZombie Blood Dpad Left(x4)\r\nInf Health RT(x4)\r\nInf Health Zombie RT(x3)+LT\r\nInf Ammo LT(x4)\r\nInf Ammo Zombie LT(x3)+RT\r\nSuper Jump LB(x4)\r\nSuper Speed LB(x3)+RB\r\nZombie Cash Y(x4)\r\nZombie Blood Dpad Left(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\n https://www.t3fury.co.uk", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			SetDWORD(addr, NOPThis);
			InfHealth = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Zombie Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Zombie Activated");
			SetDWORD(addr1, NOPThis);
			InfHealth = TRUE;
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
			SetDWORD(addr_ammo, NOPThis);
			InfAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmoZom == TRUE )
		{
			hNotify(L"Inf Ammo MP/Zom Deactivated");
			SetDWORD(0x826BE704, 0x90E30000);
			InfAmmoZom = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo MP/Zom Activated");
			SetDWORD(0x826BE704, NOPThis);
			InfAmmoZom = TRUE;
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

		if( NOAmmo == TRUE )
		{
			hNotify(L"Super Jump + No Fall Damage Deactivated");
			SetDWORD(0x82085654,0x421c0000);
			SetDWORD(0x82001650,0x43000000);
			NOAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Super Jump + No Fall Damage Activated");
			SetDWORD(0x82085654,0x491c0000);
			SetDWORD(0x82001650,0x73000000);
			NOAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( InfGrenade == TRUE )
		{
			hNotify(L"Super Speed Deactivated");
			SetDWORD(0x83556EF0,0x3f800000);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Super Speed Activated");
			SetDWORD(0x83556EF0,0x3ff00000);
			InfGrenade = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);

		if( maxcashzm == TRUE )
		{
			hNotify(L"Bling King Deactivated");
			maxcashzm = FALSE;
			Vibr01();

		}else{

			hNotify(L"Bling King Activated");
			maxcashzm = TRUE;
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
		hNotify(L"All SP Cheats Deactivated");
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All SP Cheats Activated");
		SetDWORD(addr, NOPThis);
		SetDWORD(addr_ammo, NOPThis);
		ALLCheats = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}
if( g_mb_result.rgwPasscode[0] == DPAD_RIGHT && g_mb_result.rgwPasscode[1] == DPAD_RIGHT && g_mb_result.rgwPasscode[2] == DPAD_RIGHT && g_mb_result.rgwPasscode[3] == DPAD_RIGHT )
{
	Sleep(500);

	if( ALLCheats1 == TRUE )
	{
		hNotify(L"All Zombie Cheats Deactivated");
		SetDWORD(0x8353F5EC, 0x00000000);
		SetDWORD(0x826BE704, 0x90E30000);
		maxcashzm = FALSE;
		ALLCheats2 = FALSE;
		ALLCheats1 = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Zombie Cheats Activated");
		SetDWORD(0x8353F5EC, 0x01000000);
		SetDWORD(addr1, NOPThis);
		SetDWORD(0x826BE704, NOPThis);
		maxcashzm = TRUE;
		ALLCheats2 = TRUE;
		ALLCheats1 = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}
	
if( g_mb_result.rgwPasscode[0] == DPAD_LEFT && g_mb_result.rgwPasscode[1] == DPAD_LEFT && g_mb_result.rgwPasscode[2] == DPAD_LEFT && g_mb_result.rgwPasscode[3] == DPAD_LEFT )
{
	Sleep(500);

	if( ALLCheats2 == TRUE )
	{
		hNotify(L"Zombie Blood Deactivated");
		SetDWORD(0x8353F5EC, 0x00000000);
		ALLCheats2 = FALSE;
		Vibr01();

	}else{

		hNotify(L"Zombie Blood Activated");
		ALLCheats2 = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}

}

VOID BO2Quicklaunch1()
	//wind
{
	SetDWORD(Weaponselect, 0x00000045);
		InfAmmoZom = TRUE;
}

VOID BO2Quicklaunch2()
	//ice
{
	SetDWORD(Weaponselect, 0x00000048);
	InfAmmoZom = TRUE;
}

VOID BO2Quicklaunch3()
	//fire
{
	SetDWORD(Weaponselect, 0x00000046);
	InfAmmoZom = TRUE;
}

VOID BO2Quicklaunch4()
	//lightning
{
	SetDWORD(Weaponselect, 0x00000047);
	InfAmmoZom = TRUE;
}

VOID BO2Quicklaunch5()
	//raygun
{
	SetDWORD(Weaponselect, 0x00000041);
	InfAmmoZom = TRUE;
}

VOID BO2Quicklaunch6()
	//raygun mark 2
{
	SetDWORD(Weaponselect, 0x00000042);
	InfAmmoZom = TRUE;
}

VOID BO2Quicklaunch7()
	//porters mark 2 raygun
{
	SetDWORD(Weaponselect, 0x00000043);
	InfAmmoZom = TRUE;
}


VOID BO2Quicklaunch8()
	//porters x2 raygun
{
	SetDWORD(Weaponselect, 0x00000044);
	InfAmmoZom = TRUE;
}
//Search for TU Address
VOID Boot_415608C3()
{
	hNotify(L"Black Ops 2 TU17");
	Sleep(25);

	addr = 0x82150324;

	addr1 = 0x823229D0;

	addr_ammo = 0x82150324;

	Run_Input = Press415608C3;
	Run_Trainer = Trainer415608C3;

	Quicklaunch1 = BO2Quicklaunch1;
	Quicklaunch2 = BO2Quicklaunch2;
	Quicklaunch3 = BO2Quicklaunch3;
	Quicklaunch4 = BO2Quicklaunch4;
	Quicklaunch5 = BO2Quicklaunch5;
	Quicklaunch6 = BO2Quicklaunch6;
	Quicklaunch7 = BO2Quicklaunch7;
	Quicklaunch8 = BO2Quicklaunch8;
	staticcode = 1;
	SetAddr = true;

}