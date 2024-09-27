
; winmm.dll Hijack Project
; Caution: 
;   This project code is for testing purposes only! Please do not use it in any other way.
; Code By : Baymax Patch toOls 

LoadLibraryA PROTO
GetSystemDirectoryA PROTO
GetProcAddress PROTO
GetModuleFileNameA PROTO

.data
szDllName db '\winmm.dll',0

szCloseDriver db 'CloseDriver',0
szDefDriverProc db 'DefDriverProc',0
szDriverCallback db 'DriverCallback',0
szDrvGetModuleHandle db 'DrvGetModuleHandle',0
szGetDriverModuleHandle db 'GetDriverModuleHandle',0
szOpenDriver db 'OpenDriver',0
szPlaySound db 'PlaySound',0
szPlaySoundA db 'PlaySoundA',0
szPlaySoundW db 'PlaySoundW',0
szSendDriverMessage db 'SendDriverMessage',0
szWOWAppExit db 'WOWAppExit',0
szauxGetDevCapsA db 'auxGetDevCapsA',0
szauxGetDevCapsW db 'auxGetDevCapsW',0
szauxGetNumDevs db 'auxGetNumDevs',0
szauxGetVolume db 'auxGetVolume',0
szauxOutMessage db 'auxOutMessage',0
szauxSetVolume db 'auxSetVolume',0
szjoyConfigChanged db 'joyConfigChanged',0
szjoyGetDevCapsA db 'joyGetDevCapsA',0
szjoyGetDevCapsW db 'joyGetDevCapsW',0
szjoyGetNumDevs db 'joyGetNumDevs',0
szjoyGetPos db 'joyGetPos',0
szjoyGetPosEx db 'joyGetPosEx',0
szjoyGetThreshold db 'joyGetThreshold',0
szjoyReleaseCapture db 'joyReleaseCapture',0
szjoySetCapture db 'joySetCapture',0
szjoySetThreshold db 'joySetThreshold',0
szmciDriverNotify db 'mciDriverNotify',0
szmciDriverYield db 'mciDriverYield',0
szmciExecute db 'mciExecute',0
szmciFreeCommandResource db 'mciFreeCommandResource',0
szmciGetCreatorTask db 'mciGetCreatorTask',0
szmciGetDeviceIDA db 'mciGetDeviceIDA',0
szmciGetDeviceIDFromElementIDA db 'mciGetDeviceIDFromElementIDA',0
szmciGetDeviceIDFromElementIDW db 'mciGetDeviceIDFromElementIDW',0
szmciGetDeviceIDW db 'mciGetDeviceIDW',0
szmciGetDriverData db 'mciGetDriverData',0
szmciGetErrorStringA db 'mciGetErrorStringA',0
szmciGetErrorStringW db 'mciGetErrorStringW',0
szmciGetYieldProc db 'mciGetYieldProc',0
szmciLoadCommandResource db 'mciLoadCommandResource',0
szmciSendCommandA db 'mciSendCommandA',0
szmciSendCommandW db 'mciSendCommandW',0
szmciSendStringA db 'mciSendStringA',0
szmciSendStringW db 'mciSendStringW',0
szmciSetDriverData db 'mciSetDriverData',0
szmciSetYieldProc db 'mciSetYieldProc',0
szmidiConnect db 'midiConnect',0
szmidiDisconnect db 'midiDisconnect',0
szmidiInAddBuffer db 'midiInAddBuffer',0
szmidiInClose db 'midiInClose',0
szmidiInGetDevCapsA db 'midiInGetDevCapsA',0
szmidiInGetDevCapsW db 'midiInGetDevCapsW',0
szmidiInGetErrorTextA db 'midiInGetErrorTextA',0
szmidiInGetErrorTextW db 'midiInGetErrorTextW',0
szmidiInGetID db 'midiInGetID',0
szmidiInGetNumDevs db 'midiInGetNumDevs',0
szmidiInMessage db 'midiInMessage',0
szmidiInOpen db 'midiInOpen',0
szmidiInPrepareHeader db 'midiInPrepareHeader',0
szmidiInReset db 'midiInReset',0
szmidiInStart db 'midiInStart',0
szmidiInStop db 'midiInStop',0
szmidiInUnprepareHeader db 'midiInUnprepareHeader',0
szmidiOutCacheDrumPatches db 'midiOutCacheDrumPatches',0
szmidiOutCachePatches db 'midiOutCachePatches',0
szmidiOutClose db 'midiOutClose',0
szmidiOutGetDevCapsA db 'midiOutGetDevCapsA',0
szmidiOutGetDevCapsW db 'midiOutGetDevCapsW',0
szmidiOutGetErrorTextA db 'midiOutGetErrorTextA',0
szmidiOutGetErrorTextW db 'midiOutGetErrorTextW',0
szmidiOutGetID db 'midiOutGetID',0
szmidiOutGetNumDevs db 'midiOutGetNumDevs',0
szmidiOutGetVolume db 'midiOutGetVolume',0
szmidiOutLongMsg db 'midiOutLongMsg',0
szmidiOutMessage db 'midiOutMessage',0
szmidiOutOpen db 'midiOutOpen',0
szmidiOutPrepareHeader db 'midiOutPrepareHeader',0
szmidiOutReset db 'midiOutReset',0
szmidiOutSetVolume db 'midiOutSetVolume',0
szmidiOutShortMsg db 'midiOutShortMsg',0
szmidiOutUnprepareHeader db 'midiOutUnprepareHeader',0
szmidiStreamClose db 'midiStreamClose',0
szmidiStreamOpen db 'midiStreamOpen',0
szmidiStreamOut db 'midiStreamOut',0
szmidiStreamPause db 'midiStreamPause',0
szmidiStreamPosition db 'midiStreamPosition',0
szmidiStreamProperty db 'midiStreamProperty',0
szmidiStreamRestart db 'midiStreamRestart',0
szmidiStreamStop db 'midiStreamStop',0
szmixerClose db 'mixerClose',0
szmixerGetControlDetailsA db 'mixerGetControlDetailsA',0
szmixerGetControlDetailsW db 'mixerGetControlDetailsW',0
szmixerGetDevCapsA db 'mixerGetDevCapsA',0
szmixerGetDevCapsW db 'mixerGetDevCapsW',0
szmixerGetID db 'mixerGetID',0
szmixerGetLineControlsA db 'mixerGetLineControlsA',0
szmixerGetLineControlsW db 'mixerGetLineControlsW',0
szmixerGetLineInfoA db 'mixerGetLineInfoA',0
szmixerGetLineInfoW db 'mixerGetLineInfoW',0
szmixerGetNumDevs db 'mixerGetNumDevs',0
szmixerMessage db 'mixerMessage',0
szmixerOpen db 'mixerOpen',0
szmixerSetControlDetails db 'mixerSetControlDetails',0
szmmDrvInstall db 'mmDrvInstall',0
szmmGetCurrentTask db 'mmGetCurrentTask',0
szmmTaskBlock db 'mmTaskBlock',0
szmmTaskCreate db 'mmTaskCreate',0
szmmTaskSignal db 'mmTaskSignal',0
szmmTaskYield db 'mmTaskYield',0
szmmioAdvance db 'mmioAdvance',0
szmmioAscend db 'mmioAscend',0
szmmioClose db 'mmioClose',0
szmmioCreateChunk db 'mmioCreateChunk',0
szmmioDescend db 'mmioDescend',0
szmmioFlush db 'mmioFlush',0
szmmioGetInfo db 'mmioGetInfo',0
szmmioInstallIOProcA db 'mmioInstallIOProcA',0
szmmioInstallIOProcW db 'mmioInstallIOProcW',0
szmmioOpenA db 'mmioOpenA',0
szmmioOpenW db 'mmioOpenW',0
szmmioRead db 'mmioRead',0
szmmioRenameA db 'mmioRenameA',0
szmmioRenameW db 'mmioRenameW',0
szmmioSeek db 'mmioSeek',0
szmmioSendMessage db 'mmioSendMessage',0
szmmioSetBuffer db 'mmioSetBuffer',0
szmmioSetInfo db 'mmioSetInfo',0
szmmioStringToFOURCCA db 'mmioStringToFOURCCA',0
szmmioStringToFOURCCW db 'mmioStringToFOURCCW',0
szmmioWrite db 'mmioWrite',0
szmmsystemGetVersion db 'mmsystemGetVersion',0
szsndPlaySoundA db 'sndPlaySoundA',0
szsndPlaySoundW db 'sndPlaySoundW',0
sztimeBeginPeriod db 'timeBeginPeriod',0
sztimeEndPeriod db 'timeEndPeriod',0
sztimeGetDevCaps db 'timeGetDevCaps',0
sztimeGetSystemTime db 'timeGetSystemTime',0
sztimeGetTime db 'timeGetTime',0
sztimeKillEvent db 'timeKillEvent',0
sztimeSetEvent db 'timeSetEvent',0
szwaveInAddBuffer db 'waveInAddBuffer',0
szwaveInClose db 'waveInClose',0
szwaveInGetDevCapsA db 'waveInGetDevCapsA',0
szwaveInGetDevCapsW db 'waveInGetDevCapsW',0
szwaveInGetErrorTextA db 'waveInGetErrorTextA',0
szwaveInGetErrorTextW db 'waveInGetErrorTextW',0
szwaveInGetID db 'waveInGetID',0
szwaveInGetNumDevs db 'waveInGetNumDevs',0
szwaveInGetPosition db 'waveInGetPosition',0
szwaveInMessage db 'waveInMessage',0
szwaveInOpen db 'waveInOpen',0
szwaveInPrepareHeader db 'waveInPrepareHeader',0
szwaveInReset db 'waveInReset',0
szwaveInStart db 'waveInStart',0
szwaveInStop db 'waveInStop',0
szwaveInUnprepareHeader db 'waveInUnprepareHeader',0
szwaveOutBreakLoop db 'waveOutBreakLoop',0
szwaveOutClose db 'waveOutClose',0
szwaveOutGetDevCapsA db 'waveOutGetDevCapsA',0
szwaveOutGetDevCapsW db 'waveOutGetDevCapsW',0
szwaveOutGetErrorTextA db 'waveOutGetErrorTextA',0
szwaveOutGetErrorTextW db 'waveOutGetErrorTextW',0
szwaveOutGetID db 'waveOutGetID',0
szwaveOutGetNumDevs db 'waveOutGetNumDevs',0
szwaveOutGetPitch db 'waveOutGetPitch',0
szwaveOutGetPlaybackRate db 'waveOutGetPlaybackRate',0
szwaveOutGetPosition db 'waveOutGetPosition',0
szwaveOutGetVolume db 'waveOutGetVolume',0
szwaveOutMessage db 'waveOutMessage',0
szwaveOutOpen db 'waveOutOpen',0
szwaveOutPause db 'waveOutPause',0
szwaveOutPrepareHeader db 'waveOutPrepareHeader',0
szwaveOutReset db 'waveOutReset',0
szwaveOutRestart db 'waveOutRestart',0
szwaveOutSetPitch db 'waveOutSetPitch',0
szwaveOutSetPlaybackRate db 'waveOutSetPlaybackRate',0
szwaveOutSetVolume db 'waveOutSetVolume',0
szwaveOutUnprepareHeader db 'waveOutUnprepareHeader',0
szwaveOutWrite db 'waveOutWrite',0
szNsUnknowProc_2 db 'NsUnknowProc_2',0

