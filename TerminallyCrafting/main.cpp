#include "keyInput.hpp"

int main() {
    SetHook();

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    ReleaseHook();
    return 0;
}
