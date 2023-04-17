#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>

#include "hook.hpp"
bool LoadMain(HMODULE module ) {
	Beep(200, 1000);

	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	printf("SwapBuffer addres: 0x%x\n", AdressSwapBuffer);

	HOOK::Hook();
	while (!GetAsyncKeyState(VK_INSERT) & 1);
	HOOK::UnHook(AdressSwapBuffer);


	FreeLibrary(module);
	return 0;
}



int WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved
) {
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)LoadMain, 0, 0, 0);
	case DLL_PROCESS_DETACH:
		break;
	}
	return 1;
}