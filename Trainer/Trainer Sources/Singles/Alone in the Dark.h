#include "common.h"

UINT32 g_titleID = 0x494707D1;

DWORD addr_ammo1 = 0x8244E330;
DWORD Timer1_addr = 0x82451BA8;
DWORD Timer2_addr = 0x822AC200;
DWORD Ammo_On = 0x394A7530;
DWORD Ammo_off = 0x396BFFFF;
float XValue = 200.0;
float ZValue = 0.0;


// VOID __declspec(naked) CheckHealth(VOID)
// { 
// 
// 
// 	__asm{
// 			lfs fr0,150h(r31)    // put at top with recreated
// 			lfs fr13,3FCh(r31) // put at top with recreated
//                     mflr r8
// 	     }
// 
// 	Saveregs();
// 
// 	__asm {
// 			mr MYPtr1,r31
// 	}
// 
// 	if(   *(DWORD*)(MYPtr1+0x2dc) == 0x616c6578 &&  InfHealth == TRUE )
// 	{
// 		
// 		__asm
// 		{
//  
// 			stfs XValue,150h(r31)
//             
// 		}
// 	}else{
// 		if( InfHealth == FALSE )
// 		{
// 			__asm{
// 
// 			}
// 		}
// 
// 
// 	}
// 
// 	if(   *(DWORD*)(MYPtr1+0x2dc) != 0x616c6578 &&  OneHitKo == TRUE )
// 		{
// 
// 			__asm
// 			{
// 
// 				stfs ZValue,150h(r31)
// 
// 			}
// 	
// 
// }else{
// 	if( OneHitKo == FALSE )
// 	{
// 		__asm{
// 
// 		}
// 	}
// 
// 
// }
// 	Loadregs();
// 
// 
// 
// 	__asm{
// 
// 		fcmpu cr6,fr0,fr13
// 			bgt cr6,br2 
// 
// 			mtlr r8
// 			lis r8,0x822b        
// 			ori r8,r8,0xcb00
// 			mtctr r8
// 			bctr
// 
// br2:
// 		mtlr r8
// 			lis r8,0x822B
// 			ori r8,r8,0xCB3C
// 			mtctr r8
// 			bctr
// 	}
// 
// 
// 
// }


// VOID SetHooks()
// {
//     Caveme(0x822bcaf0,CheckHealth,8);
//     HooksSet = true;
// }

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" More at T3furyGaming.co.uk", L"Alone in the Dark + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
// 	if( HooksSet == false )
// 	{
// 		SetHooks();
// 	}
	SetDWORD(0x82451B14,0x7D7E5a14);
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Items RT(x4)\r\nInf Ammo LT(x4)\r\nFlashLight/Health Spray RB(x4)\r\nStop Critical Timer LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Items Deactivated");
			SetDWORD(Timer1_addr, 0x7D5E5050);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			SetDWORD(Timer1_addr,0x7D5E5214);
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
			hNotify(L"Inf FlashLight/Health Spray Deactivated");
			SetDWORD(0x8244E4AC, 0xD01F0050);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf FlashLight/Health Spray Activated");
			SetDWORD(0x8244E4AC, NOPThis);
			OneHitKo = TRUE;
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
			SetDWORD(addr_ammo1,Addi_r11_FFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo1, Addi_r11_1);
			InfAmmo = TRUE;
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

		if( InfTimer == TRUE )
		{
			hNotify(L"Stop Critical Timer");
			SetDWORD(0x823C11A8, 0xD01F012C);
			InfTimer = FALSE;
			Vibr01();

		}else{

			hNotify(L"Stop Critical Timer");
			SetDWORD(0x823C11A8, NOPThis);
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

		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(Timer1_addr, 0x7D5E5050);
			SetDWORD(0x8244E4AC, 0xD01F0050);
			SetDWORD(addr_ammo1,Addi_r11_FFFF);
			SetDWORD(0x823C11A8, 0xD01F012C);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(Timer1_addr, 0x7D5E5214);
			SetDWORD(0x8244E4AC, NOPThis);
			SetDWORD(addr_ammo1, Addi_r11_1);
			SetDWORD(0x823C11A8, NOPThis);
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

VOID SearchAddr()
{
	hNotify(L"Alone in the Dark");
	Sleep(25);
	SetAddr = true;
}