pfCloseDriver dq 0
pfDefDriverProc dq 0
pfDriverCallback dq 0
pfDrvGetModuleHandle dq 0
pfGetDriverModuleHandle dq 0
pfOpenDriver dq 0
pfPlaySound dq 0
pfPlaySoundA dq 0
pfPlaySoundW dq 0
pfSendDriverMessage dq 0
pfWOWAppExit dq 0
pfauxGetDevCapsA dq 0
pfauxGetDevCapsW dq 0
pfauxGetNumDevs dq 0
pfauxGetVolume dq 0
pfauxOutMessage dq 0
pfauxSetVolume dq 0
pfjoyConfigChanged dq 0
pfjoyGetDevCapsA dq 0
pfjoyGetDevCapsW dq 0
pfjoyGetNumDevs dq 0
pfjoyGetPos dq 0
pfjoyGetPosEx dq 0
pfjoyGetThreshold dq 0
pfjoyReleaseCapture dq 0
pfjoySetCapture dq 0
pfjoySetThreshold dq 0
pfmciDriverNotify dq 0
pfmciDriverYield dq 0
pfmciExecute dq 0
pfmciFreeCommandResource dq 0
pfmciGetCreatorTask dq 0
pfmciGetDeviceIDA dq 0
pfmciGetDeviceIDFromElementIDA dq 0
pfmciGetDeviceIDFromElementIDW dq 0
pfmciGetDeviceIDW dq 0
pfmciGetDriverData dq 0
pfmciGetErrorStringA dq 0
pfmciGetErrorStringW dq 0
pfmciGetYieldProc dq 0
pfmciLoadCommandResource dq 0
pfmciSendCommandA dq 0
pfmciSendCommandW dq 0
pfmciSendStringA dq 0
pfmciSendStringW dq 0
pfmciSetDriverData dq 0
pfmciSetYieldProc dq 0
pfmidiConnect dq 0
pfmidiDisconnect dq 0
pfmidiInAddBuffer dq 0
pfmidiInClose dq 0
pfmidiInGetDevCapsA dq 0
pfmidiInGetDevCapsW dq 0
pfmidiInGetErrorTextA dq 0
pfmidiInGetErrorTextW dq 0
pfmidiInGetID dq 0
pfmidiInGetNumDevs dq 0
pfmidiInMessage dq 0
pfmidiInOpen dq 0
pfmidiInPrepareHeader dq 0
pfmidiInReset dq 0
pfmidiInStart dq 0
pfmidiInStop dq 0
pfmidiInUnprepareHeader dq 0
pfmidiOutCacheDrumPatches dq 0
pfmidiOutCachePatches dq 0
pfmidiOutClose dq 0
pfmidiOutGetDevCapsA dq 0
pfmidiOutGetDevCapsW dq 0
pfmidiOutGetErrorTextA dq 0
pfmidiOutGetErrorTextW dq 0
pfmidiOutGetID dq 0
pfmidiOutGetNumDevs dq 0
pfmidiOutGetVolume dq 0
pfmidiOutLongMsg dq 0
pfmidiOutMessage dq 0
pfmidiOutOpen dq 0
pfmidiOutPrepareHeader dq 0
pfmidiOutReset dq 0
pfmidiOutSetVolume dq 0
pfmidiOutShortMsg dq 0
pfmidiOutUnprepareHeader dq 0
pfmidiStreamClose dq 0
pfmidiStreamOpen dq 0
pfmidiStreamOut dq 0
pfmidiStreamPause dq 0
pfmidiStreamPosition dq 0
pfmidiStreamProperty dq 0
pfmidiStreamRestart dq 0
pfmidiStreamStop dq 0
pfmixerClose dq 0
pfmixerGetControlDetailsA dq 0
pfmixerGetControlDetailsW dq 0
pfmixerGetDevCapsA dq 0
pfmixerGetDevCapsW dq 0
pfmixerGetID dq 0
pfmixerGetLineControlsA dq 0
pfmixerGetLineControlsW dq 0
pfmixerGetLineInfoA dq 0
pfmixerGetLineInfoW dq 0
pfmixerGetNumDevs dq 0
pfmixerMessage dq 0
pfmixerOpen dq 0
pfmixerSetControlDetails dq 0
pfmmDrvInstall dq 0
pfmmGetCurrentTask dq 0
pfmmTaskBlock dq 0
pfmmTaskCreate dq 0
pfmmTaskSignal dq 0
pfmmTaskYield dq 0
pfmmioAdvance dq 0
pfmmioAscend dq 0
pfmmioClose dq 0
pfmmioCreateChunk dq 0
pfmmioDescend dq 0
pfmmioFlush dq 0
pfmmioGetInfo dq 0
pfmmioInstallIOProcA dq 0
pfmmioInstallIOProcW dq 0
pfmmioOpenA dq 0
pfmmioOpenW dq 0
pfmmioRead dq 0
pfmmioRenameA dq 0
pfmmioRenameW dq 0
pfmmioSeek dq 0
pfmmioSendMessage dq 0
pfmmioSetBuffer dq 0
pfmmioSetInfo dq 0
pfmmioStringToFOURCCA dq 0
pfmmioStringToFOURCCW dq 0
pfmmioWrite dq 0
pfmmsystemGetVersion dq 0
pfsndPlaySoundA dq 0
pfsndPlaySoundW dq 0
pftimeBeginPeriod dq 0
pftimeEndPeriod dq 0
pftimeGetDevCaps dq 0
pftimeGetSystemTime dq 0
pftimeGetTime dq 0
pftimeKillEvent dq 0
pftimeSetEvent dq 0
pfwaveInAddBuffer dq 0
pfwaveInClose dq 0
pfwaveInGetDevCapsA dq 0
pfwaveInGetDevCapsW dq 0
pfwaveInGetErrorTextA dq 0
pfwaveInGetErrorTextW dq 0
pfwaveInGetID dq 0
pfwaveInGetNumDevs dq 0
pfwaveInGetPosition dq 0
pfwaveInMessage dq 0
pfwaveInOpen dq 0
pfwaveInPrepareHeader dq 0
pfwaveInReset dq 0
pfwaveInStart dq 0
pfwaveInStop dq 0
pfwaveInUnprepareHeader dq 0
pfwaveOutBreakLoop dq 0
pfwaveOutClose dq 0
pfwaveOutGetDevCapsA dq 0
pfwaveOutGetDevCapsW dq 0
pfwaveOutGetErrorTextA dq 0
pfwaveOutGetErrorTextW dq 0
pfwaveOutGetID dq 0
pfwaveOutGetNumDevs dq 0
pfwaveOutGetPitch dq 0
pfwaveOutGetPlaybackRate dq 0
pfwaveOutGetPosition dq 0
pfwaveOutGetVolume dq 0
pfwaveOutMessage dq 0
pfwaveOutOpen dq 0
pfwaveOutPause dq 0
pfwaveOutPrepareHeader dq 0
pfwaveOutReset dq 0
pfwaveOutRestart dq 0
pfwaveOutSetPitch dq 0
pfwaveOutSetPlaybackRate dq 0
pfwaveOutSetVolume dq 0
pfwaveOutUnprepareHeader dq 0
pfwaveOutWrite dq 0
pfNsUnknowProc_2 dq 0

