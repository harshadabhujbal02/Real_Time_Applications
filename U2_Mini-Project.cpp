#include <iostream>
// Includes the input-output library.
// It allows us to use cout and endl.

#include <string>
// Includes the string data type.
// Used for account number and holder name.

#include <vector>
// Includes the vector container.
// Used to store multiple account objects.

#include <memory>
// Includes smart pointers such as unique_ptr and make_unique.

using namespace std;
// Allows us to use cout, string, vector, unique_ptr, etc.
// without writing std:: before them.



// ================= BASE CLASS =================

// Base class
class Account
// Creates a class named Account.
// This is the parent/base class for all account types.
{
protected:
    // Protected members can be accessed inside this class
    // and also inside its derived classes.

    string accountNumber;
    // Stores the account number.

    string holderName;
    // Stores the account holder's name.

    double balance;
    // Stores the current account balance.


public:
    // Public members can be accessed from outside the class.


    // Constructor
    Account(string accNo, string name, double initialBalance)
        : accountNumber(accNo),
          holderName(name),
          balance(initialBalance)
    {
        // Initializes accountNumber with accNo.
        // Initializes holderName with name.
        // Initializes balance with initialBalance.
    }


    // ================= DEPOSIT =================

    // Deposit money
    void deposit(double amount)
    {
        // Receives the amount to be deposited.

        if (amount > 0)
        {
            // Checks whether the deposit amount is positive.

            balance += amount;
            // Adds the deposit amount to the balance.

            cout << "Rs. " << amount
                 << " deposited successfully." << endl;
            // Displays successful deposit message.
        }
        else
        {
            // Executes when the amount is zero or negative.

            cout << "Invalid deposit amount." << endl;
            // Displays an error message.
        }
    }


    // ================= WITHDRAW =================

    // Pure virtual withdrawal function
    virtual void withdraw(double amount) = 0;

    // virtual
    // Allows derived classes to provide their own implementation.

    // void
    // Function does not return a value.

    // withdraw
    // Function name.

    // double amount
    // Amount to be withdrawn.

    // = 0
    // Makes this a pure virtual function.

    // Therefore Account becomes an abstract class.


    // ================= INTEREST =================

    // Pure virtual interest function
    virtual double calculateInterest() const = 0;

    // virtual
    // Allows different account classes to calculate interest differently.

    // double
    // Function returns a decimal value.

    // calculateInterest
    // Function name.

    // const
    // Function does not modify the object.

    // = 0
    // Makes it a pure virtual function.


    // ================= DISPLAY =================

    // Function to display common account information
    virtual void displayAccount() const
    {
        cout << "Account Number : " << accountNumber << endl;
        // Displays account number.

        cout << "Holder Name    : " << holderName << endl;
        // Displays account holder name.

        cout << "Balance        : Rs. " << balance << endl;
        // Displays current balance.
    }


    // Virtual destructor
    virtual ~Account() = default;

    // ~Account
    // Destructor of Account.

    // virtual
    // Allows proper destruction of derived objects.

    // = default
    // Uses compiler-generated destructor.
};



// ================= SAVINGS ACCOUNT =================

