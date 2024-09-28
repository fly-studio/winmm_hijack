// winmm.dll HiJack Project
// Caution: 
//   This project code is for testing purposes only! Please do not use it in any other way.
// Code By : Baymax Patch toOls 
//

#include <windows.h>
#include <Strsafe.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <tchar.h>


#define EXTERNC extern "C"
#define NAKED   __declspec(naked)
#define EXPORT  __declspec(dllexport)

#define NSCPP   EXPORT          NAKED 
#define NSSTD   EXTERNC EXPORT  NAKED void __stdcall
#define NSCFAST EXTERNC EXPORT  NAKED void __fastcall
#define NSCDECL EXTERNC         NAKED void __cdecl


#define HIJACK_DLLNAME L"\\winmm.dll"
HMODULE g_hSourceModule = NULL;
HMODULE g_hCurrentModule = NULL;


PVOID pfCloseDriver = NULL;
PVOID pfDefDriverProc = NULL;
PVOID pfDriverCallback = NULL;
PVOID pfDrvGetModuleHandle = NULL;
PVOID pfGetDriverModuleHandle = NULL;
PVOID pfNotifyCallbackData = NULL;
PVOID pfOpenDriver = NULL;
PVOID pfPlaySound = NULL;
PVOID pfPlaySoundA = NULL;
PVOID pfPlaySoundW = NULL;
PVOID pfSendDriverMessage = NULL;
PVOID pfWOW32DriverCallback = NULL;
PVOID pfWOW32ResolveMultiMediaHandle = NULL;
PVOID pfWOWAppExit = NULL;
PVOID pfaux32Message = NULL;
PVOID pfauxGetDevCapsA = NULL;
PVOID pfauxGetDevCapsW = NULL;
PVOID pfauxGetNumDevs = NULL;
PVOID pfauxGetVolume = NULL;
PVOID pfauxOutMessage = NULL;
PVOID pfauxSetVolume = NULL;
PVOID pfjoy32Message = NULL;
PVOID pfjoyConfigChanged = NULL;
PVOID pfjoyGetDevCapsA = NULL;
PVOID pfjoyGetDevCapsW = NULL;
PVOID pfjoyGetNumDevs = NULL;
PVOID pfjoyGetPos = NULL;
PVOID pfjoyGetPosEx = NULL;
PVOID pfjoyGetThreshold = NULL;
PVOID pfjoyReleaseCapture = NULL;
PVOID pfjoySetCapture = NULL;
PVOID pfjoySetThreshold = NULL;
PVOID pfmci32Message = NULL;
PVOID pfmciDriverNotify = NULL;
PVOID pfmciDriverYield = NULL;
PVOID pfmciExecute = NULL;
PVOID pfmciFreeCommandResource = NULL;
PVOID pfmciGetCreatorTask = NULL;
PVOID pfmciGetDeviceIDA = NULL;
PVOID pfmciGetDeviceIDFromElementIDA = NULL;
PVOID pfmciGetDeviceIDFromElementIDW = NULL;
PVOID pfmciGetDeviceIDW = NULL;
PVOID pfmciGetDriverData = NULL;
PVOID pfmciGetErrorStringA = NULL;
PVOID pfmciGetErrorStringW = NULL;
PVOID pfmciGetYieldProc = NULL;
PVOID pfmciLoadCommandResource = NULL;
PVOID pfmciSendCommandA = NULL;
PVOID pfmciSendCommandW = NULL;
PVOID pfmciSendStringA = NULL;
PVOID pfmciSendStringW = NULL;
PVOID pfmciSetDriverData = NULL;
PVOID pfmciSetYieldProc = NULL;
PVOID pfmid32Message = NULL;
PVOID pfmidiConnect = NULL;
PVOID pfmidiDisconnect = NULL;
PVOID pfmidiInAddBuffer = NULL;
PVOID pfmidiInClose = NULL;
PVOID pfmidiInGetDevCapsA = NULL;
PVOID pfmidiInGetDevCapsW = NULL;
PVOID pfmidiInGetErrorTextA = NULL;
PVOID pfmidiInGetErrorTextW = NULL;
PVOID pfmidiInGetID = NULL;
PVOID pfmidiInGetNumDevs = NULL;
PVOID pfmidiInMessage = NULL;
PVOID pfmidiInOpen = NULL;
PVOID pfmidiInPrepareHeader = NULL;
PVOID pfmidiInReset = NULL;
PVOID pfmidiInStart = NULL;
PVOID pfmidiInStop = NULL;
PVOID pfmidiInUnprepareHeader = NULL;
PVOID pfmidiOutCacheDrumPatches = NULL;
PVOID pfmidiOutCachePatches = NULL;
PVOID pfmidiOutClose = NULL;
PVOID pfmidiOutGetDevCapsA = NULL;
PVOID pfmidiOutGetDevCapsW = NULL;
PVOID pfmidiOutGetErrorTextA = NULL;
PVOID pfmidiOutGetErrorTextW = NULL;
PVOID pfmidiOutGetID = NULL;
PVOID pfmidiOutGetNumDevs = NULL;
PVOID pfmidiOutGetVolume = NULL;
PVOID pfmidiOutLongMsg = NULL;
PVOID pfmidiOutMessage = NULL;
PVOID pfmidiOutOpen = NULL;
PVOID pfmidiOutPrepareHeader = NULL;
PVOID pfmidiOutReset = NULL;
PVOID pfmidiOutSetVolume = NULL;
PVOID pfmidiOutShortMsg = NULL;
PVOID pfmidiOutUnprepareHeader = NULL;
PVOID pfmidiStreamClose = NULL;
PVOID pfmidiStreamOpen = NULL;
PVOID pfmidiStreamOut = NULL;
PVOID pfmidiStreamPause = NULL;
PVOID pfmidiStreamPosition = NULL;
PVOID pfmidiStreamProperty = NULL;
PVOID pfmidiStreamRestart = NULL;
PVOID pfmidiStreamStop = NULL;
PVOID pfmixerClose = NULL;
PVOID pfmixerGetControlDetailsA = NULL;
PVOID pfmixerGetControlDetailsW = NULL;
PVOID pfmixerGetDevCapsA = NULL;
PVOID pfmixerGetDevCapsW = NULL;
PVOID pfmixerGetID = NULL;
PVOID pfmixerGetLineControlsA = NULL;
PVOID pfmixerGetLineControlsW = NULL;
PVOID pfmixerGetLineInfoA = NULL;
PVOID pfmixerGetLineInfoW = NULL;
PVOID pfmixerGetNumDevs = NULL;
PVOID pfmixerMessage = NULL;
PVOID pfmixerOpen = NULL;
PVOID pfmixerSetControlDetails = NULL;
PVOID pfmmDrvInstall = NULL;
PVOID pfmmGetCurrentTask = NULL;
PVOID pfmmTaskBlock = NULL;
PVOID pfmmTaskCreate = NULL;
PVOID pfmmTaskSignal = NULL;
PVOID pfmmTaskYield = NULL;
PVOID pfmmioAdvance = NULL;
PVOID pfmmioAscend = NULL;
PVOID pfmmioClose = NULL;
PVOID pfmmioCreateChunk = NULL;
PVOID pfmmioDescend = NULL;
PVOID pfmmioFlush = NULL;
PVOID pfmmioGetInfo = NULL;
PVOID pfmmioInstallIOProcA = NULL;
PVOID pfmmioInstallIOProcW = NULL;
PVOID pfmmioOpenA = NULL;
PVOID pfmmioOpenW = NULL;
PVOID pfmmioRead = NULL;
PVOID pfmmioRenameA = NULL;
PVOID pfmmioRenameW = NULL;
PVOID pfmmioSeek = NULL;
PVOID pfmmioSendMessage = NULL;
PVOID pfmmioSetBuffer = NULL;
PVOID pfmmioSetInfo = NULL;
PVOID pfmmioStringToFOURCCA = NULL;
PVOID pfmmioStringToFOURCCW = NULL;
PVOID pfmmioWrite = NULL;
PVOID pfmmsystemGetVersion = NULL;
PVOID pfmod32Message = NULL;
PVOID pfmxd32Message = NULL;
PVOID pfsndPlaySoundA = NULL;
PVOID pfsndPlaySoundW = NULL;
PVOID pftid32Message = NULL;
PVOID pftimeBeginPeriod = NULL;
PVOID pftimeEndPeriod = NULL;
PVOID pftimeGetDevCaps = NULL;
PVOID pftimeGetSystemTime = NULL;
PVOID pftimeGetTime = NULL;
PVOID pftimeKillEvent = NULL;
PVOID pftimeSetEvent = NULL;
PVOID pfwaveInAddBuffer = NULL;
PVOID pfwaveInClose = NULL;
PVOID pfwaveInGetDevCapsA = NULL;
PVOID pfwaveInGetDevCapsW = NULL;
PVOID pfwaveInGetErrorTextA = NULL;
PVOID pfwaveInGetErrorTextW = NULL;
PVOID pfwaveInGetID = NULL;
PVOID pfwaveInGetNumDevs = NULL;
PVOID pfwaveInGetPosition = NULL;
PVOID pfwaveInMessage = NULL;
PVOID pfwaveInOpen = NULL;
PVOID pfwaveInPrepareHeader = NULL;
PVOID pfwaveInReset = NULL;
PVOID pfwaveInStart = NULL;
PVOID pfwaveInStop = NULL;
PVOID pfwaveInUnprepareHeader = NULL;
PVOID pfwaveOutBreakLoop = NULL;
PVOID pfwaveOutClose = NULL;
PVOID pfwaveOutGetDevCapsA = NULL;
PVOID pfwaveOutGetDevCapsW = NULL;
PVOID pfwaveOutGetErrorTextA = NULL;
PVOID pfwaveOutGetErrorTextW = NULL;
PVOID pfwaveOutGetID = NULL;
PVOID pfwaveOutGetNumDevs = NULL;
PVOID pfwaveOutGetPitch = NULL;
PVOID pfwaveOutGetPlaybackRate = NULL;
PVOID pfwaveOutGetPosition = NULL;
PVOID pfwaveOutGetVolume = NULL;
PVOID pfwaveOutMessage = NULL;
PVOID pfwaveOutOpen = NULL;
PVOID pfwaveOutPause = NULL;
PVOID pfwaveOutPrepareHeader = NULL;
PVOID pfwaveOutReset = NULL;
PVOID pfwaveOutRestart = NULL;
PVOID pfwaveOutSetPitch = NULL;
PVOID pfwaveOutSetPlaybackRate = NULL;
PVOID pfwaveOutSetVolume = NULL;
PVOID pfwaveOutUnprepareHeader = NULL;
PVOID pfwaveOutWrite = NULL;
PVOID pfwid32Message = NULL;
PVOID pfwod32Message = NULL;
PVOID pfNsUnknowProc_2 = NULL;


