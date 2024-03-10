#include "ProcessHider.h"
#include <Windows.h>

void ProcessHider::HideProcess() {
    // Get a handle to the console window
    HWND hwnd = FindWindowA(NULL, "ConsoleWindowClass");

    // Check if the handle is valid
    if (hwnd != NULL) {
        // Hide the window
        ShowWindow(hwnd, SW_HIDE);
    }
}
