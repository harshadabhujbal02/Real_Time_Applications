Student Details

Field | Details

Student Name | Harshada Suresh Bhujbal

Roll No. | AD2123

PRN | 125UAD1264

Class/Division | SY B.Tech AI & DS – Div A

Course Name | Object-Oriented Programming with c++


========================================
       OOPS - REAL TIME APPLICATIONS
========================================

SUBJECT:
Object Oriented Programming using C++

TOPIC:
Real-Time Applications

========================================
          LIST OF PROGRAMS
========================================

1. Soil Sensor Monitoring
2. Student Attendance Management
3. Product Catalog
4. Smart Home Device Manager
5. Employee Payroll System
6. Payment Gateway System
7. Vehicle Fleet Management System
8. Banking System with Account Hierarchy
=========================================          About the Repository
=========================================
This codebook contains eight C++ programs based on real-time applications. Each program demonstrates Object Oriented Programming concepts through a practical application.

========================================
          LIST OF PROGRAMS
========================================

1. Soil Sensor Monitoring
2. Student Attendance Management
3. Product Catalog
4. Smart Home Device Manager
5. Employee Payroll System
6. Payment Gateway System
7. Vehicle Fleet Management System
8. Banking System with Account Hierarchy


========================================
PROGRAM 1: SOIL SENSOR MONITORING
========================================

File:
U1_Program_1.cpp

Description:
This program demonstrates a soil sensor monitoring system
using Object Oriented Programming.

The program creates a SoilSensor class to store sensor ID,
moisture level and timestamp.

Multiple soil sensors are stored using a vector.

The sensor readings can also be updated using the
readSensor() function.

Main Features:
- Stores sensor ID
- Stores moisture level
- Stores timestamp
- Displays sensor readings
- Updates sensor readings
- Uses vector to store multiple sensors

OOP Concepts Used:
- Class
- Object
- Encapsulation
- Constructor
- Member functions
- Vector
- Private data members

Important Functions:
- readSensor()
- displayData()

Example Sensors:
S001
S002
S003

Expected Output:

=== Morning Sensor Readings ===
Sensor: S001 | Moisture: 45.2% | Time: 08:00
Sensor: S002 | Moisture: 52.8% | Time: 08:00
Sensor: S003 | Moisture: 38.5% | Time: 08:00

=== Updated Reading ===
Sensor: S001 | Moisture: 47.5% | Time: 09:00


========================================
PROGRAM 2: STUDENT ATTENDANCE MANAGEMENT
========================================

Description:
This program implements a student attendance management
system using Object Oriented Programming.

The program stores student information and records
attendance for each student.

It also calculates attendance percentage and checks
whether the student is eligible based on the 75% attendance
requirement.

The program stores multiple students using a vector and
saves attendance records into a file.

Main Features:
- Stores student roll number
- Stores student name
- Records attendance
- Calculates attendance percentage
- Checks eligibility
- Stores multiple students
- Saves records into a file
- Generates defaulter report

Eligibility Rule:
Attendance >= 75%  -> Eligible
Attendance < 75%   -> Not Eligible

OOP Concepts Used:
- Class
- Objects
- Encapsulation
- Constructor
- Member functions
- Vector
- File handling
- Conditional statements
- Loops

Important Functions:
- markAttendance()
- getAttendancePercentage()
- isEligible()
- display()
- saveToFile()

File Generated:
attendance.txt

Expected Output:

=== Attendance Report ===
Roll: 101 | Name: Rahul | Attendance: 66.6667% | Eligibility: Not Eligible
Roll: 102 | Name: Priya | Attendance: 100% | Eligibility: Eligible
Roll: 103 | Name: Amit | Attendance: 66.6667% | Eligibility: Not Eligible

Attendance records saved to attendance.txt

=== Defaulter Report ===
Roll: 101 | Name: Rahul | Attendance: 66.6667% | Eligibility: Not Eligible
Roll: 103 | Name: Amit | Attendance: 66.6667% | Eligibility: Not Eligible


========================================
PROGRAM 3: PRODUCT CATALOG
========================================

Description:
This program implements a simple product catalog using
Object Oriented Programming.

The Product class stores product ID, product name, price
and stock quantity.

A static data member is used to count the total number
of Product objects.

The program also demonstrates inline functions and a
destructor.