NSCDECL NsHiJack_CloseDriver(void)
{
    __asm JMP pfCloseDriver; 
}

NSCDECL NsHiJack_DefDriverProc(void)
{
    __asm JMP pfDefDriverProc; 
}

NSCDECL NsHiJack_DriverCallback(void)
{
    __asm JMP pfDriverCallback; 
}

NSCDECL NsHiJack_DrvGetModuleHandle(void)
{
    __asm JMP pfDrvGetModuleHandle; 
}

NSCDECL NsHiJack_GetDriverModuleHandle(void)
{
    __asm JMP pfGetDriverModuleHandle; 
}

NSCDECL NsHiJack_NotifyCallbackData(void)
{
    __asm JMP pfNotifyCallbackData; 
}

NSCDECL NsHiJack_OpenDriver(void)
{
    __asm JMP pfOpenDriver; 
}

NSCDECL NsHiJack_PlaySound(void)
{
    __asm JMP pfPlaySound; 
}

NSCDECL NsHiJack_PlaySoundA(void)
{
    __asm JMP pfPlaySoundA; 
}

NSCDECL NsHiJack_PlaySoundW(void)
{
    __asm JMP pfPlaySoundW; 
}

NSCDECL NsHiJack_SendDriverMessage(void)
{
    __asm JMP pfSendDriverMessage; 
}

NSCDECL NsHiJack_WOW32DriverCallback(void)
{
    __asm JMP pfWOW32DriverCallback; 
}

NSCDECL NsHiJack_WOW32ResolveMultiMediaHandle(void)
{
    __asm JMP pfWOW32ResolveMultiMediaHandle; 
}

NSCDECL NsHiJack_WOWAppExit(void)
{
    __asm JMP pfWOWAppExit; 
}

NSCDECL NsHiJack_aux32Message(void)
{
    __asm JMP pfaux32Message; 
}

NSCDECL NsHiJack_auxGetDevCapsA(void)
{
    __asm JMP pfauxGetDevCapsA; 
}

NSCDECL NsHiJack_auxGetDevCapsW(void)
{
    __asm JMP pfauxGetDevCapsW; 
}

NSCDECL NsHiJack_auxGetNumDevs(void)
{
    __asm JMP pfauxGetNumDevs; 
}

NSCDECL NsHiJack_auxGetVolume(void)
{
    __asm JMP pfauxGetVolume; 
}

NSCDECL NsHiJack_auxOutMessage(void)
{
    __asm JMP pfauxOutMessage; 
}

NSCDECL NsHiJack_auxSetVolume(void)
{
    __asm JMP pfauxSetVolume; 
}

NSCDECL NsHiJack_joy32Message(void)
{
    __asm JMP pfjoy32Message; 
}

NSCDECL NsHiJack_joyConfigChanged(void)
{
    __asm JMP pfjoyConfigChanged; 
}

NSCDECL NsHiJack_joyGetDevCapsA(void)
{
    __asm JMP pfjoyGetDevCapsA; 
}

NSCDECL NsHiJack_joyGetDevCapsW(void)
{
    __asm JMP pfjoyGetDevCapsW; 
}

NSCDECL NsHiJack_joyGetNumDevs(void)
{
    __asm JMP pfjoyGetNumDevs; 
}

NSCDECL NsHiJack_joyGetPos(void)
{
    __asm JMP pfjoyGetPos; 
}

NSCDECL NsHiJack_joyGetPosEx(void)
{
    __asm JMP pfjoyGetPosEx; 
}

NSCDECL NsHiJack_joyGetThreshold(void)
{
    __asm JMP pfjoyGetThreshold; 
}

NSCDECL NsHiJack_joyReleaseCapture(void)
{
    __asm JMP pfjoyReleaseCapture; 
}

NSCDECL NsHiJack_joySetCapture(void)
{
    __asm JMP pfjoySetCapture; 
}

NSCDECL NsHiJack_joySetThreshold(void)
{
    __asm JMP pfjoySetThreshold; 
}

NSCDECL NsHiJack_mci32Message(void)
{
    __asm JMP pfmci32Message; 
}

NSCDECL NsHiJack_mciDriverNotify(void)
{
    __asm JMP pfmciDriverNotify; 
}

NSCDECL NsHiJack_mciDriverYield(void)
{
    __asm JMP pfmciDriverYield; 
}

NSCDECL NsHiJack_mciExecute(void)
{
    __asm JMP pfmciExecute; 
}

NSCDECL NsHiJack_mciFreeCommandResource(void)
{
    __asm JMP pfmciFreeCommandResource; 
}

NSCDECL NsHiJack_mciGetCreatorTask(void)
{
    __asm JMP pfmciGetCreatorTask; 
}

NSCDECL NsHiJack_mciGetDeviceIDA(void)
{
    __asm JMP pfmciGetDeviceIDA; 
}

NSCDECL NsHiJack_mciGetDeviceIDFromElementIDA(void)
{
    __asm JMP pfmciGetDeviceIDFromElementIDA; 
}

NSCDECL NsHiJack_mciGetDeviceIDFromElementIDW(void)
{
    __asm JMP pfmciGetDeviceIDFromElementIDW; 
}

NSCDECL NsHiJack_mciGetDeviceIDW(void)
{
    __asm JMP pfmciGetDeviceIDW; 
}

NSCDECL NsHiJack_mciGetDriverData(void)
{
    __asm JMP pfmciGetDriverData; 
}

NSCDECL NsHiJack_mciGetErrorStringA(void)
{
    __asm JMP pfmciGetErrorStringA; 
}

NSCDECL NsHiJack_mciGetErrorStringW(void)
{
    __asm JMP pfmciGetErrorStringW; 
}

NSCDECL NsHiJack_mciGetYieldProc(void)
{
    __asm JMP pfmciGetYieldProc; 
}

NSCDECL NsHiJack_mciLoadCommandResource(void)
{
    __asm JMP pfmciLoadCommandResource; 
}

NSCDECL NsHiJack_mciSendCommandA(void)
{
    __asm JMP pfmciSendCommandA; 
}

NSCDECL NsHiJack_mciSendCommandW(void)
{
    __asm JMP pfmciSendCommandW; 
}

NSCDECL NsHiJack_mciSendStringA(void)
{
    __asm JMP pfmciSendStringA; 
}

NSCDECL NsHiJack_mciSendStringW(void)
{
    __asm JMP pfmciSendStringW; 
}

NSCDECL NsHiJack_mciSetDriverData(void)
{
    __asm JMP pfmciSetDriverData; 
}

NSCDECL NsHiJack_mciSetYieldProc(void)
{
    __asm JMP pfmciSetYieldProc; 
}

NSCDECL NsHiJack_mid32Message(void)
{
    __asm JMP pfmid32Message; 
}

NSCDECL NsHiJack_midiConnect(void)
{
    __asm JMP pfmidiConnect; 
}

NSCDECL NsHiJack_midiDisconnect(void)
{
    __asm JMP pfmidiDisconnect; 
}

NSCDECL NsHiJack_midiInAddBuffer(void)
{
    __asm JMP pfmidiInAddBuffer; 
}

NSCDECL NsHiJack_midiInClose(void)
{
    __asm JMP pfmidiInClose; 
}

NSCDECL NsHiJack_midiInGetDevCapsA(void)
{
    __asm JMP pfmidiInGetDevCapsA; 
}

NSCDECL NsHiJack_midiInGetDevCapsW(void)
{
    __asm JMP pfmidiInGetDevCapsW; 
}

NSCDECL NsHiJack_midiInGetErrorTextA(void)
{
    __asm JMP pfmidiInGetErrorTextA; 
}

NSCDECL NsHiJack_midiInGetErrorTextW(void)
{
    __asm JMP pfmidiInGetErrorTextW; 
}

NSCDECL NsHiJack_midiInGetID(void)
{
    __asm JMP pfmidiInGetID; 
}

NSCDECL NsHiJack_midiInGetNumDevs(void)
{
    __asm JMP pfmidiInGetNumDevs; 
}

NSCDECL NsHiJack_midiInMessage(void)
{
    __asm JMP pfmidiInMessage; 
}

NSCDECL NsHiJack_midiInOpen(void)
{
    __asm JMP pfmidiInOpen; 
}

NSCDECL NsHiJack_midiInPrepareHeader(void)
{
    __asm JMP pfmidiInPrepareHeader; 
}

NSCDECL NsHiJack_midiInReset(void)
{
    __asm JMP pfmidiInReset; 
}

NSCDECL NsHiJack_midiInStart(void)
{
    __asm JMP pfmidiInStart; 
}

NSCDECL NsHiJack_midiInStop(void)
{
    __asm JMP pfmidiInStop; 
}

NSCDECL NsHiJack_midiInUnprepareHeader(void)
{
    __asm JMP pfmidiInUnprepareHeader; 
}

NSCDECL NsHiJack_midiOutCacheDrumPatches(void)
{
    __asm JMP pfmidiOutCacheDrumPatches; 
}

NSCDECL NsHiJack_midiOutCachePatches(void)
{
    __asm JMP pfmidiOutCachePatches; 
}

