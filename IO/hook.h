#pragma once
#include <MinHook.h>
#include <gl/GL.h>


#include <Windows.h>
#include <iostream>


#pragma comment(lib, "opengl32.lib")


typedef int(__stdcall* GL_s) (HDC hDc);
#ifndef Hook

DWORD *AddresSwapBuffer = (DWORD*)GetProcAddress(GetModuleHandleA("opengl32.dll"),"wglSwapBuffers");
GL_s wglS = nullptr;

void wglSwapBuffers();

#endif 


