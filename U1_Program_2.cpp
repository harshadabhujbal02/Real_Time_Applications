#include <iostream>              // Provides cout and endl for displaying output
#include <string>                // Provides the string data type
#include <vector>                // Provides the vector container
#include <fstream>               // Provides file handling using ofstream

using namespace std;             // Allows us to use cout, string, vector, etc. directly


class Student                      // Defines a class named Student
{
private:                           // Private data can be accessed only inside the class

    int rollNo;                    // Stores the student's roll number
    string name;                   // Stores the student's name
    int totalDays;                 // Stores the total number of attendance days
    int presentDays;               // Stores the number of days the student was present

public:                            // Public members can be accessed from outside the class

    Student(int r, string n)       // Constructor to initialize a Student object
        : rollNo(r), name(n), totalDays(0), presentDays(0) // Initializes data members
    {
    }                              // Ends the constructor


    void markAttendance(bool isPresent) // Function to mark attendance
    {
        totalDays++;               // Increases total attendance days by 1

        if (isPresent)             // Checks whether the student is present
        {
            presentDays++;         // Increases present days by 1 if student is present
        }
    }                              // Ends markAttendance() function


    double getAttendancePercentage() const // Calculates and returns attendance percentage
    {
        if (totalDays == 0)        // Checks whether attendance has been recorded
        {
            return 0.0;            // Returns 0 if there are no attendance records
        }

        return (presentDays * 100.0) / totalDays;
        // Calculates attendance percentage
        // presentDays * 100 gives percentage
        // Dividing by totalDays gives final attendance percentage
    }                              // Ends getAttendancePercentage()


    bool isEligible() const        // Checks whether student has minimum required attendance
    {
        return getAttendancePercentage() >= 75.0;
        // Returns true if attendance is 75% or above
        // Returns false if attendance is below 75%
    }                              // Ends isEligible()


    void display() const           // Displays student attendance information
    {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: " << getAttendancePercentage() << "%"
             << " | Eligibility: ";

        if (isEligible())          // Checks student's eligibility
        {
            cout << "Eligible" << endl;       // Displays Eligible
        }
        else
        {
            cout << "Not Eligible" << endl;   // Displays Not Eligible
        }
    }                              // Ends display() function


    void saveToFile(ofstream &file) const
    // Function to save student attendance information into a file
    {
        file << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: " << getAttendancePercentage() << "%"
             << " | Eligibility: ";

        if (isEligible())          // Checks eligibility before saving
        {
            file << "Eligible" << endl;        // Saves Eligible to file
        }
        else
        {
            file << "Not Eligible" << endl;    // Saves Not Eligible to file
        }
    }                              // Ends saveToFile() function
};


int main()                       // Program execution starts from main()
{
    vector<Student> students;     // Creates a vector to store multiple Student objects


    Student s1(101, "Rahul");     // Creates first student
    Student s2(102, "Priya");     // Creates second student
    Student s3(103, "Amit");      // Creates third student


    // Rahul: 2 present out of 3 days = 66.67%
    s1.markAttendance(true);      // Rahul is present
    s1.markAttendance(true);      // Rahul is present
    s1.markAttendance(false);     // Rahul is absent


    // Priya: 3 present out of 3 days = 100%
    s2.markAttendance(true);      // Priya is present
    s2.markAttendance(true);      // Priya is present
    s2.markAttendance(true);      // Priya is present


    // Amit: 2 present out of 3 days = 66.67%
    s3.markAttendance(true);      // Amit is present
    s3.markAttendance(false);     // Amit is absent
    s3.markAttendance(true);      // Amit is present


    students.push_back(s1);       // Adds Rahul to the vector
    students.push_back(s2);       // Adds Priya to the vector
    students.push_back(s3);       // Adds Amit to the vector


    cout << "=== Attendance Report ===" << endl;
    // Displays the attendance report heading


    for (const auto& student : students)
    // Loops through every Student object in the vector
    {
        student.display();        // Displays attendance details of each student
    }


    ofstream file("attendance.txt");
    // Creates/opens a file named attendance.txt
    // Attendance information will be stored in this file


    if (file.is_open())            // Checks whether the file opened successfully
    {
        for (const auto& student : students)
        // Loops through all students
        {
            student.saveToFile(file); // Saves each student's data into the file
        }

        file.close();              // Closes the file after writing
        cout << "\nAttendance records saved to attendance.txt" << endl;
    }
    else
    {
        cout << "\nError: Could not open attendance.txt" << endl;
    }


    cout << "\n=== Defaulter Report ===" << endl;
    // Displays heading for students below 75% attendance


    bool defaulterFound = false;
    // Stores whether at least one defaulter is found
    // Initially, no defaulter has been found


    for (const auto& student : students)
    // Checks every student in the vector
    {
        if (!student.isEligible())  // Checks if attendance is below 75%
        {
            student.display();      // Displays the student's details
            defaulterFound = true;  // Marks that a defaulter was found
        }
    }


    if (!defaulterFound)            // Checks if no defaulter was found
    {
        cout << "No defaulters found." << endl;
        // Displays message when every student has at least 75% attendance
    }


    return 0;                       // Ends the program successfully
}