NSCDECL NsHiJack_midiOutClose(void)
{
    __asm JMP pfmidiOutClose; 
}

NSCDECL NsHiJack_midiOutGetDevCapsA(void)
{
    __asm JMP pfmidiOutGetDevCapsA; 
}

NSCDECL NsHiJack_midiOutGetDevCapsW(void)
{
    __asm JMP pfmidiOutGetDevCapsW; 
}

NSCDECL NsHiJack_midiOutGetErrorTextA(void)
{
    __asm JMP pfmidiOutGetErrorTextA; 
}

NSCDECL NsHiJack_midiOutGetErrorTextW(void)
{
    __asm JMP pfmidiOutGetErrorTextW; 
}

NSCDECL NsHiJack_midiOutGetID(void)
{
    __asm JMP pfmidiOutGetID; 
}

NSCDECL NsHiJack_midiOutGetNumDevs(void)
{
    __asm JMP pfmidiOutGetNumDevs; 
}

NSCDECL NsHiJack_midiOutGetVolume(void)
{
    __asm JMP pfmidiOutGetVolume; 
}

NSCDECL NsHiJack_midiOutLongMsg(void)
{
    __asm JMP pfmidiOutLongMsg; 
}

NSCDECL NsHiJack_midiOutMessage(void)
{
    __asm JMP pfmidiOutMessage; 
}

NSCDECL NsHiJack_midiOutOpen(void)
{
    __asm JMP pfmidiOutOpen; 
}

NSCDECL NsHiJack_midiOutPrepareHeader(void)
{
    __asm JMP pfmidiOutPrepareHeader; 
}

NSCDECL NsHiJack_midiOutReset(void)
{
    __asm JMP pfmidiOutReset; 
}

NSCDECL NsHiJack_midiOutSetVolume(void)
{
    __asm JMP pfmidiOutSetVolume; 
}

NSCDECL NsHiJack_midiOutShortMsg(void)
{
    __asm JMP pfmidiOutShortMsg; 
}

NSCDECL NsHiJack_midiOutUnprepareHeader(void)
{
    __asm JMP pfmidiOutUnprepareHeader; 
}

NSCDECL NsHiJack_midiStreamClose(void)
{
    __asm JMP pfmidiStreamClose; 
}

NSCDECL NsHiJack_midiStreamOpen(void)
{
    __asm JMP pfmidiStreamOpen; 
}

NSCDECL NsHiJack_midiStreamOut(void)
{
    __asm JMP pfmidiStreamOut; 
}

NSCDECL NsHiJack_midiStreamPause(void)
{
    __asm JMP pfmidiStreamPause; 
}

NSCDECL NsHiJack_midiStreamPosition(void)
{
    __asm JMP pfmidiStreamPosition; 
}

NSCDECL NsHiJack_midiStreamProperty(void)
{
    __asm JMP pfmidiStreamProperty; 
}

NSCDECL NsHiJack_midiStreamRestart(void)
{
    __asm JMP pfmidiStreamRestart; 
}

NSCDECL NsHiJack_midiStreamStop(void)
{
    __asm JMP pfmidiStreamStop; 
}

NSCDECL NsHiJack_mixerClose(void)
{
    __asm JMP pfmixerClose; 
}

NSCDECL NsHiJack_mixerGetControlDetailsA(void)
{
    __asm JMP pfmixerGetControlDetailsA; 
}

NSCDECL NsHiJack_mixerGetControlDetailsW(void)
{
    __asm JMP pfmixerGetControlDetailsW; 
}

NSCDECL NsHiJack_mixerGetDevCapsA(void)
{
    __asm JMP pfmixerGetDevCapsA; 
}

NSCDECL NsHiJack_mixerGetDevCapsW(void)
{
    __asm JMP pfmixerGetDevCapsW; 
}

NSCDECL NsHiJack_mixerGetID(void)
{
    __asm JMP pfmixerGetID; 
}

NSCDECL NsHiJack_mixerGetLineControlsA(void)
{
    __asm JMP pfmixerGetLineControlsA; 
}

NSCDECL NsHiJack_mixerGetLineControlsW(void)
{
    __asm JMP pfmixerGetLineControlsW; 
}

NSCDECL NsHiJack_mixerGetLineInfoA(void)
{
    __asm JMP pfmixerGetLineInfoA; 
}

NSCDECL NsHiJack_mixerGetLineInfoW(void)
{
    __asm JMP pfmixerGetLineInfoW; 
}

NSCDECL NsHiJack_mixerGetNumDevs(void)
{
    __asm JMP pfmixerGetNumDevs; 
}

NSCDECL NsHiJack_mixerMessage(void)
{
    __asm JMP pfmixerMessage; 
}

NSCDECL NsHiJack_mixerOpen(void)
{
    __asm JMP pfmixerOpen; 
}

NSCDECL NsHiJack_mixerSetControlDetails(void)
{
    __asm JMP pfmixerSetControlDetails; 
}

NSCDECL NsHiJack_mmDrvInstall(void)
{
    __asm JMP pfmmDrvInstall; 
}

NSCDECL NsHiJack_mmGetCurrentTask(void)
{
    __asm JMP pfmmGetCurrentTask; 
}

NSCDECL NsHiJack_mmTaskBlock(void)
{
    __asm JMP pfmmTaskBlock; 
}

NSCDECL NsHiJack_mmTaskCreate(void)
{
    __asm JMP pfmmTaskCreate; 
}

NSCDECL NsHiJack_mmTaskSignal(void)
{
    __asm JMP pfmmTaskSignal; 
}

NSCDECL NsHiJack_mmTaskYield(void)
{
    __asm JMP pfmmTaskYield; 
}

NSCDECL NsHiJack_mmioAdvance(void)
{
    __asm JMP pfmmioAdvance; 
}

NSCDECL NsHiJack_mmioAscend(void)
{
    __asm JMP pfmmioAscend; 
}

NSCDECL NsHiJack_mmioClose(void)
{
    __asm JMP pfmmioClose; 
}

NSCDECL NsHiJack_mmioCreateChunk(void)
{
    __asm JMP pfmmioCreateChunk; 
}

NSCDECL NsHiJack_mmioDescend(void)
{
    __asm JMP pfmmioDescend; 
}

NSCDECL NsHiJack_mmioFlush(void)
{
    __asm JMP pfmmioFlush; 
}

NSCDECL NsHiJack_mmioGetInfo(void)
{
    __asm JMP pfmmioGetInfo; 
}

NSCDECL NsHiJack_mmioInstallIOProcA(void)
{
    __asm JMP pfmmioInstallIOProcA; 
}

NSCDECL NsHiJack_mmioInstallIOProcW(void)
{
    __asm JMP pfmmioInstallIOProcW; 
}

NSCDECL NsHiJack_mmioOpenA(void)
{
    __asm JMP pfmmioOpenA; 
}

NSCDECL NsHiJack_mmioOpenW(void)
{
    __asm JMP pfmmioOpenW; 
}

NSCDECL NsHiJack_mmioRead(void)
{
    __asm JMP pfmmioRead; 
}

NSCDECL NsHiJack_mmioRenameA(void)
{
    __asm JMP pfmmioRenameA; 
}

NSCDECL NsHiJack_mmioRenameW(void)
{
    __asm JMP pfmmioRenameW; 
}

NSCDECL NsHiJack_mmioSeek(void)
{
    __asm JMP pfmmioSeek; 
}

NSCDECL NsHiJack_mmioSendMessage(void)
{
    __asm JMP pfmmioSendMessage; 
}

NSCDECL NsHiJack_mmioSetBuffer(void)
{
    __asm JMP pfmmioSetBuffer; 
}

NSCDECL NsHiJack_mmioSetInfo(void)
{
    __asm JMP pfmmioSetInfo; 
}

NSCDECL NsHiJack_mmioStringToFOURCCA(void)
{
    __asm JMP pfmmioStringToFOURCCA; 
}

NSCDECL NsHiJack_mmioStringToFOURCCW(void)
{
    __asm JMP pfmmioStringToFOURCCW; 
}

NSCDECL NsHiJack_mmioWrite(void)
{
    __asm JMP pfmmioWrite; 
}

NSCDECL NsHiJack_mmsystemGetVersion(void)
{
    __asm JMP pfmmsystemGetVersion; 
}

NSCDECL NsHiJack_mod32Message(void)
{
    __asm JMP pfmod32Message; 
}

NSCDECL NsHiJack_mxd32Message(void)
{
    __asm JMP pfmxd32Message; 
}

NSCDECL NsHiJack_sndPlaySoundA(void)
{
    __asm JMP pfsndPlaySoundA; 
}

NSCDECL NsHiJack_sndPlaySoundW(void)
{
    __asm JMP pfsndPlaySoundW; 
}

NSCDECL NsHiJack_tid32Message(void)
{
    __asm JMP pftid32Message; 
}

NSCDECL NsHiJack_timeBeginPeriod(void)
{
    __asm JMP pftimeBeginPeriod; 
}

NSCDECL NsHiJack_timeEndPeriod(void)
{
    __asm JMP pftimeEndPeriod; 
}

NSCDECL NsHiJack_timeGetDevCaps(void)
{
    __asm JMP pftimeGetDevCaps; 
}

NSCDECL NsHiJack_timeGetSystemTime(void)
{
    __asm JMP pftimeGetSystemTime; 
}

NSCDECL NsHiJack_timeGetTime(void)
{
    __asm JMP pftimeGetTime; 
}

NSCDECL NsHiJack_timeKillEvent(void)
{
    __asm JMP pftimeKillEvent; 
}

NSCDECL NsHiJack_timeSetEvent(void)
{
    __asm JMP pftimeSetEvent; 
}

NSCDECL NsHiJack_waveInAddBuffer(void)
{
    __asm JMP pfwaveInAddBuffer; 
}

NSCDECL NsHiJack_waveInClose(void)
{
    __asm JMP pfwaveInClose; 
}

