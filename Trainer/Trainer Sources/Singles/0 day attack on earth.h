#include "common.h"

UINT32 g_titleID = 0x584109B7;


bool AIAmmo = false;
bool InfBP = false;
bool TU = false;



bool CheckGame = FALSE;
bool CheckGame2 = FALSE;
bool GameReady = false;

BYTE gcheck[] = { 0x00 };
BYTE gcheck2[] = { 0x00 };

BYTE gchecktu[] = { 0x00 };
BYTE gchecktu2[] = { 0x00 };

BYTE nop[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnano[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnades[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopammo[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nophealth[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnv[] = { 0x60, 0x00, 0x00, 0x00 };

BYTE nano[] = { 0x7d, 0x6b, 0x52, 0x14 }; // 7D6B5214

BYTE XpMode[] = { 0x39, 0x60, 0x7f, 0xff }; // 39607FFF

BYTE ammo[] = { 0x91, 0x7f, 0x05, 0x84 }; // 917F0584

BYTE health[] = { 0x7d, 0x6a, 0x58, 0x50 }; // 7D6A5850
BYTE healthact[] = { 0x39, 0x60, 0x27, 0x10 }; // on 39602710

BYTE nades[] = { 0x90, 0x88, 0x00, 0x64 }; // 90880064

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };



VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3fury.co.uk", L"0 Day Attack On Earth +3 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
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
			pop(L"Inf Boost Deactivated");
			DoCheat(0x820DD644, nades, 4);
			CheatRB = FALSE;
			Vibr01();

		}else{
			
			pop(L"Inf Boost Activated");			
			DoCheat(0x820DD644, nopnades, 4);
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
			pop(L"Inf Time Deactivated");
			DoCheat(0x820A4FF8, ammo, 4);
			CheatLT = FALSE;
	        Vibr01();

		}else{
			
			pop(L"Inf Time Activated");
			DoCheat(0x820A4FF8, nopammo, 4);
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
			pop(L"Inf Health  Deactivated");
			DoCheat(0x820DCDB4, health, 4);
			CheatRT = FALSE;
	        Vibr01();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x820DCDB4, healthact, 4);
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
			pop(L"All Cheats Deactivated");
			DoCheat(0x820DD644, nades, 4);
			DoCheat(0x820A4FF8, ammo, 4);
			DoCheat(0x820DCDB4, health, 4);
			CheatDU = FALSE;
	        Vibr01();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x820DD644, nopnades, 4);
			DoCheat(0x820A4FF8, nopammo, 4);
			DoCheat(0x820DCDB4, healthact, 4);
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

VOID SearchAddr()
{
		hNotify(L"0 Day Attack on Earth");
		Sleep(25);
		SetAddr = true;
}
 