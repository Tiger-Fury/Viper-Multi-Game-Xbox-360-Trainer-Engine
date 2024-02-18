#include "common.h"




VOID Trainer584109B7()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3fury.co.uk", L"0 Day Attack On Earth +3 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID Press584109B7( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Time LT(x4)\r\nInf Boost RB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Boost Deactivated");
			SetDWORD(0x820DD644, 0x90880064);
			CheatRB = FALSE;
			Vibr01();

		}else{
			
			hNotify(L"Inf Boost Activated");	
			SetDWORD(0x820DD644, NOPThis);
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
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatLT == TRUE )
		{
			hNotify(L"Inf Time Deactivated");
			SetDWORD(0x820A4FF8, 0x917F0584);
			CheatLT = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Time Activated");
			SetDWORD(0x820A4FF8, NOPThis);
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
			hNotify(L"Inf Health  Deactivated");
			SetDWORD(0x820DCDB4, 0x7D6A5850);
			CheatRT = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Health Activated");
			SetDWORD(0x820DCDB4, 0x39602710);
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
			SetDWORD(0x820DD644, 0x90880064);
			SetDWORD(0x820A4FF8, 0x917F0584);
			SetDWORD(0x820DCDB4, 0x7D6A5850);
			CheatDU = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"All Cheats Activated");
			SetDWORD(0x820DD644, NOPThis);
			SetDWORD(0x820A4FF8, NOPThis);
			SetDWORD(0x820DCDB4, 0x39602710);
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

VOID Boot_584109B7()
{
		hNotify(L"0 Day Attack on Earth");
		Sleep(25);

		Run_Input = Press584109B7;
		Run_Trainer = Trainer584109B7;

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
 