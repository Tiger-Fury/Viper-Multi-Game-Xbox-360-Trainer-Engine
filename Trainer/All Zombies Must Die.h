#include "common.h"



VOID Trainer58411204()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3fury.co.uk", L"All Zombies Must Die +6 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID Press58411204( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"Inf Health/Ammo RT(x4)\r\nInf Upgrade Points LT(x4)\r\nEasy XP/Inf Gold LB(x4)\r\nInf Smart Bomb RB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat
		if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);
		
		if( CheatRB == TRUE )
		{
			hNotify(L"Inf Smart Bomb Deactivated");
			SetDWORD(0x829980AC, 0x90880064);
			CheatRB = FALSE;
			Vibr01();

		}else{
			
			hNotify(L"Inf Smart Bomb Activated");			
			SetDWORD(0x829980AC, NOPThis);
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
		
		if( CheatLB == TRUE )
		{
			hNotify(L"Easy XP/Credits Deactivated");
			SetDWORD(0x82221D54, 0x7D6B5214);
			CheatLB = FALSE;
			Vibr01();
		}else{
			hNotify(L"Easy XP/Credits Activated");
			SetDWORD(0x82221D54, 0x39607FFF);
			CheatLB = TRUE;
			Vibr01();
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatLT == TRUE )
		{
			hNotify(L"Inf Upgrade Points Deactivated");
			SetDWORD(0x8299802C, 0x90880010);
			CheatLT = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Upgrade Points Activated");
			SetDWORD(0x8299802C, NOPThis);
			CheatLT = TRUE;
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
		
		if( CheatRT == TRUE )
		{
			hNotify(L"Inf Health/Ammo  Deactivated");
			SetDWORD(0x822223F8, 0x915E0000);
			CheatRT = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Health/Ammo Activated");
			SetDWORD(0x822223F8, NOPThis);
			CheatRT = TRUE;
		    Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
			
		
	//6th cheat Multi Activate
	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);
		
		if( CheatDU == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(0x829980AC, 0x90880064);
			SetDWORD(0x8299802C, 0x90880010);
			SetDWORD(0x822223F8, 0x915E0000);
			CheatDU = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"All Cheats Activated");
			SetDWORD(0x829980AC, NOPThis);
			SetDWORD(0x8299802C, NOPThis);
			SetDWORD(0x822223F8, NOPThis);
			CheatDU = TRUE;
		    Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
				
}
 


VOID Boot_58411204()
{
	hNotify(L"All Zombies Must Die");
	Sleep(25);

	Run_Input = Press58411204;
	Run_Trainer = Trainer58411204;

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