.code

NsStringCatA proc
  push rsi
  push rdi
  xor rsi,rsi
  dec rsi
  xor rdi,rdi
  dec rdi
  xor rax,rax
  dec rdx

_NsStringCatABegin:

  inc rsi
  mov al,byte ptr [rcx+rsi]
  cmp rsi,rdx
  jge _NsStringCatAEnd
  test al,al
  jnz _NsStringCatABegin

_NsStringCatALink:

  inc rdi
  mov al,byte ptr[r8+rdi]
  test al,al
  jz _NsStringCatAEnd
  mov byte ptr [rcx+rsi],al
  inc rsi
  cmp rsi,rdx
  jge _NsStringCatAEnd
  jmp _NsStringCatALink

_NsStringCatAEnd:
  xor rax,rax
  mov byte ptr [rcx+rsi],al
  pop rdi
  pop rsi
  ret

NsStringCatA endp

NsInitDll proc

  push rsi
  sub rsp,130h
  xor rax,rax
  mov [rsp+120],rax

  lea rsi,[rsp+20h]
  mov rdx,100h
  mov rcx,rsi
  call GetSystemDirectoryA
  test rax,rax
  jz _NsInitDllEnd

  lea r8,szDllName
  mov rdx,100h
  mov rcx,rsi
  call NsStringCatA

  mov rcx,rsi
  call LoadLibraryA
  mov [rsi+100h],rax

  test rax,rax
  jz _NsInitDllEnd

  lea rdx,szCloseDriver
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfCloseDriver, rax

  lea rdx,szDefDriverProc
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfDefDriverProc, rax

  lea rdx,szDriverCallback
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfDriverCallback, rax

  lea rdx,szDrvGetModuleHandle
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfDrvGetModuleHandle, rax

  lea rdx,szGetDriverModuleHandle
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfGetDriverModuleHandle, rax

  lea rdx,szOpenDriver
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfOpenDriver, rax

  lea rdx,szPlaySound
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfPlaySound, rax

  lea rdx,szPlaySoundA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfPlaySoundA, rax

  lea rdx,szPlaySoundW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfPlaySoundW, rax

  lea rdx,szSendDriverMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfSendDriverMessage, rax

  lea rdx,szWOWAppExit
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfWOWAppExit, rax

  lea rdx,szauxGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfauxGetDevCapsA, rax

  lea rdx,szauxGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfauxGetDevCapsW, rax

  lea rdx,szauxGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfauxGetNumDevs, rax

  lea rdx,szauxGetVolume
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfauxGetVolume, rax

  lea rdx,szauxOutMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfauxOutMessage, rax

  lea rdx,szauxSetVolume
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfauxSetVolume, rax

  lea rdx,szjoyConfigChanged
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyConfigChanged, rax

  lea rdx,szjoyGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyGetDevCapsA, rax

  lea rdx,szjoyGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyGetDevCapsW, rax

  lea rdx,szjoyGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyGetNumDevs, rax

  lea rdx,szjoyGetPos
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyGetPos, rax

  lea rdx,szjoyGetPosEx
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyGetPosEx, rax

  lea rdx,szjoyGetThreshold
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyGetThreshold, rax

  lea rdx,szjoyReleaseCapture
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoyReleaseCapture, rax

  lea rdx,szjoySetCapture
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoySetCapture, rax

  lea rdx,szjoySetThreshold
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfjoySetThreshold, rax

  lea rdx,szmciDriverNotify
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciDriverNotify, rax

  lea rdx,szmciDriverYield
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciDriverYield, rax

  lea rdx,szmciExecute
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciExecute, rax

  lea rdx,szmciFreeCommandResource
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciFreeCommandResource, rax

  lea rdx,szmciGetCreatorTask
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetCreatorTask, rax

  lea rdx,szmciGetDeviceIDA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetDeviceIDA, rax

  lea rdx,szmciGetDeviceIDFromElementIDA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetDeviceIDFromElementIDA, rax

  lea rdx,szmciGetDeviceIDFromElementIDW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetDeviceIDFromElementIDW, rax

  lea rdx,szmciGetDeviceIDW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetDeviceIDW, rax

  lea rdx,szmciGetDriverData
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetDriverData, rax

  lea rdx,szmciGetErrorStringA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetErrorStringA, rax

  lea rdx,szmciGetErrorStringW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetErrorStringW, rax

  lea rdx,szmciGetYieldProc
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciGetYieldProc, rax

  lea rdx,szmciLoadCommandResource
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciLoadCommandResource, rax

  lea rdx,szmciSendCommandA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciSendCommandA, rax

  lea rdx,szmciSendCommandW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciSendCommandW, rax

  lea rdx,szmciSendStringA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciSendStringA, rax

  lea rdx,szmciSendStringW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciSendStringW, rax

  lea rdx,szmciSetDriverData
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciSetDriverData, rax

  lea rdx,szmciSetYieldProc
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmciSetYieldProc, rax

  lea rdx,szmidiConnect
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiConnect, rax

  lea rdx,szmidiDisconnect
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiDisconnect, rax

  lea rdx,szmidiInAddBuffer
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInAddBuffer, rax

  lea rdx,szmidiInClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInClose, rax

  lea rdx,szmidiInGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInGetDevCapsA, rax

  lea rdx,szmidiInGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInGetDevCapsW, rax

  lea rdx,szmidiInGetErrorTextA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInGetErrorTextA, rax

  lea rdx,szmidiInGetErrorTextW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInGetErrorTextW, rax

  lea rdx,szmidiInGetID
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInGetID, rax

  lea rdx,szmidiInGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInGetNumDevs, rax

  lea rdx,szmidiInMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInMessage, rax

  lea rdx,szmidiInOpen
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInOpen, rax

  lea rdx,szmidiInPrepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInPrepareHeader, rax

  lea rdx,szmidiInReset
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInReset, rax

  lea rdx,szmidiInStart
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInStart, rax

  lea rdx,szmidiInStop
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInStop, rax

  lea rdx,szmidiInUnprepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiInUnprepareHeader, rax

  lea rdx,szmidiOutCacheDrumPatches
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutCacheDrumPatches, rax

  lea rdx,szmidiOutCachePatches
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutCachePatches, rax

  lea rdx,szmidiOutClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutClose, rax

  lea rdx,szmidiOutGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetDevCapsA, rax

  lea rdx,szmidiOutGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetDevCapsW, rax

  lea rdx,szmidiOutGetErrorTextA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetErrorTextA, rax

  lea rdx,szmidiOutGetErrorTextW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetErrorTextW, rax

  lea rdx,szmidiOutGetID
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetID, rax

  lea rdx,szmidiOutGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetNumDevs, rax

  lea rdx,szmidiOutGetVolume
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutGetVolume, rax

  lea rdx,szmidiOutLongMsg
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutLongMsg, rax

  lea rdx,szmidiOutMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutMessage, rax

  lea rdx,szmidiOutOpen
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutOpen, rax

  lea rdx,szmidiOutPrepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutPrepareHeader, rax

  lea rdx,szmidiOutReset
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutReset, rax

  lea rdx,szmidiOutSetVolume
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutSetVolume, rax

  lea rdx,szmidiOutShortMsg
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutShortMsg, rax

  lea rdx,szmidiOutUnprepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiOutUnprepareHeader, rax

  lea rdx,szmidiStreamClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamClose, rax

  lea rdx,szmidiStreamOpen
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamOpen, rax

  lea rdx,szmidiStreamOut
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamOut, rax

  lea rdx,szmidiStreamPause
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamPause, rax

  lea rdx,szmidiStreamPosition
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamPosition, rax

  lea rdx,szmidiStreamProperty
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamProperty, rax

  lea rdx,szmidiStreamRestart
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamRestart, rax

  lea rdx,szmidiStreamStop
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmidiStreamStop, rax

  lea rdx,szmixerClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerClose, rax

  lea rdx,szmixerGetControlDetailsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetControlDetailsA, rax

  lea rdx,szmixerGetControlDetailsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetControlDetailsW, rax

  lea rdx,szmixerGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetDevCapsA, rax

  lea rdx,szmixerGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetDevCapsW, rax

  lea rdx,szmixerGetID
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetID, rax

  lea rdx,szmixerGetLineControlsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetLineControlsA, rax

  lea rdx,szmixerGetLineControlsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetLineControlsW, rax

  lea rdx,szmixerGetLineInfoA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetLineInfoA, rax

  lea rdx,szmixerGetLineInfoW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetLineInfoW, rax

  lea rdx,szmixerGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerGetNumDevs, rax

  lea rdx,szmixerMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerMessage, rax

  lea rdx,szmixerOpen
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerOpen, rax

  lea rdx,szmixerSetControlDetails
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmixerSetControlDetails, rax

  lea rdx,szmmDrvInstall
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmDrvInstall, rax

  lea rdx,szmmGetCurrentTask
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmGetCurrentTask, rax

  lea rdx,szmmTaskBlock
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmTaskBlock, rax

  lea rdx,szmmTaskCreate
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmTaskCreate, rax

  lea rdx,szmmTaskSignal
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmTaskSignal, rax

  lea rdx,szmmTaskYield
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmTaskYield, rax

  lea rdx,szmmioAdvance
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioAdvance, rax

  lea rdx,szmmioAscend
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioAscend, rax

  lea rdx,szmmioClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioClose, rax

  lea rdx,szmmioCreateChunk
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioCreateChunk, rax

  lea rdx,szmmioDescend
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioDescend, rax

  lea rdx,szmmioFlush
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioFlush, rax

  lea rdx,szmmioGetInfo
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioGetInfo, rax

  lea rdx,szmmioInstallIOProcA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioInstallIOProcA, rax

  lea rdx,szmmioInstallIOProcW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioInstallIOProcW, rax

  lea rdx,szmmioOpenA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioOpenA, rax

  lea rdx,szmmioOpenW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioOpenW, rax

  lea rdx,szmmioRead
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioRead, rax

  lea rdx,szmmioRenameA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioRenameA, rax

  lea rdx,szmmioRenameW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioRenameW, rax

  lea rdx,szmmioSeek
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioSeek, rax

  lea rdx,szmmioSendMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioSendMessage, rax

  lea rdx,szmmioSetBuffer
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioSetBuffer, rax

  lea rdx,szmmioSetInfo
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioSetInfo, rax

  lea rdx,szmmioStringToFOURCCA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioStringToFOURCCA, rax

  lea rdx,szmmioStringToFOURCCW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioStringToFOURCCW, rax

  lea rdx,szmmioWrite
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmioWrite, rax

  lea rdx,szmmsystemGetVersion
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfmmsystemGetVersion, rax

  lea rdx,szsndPlaySoundA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfsndPlaySoundA, rax

  lea rdx,szsndPlaySoundW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfsndPlaySoundW, rax

  lea rdx,sztimeBeginPeriod
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeBeginPeriod, rax

  lea rdx,sztimeEndPeriod
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeEndPeriod, rax

  lea rdx,sztimeGetDevCaps
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeGetDevCaps, rax

  lea rdx,sztimeGetSystemTime
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeGetSystemTime, rax

  lea rdx,sztimeGetTime
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeGetTime, rax

  lea rdx,sztimeKillEvent
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeKillEvent, rax

  lea rdx,sztimeSetEvent
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pftimeSetEvent, rax

  lea rdx,szwaveInAddBuffer
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInAddBuffer, rax

  lea rdx,szwaveInClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInClose, rax

  lea rdx,szwaveInGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetDevCapsA, rax

  lea rdx,szwaveInGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetDevCapsW, rax

  lea rdx,szwaveInGetErrorTextA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetErrorTextA, rax

  lea rdx,szwaveInGetErrorTextW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetErrorTextW, rax

  lea rdx,szwaveInGetID
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetID, rax

  lea rdx,szwaveInGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetNumDevs, rax

  lea rdx,szwaveInGetPosition
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInGetPosition, rax

  lea rdx,szwaveInMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInMessage, rax

  lea rdx,szwaveInOpen
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInOpen, rax

  lea rdx,szwaveInPrepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInPrepareHeader, rax

  lea rdx,szwaveInReset
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInReset, rax

  lea rdx,szwaveInStart
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInStart, rax

  lea rdx,szwaveInStop
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInStop, rax

  lea rdx,szwaveInUnprepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveInUnprepareHeader, rax

  lea rdx,szwaveOutBreakLoop
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutBreakLoop, rax

  lea rdx,szwaveOutClose
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutClose, rax

  lea rdx,szwaveOutGetDevCapsA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetDevCapsA, rax

  lea rdx,szwaveOutGetDevCapsW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetDevCapsW, rax

  lea rdx,szwaveOutGetErrorTextA
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetErrorTextA, rax

  lea rdx,szwaveOutGetErrorTextW
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetErrorTextW, rax

  lea rdx,szwaveOutGetID
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetID, rax

  lea rdx,szwaveOutGetNumDevs
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetNumDevs, rax

  lea rdx,szwaveOutGetPitch
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetPitch, rax

  lea rdx,szwaveOutGetPlaybackRate
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetPlaybackRate, rax

  lea rdx,szwaveOutGetPosition
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetPosition, rax

  lea rdx,szwaveOutGetVolume
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutGetVolume, rax

  lea rdx,szwaveOutMessage
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutMessage, rax

  lea rdx,szwaveOutOpen
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutOpen, rax

  lea rdx,szwaveOutPause
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutPause, rax

  lea rdx,szwaveOutPrepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutPrepareHeader, rax

  lea rdx,szwaveOutReset
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutReset, rax

  lea rdx,szwaveOutRestart
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutRestart, rax

  lea rdx,szwaveOutSetPitch
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutSetPitch, rax

  lea rdx,szwaveOutSetPlaybackRate
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutSetPlaybackRate, rax

  lea rdx,szwaveOutSetVolume
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutSetVolume, rax

  lea rdx,szwaveOutUnprepareHeader
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutUnprepareHeader, rax

  lea rdx,szwaveOutWrite
  mov rcx,[rsi+100h]
  call GetProcAddress
  test rax,rax
  jz _NsInitDllEnd
  mov pfwaveOutWrite, rax

  mov rdx,2
  mov rcx,[rsi+100h]
  call GetProcAddress
  ;test rax,rax
  ;jz _NsInitDllEnd
  mov pfNsUnknowProc_2, rax

  xor rax,rax
  inc rax
  mov [rsp+120],rax

