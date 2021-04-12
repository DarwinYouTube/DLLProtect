#include <Windows.h>
HWND hwnd;

BOOL WINAPI Main(HMODULE hModule) {

    MessageBox(0, "Protect Works!", "Protect Successfulled", MB_OK);
	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule); // Отключаем лишние вызовы (оптимизация)
		if (hwnd = FindWindow(0, "notepadInjector1")) {
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Main, 0, 0, 0);
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}