#pragma once
#include "hook.h"


namespace GL {
	bool __stdcall wglSwapBuffers(HDC HDC) {
	

		glDepthFunc(GL_ALWAYS);
		return wglS(HDC);
	}
}

namespace HOOK {
	
	void Hook() {
		MH_Initialize();

		MH_CreateHook(AddresSwapBuffer, &GL::wglSwapBuffers,(LPVOID*)&wglS);
		MH_EnableHook(AddresSwapBuffer);
	}

	void UnHook(LPVOID name) {
		MH_RemoveHook(name);

		MessageBoxA(0, "SUSSESSFUL", "UNHOOK", MB_OK);
	}
}