_NsInitDllEnd:

  mov rax,[rsp+120]
  add rsp,130h
  pop rsi
  ret
NsInitDll endp

Hijack64_CloseDriver proc
  jmp qword ptr [pfCloseDriver]
Hijack64_CloseDriver endp

Hijack64_DefDriverProc proc
  jmp qword ptr [pfDefDriverProc]
Hijack64_DefDriverProc endp

Hijack64_DriverCallback proc
  jmp qword ptr [pfDriverCallback]
Hijack64_DriverCallback endp

Hijack64_DrvGetModuleHandle proc
  jmp qword ptr [pfDrvGetModuleHandle]
Hijack64_DrvGetModuleHandle endp

Hijack64_GetDriverModuleHandle proc
  jmp qword ptr [pfGetDriverModuleHandle]
Hijack64_GetDriverModuleHandle endp

Hijack64_OpenDriver proc
  jmp qword ptr [pfOpenDriver]
Hijack64_OpenDriver endp

Hijack64_PlaySound proc
  jmp qword ptr [pfPlaySound]
Hijack64_PlaySound endp

Hijack64_PlaySoundA proc
  jmp qword ptr [pfPlaySoundA]
Hijack64_PlaySoundA endp

Hijack64_PlaySoundW proc
  jmp qword ptr [pfPlaySoundW]