NSCDECL NsHiJack_waveInGetDevCapsA(void)
{
    __asm JMP pfwaveInGetDevCapsA; 
}

NSCDECL NsHiJack_waveInGetDevCapsW(void)
{
    __asm JMP pfwaveInGetDevCapsW; 
}

NSCDECL NsHiJack_waveInGetErrorTextA(void)
{
    __asm JMP pfwaveInGetErrorTextA; 
}

NSCDECL NsHiJack_waveInGetErrorTextW(void)
{
    __asm JMP pfwaveInGetErrorTextW; 
}

NSCDECL NsHiJack_waveInGetID(void)
{
    __asm JMP pfwaveInGetID; 
}

NSCDECL NsHiJack_waveInGetNumDevs(void)
{
    __asm JMP pfwaveInGetNumDevs; 
}

NSCDECL NsHiJack_waveInGetPosition(void)
{
    __asm JMP pfwaveInGetPosition; 
}

NSCDECL NsHiJack_waveInMessage(void)
{
    __asm JMP pfwaveInMessage; 
}

NSCDECL NsHiJack_waveInOpen(void)
{
    __asm JMP pfwaveInOpen; 
}

NSCDECL NsHiJack_waveInPrepareHeader(void)
{
    __asm JMP pfwaveInPrepareHeader; 
}

NSCDECL NsHiJack_waveInReset(void)
{
    __asm JMP pfwaveInReset; 
}

NSCDECL NsHiJack_waveInStart(void)
{
    __asm JMP pfwaveInStart; 
}

NSCDECL NsHiJack_waveInStop(void)
{
    __asm JMP pfwaveInStop; 
}

NSCDECL NsHiJack_waveInUnprepareHeader(void)
{
    __asm JMP pfwaveInUnprepareHeader; 
}

NSCDECL NsHiJack_waveOutBreakLoop(void)
{
    __asm JMP pfwaveOutBreakLoop; 
}

NSCDECL NsHiJack_waveOutClose(void)
{
    __asm JMP pfwaveOutClose; 
}

NSCDECL NsHiJack_waveOutGetDevCapsA(void)
{
    __asm JMP pfwaveOutGetDevCapsA; 
}

NSCDECL NsHiJack_waveOutGetDevCapsW(void)
{
    __asm JMP pfwaveOutGetDevCapsW; 
}

NSCDECL NsHiJack_waveOutGetErrorTextA(void)
{
    __asm JMP pfwaveOutGetErrorTextA; 
}

NSCDECL NsHiJack_waveOutGetErrorTextW(void)
{
    __asm JMP pfwaveOutGetErrorTextW; 
}

NSCDECL NsHiJack_waveOutGetID(void)
{
    __asm JMP pfwaveOutGetID; 
}

NSCDECL NsHiJack_waveOutGetNumDevs(void)
{
    __asm JMP pfwaveOutGetNumDevs; 
}

NSCDECL NsHiJack_waveOutGetPitch(void)
{
    __asm JMP pfwaveOutGetPitch; 
}

NSCDECL NsHiJack_waveOutGetPlaybackRate(void)
{
    __asm JMP pfwaveOutGetPlaybackRate; 
}

NSCDECL NsHiJack_waveOutGetPosition(void)
{
    __asm JMP pfwaveOutGetPosition; 
}

NSCDECL NsHiJack_waveOutGetVolume(void)
{
    __asm JMP pfwaveOutGetVolume; 
}

NSCDECL NsHiJack_waveOutMessage(void)
{
    __asm JMP pfwaveOutMessage; 
}

NSCDECL NsHiJack_waveOutOpen(void)
{
    __asm JMP pfwaveOutOpen; 
}

NSCDECL NsHiJack_waveOutPause(void)
{
    __asm JMP pfwaveOutPause; 
}

NSCDECL NsHiJack_waveOutPrepareHeader(void)
{
    __asm JMP pfwaveOutPrepareHeader; 
}

NSCDECL NsHiJack_waveOutReset(void)
{
    __asm JMP pfwaveOutReset; 
}

NSCDECL NsHiJack_waveOutRestart(void)
{
    __asm JMP pfwaveOutRestart; 
}

NSCDECL NsHiJack_waveOutSetPitch(void)
{
    __asm JMP pfwaveOutSetPitch; 
}

NSCDECL NsHiJack_waveOutSetPlaybackRate(void)
{
    __asm JMP pfwaveOutSetPlaybackRate; 
}

NSCDECL NsHiJack_waveOutSetVolume(void)
{
    __asm JMP pfwaveOutSetVolume; 
}

NSCDECL NsHiJack_waveOutUnprepareHeader(void)
{
    __asm JMP pfwaveOutUnprepareHeader; 
}

NSCDECL NsHiJack_waveOutWrite(void)
{
    __asm JMP pfwaveOutWrite; 
}

NSCDECL NsHiJack_wid32Message(void)
{
    __asm JMP pfwid32Message; 
}

NSCDECL NsHiJack_wod32Message(void)
{
    __asm JMP pfwod32Message; 
}

NSCDECL NsHiJack_NsUnknowProc_2(void)
{
    __asm JMP pfNsUnknowProc_2; 
}


