#include <iostream>          // Includes input-output library for cout and endl
#include <memory>            // Includes smart pointers like unique_ptr and make_unique
#include <string>            // Includes string data type
#include <vector>            // Includes vector container

using namespace std;         // Allows us to use cout, string, vector, etc. directly


// Base class
class Vehicle
{
protected:
    string vehicleId;        // Stores the unique ID of the vehicle

    string registrationNumber; // Stores the vehicle registration number

    double fuelLevel;        // Stores the current fuel level


public:

    // Constructor of Vehicle class
    Vehicle(string vid, string reg)
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0)
    {
        // vehicleId = vid
        // registrationNumber = reg
        // fuelLevel is initially set to 100%
    }


    // Function to start the vehicle engine
    void startEngine() const
    {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
        // Displays the vehicle ID and engine-started message
    }


    // Function to add fuel
    void refuel(double amount)
    {
        fuelLevel += amount;
        // Adds the given amount of fuel to the current fuel level

        if (fuelLevel > 100.0)
        {
            // Checks whether fuel level has exceeded 100%

            fuelLevel = 100.0;
            // Limits fuel level to maximum 100%
        }
    }


    // Virtual function to display vehicle information
    virtual void displayInfo() const
    {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;

        // Displays vehicle ID
        // Displays registration number
        // Displays fuel level
    }


    // Virtual destructor
    virtual ~Vehicle() = default;
    // ~Vehicle -> Destructor
    // virtual  -> Supports proper destruction through base-class pointers
    // = default -> Uses compiler-generated destructor
};


// Derived class for trucks
class Truck : public Vehicle
// Truck inherits from Vehicle
{
private:

    double cargoCapacity;     // Stores truck's cargo capacity


public:

    // Constructor of Truck
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity)
    {
        // Calls Vehicle constructor
        // Initializes vehicleId and registrationNumber

        // Initializes cargoCapacity with capacity
    }


    // Overrides displayInfo()
    void displayInfo() const override
    {
        cout << "Truck | ";
        // Displays the vehicle type

        Vehicle::displayInfo();
        // Calls displayInfo() of the Vehicle class
        // Displays common vehicle information

        cout << "Cargo capacity: "
             << cargoCapacity
             << " tonnes" << endl;
        // Displays truck cargo capacity
    }
};


// Derived class for delivery vans
class DeliveryVan : public Vehicle
// DeliveryVan inherits from Vehicle
{
private:

    int packageCount;         // Stores the number of packages


public:

    // Constructor of DeliveryVan
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages)
    {
        // Calls Vehicle constructor

        // Initializes packageCount with packages
    }


    // Overrides displayInfo()
    void displayInfo() const override
    {
        cout << "Delivery Van | ";
        // Displays the vehicle type

        Vehicle::displayInfo();
        // Calls base class displayInfo()
        // Displays common vehicle information

        cout << "Packages loaded: "
             << packageCount << endl;
        // Displays the number of loaded packages
    }
};


// Derived class for bikes
class Bike : public Vehicle
// Bike inherits from Vehicle
{
private:

    bool hasDeliveryBox;      // Stores whether the bike has a delivery box


public:

    // Constructor of Bike
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox)
    {
        // Calls Vehicle constructor

        // Initializes hasDeliveryBox with hasBox
    }


    // Overrides displayInfo()
    void displayInfo() const override
    {
        cout << "Delivery Bike | ";
        // Displays the vehicle type

        Vehicle::displayInfo();
        // Calls base class displayInfo()
        // Displays common vehicle information

        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
        // Checks hasDeliveryBox
        // If true  -> prints "Available"
        // If false -> prints "Not available"
    }
};


// Main function
int main()
{
    // Creates a vector of unique pointers to Vehicle objects

    vector<unique_ptr<Vehicle>> fleet;
    // vector -> Stores multiple elements
    // unique_ptr -> Smart pointer that automatically manages memory
    // Vehicle -> Base class type
    // fleet -> Name of the vector


    // Creates a Truck object and adds it to the fleet

    fleet.push_back(
        make_unique<Truck>(
            "V001",
            "MH12-AB-1234",
            10.5
        )
    );

    // V001          -> Vehicle ID
    // MH12-AB-1234  -> Registration number
    // 10.5          -> Cargo capacity in tonnes


    // Creates a DeliveryVan object and adds it to the fleet

    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002",
            "MH12-CD-5678",
            50
        )
    );

    // V002          -> Vehicle ID
    // MH12-CD-5678  -> Registration number
    // 50             -> Number of packages


    // Creates a Bike object and adds it to the fleet

    fleet.push_back(
        make_unique<Bike>(
            "V003",
            "MH12-EF-9012",
            true
        )
    );

    // V003          -> Vehicle ID
    // MH12-EF-9012  -> Registration number
    // true           -> Bike has a delivery box


    cout << "=== Fleet Status ===" << endl;
    // Displays the heading


    // Loops through every vehicle in the fleet
    for (const auto& vehicle : fleet)
    {
        // const -> The pointer/reference is not modified
        // auto  -> Compiler automatically determines the data type
        // &     -> Uses a reference instead of copying
        // vehicle -> Current vehicle pointer


        vehicle->startEngine();
        // Calls startEngine() using the vehicle pointer
        // -> is used to access a member through a pointer


        vehicle->displayInfo();
        // Calls displayInfo()
        // Due to virtual function, the correct derived-class
        // version is called


        cout << endl;
        // Prints a blank line
    }


    return 0;
    // Ends the program successfully
}