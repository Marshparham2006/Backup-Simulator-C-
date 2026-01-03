# Backup-Simulator-C++
 Backup Simulator (C++): Developed an interactive console-based backup tool with file selection, storage options, security checks, password protection, progress visualization, and logging functionality. Demonstrates C++ programming, file I/O, threading, and user input validation
Project Overview

This is a C++ console-based interactive backup tool designed to simulate a real-world backup process. The program allows users to select files to backup, choose storage devices, specify backup size, and provides security checks before starting the backup. It also estimates backup time, shows progress with a dynamic progress bar, and generates a backup summary with a log option.

Features

✅ Interactive backup menu (Files, Photos, Videos)
✅ Storage device selection (Flash, External Hard, Cloud)
✅ User-specified backup size and device model
✅ Security check before backup (antivirus, unknown apps, USB devices)
✅ Password protection for backup
✅ Simulated backup progress with percentage and dynamic progress bar
✅ Estimated backup time based on size
✅ Ability to cancel backup in progress
✅ Logging of backup details to a file

Technical Details

Language: C++

Libraries: <iostream>, <string>, <chrono>, <thread>, <fstream>

Concepts Covered:

Loops, conditional statements, arrays

User input validation

File handling (logs)

Threading for simulation (this_thread::sleep_for)

Basic security simulation and password protection

How to Use

Run the program.

Choose the item to backup (Files / Photos / Videos).

Select storage location.

Enter available free space and device model.

Pass the security checks and set a backup password.

Enter the backup size.

Watch the simulated backup progress and estimated time.

View the summary and optionally check the log file (backup_log.txt).

Example Usage
Select one (1-3): 1
Device Model: SAMSUNG
Free Space (GB): 200
Security Check Passed: y n n
Backup Size: 50
Estimated Time: 33 minutes
Backup Completed Successfully!

Resume-Friendly Description

Developed an interactive C++ Backup Simulator with security checks, progress visualization, password protection, and logging functionality. The project demonstrates skills in C++ programming, user input validation, file I/O, threading, and console-based UI design.
