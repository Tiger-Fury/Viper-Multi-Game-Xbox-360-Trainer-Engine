#include "common.h"


DWORD AlienRbuf[] = {0x814B0308, 0x812B0304};
DWORD AlienRbufAmmo[] = {0x7CA8F82E, 0x7C853850};
DWORD AlienRbufItem[] = {0x814b0658, 0x890a0265};

VOID __declspec(naked) AlienRCheckHealth(VOID)
{ 


	__asm{
		lwz r9,304h(r11)

			mflr r18
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11				
	}

	if(InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x304) = 0x000005DC;

	}
	Loadregs();



	__asm{

		extsw r8,r10
		extsw r7,r9
		std r8,60h(r1)

			mtlr r18
			lis r18,0x82bf
			ori r18,r18,0x4758
			mtctr r18
			bctr


	}



}

VOID AlienRSetHooks()
{
	Caveme(addr ,AlienRCheckHealth,18);
	HooksSet = true;
}

VOID Trainer58410B22()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3fury.co.uk", L"Alien Rage + 2\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		AlienRSetHooks();
	}
}


VOID Press58410B22( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3fury.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
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
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(addr_ammo,0x7C853850);
			SetDWORD(addr_ammo +0x04,0x7C653050);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo,0x388003E7);
			SetDWORD(addr_ammo +0x04,0x386003E7);
			InfAmmo = TRUE;
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

	if(ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		SetDWORD(addr_ammo,0x7C853850);
		SetDWORD(addr_ammo +0x04,0x7C653050);
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_ammo,0x388003E7);
		SetDWORD(addr_ammo +0x04,0x386003E7);
		InfHealth = TRUE;
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
VOID Boot_58410B22()
{
	hNotify(L"Alien Rage");
	Sleep(25);

	Run_Input = Press58410B22;
	Run_Trainer = Trainer58410B22;

	Quicklaunch1 = NullQuicklaunch1;
	Quicklaunch2 = NullQuicklaunch2;
	Quicklaunch3 = NullQuicklaunch3;
	Quicklaunch4 = NullQuicklaunch4;
	Quicklaunch5 = NullQuicklaunch5;
	Quicklaunch6 = NullQuicklaunch6;
	Quicklaunch7 = NullQuicklaunch7;
	Quicklaunch8 = NullQuicklaunch8;
	addr = GetAddr(0x82000000, 0x83000000, AlienRbuf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x82A00000, 0x83000000, AlienRbufAmmo, 2, 1)+ 0x04;
	addr_Items = GetAddr(0x82000000, 0x83000000, AlienRbufItem, 2, 1)+ 0x04;

	SetAddr = true;
}