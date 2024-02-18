#include "common.h"


DWORD crysisbuf[] = {0xFC0A5FEE, 0xD01F01F4};
DWORD crysisbufSpecial[] = {0xD3FF0030, 0x38210150};
DWORD crysisbufAmmo[] = {0x419A000C, 0x93A30014};
DWORD crysisbufGren[] = {0x7D484B78, 0x91030000};
DWORD crysisbufNano[] = {0xC00A7C90, 0xD1BF0160};

VOID __declspec(naked) crysisCheckHealth(VOID)
{ 


	__asm{
		stfs fr0,1F4h(r31)

			mflr r2
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r8
			mr MYPtr2,r31
	}

	if(MYPtr1 == 0x7777  && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x1F4) = 0x43480000;

	}

	Loadregs();



	__asm{

		fsel fr13,fr31,fr8,fr13
			fcmpu cr6,fr0,fr9
			frsp fr13,fr13

			mtlr r2
			lis r2,0x82DF
			ori r2,r2,0xB04C
			mtctr r2
			bctr

	}
}

VOID crysisSetHooks()
{
	Caveme(addr ,crysisCheckHealth,2);
	HooksSet = true;
}

VOID Trainer45410968()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3fury.co.uk", L"Crysis +5 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		crysisSetHooks();
	}
}

VOID Press45410968( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Nano Energy LB(x4)\r\nInf Grenades RB(x4)\r\nInf Night Vision Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
		
		if( InfGrenade == TRUE )
		{
			hNotify(L"Inf Grenades Deactivated");
			SetDWORD(addr_Gren, 0x91030000);
			InfGrenade = FALSE;
			Vibr01();

		}else{
			
			hNotify(L"Inf Grenades Activated");			
			SetDWORD(addr_Gren, NOPThis);
			InfGrenade = true;
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
		
		if( InfStamina == TRUE )
		{
			hNotify(L"Inf Nano Energy Deactivated");
			SetDWORD(addr_Stamina, 0xD3FF0030);
			InfStamina = FALSE;
			Vibr01();
		}else{
			hNotify(L"Inf Nano Energy Activated");
			SetDWORD(addr_Stamina, NOPThis);
			InfStamina = TRUE;
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
		
		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(addr_ammo, 0x93A30014);
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
	//4th cheat
			if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Deactivated");
	//		SetDWORD(addr, 0xD01F01F4);
			InfHealth = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Health Activated");
	//		SetDWORD(addr, NOPThis);
			InfHealth = TRUE;
		    Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	// 5th cheat
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);
		
		if( InfSpecial == TRUE )
		{
			hNotify(L"Inf Night Vision Deactivated");
			SetDWORD(addr_Special, 0xD1BF0160);
			InfSpecial = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Night Vision Activated");
			SetDWORD(addr_Special, NOPThis);
			InfSpecial = TRUE;
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
		
		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(addr_Gren, 0x91030000); 
			SetDWORD(0x82E1B864, 0xD3FF0030);
			SetDWORD(addr_ammo, 0x93A30014);
			InfHealth = FALSE;
			SetDWORD(addr_Special, 0xD1BF0160);
			ALLCheats = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"All Cheats Activated");
			SetDWORD(addr_Gren, NOPThis);
			SetDWORD(0x82E1B864, NOPThis);
			SetDWORD(addr_ammo, NOPThis);
			InfHealth = TRUE;
			SetDWORD(addr_Special, NOPThis);
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

VOID Boot_45410968()
{
	hNotify(L"Crysis");
	Sleep(25);
	addr = GetAddr(0x82000000, 0x83000000, crysisbuf, 2, 1)+ 0x04;
	addr_Special = GetAddr(0x82000000, 0x83000000, crysisbufNano, 2, 1);
	addr_ammo = GetAddr(0x82A00000, 0x83000000, crysisbufAmmo, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, crysisbufGren, 2, 1)+ 0x04;
	addr_Stamina = GetAddr(0x82A00000, 0x83000000, crysisbufSpecial, 2, 1)+ 0x04;
	SetAddr = true;
}