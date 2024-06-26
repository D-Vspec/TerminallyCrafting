#ifndef KEYINPUT
#define KEYINPUT

#include <iostream>
#include <windows.h>

HHOOK hHook;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
        DWORD vkCode = p->vkCode;

        switch (vkCode) {
        case 'W':
            std::cout << "w" << std::endl;
            break;
        case 'A':
            std::cout << "a" << std::endl;
            break;
        case 'S':
            std::cout << "s" << std::endl;
            break;
        case 'D':
            std::cout << "d" << std::endl;
            break;
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

void SetHook() {
    hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
    if (hHook == NULL) {
        std::cerr << "Failed to install hook!" << std::endl;
    }
    else {
        std::cout << "Keyboard input is active" << std::endl;
    }
}

void ReleaseHook() {
    UnhookWindowsHookEx(hHook);
}

void startKeyBoardInput() {
    SetHook();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ReleaseHook();
}

#endif // !KEYINPUT
