#include "common.h"




VOID Trainer44500807()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3fury.co.uk", L"Adventure Time E.T.D BIDK +5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID Press44500807( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Special LB(x4)\r\nInf Keys RB(x4)\r\nInf Treasure X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat

		if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
		{
			Sleep(500);

			if( CheatRB == TRUE )
			{
				hNotify(L"Inf Treasure Deactivated");
				SetDWORD(0x82615638, 0x7D244A14);
				SetDWORD(0x82636C44, 0x7CEB4050);
				SetDWORD(0x826157F0, 0x7D26212E);
				CheatRB = FALSE;
				Vibr01();

			}else{

				hNotify(L"Inf Treasure Activated");			
				SetDWORD(0x82615638, 0x392003E7);
				SetDWORD(0x82636C44, 0x38E003E7);
				SetDWORD(0x826157F0, NOPThis);
				CheatRB = true;
				Vibr01();

			}

			memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
			memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
			memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
			memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
			Prompt = 0x9999;
		}
		// 2nd cheat
    if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);
		
		if( InfMoney == TRUE )
		{
			hNotify(L"Inf Special Deactivated");
			SetDWORD(0x82611F84, 0xD00A138C);
			SetDWORD(0x8261431C, 0xD1BF138C);
			InfMoney = FALSE;
			Vibr01();
		}else{
			hNotify(L"Inf Special Activated");
			SetDWORD(0x82611F84, 0xD1AA138C);
			SetDWORD(0x8261431C, 0xD3FF138C);
			InfMoney = TRUE;
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
			SetDWORD(0x8263A4E0, 0x396BFFFF);
			InfAmmo = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Ammo Activated");
			SetDWORD(0x8263A4E0, 0x396B0000);
			InfAmmo = TRUE;
		    Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//4th cheat
			if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Deactivated");
			SetDWORD(0x82619610, 0x38890063);
			InfHealth = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Health Activated");
			SetDWORD(0x82619610, NOPThis);
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

				if( InfTimer == TRUE )
				{
					hNotify(L"Inf keys Deactivated");
					SetDWORD(0x82615BAC, 0x7D0B512E);
					SetDWORD(0x82583028, 0x38890001);
					SetDWORD(0x825CDCFC, 0x38E90002);
					InfTimer = FALSE;
					Vibr01();

				}else{

					hNotify(L"Inf keys Activated");
					SetDWORD(0x82615BAC, NOPThis);
					SetDWORD(0x82583028, 0x38890063);
					SetDWORD(0x825CDCFC, 0x38E90063);
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
		
		if( AllCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(0x82615BAC, 0x7D0B512E);
			SetDWORD(0x82583028, 0x38890001);
			SetDWORD(0x825CDCFC, 0x38E90002);
			SetDWORD(0x82619610, 0x38890063);
			SetDWORD(0x8263A4E0, 0x396BFFFF);
			SetDWORD(0x82615638, 0x7D244A14);
			SetDWORD(0x82636C44, 0x7CEB4050);
			SetDWORD(0x826157F0, 0x7D26212E);
			SetDWORD(0x82611F84, 0xD00A138C);
			SetDWORD(0x8261431C, 0xD1BF138C);
			AllCheats = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"All Cheats Activated");
			SetDWORD(0x82615BAC, NOPThis);
			SetDWORD(0x82583028, 0x38890063);
			SetDWORD(0x825CDCFC, 0x38E90063);
			SetDWORD(0x82619610, NOPThis);
			SetDWORD(0x8263A4E0, 0x396B0000);
			SetDWORD(0x82615638, 0x392003E7);
			SetDWORD(0x82636C44, 0x38E003E7);
			SetDWORD(0x826157F0, NOPThis);;
			SetDWORD(0x82611F84, 0xD1AA138C);
			SetDWORD(0x8261431C, 0xD3FF138C);
			AllCheats = TRUE;
		    Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
				
}

VOID Boot_44500807()
{
	hNotify(L"Adventure Time Explore The Dungeon BIDK");
	Sleep(25);

	Run_Input = Press44500807;
	Run_Trainer = Trainer44500807;

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