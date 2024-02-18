#include "common.h"


DWORD AotGbuf[] = {0xFC000018, 0xD003021C};
DWORD AotGbuf1[] = {0x817D0148, 0x93DD014C};


VOID __declspec(naked) AotGCheckHealth(VOID)
{ 

	__asm{

			lfd fr0,-10h(r1)
			fcfid fr0,fr0
			frsp fr0,fr0 
			stfs fr0,21Ch(r3)
			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr2,r3	
	}

	if(*(DWORD*)(MYPtr2 + 0x5D5) == 0x6c617965 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x21C) = *(DWORD*)(MYPtr2 + 0x220);

	}
	else if(*(DWORD*)(MYPtr2 + 0x5D5) != 0x6c617965 && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x21C) = 0x00000000;

	}

	Loadregs();

	__asm{
		
		mtlr r15
		blr
	}
}

VOID __declspec(naked) AotGCheckScore(VOID)
{ 

	__asm{

	//	lwz r3,0Ch(r28)
	//	stw r30,148h(r28)
		lwz r11,148h(r29)
		stw r30,14Ch(r29)
			mflr r14
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r10
		mr MYPtr2,r29	
	}

	if(*(DWORD*)(MYPtr2 + 0x15D) == 0x50006c00 && InfScore == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x14C) = 0x05F5E0FF;

	}

	Loadregs();

	__asm{
		ori r10,r10,9680h
		cmpw cr6,r11,r10
		blt cr6,br2
		mtlr r14
br2:
		lis r14,0x822A
			ori r14,r14,0xD1D0
			mtctr r14
			bctr
	}
}

VOID AotGSetHooks()
{

	Caveme(addr ,AotGCheckHealth,15);
	Caveme(addr1 ,AotGCheckScore,14);
		HooksSet = true;
}



VOID Trainer58410886()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3fury.co.uk", L"Aces Of The Galaxy +4 \r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
				if( HooksSet == false )
				{
					AotGSetHooks();
				}

}

VOID Press58410886( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Bullet Time LT(x4)\r\n1 Hit Kill RB(x4)\r\n5 Stars LB(x4)\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
		
		if( InfTimer == TRUE )
		{
			hNotify(L"Inf Bullet Time Deactivated");
			SetDWORD(0x82200834, 0xd01f0258);
			InfTimer = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Bullet Time Activated");
			SetDWORD(0x82200834, NOPThis);
			InfTimer = TRUE;
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

		if( InfScore == TRUE )
		{
			hNotify(L"5 Star Levels Deactivated");
			InfScore = FALSE;
			Vibr01();

		}else{

			hNotify(L"5 Star Levels Activated");
			InfScore = TRUE;
			Vibr01();

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
			hNotify(L"Inf Health Deactivated");
			InfHealth = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Health Activated");
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
					hNotify(L"One Hit Kill Deactivated");
					OneHitKo = FALSE;
					Vibr01();

				}else{

					hNotify(L"One Hit Kill Activated");
					OneHitKo = TRUE;
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
			SetDWORD(0x82200834, 0xd01f0258);
			InfHealth = FALSE;
			InfScore = FALSE;
			OneHitKo = FALSE;
			CheatDU = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"All Cheats Activated");
			SetDWORD(0x82200834, NOPThis);
			InfHealth = TRUE;
			InfScore = TRUE;
			OneHitKo = TRUE;
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



VOID Boot_58410886()
{
	hNotify(L"Aces of the Galaxy");

			Sleep(25);

			Run_Input = Press58410886;
			Run_Trainer = Trainer58410886;

			Quicklaunch1 = NullQuicklaunch1;
			Quicklaunch2 = NullQuicklaunch2;
			Quicklaunch3 = NullQuicklaunch3;
			Quicklaunch4 = NullQuicklaunch4;
			Quicklaunch5 = NullQuicklaunch5;
			Quicklaunch6 = NullQuicklaunch6;
			Quicklaunch7 = NullQuicklaunch7;
			Quicklaunch8 = NullQuicklaunch8;
			Sleep(25);
 			addr = GetAddr(0x82000000, 0x83000000, AotGbuf, 2, 1)- 0x08;
 			addr1 = GetAddr(0x82000000, 0x83000000, AotGbuf1, 2, 1);

			SetAddr = true;
}