Main Features:
- Stores product ID
- Stores product name
- Stores product price
- Stores stock quantity
- Updates stock
- Counts total products
- Displays product information

OOP Concepts Used:
- Class
- Objects
- Encapsulation
- Constructor
- Static data member
- Static member function
- Inline function
- Const member function
- Destructor

Important Functions:
- getId()
- getName()
- getPrice()
- updateStock()
- getTotalProducts()
- display()

Example Products:
Laptop
Mouse
Keyboard

Expected Output:

=== Product Catalog ===
ID: 1001 | Product: Laptop | Price: Rs. 55000 | Stock: 15
ID: 1002 | Product: Mouse | Price: Rs. 450 | Stock: 50
ID: 1003 | Product: Keyboard | Price: Rs. 1200 | Stock: 30

Total Products in Catalog: 3


========================================
PROGRAM 4: SMART HOME DEVICE MANAGER
========================================

Description:
This program implements a Smart Home Device Manager
using Object Oriented Programming.

The SmartDevice class stores information about smart
home devices such as device ID, name, location, status
and last updated time.

The program can switch devices ON or OFF and can also
change the status of a device.

Main Features:
- Stores device ID
- Stores device name
- Stores device location
- Stores device status
- Stores last updated time
- Switches device ON
- Switches device OFF
- Changes device status
- Displays device details

Example Devices:
- Smart Light
- Thermostat
- Security Camera
- Smart Door Lock

OOP Concepts Used:
- Class
- Objects
- Encapsulation
- Constructor
- Member functions
- Destructor
- Private data members

Important Functions:
- switchOn()
- switchOff()
- changeStatus()
- display()

Initial Status:
All devices are initially set to OFF.

Example Operations:
Smart Light -> ON at 10:00 AM
Thermostat -> ON at 10:05 AM
Security Camera -> ON at 10:10 AM
Smart Door Lock -> ON at 10:15 AM

The thermostat status is later changed to 24°C.

Expected Output:

====================================
     SMART HOME DEVICE MANAGER
====================================

===== INITIAL DEVICE STATUS =====

-----------------------------
Device ID     : 101
Device Name   : Smart Light
Location      : Living Room
Status        : OFF
Last Updated  : Not updated

-----------------------------
Device ID     : 102
Device Name   : Thermostat
Location      : Bedroom
Status        : OFF
Last Updated  : Not updated

-----------------------------
Device ID     : 103
Device Name   : Security Camera
Location      : Main Door
Status        : OFF
Last Updated  : Not updated

-----------------------------
Device ID     : 104
Device Name   : Smart Door Lock
Location      : Main Door
Status        : OFF
Last Updated  : Not updated

===== SWITCHING DEVICES ON =====
Smart Light is switched ON.
Thermostat is switched ON.
Security Camera is switched ON.
Smart Door Lock is switched ON.

===== CHANGING DEVICE STATUS =====
Thermostat status changed to 24°C.

===== SWITCHING DEVICE OFF =====
Smart Light is switched OFF.

====================================
        SMART HOME DASHBOARD
====================================

-----------------------------
Device ID     : 101
Device Name   : Smart Light
Location      : Living Room
Status        : OFF
Last Updated  : 10:30 AM

-----------------------------
Device ID     : 102
Device Name   : Thermostat
Location      : Bedroom
Status        : 24°C
Last Updated  : 10:20 AM

-----------------------------
Device ID     : 103
Device Name   : Security Camera
Location      : Main Door
Status        : ON
Last Updated  : 10:10 AM

-----------------------------
Device ID     : 104
Device Name   : Smart Door Lock
Location      : Main Door
Status        : ON
Last Updated  : 10:15 AM

====================================
       DASHBOARD COMPLETED
====================================


========================================
PROGRAM 5: EMPLOYEE PAYROLL SYSTEM
========================================

Description:
This program implements an Employee Payroll System
using inheritance and polymorphism.

Employee is the base class.

Three derived classes are created:
- FullTimeEmployee
- PartTimeEmployee
- Intern

Each employee type calculates salary differently.

Main Features:
- Stores employee ID
- Stores employee name
- Stores department
- Calculates salary
- Displays employee information
- Supports different employee types

Salary Calculation:

Full-Time Employee:
Salary = Monthly Salary

Part-Time Employee:
Salary = Hourly Rate × Hours Worked

