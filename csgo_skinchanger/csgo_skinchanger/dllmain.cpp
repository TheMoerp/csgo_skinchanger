#include <Windows.h>
#include <stdio.h>
#include <iostream>

#include "hook.h"
#include "skinchanger.h"


uintptr_t clientBase;
FrameStageNotify oFrameStageNotify = nullptr;


void _stdcall hkFrameStageNotify(ClientFrameStage_t curStage) {
	if (curStage == FRAME_NET_UPDATE_POSTDATAUPDATE_START) {
		skinchanger();
	}
	oFrameStageNotify(curStage);
}



DWORD WINAPI MainThread(HMODULE hModule) {
	tCreateInterface clientFact = (tCreateInterface)GetProcAddress(GetModuleHandleA("client.dll"), "CreateInterface");
	void* client = clientFact("VClient018", NULL);
	uintptr_t* clientVTable = (*reinterpret_cast<uintptr_t**>(client));

	oFrameStageNotify = (FrameStageNotify)TrampHook((char*)vTable[37], (char*)hkFrameStageNotify, 9);

	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
	/*AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);*/
	clientBase = (uintptr_t)GetModuleHandle(L"client.dll");

	switch (reason) {
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hModule, 0, nullptr));
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}