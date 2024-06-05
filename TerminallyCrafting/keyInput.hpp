#include <iostream>
#include <windows.h>

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

void SetHook();

void ReleaseHook();

void startKeyBoardInput();