#include <iostream>          // Includes the input/output library for cout and endl
#include <string>            // Includes the string data type
#include <vector>            // Includes the vector container

using namespace std;         // Allows us to use cout, string, vector, etc. without writing std::

 
class SoilSensor               // Defines a class named SoilSensor
{ 
private:                       // Starts the private section; data here cannot be accessed directly outside the class

    string sensorId;           // Stores the unique ID/name of the soil sensor
    double moistureLevel;      // Stores the soil moisture percentage as a decimal number
    string timestamp;          // Stores the time of the sensor reading
 
public:                        // Starts the public section; members here can be accessed from outside the class

    SoilSensor(string id, double moisture, string time)   // Constructor of SoilSensor
        : sensorId(id), moistureLevel(moisture), timestamp(time) // Initializes the three data members
    {}                           // Empty constructor body
 
    void readSensor(double newMoisture, string newTime)     // Function to update sensor readings
    {
        moistureLevel = newMoisture;   // Updates the moisture level with the new value
        timestamp = newTime;            // Updates the timestamp with the new time
    }                                   // Ends readSensor() function
 
    void displayData() const             // Function to display sensor information
    {                                    // const means this function will not modify the object

        cout << "Sensor: " << sensorId   // Prints the word "Sensor:" and sensor ID
             << " | Moisture: "            // Prints the label "Moisture:"
             << moistureLevel << "%"       // Prints the moisture value followed by %
             << " | Time: "                // Prints the label "Time:"
             << timestamp << endl;         // Prints the timestamp and moves to the next line
    }                                     // Ends displayData() function
};                                        // Ends the SoilSensor class


int main()                              // Main function; program execution starts here
{ 
    vector<SoilSensor> farmSensors;     // Creates a vector named farmSensors
                                        // It can store multiple SoilSensor objects

    farmSensors.emplace_back("S001", 45.2, "08:00"); 
    // Creates a SoilSensor object with:
    // Sensor ID = S001
    // Moisture = 45.2%
    // Time = 08:00
    // emplace_back() adds the object directly into the vector

    farmSensors.emplace_back("S002", 52.8, "08:00"); 
    // Adds the second sensor:
    // Sensor ID = S002
    // Moisture = 52.8%
    // Time = 08:00

    farmSensors.emplace_back("S003", 38.5, "08:00"); 
    // Adds the third sensor:
    // Sensor ID = S003
    // Moisture = 38.5%
    // Time = 08:00


    cout << "=== Morning Sensor Readings ===" << endl;
    // Displays the heading "Morning Sensor Readings"
    // endl moves the cursor to the next line


    for (const auto& sensor : farmSensors)
    // for = loop
    // const = sensor object will not be modified
    // auto = compiler automatically determines the data type
    // & = uses a reference instead of making a copy
    // sensor = temporary name for each SoilSensor object
    // : farmSensors = takes each object from the farmSensors vector

    { 
        sensor.displayData();       // Calls displayData() for the current sensor
    }                               // Ends the for loop


    farmSensors[0].readSensor(47.5, "09:00");
    // farmSensors[0] = first sensor in the vector
    // readSensor() = updates its sensor information
    // 47.5 = new moisture level
    // "09:00" = new timestamp


    cout << "\n=== Updated Reading ===" << endl;
    // \n = adds a blank line before the heading
    // Displays "Updated Reading"


    farmSensors[0].displayData();
    // Displays the updated information of the first sensor

}                                   // Ends main() function