Hijack64_PlaySoundW endp

Hijack64_SendDriverMessage proc
  jmp qword ptr [pfSendDriverMessage]
Hijack64_SendDriverMessage endp

Hijack64_WOWAppExit proc
  jmp qword ptr [pfWOWAppExit]
Hijack64_WOWAppExit endp

Hijack64_auxGetDevCapsA proc
  jmp qword ptr [pfauxGetDevCapsA]
Hijack64_auxGetDevCapsA endp

Hijack64_auxGetDevCapsW proc
  jmp qword ptr [pfauxGetDevCapsW]
Hijack64_auxGetDevCapsW endp

Hijack64_auxGetNumDevs proc
  jmp qword ptr [pfauxGetNumDevs]
Hijack64_auxGetNumDevs endp

Hijack64_auxGetVolume proc
  jmp qword ptr [pfauxGetVolume]
Hijack64_auxGetVolume endp

Hijack64_auxOutMessage proc
  jmp qword ptr [pfauxOutMessage]
Hijack64_auxOutMessage endp

Hijack64_auxSetVolume proc
  jmp qword ptr [pfauxSetVolume]
Hijack64_auxSetVolume endp

Hijack64_joyConfigChanged proc
  jmp qword ptr [pfjoyConfigChanged]
Hijack64_joyConfigChanged endp

Hijack64_joyGetDevCapsA proc
  jmp qword ptr [pfjoyGetDevCapsA]
Hijack64_joyGetDevCapsA endp

Hijack64_joyGetDevCapsW proc
  jmp qword ptr [pfjoyGetDevCapsW]
Hijack64_joyGetDevCapsW endp

Hijack64_joyGetNumDevs proc
  jmp qword ptr [pfjoyGetNumDevs]
Hijack64_joyGetNumDevs endp

Hijack64_joyGetPos proc
  jmp qword ptr [pfjoyGetPos]
Hijack64_joyGetPos endp

Hijack64_joyGetPosEx proc
  jmp qword ptr [pfjoyGetPosEx]
Hijack64_joyGetPosEx endp

Hijack64_joyGetThreshold proc
  jmp qword ptr [pfjoyGetThreshold]
Hijack64_joyGetThreshold endp

Hijack64_joyReleaseCapture proc
  jmp qword ptr [pfjoyReleaseCapture]
Hijack64_joyReleaseCapture endp

Hijack64_joySetCapture proc
  jmp qword ptr [pfjoySetCapture]
Hijack64_joySetCapture endp

Hijack64_joySetThreshold proc
  jmp qword ptr [pfjoySetThreshold]
Hijack64_joySetThreshold endp

Hijack64_mciDriverNotify proc
  jmp qword ptr [pfmciDriverNotify]
