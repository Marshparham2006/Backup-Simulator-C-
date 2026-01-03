#include <iostream>
#include <string>
#include <fstream>      // For saving backup summary
#include <chrono>       // For timing & delays
#include <thread>       // For simulating progress
#include <cstdlib>      // For rand()
#include <ctime>        // For srand()
#include <limits>       // For input validation

using namespace std;

int main() {
    srand(time(0)); // Seed random generator for virus simulation

    // ===== Variables =====
    string backupItems[] = {"Files", "Photos", "Videos"}; // Available backup items
    int choice, storage, freeSpace, backupSize;           // User selections
    string deviceModel;                                   // Device model input
    char antivirus, cracked, usb;                         // Security check inputs
    string password;                                      // Backup password

    // ===== MAIN MENU =====
    cout << "=============================\n";
    cout << "         BACKUP MENU         \n";
    cout << "=============================\n";

    cout << "What do you want to back up?\n";
    for (int i = 0; i < 3; i++)
        cout << i + 1 << ") " << backupItems[i] << endl;

    cout << "Select one (1-3): ";
    cin >> choice;

    // Input validation
    if (choice < 1 || choice > 3) {
        cout << "Invalid option. Exiting.\n";
        return 0;
    }

    cout << "\nYou chose: " << backupItems[choice - 1] << "\n";

    // ===== STORAGE SELECTION =====
    cout << "\nWhere do you want to save backup?\n";
    cout << "1) Flash\n2) External Hard\n3) Cloud Storage\n";
    cout << "Select (1-3): ";
    cin >> storage;

    // ===== SYSTEM INFO =====
    cout << "\nHow much free space do you have? (GB): ";
    cin >> freeSpace;
    cin.ignore(); // Clear input buffer
    cout << "Enter your device model: ";
    getline(cin, deviceModel);

    // ===== SECURITY CHECK =====
    cout << "\n⚠ Security Check Before Backup\n";
    cout << "Has your device been scanned with antivirus recently? (y/n): ";
    cin >> antivirus;

    cout << "Have you downloaded cracked / unknown apps recently? (y/n): ";
    cin >> cracked;

    cout << "Did you plug unknown USB devices? (y/n): ";
    cin >> usb;

    // If any security risk detected, cancel backup
    if (antivirus == 'n' || cracked == 'y' || usb == 'y') {
        cout << "\n❌ Risk detected! Backup cancelled for safety.\n";
        return 0;
    }

    // ===== BACKUP SIZE INPUT =====
    while (true) {
        cout << "\nEnter desired backup size in GB: ";
        cin >> backupSize;

        // Input validation: must be positive number and fit free space
        if (cin.fail()) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Please enter a valid number.\n";
            continue;
        }

        if (backupSize <= 0) {
            cout << "❌ Backup size must be greater than 0.\n";
            continue;
        }

        if (backupSize > freeSpace) {
            cout << "❌ Not enough free space! You have " << freeSpace << " GB.\n";
            continue;
        }

        break; // valid input
    }

    // ===== OPTIONAL PASSWORD =====
    cout << "\nSet a simple backup password (optional, leave blank to skip): ";
    cin.ignore();
    getline(cin, password);

    // ===== ESTIMATE TIME =====
    // Assuming backup speed ~1.5 GB/min
    double estimatedMinutes = backupSize / 1.5;
    int minPart = estimatedMinutes;
    int secPart = static_cast<int>((estimatedMinutes - minPart) * 60);
    cout << "\nEstimated backup time: " << minPart << " minutes " << secPart << " seconds\n";

    // ===== VIRUS SCAN SIMULATION =====
    cout << "\nScanning device for viruses...\n";
    for (int p = 0; p <= 100; p += 20) {
        cout << "Scanning: " << p << "%\n";
        this_thread::sleep_for(chrono::milliseconds(400));
    }

    bool virusFound = rand() % 4 == 0; // Random chance of virus
    if (virusFound) {
        cout << "\n⚠ Virus detected! Cleaning system...\n";
        for (int p = 0; p <= 100; p += 10) {
            cout << "Removing: " << p << "%\n";
            this_thread::sleep_for(chrono::milliseconds(200));
        }
        cout << "✔ Cleaned. Safe to continue.\n";
    } else {
        cout << "\n✔ No threats found. Device is safe.\n";
    }

    // ===== BACKUP PROGRESS BAR =====
    cout << "\nStarting backup...\n";
    for (int p = 0; p <= 100; p += 5) {
        int bars = p / 2; // progress bar scale (50 chars)
        cout << "Backing up: [";
        for (int i = 0; i < 50; i++)
            cout << (i < bars ? '#' : '-');
        cout << "] " << p << "%\r" << flush;
        this_thread::sleep_for(chrono::milliseconds(120));
    }

    cout << "\nBackup completed successfully!\n";

    // ===== SAVE LOG TO FILE =====
    ofstream logFile("backup_summary.txt");
    logFile << "=============================\n";
    logFile << "       BACKUP SUMMARY        \n";
    logFile << "=============================\n";
    logFile << "Device Model   : " << deviceModel << "\n";
    logFile << "Backup Item    : " << backupItems[choice - 1] << "\n";
    logFile << "Backup Size    : " << backupSize << " GB\n";
    logFile << "Storage Device : " << (storage == 1 ? "Flash" : storage == 2 ? "External Hard" : "Cloud Storage") << "\n";
    logFile << "Estimated Time : " << minPart << "m " << secPart << "s\n";
    logFile << "Password       : " << (password.empty() ? "None" : password) << "\n";
    logFile << "Status         : Completed Successfully\n";
    logFile << "=============================\n";
    logFile.close();

    cout << "\n✔ Summary saved to 'backup_summary.txt'\n";

    return 0;
}
