#pragma once
#include <Windows.h>


bool Hook(char* src, char* dst, int len);

char* TrampHook(char* src, char* dst, unsigned int len);

enum ClientFrameStage_t : int {
    FRAME_UNDEFINED = -1,
    FRAME_START,
    FRAME_NET_UPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_START,
    FRAME_NET_UPDATE_POSTDATAUPDATE_END,
    FRAME_NET_UPDATE_END,
    FRAME_RENDER_START,
    FRAME_RENDER_END
};

typedef void(_stdcall* FrameStageNotify)(ClientFrameStage_t curStage);

typedef void* (__cdecl* tCreateInterface)(const char* name, int* returnCode);