Hijack64_mciDriverNotify endp

Hijack64_mciDriverYield proc
  jmp qword ptr [pfmciDriverYield]
Hijack64_mciDriverYield endp

Hijack64_mciExecute proc
  jmp qword ptr [pfmciExecute]
Hijack64_mciExecute endp

Hijack64_mciFreeCommandResource proc
  jmp qword ptr [pfmciFreeCommandResource]
Hijack64_mciFreeCommandResource endp

Hijack64_mciGetCreatorTask proc
  jmp qword ptr [pfmciGetCreatorTask]
Hijack64_mciGetCreatorTask endp

Hijack64_mciGetDeviceIDA proc
  jmp qword ptr [pfmciGetDeviceIDA]
Hijack64_mciGetDeviceIDA endp

Hijack64_mciGetDeviceIDFromElementIDA proc
  jmp qword ptr [pfmciGetDeviceIDFromElementIDA]
Hijack64_mciGetDeviceIDFromElementIDA endp

Hijack64_mciGetDeviceIDFromElementIDW proc
  jmp qword ptr [pfmciGetDeviceIDFromElementIDW]
Hijack64_mciGetDeviceIDFromElementIDW endp

Hijack64_mciGetDeviceIDW proc
  jmp qword ptr [pfmciGetDeviceIDW]
Hijack64_mciGetDeviceIDW endp

Hijack64_mciGetDriverData proc
  jmp qword ptr [pfmciGetDriverData]
Hijack64_mciGetDriverData endp

Hijack64_mciGetErrorStringA proc
  jmp qword ptr [pfmciGetErrorStringA]
Hijack64_mciGetErrorStringA endp

Hijack64_mciGetErrorStringW proc
  jmp qword ptr [pfmciGetErrorStringW]
Hijack64_mciGetErrorStringW endp

Hijack64_mciGetYieldProc proc
  jmp qword ptr [pfmciGetYieldProc]
Hijack64_mciGetYieldProc endp

Hijack64_mciLoadCommandResource proc
  jmp qword ptr [pfmciLoadCommandResource]
Hijack64_mciLoadCommandResource endp

Hijack64_mciSendCommandA proc
  jmp qword ptr [pfmciSendCommandA]
Hijack64_mciSendCommandA endp

Hijack64_mciSendCommandW proc
  jmp qword ptr [pfmciSendCommandW]
Hijack64_mciSendCommandW endp

Hijack64_mciSendStringA proc
  jmp qword ptr [pfmciSendStringA]
Hijack64_mciSendStringA endp

Hijack64_mciSendStringW proc
  jmp qword ptr [pfmciSendStringW]
Hijack64_mciSendStringW endp

Hijack64_mciSetDriverData proc
  jmp qword ptr [pfmciSetDriverData]
Hijack64_mciSetDriverData endp

Hijack64_mciSetYieldProc proc
  jmp qword ptr [pfmciSetYieldProc]
Hijack64_mciSetYieldProc endp

Hijack64_midiConnect proc
  jmp qword ptr [pfmidiConnect]
Hijack64_midiConnect endp

Hijack64_midiDisconnect proc
  jmp qword ptr [pfmidiDisconnect]
Hijack64_midiDisconnect endp

Hijack64_midiInAddBuffer proc
  jmp qword ptr [pfmidiInAddBuffer]
Hijack64_midiInAddBuffer endp

Hijack64_midiInClose proc
  jmp qword ptr [pfmidiInClose]
Hijack64_midiInClose endp

Hijack64_midiInGetDevCapsA proc
  jmp qword ptr [pfmidiInGetDevCapsA]
Hijack64_midiInGetDevCapsA endp

Hijack64_midiInGetDevCapsW proc
  jmp qword ptr [pfmidiInGetDevCapsW]
Hijack64_midiInGetDevCapsW endp

Hijack64_midiInGetErrorTextA proc
  jmp qword ptr [pfmidiInGetErrorTextA]
Hijack64_midiInGetErrorTextA endp

Hijack64_midiInGetErrorTextW proc
  jmp qword ptr [pfmidiInGetErrorTextW]
Hijack64_midiInGetErrorTextW endp

Hijack64_midiInGetID proc
  jmp qword ptr [pfmidiInGetID]
Hijack64_midiInGetID endp

Hijack64_midiInGetNumDevs proc
  jmp qword ptr [pfmidiInGetNumDevs]
Hijack64_midiInGetNumDevs endp

Hijack64_midiInMessage proc
  jmp qword ptr [pfmidiInMessage]
Hijack64_midiInMessage endp

Hijack64_midiInOpen proc
  jmp qword ptr [pfmidiInOpen]
Hijack64_midiInOpen endp

Hijack64_midiInPrepareHeader proc
  jmp qword ptr [pfmidiInPrepareHeader]
Hijack64_midiInPrepareHeader endp

Hijack64_midiInReset proc
  jmp qword ptr [pfmidiInReset]
Hijack64_midiInReset endp

Hijack64_midiInStart proc
  jmp qword ptr [pfmidiInStart]
Hijack64_midiInStart endp

Hijack64_midiInStop proc
  jmp qword ptr [pfmidiInStop]
Hijack64_midiInStop endp

Hijack64_midiInUnprepareHeader proc
  jmp qword ptr [pfmidiInUnprepareHeader]
Hijack64_midiInUnprepareHeader endp

Hijack64_midiOutCacheDrumPatches proc
  jmp qword ptr [pfmidiOutCacheDrumPatches]
Hijack64_midiOutCacheDrumPatches endp

Hijack64_midiOutCachePatches proc
  jmp qword ptr [pfmidiOutCachePatches]
Hijack64_midiOutCachePatches endp

Hijack64_midiOutClose proc
  jmp qword ptr [pfmidiOutClose]
Hijack64_midiOutClose endp

Hijack64_midiOutGetDevCapsA proc
  jmp qword ptr [pfmidiOutGetDevCapsA]
Hijack64_midiOutGetDevCapsA endp

Hijack64_midiOutGetDevCapsW proc
  jmp qword ptr [pfmidiOutGetDevCapsW]
Hijack64_midiOutGetDevCapsW endp

Hijack64_midiOutGetErrorTextA proc
  jmp qword ptr [pfmidiOutGetErrorTextA]
Hijack64_midiOutGetErrorTextA endp

Hijack64_midiOutGetErrorTextW proc
  jmp qword ptr [pfmidiOutGetErrorTextW]
Hijack64_midiOutGetErrorTextW endp

Hijack64_midiOutGetID proc
  jmp qword ptr [pfmidiOutGetID]
Hijack64_midiOutGetID endp

Hijack64_midiOutGetNumDevs proc
  jmp qword ptr [pfmidiOutGetNumDevs]
Hijack64_midiOutGetNumDevs endp

Hijack64_midiOutGetVolume proc
  jmp qword ptr [pfmidiOutGetVolume]
Hijack64_midiOutGetVolume endp

Hijack64_midiOutLongMsg proc
  jmp qword ptr [pfmidiOutLongMsg]
Hijack64_midiOutLongMsg endp

Hijack64_midiOutMessage proc
  jmp qword ptr [pfmidiOutMessage]
Hijack64_midiOutMessage endp

Hijack64_midiOutOpen proc
  jmp qword ptr [pfmidiOutOpen]
Hijack64_midiOutOpen endp

Hijack64_midiOutPrepareHeader proc
  jmp qword ptr [pfmidiOutPrepareHeader]
