Car Black box

Project Overview:
Developed an interactive vehicle dashboard and event logging system using the PIC18F4580 microcontroller. The project involves storing initial values in the internal EEPROM and executing the main program to create an interface via an on-board CLCD screen. This system provides real-time vehicle information and logs various events, enhancing the user experience with a secure and interactive interface.

Key Features:

Dashboard Display: Real-time display of current time, last occurred event, and vehicle speed, adjustable using an on-board potentiometer (POT).
Event Registration: Utilized matrix switches for logging collision, gear up, and gear down events. All events are stored in the internal EEPROM for later viewing.
Secure Access: Implemented a password-protected menu system, with an initial password of "1010", changeable by the user. Included features like asterisks for password entry, multiple attempts, and lockout on repeated failures.
Event Logging: Last 10 events viewable, with options to clear logs and download logs via serial terminal (e.g., minicom, PuTTY).
Time Setting: Allowed users to set the time in 24-hour format, with the operation logged as an event.
Password Management: Enabled password changes with verification, logging each change event.
Log Download: Supported downloading the event log through a serial connection to a PC.
Technologies Used:

PIC18F4580 Microcontroller
C Programming
EEPROM for data storage
Real-Time Clock (RTC)
CLCD Screen for user interface
Matrix switches for user input
Serial communication for data log download
Outcome:
Successfully created a robust and interactive vehicle dashboard system, enhancing vehicle monitoring and event logging capabilities. This project demonstrates expertise in embedded systems, microcontroller programming, and user interface design.
