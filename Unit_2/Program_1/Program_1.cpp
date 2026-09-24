#include <iostream>          // Includes input-output library for cout and endl
#include <string>            // Includes string data type

using namespace std;         // Allows us to use cout, string, endl directly


// Base class
class Employee
{
protected:
    int empId;               // Stores employee ID

    string name;             // Stores employee name

    string department;       // Stores employee department


public:

    // Constructor of Employee class
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept)
    {
        // Initializes empId with id
        // Initializes name with n
        // Initializes department with dept
    }


    // Function to display basic employee information
    void displayBasicInfo() const
    {
        cout << "ID: " << empId
             // Displays employee ID

             << " | Name: " << name
             // Displays employee name

             << " | Department: " << department;
             // Displays employee department
    }


    // Pure virtual function
    virtual double calculateSalary() const = 0;
    // virtual       -> Allows derived classes to provide their own version
    // double        -> Function returns a decimal value
    // calculateSalary -> Function name
    // const         -> Function does not modify object data
    // = 0           -> Makes this a pure virtual function
    // The Employee class becomes an abstract class


    // Virtual destructor
    virtual ~Employee() = default;
    // virtual   -> Allows proper destructor behavior with inheritance
    // ~Employee -> Destructor of Employee
    // = default -> Uses the compiler-generated destructor
};


// Derived class for full-time employees
class FullTimeEmployee : public Employee
// FullTimeEmployee inherits from Employee
// public inheritance means public members remain public
{
private:

    double monthlySalary;    // Stores monthly salary


public:

    // Constructor of FullTimeEmployee
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary)
    {
        // Calls Employee constructor to initialize:
        // empId, name and department

        // Initializes monthlySalary with salary
    }


    // Overriding calculateSalary()
    double calculateSalary() const override
    {
        // override means this function overrides
        // the pure virtual function of the base class

        return monthlySalary;
        // Returns the monthly salary
    }


    // Function to display full-time employee details
    void display() const
    {
        displayBasicInfo();
        // Calls the base class function
        // Displays ID, name and department

        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;
        // Displays employee type
        // Calls calculateSalary()
        // Displays monthly salary
    }
};


// Derived class for part-time employees
class PartTimeEmployee : public Employee
// PartTimeEmployee inherits from Employee
{
private:

    double hourlyRate;       // Stores payment per hour

    int hoursWorked;         // Stores number of hours worked


public:

    // Constructor of PartTimeEmployee
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept), hourlyRate(rate), hoursWorked(hours)
    {
        // Calls Employee constructor
        // Initializes empId, name and department

        // Initializes hourlyRate with rate

        // Initializes hoursWorked with hours
    }


    // Overriding calculateSalary()
    double calculateSalary() const override
    {
        // Provides the Part-Time implementation
        // of calculateSalary()

        return hourlyRate * hoursWorked;
        // Salary = hourly rate × hours worked
    }


    // Function to display part-time employee details
    void display() const
    {
        displayBasicInfo();
        // Displays ID, name and department

        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;
        // Displays employee type
        // Calculates and displays salary
    }
};


// Derived class for interns
class Intern : public Employee
// Intern inherits from Employee
{
private:

    double stipend;          // Stores intern's stipend


public:

    // Constructor of Intern
    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept), stipend(stipendAmount)
    {
        // Calls Employee constructor
        // Initializes empId, name and department

        // Initializes stipend with stipendAmount
    }


    // Overriding calculateSalary()
    double calculateSalary() const override
    {
        // Provides the Intern implementation
        // of calculateSalary()

        return stipend;
        // Returns the intern's stipend
    }


    // Function to display intern details
    void display() const
    {
        displayBasicInfo();
        // Displays ID, name and department

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;
        // Displays employee type
        // Calculates and displays stipend
    }
};


// Main function
int main()
{
    // Creating Full-Time Employee object
    FullTimeEmployee f1(101, "Amit", "IT", 65000);
    // 101       -> Employee ID
    // Amit      -> Employee name
    // IT        -> Department
    // 65000     -> Monthly salary


    // Creating Part-Time Employee object
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);
    // 102       -> Employee ID
    // Sneha     -> Employee name
    // HR        -> Department
    // 250       -> Hourly rate
    // 120       -> Hours worked


    // Creating Intern object
    Intern i1(103, "Rohan", "Marketing", 15000);
    // 103          -> Employee ID
    // Rohan        -> Employee name
    // Marketing    -> Department
    // 15000        -> Stipend


    cout << "=== Employee Payroll ===" << endl;
    // Prints the heading


    f1.display();
    // Displays Full-Time Employee information
    // Salary = Rs. 65000


    p1.display();
    // Displays Part-Time Employee information
    // Salary = 250 × 120 = Rs. 30000


    i1.display();
    // Displays Intern information
    // Stipend = Rs. 15000
}