class SavingsAccount : public Account
// Creates SavingsAccount class.
// It inherits from Account.
// Therefore SavingsAccount is a derived/child class.
{
private:

    double interestRate;
    // Stores the savings account interest rate.


public:

    // Constructor of SavingsAccount
    SavingsAccount(string accNo,
                   string name,
                   double initialBalance)
        : Account(accNo, name, initialBalance),
          interestRate(4.0)
    {
        // Calls the Account constructor.

        // Sets the savings interest rate to 4%.
    }


    // Withdrawal function
    void withdraw(double amount) override
    {
        // override means this function overrides
        // the pure virtual withdraw() function
        // of the Account class.

        if (amount > 0 && amount <= balance)
        {
            // Checks:
            // 1. Amount is greater than zero.
            // 2. Amount is not greater than balance.

            balance -= amount;
            // Subtracts withdrawal amount from balance.

            cout << "Rs. " << amount
                 << " withdrawn from Savings Account." << endl;
            // Displays successful withdrawal message.
        }
        else
        {
            // Executes if amount is invalid
            // or balance is insufficient.

            cout << "Invalid withdrawal amount or insufficient balance."
                 << endl;
            // Displays error message.
        }
    }


    // Calculate savings interest
    double calculateInterest() const override
    {
        // Calculates interest using:

        // Interest = Balance × Interest Rate / 100

        return balance * interestRate / 100;
        // Returns calculated interest.
    }


    // Display savings account
    void displayAccount() const override
    {
        cout << "\n===== Savings Account =====" << endl;
        // Displays account type heading.

        Account::displayAccount();
        // Calls displayAccount() of the parent Account class.
        // Displays account number, holder name and balance.

        cout << "Interest Rate  : "
             << interestRate << "%" << endl;
        // Displays interest rate.

        cout << "Interest       : Rs. "
             << calculateInterest() << endl;
        // Calculates and displays interest.
    }
};



// ================= CURRENT ACCOUNT =================

class CurrentAccount : public Account
// Creates CurrentAccount class.
// It inherits from Account.
{
private:

    double interestRate;
    // Stores current account interest rate.


public:

    // Constructor
    CurrentAccount(string accNo,
                   string name,
                   double initialBalance)
        : Account(accNo, name, initialBalance),
          interestRate(2.0)
    {
        // Calls Account constructor.

        // Sets current account interest rate to 2%.
    }


    // Withdrawal function
    void withdraw(double amount) override
    {
        // Overrides the Account withdraw() function.

        if (amount > 0 && amount <= balance)
        {
            // Checks whether withdrawal amount is valid.

            balance -= amount;
            // Subtracts amount from balance.

            cout << "Rs. " << amount
                 << " withdrawn from Current Account." << endl;
            // Displays successful withdrawal message.
        }
        else
        {
            // Executes when withdrawal is invalid.

            cout << "Invalid withdrawal amount or insufficient balance."
                 << endl;
            // Displays error message.
        }
    }


    // Calculate current account interest
    double calculateInterest() const override
    {
        // Calculates interest using:

        // Interest = Balance × Interest Rate / 100

        return balance * interestRate / 100;
        // Returns calculated interest.
    }


    // Display current account
    void displayAccount() const override
    {
        cout << "\n===== Current Account =====" << endl;
        // Displays account type heading.

        Account::displayAccount();
        // Displays common account information.

        cout << "Interest Rate  : "
             << interestRate << "%" << endl;
        // Displays interest rate.

        cout << "Interest       : Rs. "
             << calculateInterest() << endl;
        // Calculates and displays interest.
    }
};



// ================= FIXED DEPOSIT ACCOUNT =================

class FixedDepositAccount : public Account
// Creates FixedDepositAccount class.
// It inherits from Account.
{
private:

    double interestRate;
    // Stores fixed deposit interest rate.

    int durationYears;
    // Stores FD duration in years.


public:

    // Constructor
    FixedDepositAccount(string accNo,
                        string name,
                        double initialBalance,
                        int years)
        : Account(accNo, name, initialBalance),
          interestRate(7.0),
          durationYears(years)
    {
        // Calls Account constructor.

        // Sets interest rate to 7%.

        // Stores FD duration.
    }


    // Withdrawal function
    void withdraw(double amount) override
    {
        // Overrides the Account withdraw() function.

        cout << "Withdrawal is not allowed from Fixed Deposit Account "
             << "before maturity." << endl;
        // Displays that withdrawal is not allowed
        // before the fixed deposit matures.
    }


    // Calculate fixed deposit interest
    double calculateInterest() const override
    {
        // Simple Interest formula:
        //
        // Interest =
        // Balance × Rate × Time / 100

        return balance * interestRate * durationYears / 100;
        // Returns the calculated FD interest.
    }


    // Display FD information
    void displayAccount() const override
    {
        cout << "\n===== Fixed Deposit Account =====" << endl;
        // Displays FD heading.

        Account::displayAccount();
        // Displays account number, name and balance.

        cout << "Interest Rate  : "
             << interestRate << "%" << endl;
        // Displays FD interest rate.

        cout << "Duration       : "
             << durationYears << " years" << endl;
        // Displays FD duration.

        cout << "Interest       : Rs. "
             << calculateInterest() << endl;
        // Calculates and displays FD interest.
    }
};