Intern:
Salary = Stipend

OOP Concepts Used:
- Inheritance
- Abstraction
- Polymorphism
- Pure virtual function
- Function overriding
- Constructor
- Virtual destructor
- Protected members

Base Class:
Employee

Derived Classes:
FullTimeEmployee
PartTimeEmployee
Intern

Important Functions:
- displayBasicInfo()
- calculateSalary()
- display()

Important Keyword:
virtual

Pure Virtual Function:
virtual double calculateSalary() const = 0;

The pure virtual function makes Employee an
abstract class.

Expected Output:

=== Employee Payroll ===
ID: 101 | Name: Amit | Department: IT | Type: Full-Time | Salary: Rs. 65000
ID: 102 | Name: Sneha | Department: HR | Type: Part-Time | Salary: Rs. 30000
ID: 103 | Name: Rohan | Department: Marketing | Type: Intern | Stipend: Rs. 15000


========================================
PROGRAM 6: PAYMENT GATEWAY SYSTEM
========================================

Description:
This program implements a simple Payment Gateway System
using inheritance, abstraction and runtime polymorphism.

PaymentMethod is the base class.

Three payment methods are implemented:
- Credit Card
- UPI
- Net Banking

Each payment method has its own implementation of
processPayment().

Main Features:
- Stores transaction ID
- Stores payment amount
- Supports Credit Card payment
- Supports UPI payment
- Supports Net Banking payment
- Processes different payment types
- Uses smart pointers
- Uses vector

OOP Concepts Used:
- Inheritance
- Abstraction
- Runtime polymorphism
- Pure virtual function
- Function overriding
- Virtual destructor
- Smart pointers
- Vector

Base Class:
PaymentMethod

Derived Classes:
CreditCardPayment
UPIPayment
NetBankingPayment

Important Function:
processPayment()

Pure Virtual Function:
virtual bool processPayment() const = 0;

Smart Pointer Used:
unique_ptr

Function Used:
make_unique()

Important Statement:
payment->processPayment();

This demonstrates runtime polymorphism because the appropriate derived-class processPayment() function is called.

Expected Output:

=== Payment Gateway ===
Credit-card transaction TXN001 for Rs. 2500 using XXXX-XXXX 1234 completed.
UPI transaction TXN002 for Rs. 1200 from student@upi completed.
Net-banking transaction TXN003 for Rs. 5000 through Example Bank completed.


========================================
PROGRAM 7: VEHICLE FLEET MANAGEMENT SYSTEM
========================================

Description:
This program implements a Vehicle Fleet Management System using inheritance and runtime polymorphism.

Vehicle is the base class.

Three different types of vehicles are created:
- Truck
- Delivery Van
- Bike

The program stores vehicle information such as vehicle ID,registration number and fuel level.

Main Features:
- Stores vehicle ID
- Stores registration number
- Stores fuel level
- Starts vehicle engine
- Refuels vehicle
- Displays vehicle information
- Stores multiple vehicles
- Supports different vehicle types

Vehicle Types:
1. Truck
2. Delivery Van
3. Delivery Bike

Truck Feature:
- Cargo capacity

Delivery Van Feature:
- Number of packages

Bike Feature:
- Delivery box availability

OOP Concepts Used:
- Inheritance
- Polymorphism
- Function overriding
- Virtual function
- Virtual destructor
- Smart pointers
- Vector
- Encapsulation

Base Class:
Vehicle

Derived Classes:
Truck
DeliveryVan
Bike

Important Functions:
- startEngine()
- refuel()
- displayInfo()

Important Statement:
vehicle->displayInfo();

Because displayInfo() is virtual, the appropriate derived-class version is called at runtime.

This demonstrates runtime polymorphism.

Expected Output:

=== Fleet Status ===
Vehicle V001 engine started.
Truck | Vehicle ID: V001 | Registration: MH12-AB-1234 | Fuel: 100%
Cargo capacity: 10.5 tonnes

Vehicle V002 engine started.
Delivery Van | Vehicle ID: V002 | Registration: MH12-CD-5678 | Fuel: 100%
Packages loaded: 50

Vehicle V003 engine started.
Delivery Bike | Vehicle ID: V003 | Registration: MH12-EF-9012 | Fuel: 100%
Delivery box: Available


========================================
PROGRAM 8: BANKING SYSTEM WITH ACCOUNT HIERARCHY
========================================

