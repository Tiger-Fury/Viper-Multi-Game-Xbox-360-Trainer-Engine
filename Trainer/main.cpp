#include "common.h"
#include "gamebooter.h"
#include "HudD3D.h"

DM_MEMORY_STATISTICS MemStat;
UINT32 g_titleID;

DWORD dwPlayerIndex = 0;
XINPUT_STATE state;
DWORD info;
DWORD GameID = g_titleID;

typedef struct _EX_TITLE_TERMINATE_REGISTRATION
{
	void* NotificationRoutine;
	UINT32 Priority;
	LIST_ENTRY ListEntry;
} EX_TITLE_TERMINATE_REGISTRATION, *PEX_TITLE_TERMINATE_REGISTRATION;
#ifdef __cplusplus

extern "C"
{
#endif
	//BOOL __stdcall MmIsAddressValid(UINT64 addr);
	DWORD __stdcall ExCreateThread(PHANDLE pHandle, DWORD dwStackSize, LPDWORD lpThreadId, VOID* apiThreadStartup , LPTHREAD_START_ROUTINE lpStartAddress, LPVOID lpParameter, DWORD dwCreationFlagsMod);
	VOID __stdcall ExRegisterTitleTerminateNotification(PEX_TITLE_TERMINATE_REGISTRATION, BOOL);
#ifdef __cplusplus
}
#endif

MEMORYSTATUS stat;

BOOL g_killThread = FALSE;
EX_TITLE_TERMINATE_REGISTRATION g_ettr;



void __stdcall TitleTerminate(void)
{

	if(!XamGetCurrentTitleId)
		return;

	if(XamGetCurrentTitleId() == g_titleID)
		//g_killThread = TRUE;

	return;
}

DWORD WINAPI MainThread( LPVOID lParam )
{
	DbgPrint("Main thread started\r\n");
	g_ettr.NotificationRoutine = TitleTerminate;
	g_ettr.Priority = 0x7C800000;
	ExRegisterTitleTerminateNotification(&g_ettr, TRUE);
	
	DbgPrint("Begging main loop\r\n");

	if (staticcode == 0)
     { 
      ExCreateThread(&hTh01, 0, &hThId01, (VOID*)XapiThreadStartup , 
            (LPTHREAD_START_ROUTINE)Statics, NULL, 0x2);
            staticcode = 1;
     }
	
	while( g_killThread != TRUE )
	{
		if(BootInfo != XamGetCurrentTitleId())
		{
			SetAddr = false;
			Sleep(500);
			BootInfo = XamGetCurrentTitleId();
			if(BootInfo < 0x80000000 || BootInfo == 0xFFFE07D2)
			{
				for(info = 0; info < sizeof(Game_Init)/8; info++)
				{
					if(Game_Init[info].id == BootInfo)
					{
						(*Game_Init[info].init)();
						SetAddr = true;
						break;
					}
				}
			}
		}
			if( XInputGetState( dwPlayerIndex, &state ) == ERROR_SUCCESS )
			{
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_A && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP )
								{
									   Quicklaunch1();
								}
								
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_A && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT )
								{
								       Quicklaunch2();
								}
								 			
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_A  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT )
								{
								       Quicklaunch3();
								}
								
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_A  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN )
								{
									   Quicklaunch4();
								}
						
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_X  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP )
								{
								       Quicklaunch5();
								}
								
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_X  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT )
								{
								       Quicklaunch6();
								}
								
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_X  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT )
								{
								       Quicklaunch7();
								}
					
					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_X  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN )
								{
								       Quicklaunch8();
								}

					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP )
								{
										Run_Trainer();
								}

					if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_START )
								{
										Run_Trainer();
								}
			
					if( Prompt == 0x000003E5 && g_mb_result.rgwPasscode[0] != 0x00 && g_mb_result.rgwPasscode[1] != 0x00 && g_mb_result.rgwPasscode[2] != 0x00 && g_mb_result.rgwPasscode[3] != 0x00 )
								{
										Run_Input( g_mb_result );

										memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
										memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
										memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
										memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
										Prompt = 0x9999;
								}
								}else{
										memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
										memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
										memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
										memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
										Prompt = 0x9999;
										DbgPrint("XInputGetState Failed!\r\n");
							}

					Sleep(500);
				}

			DbgPrint("Detected title end, Trainer is terminating here.");
			return 0;
		}

XUSER_SIGNIN_STATE XamUserGetSigninStateHook( DWORD DwUserIndex )
{
	return eXUserSigninState_SignedInToLive;
}

extern "C" const TCHAR szModuleName[] = TEXT("Trainer.dll");

extern "C" void Initialize( void )
{

	

	memset( &state, 0, sizeof(state) );
	DbgPrint("Resolving XamGetCurrentTitleId\r\n");
	
	XamGetCurrentTitleId = (UINT32 (*)(void))(resolveFunct("xam.xex", 0x1CF));
	
	if(!XamGetCurrentTitleId)
		return;
	
	HANDLE hThread;
	DWORD hThreadId;

	DbgPrint("Creating MainThread\r\n");
	ExCreateThread(&hThread, 0, &hThreadId, (VOID*)XapiThreadStartup , (LPTHREAD_START_ROUTINE)MainThread, NULL, 0x2);
	XSetThreadProcessor(hThread, 3);
	ResumeThread(hThread);
	CloseHandle(hThread);
	
	
	
	Sleep(3000); 
	return;
}



BOOL APIENTRY DllMain(HANDLE hInstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch( fdwReason )
	{
		case DLL_PROCESS_ATTACH:
			DbgPrint("Trainer Loaded!\r\n");
			DmSetMemoryD = (HRESULT (__cdecl *)(LPVOID, DWORD, LPCVOID, LPDWORD)) (ResolveFunct("xbdm.xex", 40));
			if (DmSetMemoryD != 0){
				KrnlType = 1;
				DmGetMemoryD = (HRESULT (__cdecl *)(LPCVOID, DWORD, LPVOID, LPDWORD)) (ResolveFunct("xbdm.xex", 10));
			}

			Initialize();

			if (KrnlType == 1){
           {
              hNotify(L"Omni Trainer Loaded");
			  hNotify(L"https://www.t3fury.co.uk");
			    Sleep(200);

				memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
				Prompt = 0x9999; 
           }
				}else{
	       {
              hNotify(L"Omni Trainer Loaded");
			  hNotify(L"https://www.t3fury.co.uk");
				Sleep(200);

				memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
				Prompt = 0x9999; 
           }

		}		 
		break;
	}


  return(TRUE);

}