// ================= MAIN FUNCTION =================

int main()
{
    // Creates a vector of unique pointers
    // to Account objects.

    vector<unique_ptr<Account>> accounts;

    // vector
    // Stores multiple elements.

    // unique_ptr<Account>
    // Smart pointer to an Account object.

    // accounts
    // Name of the vector.



    // ================= CREATE SAVINGS ACCOUNT =================

    accounts.push_back(
        make_unique<SavingsAccount>(
            "SA1001",
            "Amit",
            50000
        )
    );

    // make_unique<SavingsAccount>
    // Creates a SavingsAccount object.

    // "SA1001"
    // Account number.

    // "Amit"
    // Account holder name.

    // 50000
    // Initial balance.

    // push_back()
    // Adds the account to the vector.



    // ================= CREATE CURRENT ACCOUNT =================

    accounts.push_back(
        make_unique<CurrentAccount>(
            "CA1002",
            "Sneha",
            80000
        )
    );

    // CA1002 -> Account number.
    // Sneha  -> Account holder.
    // 80000  -> Initial balance.



    // ================= CREATE FIXED DEPOSIT =================

    accounts.push_back(
        make_unique<FixedDepositAccount>(
            "FD1003",
            "Rohan",
            100000,
            3
        )
    );

    // FD1003 -> Account number.
    // Rohan   -> Account holder.
    // 100000  -> Initial balance.
    // 3       -> FD duration of 3 years.



    // ================= PROGRAM HEADER =================

    cout << "========================================" << endl;
    // Prints top border.

    cout << "       BANKING SYSTEM" << endl;
    // Prints program title.

    cout << "========================================" << endl;
    // Prints bottom border.



    // ================= DEPOSIT =================

    cout << "\n--- Deposit Operation ---" << endl;
    // Prints deposit section heading.

    accounts[0]->deposit(5000);
    // accounts[0] refers to the first account.
    // The first account is the Savings Account.
    // Deposits Rs. 5000.
    //
    // -> is used to access a function through a pointer.



    // ================= WITHDRAWAL =================

    cout << "\n--- Withdrawal Operation ---" << endl;
    // Prints withdrawal section heading.

    accounts[0]->withdraw(10000);
    // Calls withdraw() for the first account.
    // Since the first account is SavingsAccount,
    // SavingsAccount's withdraw() function is executed.
    //
    // Initial balance = Rs. 50,000
    // Deposit         = Rs. 5,000
    // New balance     = Rs. 55,000
    // Withdrawal      = Rs. 10,000
    // Final balance   = Rs. 45,000



    // ================= DISPLAY ACCOUNTS =================

    cout << "\n--- Account Details ---" << endl;
    // Prints account details heading.


    // Loop through all accounts
    for (const auto& account : accounts)
    {
        // const
        // Prevents modification of the reference.

        // auto
        // Compiler automatically determines the data type.

        // &
        // Uses a reference instead of copying the smart pointer.

        // account
        // Represents the current account in the loop.


        account->displayAccount();
        // Calls displayAccount().
        //
        // Because displayAccount() is virtual,
        // the correct derived-class version is called.
    }



    // ================= END MESSAGE =================

    cout << "\n========================================" << endl;
    // Prints top border.

    cout << "       BANKING SYSTEM COMPLETED" << endl;
    // Prints completion message.

    cout << "========================================" << endl;
    // Prints bottom border.


    return 0;
    // Ends the program successfully.
}