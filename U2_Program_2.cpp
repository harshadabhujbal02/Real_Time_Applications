#include <iostream>          // Includes input-output library for cout and endl
#include <memory>            // Includes smart pointers such as unique_ptr and make_unique
#include <string>            // Includes string data type
#include <vector>            // Includes vector container

using namespace std;         // Allows us to use cout, string, vector, etc. directly


// Base class for different payment methods
class PaymentMethod
{
protected:
    string transactionId;    // Stores the unique transaction ID

    double amount;           // Stores the payment amount


public:

    // Constructor of PaymentMethod
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt)
    {
        // Initializes transactionId with tid
        // Initializes amount with amt
    }


    // Pure virtual function
    virtual bool processPayment() const = 0;
    // virtual          -> Allows derived classes to provide their own implementation
    // bool             -> Function returns true or false
    // processPayment   -> Function name
    // const            -> Function does not modify the object
    // = 0              -> Makes this a pure virtual function
    // PaymentMethod becomes an abstract class


    // Virtual destructor
    virtual ~PaymentMethod() = default;
    // ~PaymentMethod -> Destructor of the PaymentMethod class
    // virtual        -> Supports proper destruction through base-class pointers
    // = default      -> Uses the compiler-generated destructor
};


// Derived class for Credit Card payments
class CreditCardPayment : public PaymentMethod
// CreditCardPayment inherits from PaymentMethod
{
private:

    string maskedCardNumber;     // Stores a masked credit-card number


public:

    // Constructor of CreditCardPayment
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card)
    {
        // Calls PaymentMethod constructor
        // Initializes transactionId and amount

        // Initializes maskedCardNumber with card
    }


    // Overrides the processPayment function
    bool processPayment() const override
    {
        // override means this function replaces
        // the pure virtual function of the base class

        cout << "Credit-card transaction " << transactionId
             // Displays the transaction ID

             << " for Rs. " << amount
             // Displays the payment amount

             << " using " << maskedCardNumber
             // Displays the masked card number

             << " completed." << endl;
             // Displays that the transaction is completed

        return true;
        // Returns true to indicate successful payment
    }
};


// Derived class for UPI payments
class UPIPayment : public PaymentMethod
// UPIPayment inherits from PaymentMethod
{
private:

    string upiId;              // Stores the UPI ID


public:

    // Constructor of UPIPayment
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi)
    {
        // Calls PaymentMethod constructor
        // Initializes transactionId and amount

        // Initializes upiId with upi
    }


    // Overrides processPayment
    bool processPayment() const override
    {
        // Provides the UPI-specific implementation

        cout << "UPI transaction " << transactionId
             // Displays transaction ID

             << " for Rs. " << amount
             // Displays payment amount

             << " from " << upiId
             // Displays the UPI ID

             << " completed." << endl;
             // Displays that the payment is completed

        return true;
        // Returns true for successful payment
    }
};


// Derived class for Net Banking payments
class NetBankingPayment : public PaymentMethod
// NetBankingPayment inherits from PaymentMethod
{
private:

    string bankName;           // Stores the bank name


public:

    // Constructor of NetBankingPayment
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank)
    {
        // Calls PaymentMethod constructor
        // Initializes transactionId and amount

        // Initializes bankName with bank
    }


    // Overrides processPayment
    bool processPayment() const override
    {
        // Provides the Net Banking implementation

        cout << "Net-banking transaction " << transactionId
             // Displays transaction ID

             << " for Rs. " << amount
             // Displays payment amount

             << " through " << bankName
             // Displays bank name

             << " completed." << endl;
             // Displays transaction completion message

        return true;
        // Returns true for successful payment
    }
};


// Main function
int main()
{
    // Creates a vector that stores unique pointers
    // to PaymentMethod objects

    vector<unique_ptr<PaymentMethod>> payments;
    // vector              -> Container that stores multiple values
    // unique_ptr          -> Smart pointer that owns an object
    // PaymentMethod       -> Base class type
    // payments            -> Name of the vector


    // Creates a CreditCardPayment object dynamically
    // and stores it inside the vector

    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001",
            2500,
            "XXXX-XXXX 1234"
        )
    );

    // TXN001          -> Transaction ID
    // 2500            -> Payment amount
    // XXXX-XXXX 1234  -> Masked card number
    // make_unique     -> Creates a unique_ptr automatically
    // push_back       -> Adds the pointer to the vector


    // Creates a UPIPayment object
    // and adds it to the vector

    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002",
            1200,
            "student@upi"
        )
    );

    // TXN002        -> Transaction ID
    // 1200          -> Payment amount
    // student@upi   -> UPI ID


    // Creates a NetBankingPayment object
    // and adds it to the vector

    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003",
            5000,
            "Example Bank"
        )
    );

    // TXN003       -> Transaction ID
    // 5000         -> Payment amount
    // Example Bank -> Bank name


    cout << "=== Payment Gateway ===" << endl;
    // Displays the heading


    // Loop through every payment in the vector
    for (const auto& payment : payments)
    {
        // const -> The pointer cannot be modified inside the loop
        // auto  -> Compiler automatically determines the data type
        // &     -> Uses a reference instead of making a copy
        // payment -> Current payment object/pointer


        payment->processPayment();
        // -> is used to access the object through a pointer
        // Calls processPayment()
        // The correct derived-class version is executed
    }


    return 0;
    // Ends the program successfully
}