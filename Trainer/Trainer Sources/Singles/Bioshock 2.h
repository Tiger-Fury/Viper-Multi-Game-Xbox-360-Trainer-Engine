#include "common.h"

UINT32 g_titleID = 0x54540861;


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		stfs fr8,5C4h(r31)

			mflr r16
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
		mr MYPtr2,r0
	}

	if(MYPtr2 != 0x010C && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x5C4) = 0x43960000;

	}
	if(MYPtr2 == 0x010C && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1+0x5C4) = 0;

	}
	Loadregs();



	__asm{

		beq cr6,br2
		lwz r11,0(r31) 
		mr r3,r31 


		mtlr r16
		lis r16,0x8270     
		ori r16,r16,0x04E8
		mtctr r16
		bctr

br2:
		mtlr r16
			lis r16,0x8270
			ori r16,r16,0x04F4
			mtctr r16
			bctr

	}


}

VOID SetHooks()
{
	Caveme(addr ,CheckHealth,16);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at https://www.t3fury.co.uk", L"Bioshock 2 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\n1 Hit Kill RB(x4)\r\nInf Ammo LT(x4)\r\nInf Fuel LB(x4)\r\nInf EVE Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(addr_ammo, 0x90FD0000);
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
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( InfSpecial == TRUE )
		{
			hNotify(L"Inf Fuel Deactivated");
			SetDWORD(addr_ammo1, 0x910B004C);
			InfSpecial = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Fuel Activated");
			SetDWORD(addr_ammo1, NOPThis);
			InfSpecial = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
{
	Sleep(500);

	if( InfAbility == TRUE )
	{
		hNotify(L"Inf Eve Deactivated");
		SetDWORD(addr_Ability, 0xD0DF0CB0);
		InfAbility = FALSE;
		Vibr01();

	}else{

		hNotify(L"Inf Eve Activated");
		SetDWORD(addr_Ability, NOPThis);
		InfAbility = TRUE;
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
		InfHealth = FALSE;
		OneHitKo = FALSE;
		SetDWORD(addr_ammo, 0x90FD0000);
		SetDWORD(addr_ammo1, 0x910B004C);
		SetDWORD(addr_Ability, 0xD0DF0CB0);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfHealth = TRUE;
		OneHitKo = TRUE;
		SetDWORD(addr_ammo, NOPThis); 
		SetDWORD(addr_ammo1, NOPThis);
		SetDWORD(addr_Ability, NOPThis);
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

//Search for TU Address
VOID SearchAddr()
{
	hNotify(L"Bioshock 2");
	Sleep(25);

	DWORD buf[] = {0xFD004818, 0xD11F05C4};
	DWORD Ammo_buf[] = {0x90FD0000, 0x90FC0000};
	DWORD Drill_buf[] = {0x7D0A4850, 0x910B004C};
	//DWORD exp_buf[] = {0xEDA0082A, 0x7DABED2E};
	//DWORD renown_buf[] = {0x7D7DE214, 0x556A003E};
	DWORD Plasma_buf[] = {0xFCC03818, 0xD0DF0CB0};
	
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1) + 0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, Ammo_buf, 2, 1);
	addr_ammo1 = GetAddr(0x82000000, 0x83000000, Drill_buf, 2, 1) + 0x04;
	addr_Ability = GetAddr(0x82000000, 0x83000000, Plasma_buf, 1, 2) + 0x04;
	
	//Renown_addr = GetAddr(0x82000000, 0x83000000, renown_buf, 2, 1);
	Static_Menu = Null_Menu;
}