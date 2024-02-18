#include "common.h"

UINT32 g_titleID = 0x4B4E083C;


DWORD MYPtr1;
DWORD addr_ammo1 = 0x82291A7C;
DWORD Ammo_On = 0x396003E7;
DWORD Ammo_off = 0x914B00E4;
DWORD Null_It = 0x00000000;
float XValue = 10000.0;
WORD HV = 0x1f40;
DWORD HVaddr;
DWORD Recaddr;
DWORD RoFaddr;
HVbuf[] = {0xA17E0E5A, 0xB17F0008};
DWORD Recbuf[] = {0x3A83126F, 0x3B800000};
DWORD RoFbuf[] = {0x3DA3D70A, 0x3FC90FDB};
float ZValue = 0.0;


VOID __declspec(naked) CheckHealth(VOID)
{ 
	__asm{
			lhz r11,0E5Ah(r30)

            mflr r15
	     }

	Saveregs();

	__asm 
	{
			mr MYPtr1,r30
	}

	if(InfHealth = TRUE)
	{
		if(*(WORD*)(MYPtr1+0xE5a) == 0x1f40)
			*(WORD*)(MYPtr1+0xE5c) = 0x7f40;
			
	}
	Loadregs();

	__asm{

		sth r11,8(r31)
		lwz r10,0E60h(r30)
		stw r10,0Ch(r31)

			mtlr r15
			lis r15,0x827b     
			ori r15,r15,0xdc0c
			mtctr r15
			bctr

	}



}


VOID SetHooks()
{
	HVaddr = GetAddr(0x827B0000, 0x83000000, HVbuf, 2, 1);
    Caveme(HVaddr,CheckHealth,15);
	Recaddr = GetAddr(0x82000000, 0x83000000, Recbuf, 2, 1);
	RoFaddr = GetAddr(0x82000000, 0x83000000, RoFbuf, 2, 1);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"t3fury XPGamesaves.com", L"MGS Peace Walker + 3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nRate of Fire LT(x4)\r\nNo Recoil LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury r\nXPGamesaves.com\r\nHome To 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Rate of Fire Deactivated");
			SetDWORD(RoFaddr,0x3da3d70a);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Rate of Fire Activated");
			SetDWORD(RoFaddr, Null_It);
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

		if( InfGrenade == TRUE )
		{
			hNotify(L"No Recoil Deactivated");
			SetDWORD(Recaddr, 0x3a83126f);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Recoil Activated");
			SetDWORD(Recaddr, Null_It);
			InfGrenade = TRUE;
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
	hNotify(L"MGS Peace Walker");
	Sleep(25);
	SetAddr = true;
}