Description:
This mini-project implements a Banking System using Object Oriented Programming.

Account is the base class.

Three derived account classes are created:
- SavingsAccount
- CurrentAccount
- FixedDepositAccount

The system supports account information, deposits,withdrawals and interest calculation.

Main Features:
- Stores account number
- Stores account holder name
- Stores account balance
- Deposits money
- Withdraws money
- Calculates interest
- Displays account details
- Supports different account types
- Uses runtime polymorphism
- Uses smart pointers
- Uses vector

Account Types:

1. Savings Account
   Interest Rate = 4%

2. Current Account
   Interest Rate = 2%

3. Fixed Deposit Account
   Interest Rate = 7%

Fixed Deposit:
Interest = Balance × Rate × Time / 100

Savings and Current Account:
Interest = Balance × Rate / 100

OOP Concepts Used:
- Class
- Inheritance
- Abstraction
- Polymorphism
- Pure virtual functions
- Function overriding
- Constructor
- Virtual destructor
- Smart pointers
- Vector
- Encapsulation

Base Class:
Account

Derived Classes:
SavingsAccount
CurrentAccount
FixedDepositAccount

Important Functions:
- deposit()
- withdraw()
- calculateInterest()
- displayAccount()

Pure Virtual Functions:
virtual void withdraw(double amount) = 0;

virtual double calculateInterest() const = 0;

Important Statement:
account->displayAccount();

This demonstrates runtime polymorphism because the appropriate account-specific displayAccount() function is called.

Expected Output:

========================================
       BANKING SYSTEM
========================================

--- Deposit Operation ---
Rs. 5000 deposited successfully.

--- Withdrawal Operation ---
Rs. 10000 withdrawn from Savings Account.

--- Account Details ---

===== Savings Account =====
Account Number : SA1001
Holder Name    : Amit
Balance        : Rs. 45000
Interest Rate  : 4%
Interest       : Rs. 1800

===== Current Account =====
Account Number : CA1002
Holder Name    : Sneha
Balance        : Rs. 80000
Interest Rate  : 2%
Interest       : Rs. 1600

===== Fixed Deposit Account =====
Account Number : FD1003
Holder Name    : Rohan
Balance        : Rs. 100000
Interest Rate  : 7%
Duration       : 3 years
Interest       : Rs. 21000

========================================
       BANKING SYSTEM COMPLETED
========================================


========================================
        OOP CONCEPT SUMMARY
========================================

The above programs demonstrate the following important
Object Oriented Programming concepts:

1. CLASS
   A class is a blueprint for creating objects.

2. OBJECT
   An object is an instance of a class.

3. ENCAPSULATION
   Data and functions are combined inside a class.

4. INHERITANCE
   A derived class can inherit properties and functions
   from a base class.

5. ABSTRACTION
   Unnecessary implementation details are hidden and
   only required functionality is provided.

6. POLYMORPHISM
   The same function can behave differently for different
   objects.

7. VIRTUAL FUNCTION
   Allows the derived-class function to be called through
   a base-class pointer.

8. PURE VIRTUAL FUNCTION
   A virtual function declared using = 0.

9. FUNCTION OVERRIDING
   A derived class provides its own implementation of
   a base-class virtual function.

10. CONSTRUCTOR
    Automatically initializes an object when it is created.

11. DESTRUCTOR
    Automatically executes when an object is destroyed.

12. VECTOR
    Used to store multiple objects or pointers.

13. SMART POINTER
    unique_ptr automatically manages dynamically allocated
    objects.

14. RUNTIME POLYMORPHISM
    The function to be executed is decided at runtime.


========================================
        TESTING ENVIRONMENT
========================================

Language Used:
C++

Compiler:
G++ (MinGW)

IDE:
Visual Studio Code

Operating System:
Windows

Programming Paradigm:
Object Oriented Programming (OOP)


========================================
             CONCLUSION
========================================

These eight programs demonstrate practical applications of Object Oriented Programming in C++.

The programs cover basic and advanced OOP concepts such as classes, objects, encapsulation, constructors, inheritance,
abstraction, polymorphism, virtual functions, overriding,vectors and smart pointers.

These real-time applications help understand how OOP
concepts can be used to design structured and reusable
software systems.


========================================
      END OF REAL TIME APPLICATIONS
========================================