Hijack64_midiOutPrepareHeader endp

Hijack64_midiOutReset proc
  jmp qword ptr [pfmidiOutReset]
Hijack64_midiOutReset endp

Hijack64_midiOutSetVolume proc
  jmp qword ptr [pfmidiOutSetVolume]
Hijack64_midiOutSetVolume endp

Hijack64_midiOutShortMsg proc
  jmp qword ptr [pfmidiOutShortMsg]
Hijack64_midiOutShortMsg endp

Hijack64_midiOutUnprepareHeader proc
  jmp qword ptr [pfmidiOutUnprepareHeader]
Hijack64_midiOutUnprepareHeader endp

Hijack64_midiStreamClose proc
  jmp qword ptr [pfmidiStreamClose]
Hijack64_midiStreamClose endp

Hijack64_midiStreamOpen proc
  jmp qword ptr [pfmidiStreamOpen]
Hijack64_midiStreamOpen endp

Hijack64_midiStreamOut proc
  jmp qword ptr [pfmidiStreamOut]
Hijack64_midiStreamOut endp

Hijack64_midiStreamPause proc
  jmp qword ptr [pfmidiStreamPause]
Hijack64_midiStreamPause endp

Hijack64_midiStreamPosition proc
  jmp qword ptr [pfmidiStreamPosition]
Hijack64_midiStreamPosition endp

Hijack64_midiStreamProperty proc
  jmp qword ptr [pfmidiStreamProperty]
Hijack64_midiStreamProperty endp

Hijack64_midiStreamRestart proc
  jmp qword ptr [pfmidiStreamRestart]
Hijack64_midiStreamRestart endp

Hijack64_midiStreamStop proc
  jmp qword ptr [pfmidiStreamStop]
Hijack64_midiStreamStop endp

Hijack64_mixerClose proc
  jmp qword ptr [pfmixerClose]
Hijack64_mixerClose endp

Hijack64_mixerGetControlDetailsA proc
  jmp qword ptr [pfmixerGetControlDetailsA]
Hijack64_mixerGetControlDetailsA endp

Hijack64_mixerGetControlDetailsW proc
  jmp qword ptr [pfmixerGetControlDetailsW]
Hijack64_mixerGetControlDetailsW endp

Hijack64_mixerGetDevCapsA proc
  jmp qword ptr [pfmixerGetDevCapsA]
Hijack64_mixerGetDevCapsA endp

Hijack64_mixerGetDevCapsW proc
  jmp qword ptr [pfmixerGetDevCapsW]
Hijack64_mixerGetDevCapsW endp

Hijack64_mixerGetID proc
  jmp qword ptr [pfmixerGetID]
Hijack64_mixerGetID endp

Hijack64_mixerGetLineControlsA proc
  jmp qword ptr [pfmixerGetLineControlsA]
Hijack64_mixerGetLineControlsA endp

Hijack64_mixerGetLineControlsW proc
  jmp qword ptr [pfmixerGetLineControlsW]
Hijack64_mixerGetLineControlsW endp

Hijack64_mixerGetLineInfoA proc
  jmp qword ptr [pfmixerGetLineInfoA]
Hijack64_mixerGetLineInfoA endp

Hijack64_mixerGetLineInfoW proc
  jmp qword ptr [pfmixerGetLineInfoW]
Hijack64_mixerGetLineInfoW endp

Hijack64_mixerGetNumDevs proc
  jmp qword ptr [pfmixerGetNumDevs]
Hijack64_mixerGetNumDevs endp

Hijack64_mixerMessage proc
  jmp qword ptr [pfmixerMessage]
Hijack64_mixerMessage endp

Hijack64_mixerOpen proc
  jmp qword ptr [pfmixerOpen]
Hijack64_mixerOpen endp

Hijack64_mixerSetControlDetails proc
  jmp qword ptr [pfmixerSetControlDetails]
Hijack64_mixerSetControlDetails endp

Hijack64_mmDrvInstall proc
  jmp qword ptr [pfmmDrvInstall]
Hijack64_mmDrvInstall endp

Hijack64_mmGetCurrentTask proc
  jmp qword ptr [pfmmGetCurrentTask]
Hijack64_mmGetCurrentTask endp

Hijack64_mmTaskBlock proc
  jmp qword ptr [pfmmTaskBlock]
Hijack64_mmTaskBlock endp

Hijack64_mmTaskCreate proc
  jmp qword ptr [pfmmTaskCreate]
Hijack64_mmTaskCreate endp

Hijack64_mmTaskSignal proc
  jmp qword ptr [pfmmTaskSignal]
Hijack64_mmTaskSignal endp

Hijack64_mmTaskYield proc
  jmp qword ptr [pfmmTaskYield]
Hijack64_mmTaskYield endp

Hijack64_mmioAdvance proc
  jmp qword ptr [pfmmioAdvance]
Hijack64_mmioAdvance endp

Hijack64_mmioAscend proc
  jmp qword ptr [pfmmioAscend]
Hijack64_mmioAscend endp

Hijack64_mmioClose proc
  jmp qword ptr [pfmmioClose]
Hijack64_mmioClose endp

Hijack64_mmioCreateChunk proc
  jmp qword ptr [pfmmioCreateChunk]
Hijack64_mmioCreateChunk endp

Hijack64_mmioDescend proc
  jmp qword ptr [pfmmioDescend]
Hijack64_mmioDescend endp

Hijack64_mmioFlush proc
  jmp qword ptr [pfmmioFlush]
Hijack64_mmioFlush endp

Hijack64_mmioGetInfo proc
  jmp qword ptr [pfmmioGetInfo]
Hijack64_mmioGetInfo endp

Hijack64_mmioInstallIOProcA proc
  jmp qword ptr [pfmmioInstallIOProcA]
Hijack64_mmioInstallIOProcA endp

Hijack64_mmioInstallIOProcW proc
  jmp qword ptr [pfmmioInstallIOProcW]
Hijack64_mmioInstallIOProcW endp

Hijack64_mmioOpenA proc
  jmp qword ptr [pfmmioOpenA]
Hijack64_mmioOpenA endp

Hijack64_mmioOpenW proc
  jmp qword ptr [pfmmioOpenW]
Hijack64_mmioOpenW endp

Hijack64_mmioRead proc
  jmp qword ptr [pfmmioRead]
Hijack64_mmioRead endp

Hijack64_mmioRenameA proc
  jmp qword ptr [pfmmioRenameA]
Hijack64_mmioRenameA endp

Hijack64_mmioRenameW proc
  jmp qword ptr [pfmmioRenameW]
Hijack64_mmioRenameW endp

Hijack64_mmioSeek proc
  jmp qword ptr [pfmmioSeek]
Hijack64_mmioSeek endp

Hijack64_mmioSendMessage proc
  jmp qword ptr [pfmmioSendMessage]
Hijack64_mmioSendMessage endp

Hijack64_mmioSetBuffer proc
  jmp qword ptr [pfmmioSetBuffer]
Hijack64_mmioSetBuffer endp

Hijack64_mmioSetInfo proc
  jmp qword ptr [pfmmioSetInfo]
Hijack64_mmioSetInfo endp

Hijack64_mmioStringToFOURCCA proc
  jmp qword ptr [pfmmioStringToFOURCCA]
Hijack64_mmioStringToFOURCCA endp

Hijack64_mmioStringToFOURCCW proc
  jmp qword ptr [pfmmioStringToFOURCCW]
Hijack64_mmioStringToFOURCCW endp

