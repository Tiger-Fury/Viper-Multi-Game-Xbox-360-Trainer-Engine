#include "common.h"

DWORD Weaponselect = 0x83551CAC;
// Cheat -----------------------------------------------------------------------------------
DWORD pokeShealth = 0x39400FA0;



VOID Trainer415608C3()
{
	Prompt = XShowMessageBoxUI(0, L" More at T3fury.co.uk", L"Cod Blops2 TU18 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID Press415608C3( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		if(Gamexex == 0)
		{
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Campaign Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
		}
		if(Gamexex == 1)
		{
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Zombies/MP Cheats Dpad Up(x4)\r\nInf Zombies Health RT(x4)\r\nInf Zombies Ammo LT(x4)\r\nSuper Jump LB(x4)\r\nSuper Speed RB(x4)\r\nZombie Cash Y(x4)\r\nZombie Blood X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
		}
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
			if(Gamexex == 0)
			{
				hNotify(L"Inf Health Deactivated");
				SetDWORD(0x8229D144, 0x917B01A0);
				InfHealth = FALSE;
				Vibr01();
			}
			if(Gamexex == 1)
			{
				hNotify(L"Inf Health Zombies Deactivated");
				SetDWORD(0x823229D0, 0x911F01A8);
				InfHealth = FALSE;
				Vibr01();
			}


		}else{

			if(Gamexex == 0)
			{
				hNotify(L"Inf Health Activated");
				SetDWORD(0x8229D144, NOPThis);
				InfHealth = TRUE;
				Vibr01();
			}
			if(Gamexex == 1)
			{
				hNotify(L"Inf Health Zombie Activated");
				SetDWORD(0x823229D0, NOPThis);
				InfHealth = TRUE;
				Vibr01();
			}
	

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
			if(Gamexex == 0)
			{
				hNotify(L"Inf Ammo Deactivated");
				SetDWORD(0x82150324, 0x90E30000);
				InfAmmo = FALSE;
				Vibr01();
			}
			if(Gamexex == 1)
			{
				hNotify(L"Inf Ammo MP/Zombies Deactivated");
				SetDWORD(0x826BE71C, 0x90E30000);
				InfAmmo = FALSE;
				Vibr01();
			}
		

		}else{

			if(Gamexex == 0)
			{
				hNotify(L"Inf Ammo Activated");
				SetDWORD(0x82150324, NOPThis);
				InfAmmo = TRUE;
				Vibr01();
			}
			if(Gamexex == 1)
			{
				hNotify(L"Inf Ammo MP/Zombies Activated");
				SetDWORD(0x826BE71C, NOPThis);
				InfAmmo = TRUE;
				Vibr01();
			}

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
			if(Gamexex == 1)
			{
			hNotify(L"Super Jump + No Fall Damage Deactivated");
			SetDWORD(0x82085654,0x421c0000);
			SetDWORD(0x82001650,0x43000000);
			NOAmmo = FALSE;
			Vibr01();
			}
		}else{

			if(Gamexex == 1)
			{
			hNotify(L"Super Jump + No Fall Damage Activated");
			SetDWORD(0x82085654,0x491c0000);
			SetDWORD(0x82001650,0x73000000);
			NOAmmo = TRUE;
			Vibr01();
			}
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

		if( InfGrenade == TRUE )
		{
			if(Gamexex == 1)
			{
			hNotify(L"Super Speed Deactivated");
			SetDWORD(0x83556EF0,0x3f800000);
			InfGrenade = FALSE;
			Vibr01();
			}
		}else{

			if(Gamexex == 1)
			{
			hNotify(L"Super Speed Activated");
			SetDWORD(0x83556EF0,0x3ff00000);
			InfGrenade = TRUE;
			Vibr01();
			}
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
			if(Gamexex == 1)
			{
			hNotify(L"Bling King Deactivated");
			maxcashzm = FALSE;
			Vibr01();
			}
		}else{

			if(Gamexex == 1)
			{
			hNotify(L"Bling King Activated");
			maxcashzm = TRUE;
			Vibr01();
			}
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
		if(Gamexex == 0)
		{
		hNotify(L"All Campaign Cheats Deactivated");
		SetDWORD(0x8229D144, 0x917B01A0);
		SetDWORD(0x82150324, 0x90E30000);
		ALLCheats = FALSE;
		Vibr01();
		}
		if(Gamexex == 1)
		{
			hNotify(L"All Zombie/MP Cheats Deactivated");
			SetDWORD(0x8353F5EC, 0x00000000);
			SetDWORD(0x826BE71C, 0x90E30000);
			maxcashzm = FALSE;
			ALLCheats2 = FALSE;
			ALLCheats = FALSE;
			Vibr01();
		}
	}else{

		if(Gamexex == 0)
		{
		hNotify(L"All Campaign Cheats Activated");
		SetDWORD(0x8229D144, NOPThis);
		SetDWORD(0x82150324, NOPThis);
		ALLCheats = TRUE;
		Vibr01();
		}
		if(Gamexex == 1)
		{
			hNotify(L"All Zombie/MP Cheats Activated");
			SetDWORD(0x8353F5EC, 0x01000000);
			SetDWORD(0x823229D0, NOPThis);
			SetDWORD(0x826BE71C, NOPThis);
			maxcashzm = TRUE;
			ALLCheats2 = TRUE;
			ALLCheats = TRUE;
			Vibr01();
		}
	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}

if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
{
	Sleep(500);

	if( ALLCheats2 == TRUE )
	{
		if(Gamexex == 1)
		{
		hNotify(L"Zombie Blood Deactivated");
		ALLCheats2 = FALSE;
		Vibr01();
		}
	}else{
		if(Gamexex == 1)
		{
		hNotify(L"Zombie Blood Activated");
		ALLCheats2 = TRUE;
		Vibr01();
		}
	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}
}

VOID blops2Quicklaunch1()
	//wind
{
	SetDWORD(Weaponselect, 0x00000045);
		InfAmmoZom = TRUE;
}



VOID blops2Quicklaunch2()
	//ice
{
	SetDWORD(Weaponselect, 0x00000048);
	InfAmmoZom = TRUE;
}

VOID blops2Quicklaunch3()
	//fire
{
	SetDWORD(Weaponselect, 0x00000046);
	InfAmmoZom = TRUE;
}

VOID blops2Quicklaunch4()
	//lightning
{
	SetDWORD(Weaponselect, 0x00000047);
	InfAmmoZom = TRUE;
}

VOID blops2Quicklaunch5()
	//raygun
{
	SetDWORD(Weaponselect, 0x00000041);
	InfAmmoZom = TRUE;
}

VOID blops2Quicklaunch6()
	//raygun mark 2
{
	SetDWORD(Weaponselect, 0x00000042);
	InfAmmoZom = TRUE;
}

VOID blops2Quicklaunch7()
	//porters mark 2 raygun
{
	SetDWORD(Weaponselect, 0x00000043);
	InfAmmoZom = TRUE;
}

VOID blops2Quicklaunch8()
	//porters x2 raygun
{
	SetDWORD(Weaponselect, 0x00000044);
	InfAmmoZom = TRUE;
}
//Search for TU Address
VOID Boot_415608C3()
{
	Run_Input = Press415608C3;
	Run_Trainer = Trainer415608C3;
	if (GetDWORD(0x82294B04) == 0x1D440370)
	{
		hNotify(L"Call of Duty: Black Ops 2");
		Gamexex = 0;
		Sleep(25);
		SetAddr = true;
	}
	if (GetDWORD(0x82294B04) == 0x2F030000)
	{
		hNotify(L"Call of Duty: Black Ops 2 MP/Zombie");
		Gamexex = 1;
		Sleep(25);
		Quicklaunch1 = blops2Quicklaunch1;
		Quicklaunch2 = blops2Quicklaunch2;
		Quicklaunch3 = blops2Quicklaunch3;
		Quicklaunch4 = blops2Quicklaunch4;
		Quicklaunch5 = blops2Quicklaunch5;
		Quicklaunch6 = blops2Quicklaunch6;
		Quicklaunch7 = blops2Quicklaunch7;
		Quicklaunch8 = blops2Quicklaunch8;
		SetAddr = true;
	}
	

	

}