#pragma comment(linker, "/EXPORT:CloseDriver=_NsHiJack_CloseDriver,@4")
#pragma comment(linker, "/EXPORT:DefDriverProc=_NsHiJack_DefDriverProc,@5")
#pragma comment(linker, "/EXPORT:DriverCallback=_NsHiJack_DriverCallback,@6")
#pragma comment(linker, "/EXPORT:DrvGetModuleHandle=_NsHiJack_DrvGetModuleHandle,@7")
#pragma comment(linker, "/EXPORT:GetDriverModuleHandle=_NsHiJack_GetDriverModuleHandle,@8")
#pragma comment(linker, "/EXPORT:NotifyCallbackData=_NsHiJack_NotifyCallbackData,@9")
#pragma comment(linker, "/EXPORT:OpenDriver=_NsHiJack_OpenDriver,@10")
#pragma comment(linker, "/EXPORT:PlaySound=_NsHiJack_PlaySound,@11")
#pragma comment(linker, "/EXPORT:PlaySoundA=_NsHiJack_PlaySoundA,@12")
#pragma comment(linker, "/EXPORT:PlaySoundW=_NsHiJack_PlaySoundW,@13")
#pragma comment(linker, "/EXPORT:SendDriverMessage=_NsHiJack_SendDriverMessage,@14")
#pragma comment(linker, "/EXPORT:WOW32DriverCallback=_NsHiJack_WOW32DriverCallback,@15")
#pragma comment(linker, "/EXPORT:WOW32ResolveMultiMediaHandle=_NsHiJack_WOW32ResolveMultiMediaHandle,@16")
#pragma comment(linker, "/EXPORT:WOWAppExit=_NsHiJack_WOWAppExit,@17")
#pragma comment(linker, "/EXPORT:aux32Message=_NsHiJack_aux32Message,@18")
#pragma comment(linker, "/EXPORT:auxGetDevCapsA=_NsHiJack_auxGetDevCapsA,@19")
#pragma comment(linker, "/EXPORT:auxGetDevCapsW=_NsHiJack_auxGetDevCapsW,@20")
#pragma comment(linker, "/EXPORT:auxGetNumDevs=_NsHiJack_auxGetNumDevs,@21")
#pragma comment(linker, "/EXPORT:auxGetVolume=_NsHiJack_auxGetVolume,@22")
#pragma comment(linker, "/EXPORT:auxOutMessage=_NsHiJack_auxOutMessage,@23")
#pragma comment(linker, "/EXPORT:auxSetVolume=_NsHiJack_auxSetVolume,@24")
#pragma comment(linker, "/EXPORT:joy32Message=_NsHiJack_joy32Message,@25")
#pragma comment(linker, "/EXPORT:joyConfigChanged=_NsHiJack_joyConfigChanged,@26")
#pragma comment(linker, "/EXPORT:joyGetDevCapsA=_NsHiJack_joyGetDevCapsA,@27")
#pragma comment(linker, "/EXPORT:joyGetDevCapsW=_NsHiJack_joyGetDevCapsW,@28")
#pragma comment(linker, "/EXPORT:joyGetNumDevs=_NsHiJack_joyGetNumDevs,@29")
#pragma comment(linker, "/EXPORT:joyGetPos=_NsHiJack_joyGetPos,@30")
#pragma comment(linker, "/EXPORT:joyGetPosEx=_NsHiJack_joyGetPosEx,@31")
#pragma comment(linker, "/EXPORT:joyGetThreshold=_NsHiJack_joyGetThreshold,@32")
#pragma comment(linker, "/EXPORT:joyReleaseCapture=_NsHiJack_joyReleaseCapture,@33")
#pragma comment(linker, "/EXPORT:joySetCapture=_NsHiJack_joySetCapture,@34")
#pragma comment(linker, "/EXPORT:joySetThreshold=_NsHiJack_joySetThreshold,@35")
#pragma comment(linker, "/EXPORT:mci32Message=_NsHiJack_mci32Message,@36")
#pragma comment(linker, "/EXPORT:mciDriverNotify=_NsHiJack_mciDriverNotify,@37")
#pragma comment(linker, "/EXPORT:mciDriverYield=_NsHiJack_mciDriverYield,@38")
#pragma comment(linker, "/EXPORT:mciExecute=_NsHiJack_mciExecute,@3")
#pragma comment(linker, "/EXPORT:mciFreeCommandResource=_NsHiJack_mciFreeCommandResource,@39")
#pragma comment(linker, "/EXPORT:mciGetCreatorTask=_NsHiJack_mciGetCreatorTask,@40")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDA=_NsHiJack_mciGetDeviceIDA,@41")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDA=_NsHiJack_mciGetDeviceIDFromElementIDA,@42")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDFromElementIDW=_NsHiJack_mciGetDeviceIDFromElementIDW,@43")
#pragma comment(linker, "/EXPORT:mciGetDeviceIDW=_NsHiJack_mciGetDeviceIDW,@44")
#pragma comment(linker, "/EXPORT:mciGetDriverData=_NsHiJack_mciGetDriverData,@45")
#pragma comment(linker, "/EXPORT:mciGetErrorStringA=_NsHiJack_mciGetErrorStringA,@46")
#pragma comment(linker, "/EXPORT:mciGetErrorStringW=_NsHiJack_mciGetErrorStringW,@47")
#pragma comment(linker, "/EXPORT:mciGetYieldProc=_NsHiJack_mciGetYieldProc,@48")
#pragma comment(linker, "/EXPORT:mciLoadCommandResource=_NsHiJack_mciLoadCommandResource,@49")
#pragma comment(linker, "/EXPORT:mciSendCommandA=_NsHiJack_mciSendCommandA,@50")
#pragma comment(linker, "/EXPORT:mciSendCommandW=_NsHiJack_mciSendCommandW,@51")
#pragma comment(linker, "/EXPORT:mciSendStringA=_NsHiJack_mciSendStringA,@52")
#pragma comment(linker, "/EXPORT:mciSendStringW=_NsHiJack_mciSendStringW,@53")
#pragma comment(linker, "/EXPORT:mciSetDriverData=_NsHiJack_mciSetDriverData,@54")
#pragma comment(linker, "/EXPORT:mciSetYieldProc=_NsHiJack_mciSetYieldProc,@55")
#pragma comment(linker, "/EXPORT:mid32Message=_NsHiJack_mid32Message,@56")
#pragma comment(linker, "/EXPORT:midiConnect=_NsHiJack_midiConnect,@57")
#pragma comment(linker, "/EXPORT:midiDisconnect=_NsHiJack_midiDisconnect,@58")
#pragma comment(linker, "/EXPORT:midiInAddBuffer=_NsHiJack_midiInAddBuffer,@59")
#pragma comment(linker, "/EXPORT:midiInClose=_NsHiJack_midiInClose,@60")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsA=_NsHiJack_midiInGetDevCapsA,@61")
#pragma comment(linker, "/EXPORT:midiInGetDevCapsW=_NsHiJack_midiInGetDevCapsW,@62")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextA=_NsHiJack_midiInGetErrorTextA,@63")
#pragma comment(linker, "/EXPORT:midiInGetErrorTextW=_NsHiJack_midiInGetErrorTextW,@64")
#pragma comment(linker, "/EXPORT:midiInGetID=_NsHiJack_midiInGetID,@65")
#pragma comment(linker, "/EXPORT:midiInGetNumDevs=_NsHiJack_midiInGetNumDevs,@66")
#pragma comment(linker, "/EXPORT:midiInMessage=_NsHiJack_midiInMessage,@67")
#pragma comment(linker, "/EXPORT:midiInOpen=_NsHiJack_midiInOpen,@68")
#pragma comment(linker, "/EXPORT:midiInPrepareHeader=_NsHiJack_midiInPrepareHeader,@69")
#pragma comment(linker, "/EXPORT:midiInReset=_NsHiJack_midiInReset,@70")
#pragma comment(linker, "/EXPORT:midiInStart=_NsHiJack_midiInStart,@71")
#pragma comment(linker, "/EXPORT:midiInStop=_NsHiJack_midiInStop,@72")
#pragma comment(linker, "/EXPORT:midiInUnprepareHeader=_NsHiJack_midiInUnprepareHeader,@73")
#pragma comment(linker, "/EXPORT:midiOutCacheDrumPatches=_NsHiJack_midiOutCacheDrumPatches,@74")
#pragma comment(linker, "/EXPORT:midiOutCachePatches=_NsHiJack_midiOutCachePatches,@75")
#pragma comment(linker, "/EXPORT:midiOutClose=_NsHiJack_midiOutClose,@76")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsA=_NsHiJack_midiOutGetDevCapsA,@77")
#pragma comment(linker, "/EXPORT:midiOutGetDevCapsW=_NsHiJack_midiOutGetDevCapsW,@78")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextA=_NsHiJack_midiOutGetErrorTextA,@79")
#pragma comment(linker, "/EXPORT:midiOutGetErrorTextW=_NsHiJack_midiOutGetErrorTextW,@80")
#pragma comment(linker, "/EXPORT:midiOutGetID=_NsHiJack_midiOutGetID,@81")
#pragma comment(linker, "/EXPORT:midiOutGetNumDevs=_NsHiJack_midiOutGetNumDevs,@82")
#pragma comment(linker, "/EXPORT:midiOutGetVolume=_NsHiJack_midiOutGetVolume,@83")
#pragma comment(linker, "/EXPORT:midiOutLongMsg=_NsHiJack_midiOutLongMsg,@84")
#pragma comment(linker, "/EXPORT:midiOutMessage=_NsHiJack_midiOutMessage,@85")
#pragma comment(linker, "/EXPORT:midiOutOpen=_NsHiJack_midiOutOpen,@86")
#pragma comment(linker, "/EXPORT:midiOutPrepareHeader=_NsHiJack_midiOutPrepareHeader,@87")
#pragma comment(linker, "/EXPORT:midiOutReset=_NsHiJack_midiOutReset,@88")
#pragma comment(linker, "/EXPORT:midiOutSetVolume=_NsHiJack_midiOutSetVolume,@89")
#pragma comment(linker, "/EXPORT:midiOutShortMsg=_NsHiJack_midiOutShortMsg,@90")
#pragma comment(linker, "/EXPORT:midiOutUnprepareHeader=_NsHiJack_midiOutUnprepareHeader,@91")
#pragma comment(linker, "/EXPORT:midiStreamClose=_NsHiJack_midiStreamClose,@92")
#pragma comment(linker, "/EXPORT:midiStreamOpen=_NsHiJack_midiStreamOpen,@93")
#pragma comment(linker, "/EXPORT:midiStreamOut=_NsHiJack_midiStreamOut,@94")
#pragma comment(linker, "/EXPORT:midiStreamPause=_NsHiJack_midiStreamPause,@95")
#pragma comment(linker, "/EXPORT:midiStreamPosition=_NsHiJack_midiStreamPosition,@96")
#pragma comment(linker, "/EXPORT:midiStreamProperty=_NsHiJack_midiStreamProperty,@97")
#pragma comment(linker, "/EXPORT:midiStreamRestart=_NsHiJack_midiStreamRestart,@98")
#pragma comment(linker, "/EXPORT:midiStreamStop=_NsHiJack_midiStreamStop,@99")
#pragma comment(linker, "/EXPORT:mixerClose=_NsHiJack_mixerClose,@100")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsA=_NsHiJack_mixerGetControlDetailsA,@101")
#pragma comment(linker, "/EXPORT:mixerGetControlDetailsW=_NsHiJack_mixerGetControlDetailsW,@102")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsA=_NsHiJack_mixerGetDevCapsA,@103")
#pragma comment(linker, "/EXPORT:mixerGetDevCapsW=_NsHiJack_mixerGetDevCapsW,@104")
#pragma comment(linker, "/EXPORT:mixerGetID=_NsHiJack_mixerGetID,@105")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsA=_NsHiJack_mixerGetLineControlsA,@106")
#pragma comment(linker, "/EXPORT:mixerGetLineControlsW=_NsHiJack_mixerGetLineControlsW,@107")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoA=_NsHiJack_mixerGetLineInfoA,@108")
#pragma comment(linker, "/EXPORT:mixerGetLineInfoW=_NsHiJack_mixerGetLineInfoW,@109")
#pragma comment(linker, "/EXPORT:mixerGetNumDevs=_NsHiJack_mixerGetNumDevs,@110")
#pragma comment(linker, "/EXPORT:mixerMessage=_NsHiJack_mixerMessage,@111")
#pragma comment(linker, "/EXPORT:mixerOpen=_NsHiJack_mixerOpen,@112")
#pragma comment(linker, "/EXPORT:mixerSetControlDetails=_NsHiJack_mixerSetControlDetails,@113")
#pragma comment(linker, "/EXPORT:mmDrvInstall=_NsHiJack_mmDrvInstall,@114")
#pragma comment(linker, "/EXPORT:mmGetCurrentTask=_NsHiJack_mmGetCurrentTask,@115")
#pragma comment(linker, "/EXPORT:mmTaskBlock=_NsHiJack_mmTaskBlock,@116")
#pragma comment(linker, "/EXPORT:mmTaskCreate=_NsHiJack_mmTaskCreate,@117")
#pragma comment(linker, "/EXPORT:mmTaskSignal=_NsHiJack_mmTaskSignal,@118")
#pragma comment(linker, "/EXPORT:mmTaskYield=_NsHiJack_mmTaskYield,@119")
#pragma comment(linker, "/EXPORT:mmioAdvance=_NsHiJack_mmioAdvance,@120")
#pragma comment(linker, "/EXPORT:mmioAscend=_NsHiJack_mmioAscend,@121")
#pragma comment(linker, "/EXPORT:mmioClose=_NsHiJack_mmioClose,@122")
#pragma comment(linker, "/EXPORT:mmioCreateChunk=_NsHiJack_mmioCreateChunk,@123")
#pragma comment(linker, "/EXPORT:mmioDescend=_NsHiJack_mmioDescend,@124")
#pragma comment(linker, "/EXPORT:mmioFlush=_NsHiJack_mmioFlush,@125")
#pragma comment(linker, "/EXPORT:mmioGetInfo=_NsHiJack_mmioGetInfo,@126")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcA=_NsHiJack_mmioInstallIOProcA,@127")
#pragma comment(linker, "/EXPORT:mmioInstallIOProcW=_NsHiJack_mmioInstallIOProcW,@128")
#pragma comment(linker, "/EXPORT:mmioOpenA=_NsHiJack_mmioOpenA,@129")
#pragma comment(linker, "/EXPORT:mmioOpenW=_NsHiJack_mmioOpenW,@130")
#pragma comment(linker, "/EXPORT:mmioRead=_NsHiJack_mmioRead,@131")
#pragma comment(linker, "/EXPORT:mmioRenameA=_NsHiJack_mmioRenameA,@132")
#pragma comment(linker, "/EXPORT:mmioRenameW=_NsHiJack_mmioRenameW,@133")
#pragma comment(linker, "/EXPORT:mmioSeek=_NsHiJack_mmioSeek,@134")
#pragma comment(linker, "/EXPORT:mmioSendMessage=_NsHiJack_mmioSendMessage,@135")
#pragma comment(linker, "/EXPORT:mmioSetBuffer=_NsHiJack_mmioSetBuffer,@136")
#pragma comment(linker, "/EXPORT:mmioSetInfo=_NsHiJack_mmioSetInfo,@137")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCA=_NsHiJack_mmioStringToFOURCCA,@138")
#pragma comment(linker, "/EXPORT:mmioStringToFOURCCW=_NsHiJack_mmioStringToFOURCCW,@139")
#pragma comment(linker, "/EXPORT:mmioWrite=_NsHiJack_mmioWrite,@140")
#pragma comment(linker, "/EXPORT:mmsystemGetVersion=_NsHiJack_mmsystemGetVersion,@141")
#pragma comment(linker, "/EXPORT:mod32Message=_NsHiJack_mod32Message,@142")
#pragma comment(linker, "/EXPORT:mxd32Message=_NsHiJack_mxd32Message,@143")
#pragma comment(linker, "/EXPORT:sndPlaySoundA=_NsHiJack_sndPlaySoundA,@144")
#pragma comment(linker, "/EXPORT:sndPlaySoundW=_NsHiJack_sndPlaySoundW,@145")
#pragma comment(linker, "/EXPORT:tid32Message=_NsHiJack_tid32Message,@146")
#pragma comment(linker, "/EXPORT:timeBeginPeriod=_NsHiJack_timeBeginPeriod,@147")
#pragma comment(linker, "/EXPORT:timeEndPeriod=_NsHiJack_timeEndPeriod,@148")
#pragma comment(linker, "/EXPORT:timeGetDevCaps=_NsHiJack_timeGetDevCaps,@149")
#pragma comment(linker, "/EXPORT:timeGetSystemTime=_NsHiJack_timeGetSystemTime,@150")
#pragma comment(linker, "/EXPORT:timeGetTime=_NsHiJack_timeGetTime,@151")
#pragma comment(linker, "/EXPORT:timeKillEvent=_NsHiJack_timeKillEvent,@152")
#pragma comment(linker, "/EXPORT:timeSetEvent=_NsHiJack_timeSetEvent,@153")
#pragma comment(linker, "/EXPORT:waveInAddBuffer=_NsHiJack_waveInAddBuffer,@154")
#pragma comment(linker, "/EXPORT:waveInClose=_NsHiJack_waveInClose,@155")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsA=_NsHiJack_waveInGetDevCapsA,@156")
#pragma comment(linker, "/EXPORT:waveInGetDevCapsW=_NsHiJack_waveInGetDevCapsW,@157")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextA=_NsHiJack_waveInGetErrorTextA,@158")
#pragma comment(linker, "/EXPORT:waveInGetErrorTextW=_NsHiJack_waveInGetErrorTextW,@159")
#pragma comment(linker, "/EXPORT:waveInGetID=_NsHiJack_waveInGetID,@160")
#pragma comment(linker, "/EXPORT:waveInGetNumDevs=_NsHiJack_waveInGetNumDevs,@161")
#pragma comment(linker, "/EXPORT:waveInGetPosition=_NsHiJack_waveInGetPosition,@162")
#pragma comment(linker, "/EXPORT:waveInMessage=_NsHiJack_waveInMessage,@163")
#pragma comment(linker, "/EXPORT:waveInOpen=_NsHiJack_waveInOpen,@164")
#pragma comment(linker, "/EXPORT:waveInPrepareHeader=_NsHiJack_waveInPrepareHeader,@165")
#pragma comment(linker, "/EXPORT:waveInReset=_NsHiJack_waveInReset,@166")
#pragma comment(linker, "/EXPORT:waveInStart=_NsHiJack_waveInStart,@167")
#pragma comment(linker, "/EXPORT:waveInStop=_NsHiJack_waveInStop,@168")
#pragma comment(linker, "/EXPORT:waveInUnprepareHeader=_NsHiJack_waveInUnprepareHeader,@169")
#pragma comment(linker, "/EXPORT:waveOutBreakLoop=_NsHiJack_waveOutBreakLoop,@170")
#pragma comment(linker, "/EXPORT:waveOutClose=_NsHiJack_waveOutClose,@171")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsA=_NsHiJack_waveOutGetDevCapsA,@172")
#pragma comment(linker, "/EXPORT:waveOutGetDevCapsW=_NsHiJack_waveOutGetDevCapsW,@173")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextA=_NsHiJack_waveOutGetErrorTextA,@174")
#pragma comment(linker, "/EXPORT:waveOutGetErrorTextW=_NsHiJack_waveOutGetErrorTextW,@175")
#pragma comment(linker, "/EXPORT:waveOutGetID=_NsHiJack_waveOutGetID,@176")
#pragma comment(linker, "/EXPORT:waveOutGetNumDevs=_NsHiJack_waveOutGetNumDevs,@177")
#pragma comment(linker, "/EXPORT:waveOutGetPitch=_NsHiJack_waveOutGetPitch,@178")
#pragma comment(linker, "/EXPORT:waveOutGetPlaybackRate=_NsHiJack_waveOutGetPlaybackRate,@179")
#pragma comment(linker, "/EXPORT:waveOutGetPosition=_NsHiJack_waveOutGetPosition,@180")
#pragma comment(linker, "/EXPORT:waveOutGetVolume=_NsHiJack_waveOutGetVolume,@181")
#pragma comment(linker, "/EXPORT:waveOutMessage=_NsHiJack_waveOutMessage,@182")
#pragma comment(linker, "/EXPORT:waveOutOpen=_NsHiJack_waveOutOpen,@183")
#pragma comment(linker, "/EXPORT:waveOutPause=_NsHiJack_waveOutPause,@184")
#pragma comment(linker, "/EXPORT:waveOutPrepareHeader=_NsHiJack_waveOutPrepareHeader,@185")
#pragma comment(linker, "/EXPORT:waveOutReset=_NsHiJack_waveOutReset,@186")
#pragma comment(linker, "/EXPORT:waveOutRestart=_NsHiJack_waveOutRestart,@187")
#pragma comment(linker, "/EXPORT:waveOutSetPitch=_NsHiJack_waveOutSetPitch,@188")
#pragma comment(linker, "/EXPORT:waveOutSetPlaybackRate=_NsHiJack_waveOutSetPlaybackRate,@189")
#pragma comment(linker, "/EXPORT:waveOutSetVolume=_NsHiJack_waveOutSetVolume,@190")
#pragma comment(linker, "/EXPORT:waveOutUnprepareHeader=_NsHiJack_waveOutUnprepareHeader,@191")
#pragma comment(linker, "/EXPORT:waveOutWrite=_NsHiJack_waveOutWrite,@192")
#pragma comment(linker, "/EXPORT:wid32Message=_NsHiJack_wid32Message,@193")
#pragma comment(linker, "/EXPORT:wod32Message=_NsHiJack_wod32Message,@194")
#pragma comment(linker, "/EXPORT:NsUnknowProc_2=_NsHiJack_NsUnknowProc_2,@2,NONAME")




