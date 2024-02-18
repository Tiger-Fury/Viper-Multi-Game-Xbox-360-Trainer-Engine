#include "common.h"

UINT32 g_titleID = 0x584113C6;

bool OneHitKo = false;
bool HooksSet = false;
bool InfHealth = false;
WORD Ptr1;
float XValue = 1000.0;
float ZValue = 0.0;


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		    lfs fr13,0C0h(r3)
                    lfs fr0,1090h(r11)
                    li r11,1
                    mflr r5
	     }

	Saveregs();



	if( InfHealth == TRUE )
	{
		
		__asm
		{
 
			stfs XValue,0C0h(r3)
            
		}

	}else{
		if( InfHealth == FALSE )
		{
			__asm{
          
			}
		}
	

	}

	Loadregs();



	__asm{

                        fcmpu cr6,fr13,fr0
                        ble cr6,br2
                         
                        mtlr r5
			lis r5,0x8240        
			ori r5,r5,0xEFE8
			mtctr r5
			bctr

br2:
                        mtlr r5
			lis r5,0x8240
			ori r5,r5,0xEFEC
			mtctr r5
			bctr
	}



}

VOID SetHooks()
{
    Caveme(0x8240efd4,CheckHealth,5);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Test Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		SetHooks();
	}
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
}