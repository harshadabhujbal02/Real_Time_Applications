#include <iostream>          // Includes the input-output library for cout and endl
#include <string>            // Includes the string data type

using namespace std;         // Allows us to use cout, string, endl without writing std::


// Class for Smart Home Device
class SmartDevice              // Defines a class named SmartDevice
{ 
private:                       // Private members can be accessed only inside the class

    int deviceID;              // Stores the unique ID of the device

    string deviceName;         // Stores the name of the device

    string location;           // Stores where the device is located

    string status;             // Stores the current status of the device

    string lastUpdated;        // Stores the time when the device was last updated


public:                        // Public members can be accessed from outside the class


    // Constructor
    SmartDevice(int id, string name, string loc)   // Constructor with 3 parameters
    { 
        deviceID = id;          // Assigns id to deviceID

        deviceName = name;      // Assigns name to deviceName

        location = loc;         // Assigns loc to location

        status = "OFF";         // Initially sets the device status to OFF

        lastUpdated = "Not updated";  // Initially no update time is available
    } 


    // Function to switch ON the device
    void switchOn(string time)          // Function that turns the device ON
    { 
        status = "ON";                  // Changes the status to ON

        lastUpdated = time;             // Stores the given time as the last update time

        cout << deviceName << " is switched ON." << endl;
        // Displays the device name and ON message
    } 


    // Function to switch OFF the device
    void switchOff(string time)         // Function that turns the device OFF
    { 
        status = "OFF";                 // Changes the status to OFF

        lastUpdated = time;             // Stores the given time as the last update time

        cout << deviceName << " is switched OFF." << endl;
        // Displays the device name and OFF message
    } 


    // Function to change device status
    void changeStatus(string newStatus, string time)
    // Function that changes the status to a new value
    { 
        status = newStatus;             // Assigns newStatus to status

        lastUpdated = time;             // Stores the given time as the last update time

        cout << deviceName << " status changed to "
             << status << "." << endl;
        // Displays the device name and its new status
    } 


    // Function to display device details
    void display()                       // Function used to display all device information
    { 
        cout << "\n-----------------------------" << endl;
        // Prints a separator line
        // \n moves the cursor to a new line

        cout << "Device ID     : " << deviceID << endl;
        // Displays the device ID

        cout << "Device Name   : " << deviceName << endl;
        // Displays the device name

        cout << "Location      : " << location << endl;
        // Displays the device location

        cout << "Status        : " << status << endl;
        // Displays the current device status

        cout << "Last Updated  : " << lastUpdated << endl;
        // Displays the last update time
    } 


    // Destructor
    ~SmartDevice()                       // Destructor is called when an object is destroyed
    { 
        // Destructor called when object is destroyed
    } 
};                                      // End of SmartDevice class


int main()                              // Main function; program execution starts here
{ 
    cout << "====================================" << endl;
    // Prints the top border

    cout << "     SMART HOME DEVICE MANAGER      " << endl;
    // Prints the title

    cout << "====================================" << endl;
    // Prints the bottom border


    // Creating smart home devices

    SmartDevice light(101, "Smart Light", "Living Room");
    // Creates an object named light
    // Device ID = 101
    // Device Name = Smart Light
    // Location = Living Room
    // Constructor is automatically called

    SmartDevice thermostat(102, "Thermostat", "Bedroom");
    // Creates thermostat object
    // Device ID = 102
    // Device Name = Thermostat
    // Location = Bedroom

    SmartDevice camera(103, "Security Camera", "Main Door");
    // Creates camera object
    // Device ID = 103
    // Device Name = Security Camera
    // Location = Main Door

    SmartDevice doorLock(104, "Smart Door Lock", "Main Door");
    // Creates doorLock object
    // Device ID = 104
    // Device Name = Smart Door Lock
    // Location = Main Door


    // Display initial device details

    cout << "\n===== INITIAL DEVICE STATUS =====";
    // Prints heading for the initial status section


    light.display();
    // Displays the initial details of the Smart Light

    thermostat.display();
    // Displays the initial details of the Thermostat

    camera.display();
    // Displays the initial details of the Security Camera

    doorLock.display();
    // Displays the initial details of the Smart Door Lock


    // Switching devices ON

    cout << "\n\n===== SWITCHING DEVICES ON =====";
    // Prints heading for switching devices ON


    light.switchOn("10:00 AM");
    // Switches Smart Light ON
    // Last updated time becomes 10:00 AM

    thermostat.switchOn("10:05 AM");
    // Switches Thermostat ON
    // Last updated time becomes 10:05 AM

    camera.switchOn("10:10 AM");
    // Switches Security Camera ON
    // Last updated time becomes 10:10 AM

    doorLock.switchOn("10:15 AM");
    // Switches Smart Door Lock ON
    // Last updated time becomes 10:15 AM


    // Changing status

    cout << "\n\n===== CHANGING DEVICE STATUS =====";
    // Prints heading for changing status


    thermostat.changeStatus("24°C", "10:20 AM");
    // Changes thermostat status to 24°C
    // Last updated time becomes 10:20 AM


    // Switching a device OFF

    cout << "===== SWITCHING DEVICE OFF =====";
    // Prints heading for switching a device OFF


    light.switchOff("10:30 AM");
    // Switches Smart Light OFF
    // Last updated time becomes 10:30 AM


    // Display final home dashboard

    cout << "\n\n====================================";
    // Prints the top border of dashboard

    cout << "\n        SMART HOME DASHBOARD";
    // Prints the dashboard heading

    cout << "\n====================================";
    // Prints the bottom border


    light.display();
    // Displays final Smart Light details

    thermostat.display();
    // Displays final Thermostat details

    camera.display();
    // Displays final Security Camera details

    doorLock.display();
    // Displays final Smart Door Lock details


    cout << "\n\n====================================" << endl;
    // Prints the top border of completion message

    cout << "       DASHBOARD COMPLETED          " << endl;
    // Displays dashboard completed message

    cout << "====================================" << endl;
    // Prints the bottom border


    return 0;                     // Returns 0 to indicate successful program execution
}