FARPROC NsGetSourceAddressUnCheckResult(PCSTR pszProcName)
{
    return GetProcAddress(g_hSourceModule, pszProcName);
}


VOID WINAPI NsInitDllExportProc()
{
    pfCloseDriver = NsGetSourceAddressUnCheckResult("CloseDriver");
    pfDefDriverProc = NsGetSourceAddressUnCheckResult("DefDriverProc");
    pfDriverCallback = NsGetSourceAddressUnCheckResult("DriverCallback");
    pfDrvGetModuleHandle = NsGetSourceAddressUnCheckResult("DrvGetModuleHandle");
    pfGetDriverModuleHandle = NsGetSourceAddressUnCheckResult("GetDriverModuleHandle");
    pfNotifyCallbackData = NsGetSourceAddressUnCheckResult("NotifyCallbackData");
    pfOpenDriver = NsGetSourceAddressUnCheckResult("OpenDriver");
    pfPlaySound = NsGetSourceAddressUnCheckResult("PlaySound");
    pfPlaySoundA = NsGetSourceAddressUnCheckResult("PlaySoundA");
    pfPlaySoundW = NsGetSourceAddressUnCheckResult("PlaySoundW");
    pfSendDriverMessage = NsGetSourceAddressUnCheckResult("SendDriverMessage");
    pfWOW32DriverCallback = NsGetSourceAddressUnCheckResult("WOW32DriverCallback");
    pfWOW32ResolveMultiMediaHandle = NsGetSourceAddressUnCheckResult("WOW32ResolveMultiMediaHandle");
    pfWOWAppExit = NsGetSourceAddressUnCheckResult("WOWAppExit");
    pfaux32Message = NsGetSourceAddressUnCheckResult("aux32Message");
    pfauxGetDevCapsA = NsGetSourceAddressUnCheckResult("auxGetDevCapsA");
    pfauxGetDevCapsW = NsGetSourceAddressUnCheckResult("auxGetDevCapsW");
    pfauxGetNumDevs = NsGetSourceAddressUnCheckResult("auxGetNumDevs");
    pfauxGetVolume = NsGetSourceAddressUnCheckResult("auxGetVolume");
    pfauxOutMessage = NsGetSourceAddressUnCheckResult("auxOutMessage");
    pfauxSetVolume = NsGetSourceAddressUnCheckResult("auxSetVolume");
    pfjoy32Message = NsGetSourceAddressUnCheckResult("joy32Message");
    pfjoyConfigChanged = NsGetSourceAddressUnCheckResult("joyConfigChanged");
    pfjoyGetDevCapsA = NsGetSourceAddressUnCheckResult("joyGetDevCapsA");
    pfjoyGetDevCapsW = NsGetSourceAddressUnCheckResult("joyGetDevCapsW");
    pfjoyGetNumDevs = NsGetSourceAddressUnCheckResult("joyGetNumDevs");
    pfjoyGetPos = NsGetSourceAddressUnCheckResult("joyGetPos");
    pfjoyGetPosEx = NsGetSourceAddressUnCheckResult("joyGetPosEx");
    pfjoyGetThreshold = NsGetSourceAddressUnCheckResult("joyGetThreshold");
    pfjoyReleaseCapture = NsGetSourceAddressUnCheckResult("joyReleaseCapture");
    pfjoySetCapture = NsGetSourceAddressUnCheckResult("joySetCapture");
    pfjoySetThreshold = NsGetSourceAddressUnCheckResult("joySetThreshold");
    pfmci32Message = NsGetSourceAddressUnCheckResult("mci32Message");
    pfmciDriverNotify = NsGetSourceAddressUnCheckResult("mciDriverNotify");
    pfmciDriverYield = NsGetSourceAddressUnCheckResult("mciDriverYield");
    pfmciExecute = NsGetSourceAddressUnCheckResult("mciExecute");
    pfmciFreeCommandResource = NsGetSourceAddressUnCheckResult("mciFreeCommandResource");
    pfmciGetCreatorTask = NsGetSourceAddressUnCheckResult("mciGetCreatorTask");
    pfmciGetDeviceIDA = NsGetSourceAddressUnCheckResult("mciGetDeviceIDA");
    pfmciGetDeviceIDFromElementIDA = NsGetSourceAddressUnCheckResult("mciGetDeviceIDFromElementIDA");
    pfmciGetDeviceIDFromElementIDW = NsGetSourceAddressUnCheckResult("mciGetDeviceIDFromElementIDW");
    pfmciGetDeviceIDW = NsGetSourceAddressUnCheckResult("mciGetDeviceIDW");
    pfmciGetDriverData = NsGetSourceAddressUnCheckResult("mciGetDriverData");
    pfmciGetErrorStringA = NsGetSourceAddressUnCheckResult("mciGetErrorStringA");
    pfmciGetErrorStringW = NsGetSourceAddressUnCheckResult("mciGetErrorStringW");
    pfmciGetYieldProc = NsGetSourceAddressUnCheckResult("mciGetYieldProc");
    pfmciLoadCommandResource = NsGetSourceAddressUnCheckResult("mciLoadCommandResource");
    pfmciSendCommandA = NsGetSourceAddressUnCheckResult("mciSendCommandA");
    pfmciSendCommandW = NsGetSourceAddressUnCheckResult("mciSendCommandW");
    pfmciSendStringA = NsGetSourceAddressUnCheckResult("mciSendStringA");
    pfmciSendStringW = NsGetSourceAddressUnCheckResult("mciSendStringW");
    pfmciSetDriverData = NsGetSourceAddressUnCheckResult("mciSetDriverData");
    pfmciSetYieldProc = NsGetSourceAddressUnCheckResult("mciSetYieldProc");
    pfmid32Message = NsGetSourceAddressUnCheckResult("mid32Message");
    pfmidiConnect = NsGetSourceAddressUnCheckResult("midiConnect");
    pfmidiDisconnect = NsGetSourceAddressUnCheckResult("midiDisconnect");
    pfmidiInAddBuffer = NsGetSourceAddressUnCheckResult("midiInAddBuffer");
    pfmidiInClose = NsGetSourceAddressUnCheckResult("midiInClose");
    pfmidiInGetDevCapsA = NsGetSourceAddressUnCheckResult("midiInGetDevCapsA");
    pfmidiInGetDevCapsW = NsGetSourceAddressUnCheckResult("midiInGetDevCapsW");
    pfmidiInGetErrorTextA = NsGetSourceAddressUnCheckResult("midiInGetErrorTextA");
    pfmidiInGetErrorTextW = NsGetSourceAddressUnCheckResult("midiInGetErrorTextW");
    pfmidiInGetID = NsGetSourceAddressUnCheckResult("midiInGetID");
    pfmidiInGetNumDevs = NsGetSourceAddressUnCheckResult("midiInGetNumDevs");
    pfmidiInMessage = NsGetSourceAddressUnCheckResult("midiInMessage");
    pfmidiInOpen = NsGetSourceAddressUnCheckResult("midiInOpen");
    pfmidiInPrepareHeader = NsGetSourceAddressUnCheckResult("midiInPrepareHeader");
    pfmidiInReset = NsGetSourceAddressUnCheckResult("midiInReset");
    pfmidiInStart = NsGetSourceAddressUnCheckResult("midiInStart");
    pfmidiInStop = NsGetSourceAddressUnCheckResult("midiInStop");
    pfmidiInUnprepareHeader = NsGetSourceAddressUnCheckResult("midiInUnprepareHeader");
    pfmidiOutCacheDrumPatches = NsGetSourceAddressUnCheckResult("midiOutCacheDrumPatches");
    pfmidiOutCachePatches = NsGetSourceAddressUnCheckResult("midiOutCachePatches");
    pfmidiOutClose = NsGetSourceAddressUnCheckResult("midiOutClose");
    pfmidiOutGetDevCapsA = NsGetSourceAddressUnCheckResult("midiOutGetDevCapsA");
    pfmidiOutGetDevCapsW = NsGetSourceAddressUnCheckResult("midiOutGetDevCapsW");
    pfmidiOutGetErrorTextA = NsGetSourceAddressUnCheckResult("midiOutGetErrorTextA");
    pfmidiOutGetErrorTextW = NsGetSourceAddressUnCheckResult("midiOutGetErrorTextW");
    pfmidiOutGetID = NsGetSourceAddressUnCheckResult("midiOutGetID");
    pfmidiOutGetNumDevs = NsGetSourceAddressUnCheckResult("midiOutGetNumDevs");
    pfmidiOutGetVolume = NsGetSourceAddressUnCheckResult("midiOutGetVolume");
    pfmidiOutLongMsg = NsGetSourceAddressUnCheckResult("midiOutLongMsg");
    pfmidiOutMessage = NsGetSourceAddressUnCheckResult("midiOutMessage");
    pfmidiOutOpen = NsGetSourceAddressUnCheckResult("midiOutOpen");
    pfmidiOutPrepareHeader = NsGetSourceAddressUnCheckResult("midiOutPrepareHeader");
    pfmidiOutReset = NsGetSourceAddressUnCheckResult("midiOutReset");
    pfmidiOutSetVolume = NsGetSourceAddressUnCheckResult("midiOutSetVolume");
    pfmidiOutShortMsg = NsGetSourceAddressUnCheckResult("midiOutShortMsg");
    pfmidiOutUnprepareHeader = NsGetSourceAddressUnCheckResult("midiOutUnprepareHeader");
    pfmidiStreamClose = NsGetSourceAddressUnCheckResult("midiStreamClose");
    pfmidiStreamOpen = NsGetSourceAddressUnCheckResult("midiStreamOpen");
    pfmidiStreamOut = NsGetSourceAddressUnCheckResult("midiStreamOut");
    pfmidiStreamPause = NsGetSourceAddressUnCheckResult("midiStreamPause");
    pfmidiStreamPosition = NsGetSourceAddressUnCheckResult("midiStreamPosition");
    pfmidiStreamProperty = NsGetSourceAddressUnCheckResult("midiStreamProperty");
    pfmidiStreamRestart = NsGetSourceAddressUnCheckResult("midiStreamRestart");
    pfmidiStreamStop = NsGetSourceAddressUnCheckResult("midiStreamStop");
    pfmixerClose = NsGetSourceAddressUnCheckResult("mixerClose");
    pfmixerGetControlDetailsA = NsGetSourceAddressUnCheckResult("mixerGetControlDetailsA");
    pfmixerGetControlDetailsW = NsGetSourceAddressUnCheckResult("mixerGetControlDetailsW");
    pfmixerGetDevCapsA = NsGetSourceAddressUnCheckResult("mixerGetDevCapsA");
    pfmixerGetDevCapsW = NsGetSourceAddressUnCheckResult("mixerGetDevCapsW");
    pfmixerGetID = NsGetSourceAddressUnCheckResult("mixerGetID");
    pfmixerGetLineControlsA = NsGetSourceAddressUnCheckResult("mixerGetLineControlsA");
    pfmixerGetLineControlsW = NsGetSourceAddressUnCheckResult("mixerGetLineControlsW");
    pfmixerGetLineInfoA = NsGetSourceAddressUnCheckResult("mixerGetLineInfoA");
    pfmixerGetLineInfoW = NsGetSourceAddressUnCheckResult("mixerGetLineInfoW");
    pfmixerGetNumDevs = NsGetSourceAddressUnCheckResult("mixerGetNumDevs");
    pfmixerMessage = NsGetSourceAddressUnCheckResult("mixerMessage");
    pfmixerOpen = NsGetSourceAddressUnCheckResult("mixerOpen");
    pfmixerSetControlDetails = NsGetSourceAddressUnCheckResult("mixerSetControlDetails");
    pfmmDrvInstall = NsGetSourceAddressUnCheckResult("mmDrvInstall");
    pfmmGetCurrentTask = NsGetSourceAddressUnCheckResult("mmGetCurrentTask");
    pfmmTaskBlock = NsGetSourceAddressUnCheckResult("mmTaskBlock");
    pfmmTaskCreate = NsGetSourceAddressUnCheckResult("mmTaskCreate");
    pfmmTaskSignal = NsGetSourceAddressUnCheckResult("mmTaskSignal");
    pfmmTaskYield = NsGetSourceAddressUnCheckResult("mmTaskYield");
    pfmmioAdvance = NsGetSourceAddressUnCheckResult("mmioAdvance");
    pfmmioAscend = NsGetSourceAddressUnCheckResult("mmioAscend");
    pfmmioClose = NsGetSourceAddressUnCheckResult("mmioClose");
    pfmmioCreateChunk = NsGetSourceAddressUnCheckResult("mmioCreateChunk");
    pfmmioDescend = NsGetSourceAddressUnCheckResult("mmioDescend");
    pfmmioFlush = NsGetSourceAddressUnCheckResult("mmioFlush");
    pfmmioGetInfo = NsGetSourceAddressUnCheckResult("mmioGetInfo");
    pfmmioInstallIOProcA = NsGetSourceAddressUnCheckResult("mmioInstallIOProcA");
    pfmmioInstallIOProcW = NsGetSourceAddressUnCheckResult("mmioInstallIOProcW");
    pfmmioOpenA = NsGetSourceAddressUnCheckResult("mmioOpenA");
    pfmmioOpenW = NsGetSourceAddressUnCheckResult("mmioOpenW");
    pfmmioRead = NsGetSourceAddressUnCheckResult("mmioRead");
    pfmmioRenameA = NsGetSourceAddressUnCheckResult("mmioRenameA");
    pfmmioRenameW = NsGetSourceAddressUnCheckResult("mmioRenameW");
    pfmmioSeek = NsGetSourceAddressUnCheckResult("mmioSeek");
    pfmmioSendMessage = NsGetSourceAddressUnCheckResult("mmioSendMessage");
    pfmmioSetBuffer = NsGetSourceAddressUnCheckResult("mmioSetBuffer");
    pfmmioSetInfo = NsGetSourceAddressUnCheckResult("mmioSetInfo");
    pfmmioStringToFOURCCA = NsGetSourceAddressUnCheckResult("mmioStringToFOURCCA");
    pfmmioStringToFOURCCW = NsGetSourceAddressUnCheckResult("mmioStringToFOURCCW");
    pfmmioWrite = NsGetSourceAddressUnCheckResult("mmioWrite");
    pfmmsystemGetVersion = NsGetSourceAddressUnCheckResult("mmsystemGetVersion");
    pfmod32Message = NsGetSourceAddressUnCheckResult("mod32Message");
    pfmxd32Message = NsGetSourceAddressUnCheckResult("mxd32Message");
    pfsndPlaySoundA = NsGetSourceAddressUnCheckResult("sndPlaySoundA");
    pfsndPlaySoundW = NsGetSourceAddressUnCheckResult("sndPlaySoundW");
    pftid32Message = NsGetSourceAddressUnCheckResult("tid32Message");
    pftimeBeginPeriod = NsGetSourceAddressUnCheckResult("timeBeginPeriod");
    pftimeEndPeriod = NsGetSourceAddressUnCheckResult("timeEndPeriod");
    pftimeGetDevCaps = NsGetSourceAddressUnCheckResult("timeGetDevCaps");
    pftimeGetSystemTime = NsGetSourceAddressUnCheckResult("timeGetSystemTime");
    pftimeGetTime = NsGetSourceAddressUnCheckResult("timeGetTime");
    pftimeKillEvent = NsGetSourceAddressUnCheckResult("timeKillEvent");
    pftimeSetEvent = NsGetSourceAddressUnCheckResult("timeSetEvent");
    pfwaveInAddBuffer = NsGetSourceAddressUnCheckResult("waveInAddBuffer");
    pfwaveInClose = NsGetSourceAddressUnCheckResult("waveInClose");
    pfwaveInGetDevCapsA = NsGetSourceAddressUnCheckResult("waveInGetDevCapsA");
    pfwaveInGetDevCapsW = NsGetSourceAddressUnCheckResult("waveInGetDevCapsW");
    pfwaveInGetErrorTextA = NsGetSourceAddressUnCheckResult("waveInGetErrorTextA");
    pfwaveInGetErrorTextW = NsGetSourceAddressUnCheckResult("waveInGetErrorTextW");
    pfwaveInGetID = NsGetSourceAddressUnCheckResult("waveInGetID");
    pfwaveInGetNumDevs = NsGetSourceAddressUnCheckResult("waveInGetNumDevs");
    pfwaveInGetPosition = NsGetSourceAddressUnCheckResult("waveInGetPosition");
    pfwaveInMessage = NsGetSourceAddressUnCheckResult("waveInMessage");
    pfwaveInOpen = NsGetSourceAddressUnCheckResult("waveInOpen");
    pfwaveInPrepareHeader = NsGetSourceAddressUnCheckResult("waveInPrepareHeader");
    pfwaveInReset = NsGetSourceAddressUnCheckResult("waveInReset");
    pfwaveInStart = NsGetSourceAddressUnCheckResult("waveInStart");
    pfwaveInStop = NsGetSourceAddressUnCheckResult("waveInStop");
    pfwaveInUnprepareHeader = NsGetSourceAddressUnCheckResult("waveInUnprepareHeader");
    pfwaveOutBreakLoop = NsGetSourceAddressUnCheckResult("waveOutBreakLoop");
    pfwaveOutClose = NsGetSourceAddressUnCheckResult("waveOutClose");
    pfwaveOutGetDevCapsA = NsGetSourceAddressUnCheckResult("waveOutGetDevCapsA");
    pfwaveOutGetDevCapsW = NsGetSourceAddressUnCheckResult("waveOutGetDevCapsW");
    pfwaveOutGetErrorTextA = NsGetSourceAddressUnCheckResult("waveOutGetErrorTextA");
    pfwaveOutGetErrorTextW = NsGetSourceAddressUnCheckResult("waveOutGetErrorTextW");
    pfwaveOutGetID = NsGetSourceAddressUnCheckResult("waveOutGetID");
    pfwaveOutGetNumDevs = NsGetSourceAddressUnCheckResult("waveOutGetNumDevs");
    pfwaveOutGetPitch = NsGetSourceAddressUnCheckResult("waveOutGetPitch");
    pfwaveOutGetPlaybackRate = NsGetSourceAddressUnCheckResult("waveOutGetPlaybackRate");
    pfwaveOutGetPosition = NsGetSourceAddressUnCheckResult("waveOutGetPosition");
    pfwaveOutGetVolume = NsGetSourceAddressUnCheckResult("waveOutGetVolume");
    pfwaveOutMessage = NsGetSourceAddressUnCheckResult("waveOutMessage");
    pfwaveOutOpen = NsGetSourceAddressUnCheckResult("waveOutOpen");
    pfwaveOutPause = NsGetSourceAddressUnCheckResult("waveOutPause");
    pfwaveOutPrepareHeader = NsGetSourceAddressUnCheckResult("waveOutPrepareHeader");
    pfwaveOutReset = NsGetSourceAddressUnCheckResult("waveOutReset");
    pfwaveOutRestart = NsGetSourceAddressUnCheckResult("waveOutRestart");
    pfwaveOutSetPitch = NsGetSourceAddressUnCheckResult("waveOutSetPitch");
    pfwaveOutSetPlaybackRate = NsGetSourceAddressUnCheckResult("waveOutSetPlaybackRate");
    pfwaveOutSetVolume = NsGetSourceAddressUnCheckResult("waveOutSetVolume");
    pfwaveOutUnprepareHeader = NsGetSourceAddressUnCheckResult("waveOutUnprepareHeader");
    pfwaveOutWrite = NsGetSourceAddressUnCheckResult("waveOutWrite");
    pfwid32Message = NsGetSourceAddressUnCheckResult("wid32Message");
    pfwod32Message = NsGetSourceAddressUnCheckResult("wod32Message");
    pfNsUnknowProc_2 = NsGetSourceAddressUnCheckResult( MAKEINTRESOURCEA(2) );
}