Hijack64_mmioWrite proc
  jmp qword ptr [pfmmioWrite]
Hijack64_mmioWrite endp

Hijack64_mmsystemGetVersion proc
  jmp qword ptr [pfmmsystemGetVersion]
Hijack64_mmsystemGetVersion endp

Hijack64_sndPlaySoundA proc
  jmp qword ptr [pfsndPlaySoundA]
Hijack64_sndPlaySoundA endp

Hijack64_sndPlaySoundW proc
  jmp qword ptr [pfsndPlaySoundW]
Hijack64_sndPlaySoundW endp

Hijack64_timeBeginPeriod proc
  jmp qword ptr [pftimeBeginPeriod]
Hijack64_timeBeginPeriod endp

Hijack64_timeEndPeriod proc
  jmp qword ptr [pftimeEndPeriod]
Hijack64_timeEndPeriod endp

Hijack64_timeGetDevCaps proc
  jmp qword ptr [pftimeGetDevCaps]
Hijack64_timeGetDevCaps endp

Hijack64_timeGetSystemTime proc
  jmp qword ptr [pftimeGetSystemTime]
Hijack64_timeGetSystemTime endp

Hijack64_timeGetTime proc
  jmp qword ptr [pftimeGetTime]
Hijack64_timeGetTime endp

Hijack64_timeKillEvent proc
  jmp qword ptr [pftimeKillEvent]
Hijack64_timeKillEvent endp

Hijack64_timeSetEvent proc
  jmp qword ptr [pftimeSetEvent]
Hijack64_timeSetEvent endp

Hijack64_waveInAddBuffer proc
  jmp qword ptr [pfwaveInAddBuffer]
Hijack64_waveInAddBuffer endp

Hijack64_waveInClose proc
  jmp qword ptr [pfwaveInClose]
Hijack64_waveInClose endp

Hijack64_waveInGetDevCapsA proc
  jmp qword ptr [pfwaveInGetDevCapsA]
Hijack64_waveInGetDevCapsA endp

Hijack64_waveInGetDevCapsW proc
  jmp qword ptr [pfwaveInGetDevCapsW]
Hijack64_waveInGetDevCapsW endp

Hijack64_waveInGetErrorTextA proc
  jmp qword ptr [pfwaveInGetErrorTextA]
Hijack64_waveInGetErrorTextA endp

Hijack64_waveInGetErrorTextW proc
  jmp qword ptr [pfwaveInGetErrorTextW]
Hijack64_waveInGetErrorTextW endp

Hijack64_waveInGetID proc
  jmp qword ptr [pfwaveInGetID]
Hijack64_waveInGetID endp

Hijack64_waveInGetNumDevs proc
  jmp qword ptr [pfwaveInGetNumDevs]
Hijack64_waveInGetNumDevs endp

Hijack64_waveInGetPosition proc
  jmp qword ptr [pfwaveInGetPosition]
Hijack64_waveInGetPosition endp

Hijack64_waveInMessage proc
  jmp qword ptr [pfwaveInMessage]
Hijack64_waveInMessage endp

Hijack64_waveInOpen proc
  jmp qword ptr [pfwaveInOpen]
Hijack64_waveInOpen endp

Hijack64_waveInPrepareHeader proc
  jmp qword ptr [pfwaveInPrepareHeader]
Hijack64_waveInPrepareHeader endp

Hijack64_waveInReset proc
  jmp qword ptr [pfwaveInReset]
Hijack64_waveInReset endp

Hijack64_waveInStart proc
  jmp qword ptr [pfwaveInStart]
Hijack64_waveInStart endp

Hijack64_waveInStop proc
  jmp qword ptr [pfwaveInStop]
Hijack64_waveInStop endp

Hijack64_waveInUnprepareHeader proc
  jmp qword ptr [pfwaveInUnprepareHeader]
Hijack64_waveInUnprepareHeader endp

Hijack64_waveOutBreakLoop proc
  jmp qword ptr [pfwaveOutBreakLoop]
Hijack64_waveOutBreakLoop endp

Hijack64_waveOutClose proc
  jmp qword ptr [pfwaveOutClose]
Hijack64_waveOutClose endp

Hijack64_waveOutGetDevCapsA proc
  jmp qword ptr [pfwaveOutGetDevCapsA]
Hijack64_waveOutGetDevCapsA endp

Hijack64_waveOutGetDevCapsW proc
  jmp qword ptr [pfwaveOutGetDevCapsW]
Hijack64_waveOutGetDevCapsW endp

Hijack64_waveOutGetErrorTextA proc
  jmp qword ptr [pfwaveOutGetErrorTextA]
Hijack64_waveOutGetErrorTextA endp

Hijack64_waveOutGetErrorTextW proc
  jmp qword ptr [pfwaveOutGetErrorTextW]
Hijack64_waveOutGetErrorTextW endp

Hijack64_waveOutGetID proc
  jmp qword ptr [pfwaveOutGetID]
Hijack64_waveOutGetID endp

Hijack64_waveOutGetNumDevs proc
  jmp qword ptr [pfwaveOutGetNumDevs]
Hijack64_waveOutGetNumDevs endp

Hijack64_waveOutGetPitch proc
  jmp qword ptr [pfwaveOutGetPitch]
Hijack64_waveOutGetPitch endp

Hijack64_waveOutGetPlaybackRate proc
  jmp qword ptr [pfwaveOutGetPlaybackRate]
Hijack64_waveOutGetPlaybackRate endp

Hijack64_waveOutGetPosition proc
  jmp qword ptr [pfwaveOutGetPosition]
Hijack64_waveOutGetPosition endp

Hijack64_waveOutGetVolume proc
  jmp qword ptr [pfwaveOutGetVolume]
Hijack64_waveOutGetVolume endp

Hijack64_waveOutMessage proc
  jmp qword ptr [pfwaveOutMessage]
Hijack64_waveOutMessage endp

Hijack64_waveOutOpen proc
  jmp qword ptr [pfwaveOutOpen]
Hijack64_waveOutOpen endp

Hijack64_waveOutPause proc
  jmp qword ptr [pfwaveOutPause]
Hijack64_waveOutPause endp

Hijack64_waveOutPrepareHeader proc
  jmp qword ptr [pfwaveOutPrepareHeader]
Hijack64_waveOutPrepareHeader endp

Hijack64_waveOutReset proc
  jmp qword ptr [pfwaveOutReset]
Hijack64_waveOutReset endp

Hijack64_waveOutRestart proc
  jmp qword ptr [pfwaveOutRestart]
Hijack64_waveOutRestart endp

Hijack64_waveOutSetPitch proc
  jmp qword ptr [pfwaveOutSetPitch]
Hijack64_waveOutSetPitch endp

Hijack64_waveOutSetPlaybackRate proc
  jmp qword ptr [pfwaveOutSetPlaybackRate]
Hijack64_waveOutSetPlaybackRate endp

Hijack64_waveOutSetVolume proc
  jmp qword ptr [pfwaveOutSetVolume]
Hijack64_waveOutSetVolume endp

Hijack64_waveOutUnprepareHeader proc
  jmp qword ptr [pfwaveOutUnprepareHeader]
Hijack64_waveOutUnprepareHeader endp

Hijack64_waveOutWrite proc
  jmp qword ptr [pfwaveOutWrite]
Hijack64_waveOutWrite endp

Hijack64_NsUnknowProc_2 proc
  jmp qword ptr [pfNsUnknowProc_2]
Hijack64_NsUnknowProc_2 endp


end
