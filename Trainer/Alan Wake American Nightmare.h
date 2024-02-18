#include "common.h"



// static void Statics(){
// 	while (1){
// 
// 		if (InfHealth == TRUE)
// 		{
// 			SetDWORD(0xDF7361A8, 0x3f800000);
// 
// 		} 
// 		
// 		Sleep(10); 
// 	}
// } 


/*VOID __declspec(naked) CheckHP(VOID) {
	
	/*
	    822D90AC       lfs fr13,-19F0h(r11) 
		822D90B0     fmadds fr0,fr31,fr0,fr13 
		822D90B4     fnmsubs fr0,fr0,fr30,fr12 
		822D90B8     stfs fr0,118Ch(r30)//breakpoint 
		Return address
		822D90BC     mr r3,r30

	DWORD dwPtr;

 __asm {
	mr dwPtr,r25
       lfs fr13,-19F0h(r11) 
	   fmadds fr0,fr31,fr0,fr13 
	   fnmsubs fr0,fr0,fr30,fr12 
       stfs fr0,118Ch(r30)//breakpoint  

 }

 if (dwPtr == 0x00 && InfHealth == TRUE) {
  float fltValue = 100.0f;
  __asm 
  { 

	stfs fltValue,118Ch(r30)
  }

 }else{

if( InfHealth == FALSE )
	 {
		 __asm
		 {

		 }
	 }

 }
 if (dwPtr == 0x01 && OneHitKo == TRUE) {
	 float XValue = -1.0f;
	 __asm 
	 { 

		 stfs XValue,118Ch(r30)
	 }

 }else{

	 if( OneHitKo == FALSE )
	 {
		 __asm
		 {

		 }
	 }

 }
 
 // 82ECC2D0
 __asm{
  lis r11,0x822D   
  ori r11,r11,0x90BC
  mtctr r11
  bctr      
 }
 
}

VOID SetHooks()
{


	 DWORD IHealth[4];
	 patchInJump( (PDWORD)IHealth, (DWORD)CheckHP, FALSE );
	 
		DoCave(0x822D90AC, &IHealth[0], 4);
		DoCave(0x822D90B0, &IHealth[1], 4);
		DoCave(0x822D90B4, &IHealth[2], 4);
		DoCave(0x822D90B8, &IHealth[3], 4);

		HooksSet = true;
}*/


VOID Trainer58411233()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3fury.co.uk", L"Alan Wake American Nightmare +4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

				//if( HooksSet == false )
				//{
					//SetHooks();
				//}

}

VOID Press58411233( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades RB(x4)\r\nInf Light LB(x4)\r\nHope You Enjoy\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(0x823F2754, 0x7CCAF92E);
			CheatLT = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"Inf Ammo Activated");
			SetDWORD(0x823F2754, NOPThis);
			CheatLT = TRUE;
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
					hNotify(L"Inf Grenades Deactivated");
					SetDWORD(0x82410094, 0x7C69F92E);
					OneHitKo = FALSE;
					Vibr01();

				}else{

					hNotify(L"Inf Grenades Activated");
					SetDWORD(0x82410094, NOPThis);
					OneHitKo = TRUE;
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

				if( MaxCash == TRUE )
				{
					hNotify(L"Inf Light Deactivated");
					SetDWORD(0x82350478, 0xD1890004);
					MaxCash = FALSE;
					Vibr01();

				}else{

					hNotify(L"Inf Light Activated");
					SetDWORD(0x82350478, NOPThis);
					MaxCash = TRUE;
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
			SetDWORD(0x82350478, 0xD1890004);
			SetDWORD(0x82410094, 0x7C69F92E);
			SetDWORD(0x823F2754, 0x7CCAF92E);
			InfHealth = FALSE;
			CheatDU = FALSE;
	        Vibr01();

		}else{
			
			hNotify(L"All Cheats Activated");
			SetDWORD(0x82350478, NOPThis);
			SetDWORD(0x82410094, NOPThis);
			SetDWORD(0x823F2754, NOPThis);
			InfHealth = TRUE;
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

VOID Boot_58411233()
{
	hNotify(L"Alan Wake: American Nightmare");
	Sleep(25);
	Run_Input = Press58411233;
	Run_Trainer = Trainer58411233;

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