std::filesystem::path GetCurrentDllDir(HMODULE hModule = NULL)
{
    if (NULL == hModule) {
        hModule = GetModuleHandle(NULL); // 获取调用者的模块句柄
    }
    TCHAR pathBuffer[MAX_PATH] = { 0 };
    // 获取包含文件名的完整路径
    if (GetModuleFileName(hModule, pathBuffer, MAX_PATH) == 0) {
        return {};
    }

    // 获取dir
    return std::filesystem::path(pathBuffer).parent_path();
}

void LoadInjectDlls(HMODULE hModule = NULL) {
    std::filesystem::path currentDir = GetCurrentDllDir();

    std::filesystem::path filename = currentDir / "inject.txt";
    // 检查文件是否存在
    std::ifstream file(filename);
    if (!file.is_open()) {
        OutputDebugString(L"inject.txt does not exist, skip inject.");
        return;
    }

    OutputDebugString(TEXT("read inject.txt."));
    TCHAR output[1024];
    std::string line;
    // 逐行读取文件
    while (std::getline(file, line)) {
        // 去除空白字符
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
        // 检查文件名是否以.dll结尾
        if (!line.empty() && line.size() > 4 && line.substr(line.size() - 4) == ".dll") {
            std::filesystem::path dllPath(line);
            // 如果不是绝对路径，就在当前路径下查找
            if (!dllPath.is_absolute()) {
                dllPath = currentDir / dllPath;
            }
            _stprintf_s(output, _countof(output), TEXT("try to load dll: %s"), dllPath.c_str());
            OutputDebugString(output);

            if (std::filesystem::exists(dllPath)) {
                HMODULE hModule = LoadLibrary(dllPath.c_str());
                if (hModule) {
                    _stprintf_s(output, _countof(output), TEXT("injected dll: %s"), dllPath.c_str());
                    OutputDebugString(output);
                }
            }
        }
    }
}

BOOL NsLoad()
{
    TCHAR szSourceName[MAX_PATH];
    GetSystemDirectory(szSourceName, MAX_PATH);
    StringCchCat(szSourceName, MAX_PATH, HIJACK_DLLNAME );
    g_hSourceModule = LoadLibrary(szSourceName);
    if (g_hSourceModule == NULL)
        return FALSE;
    NsInitDllExportProc();

    return TRUE;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                      )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        {
            g_hCurrentModule = hModule;
            DisableThreadLibraryCalls(hModule);
            if ( !NsLoad() )
                return FALSE;

            LoadInjectDlls(hModule);

            break;
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

