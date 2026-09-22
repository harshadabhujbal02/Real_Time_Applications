#include <iostream>                  // Includes input/output library for cout and endl
#include <string>                    // Includes string data type

using namespace std;                 // Allows us to use cout, string, etc. directly


class Product                         // Defines a class named Product
{
private:                              // Starts the private section

    int productId;                    // Stores the unique ID of the product
    string productName;               // Stores the name of the product
    double price;                     // Stores the price of the product
    int stockQuantity;                // Stores the number of products available in stock

    static int totalProducts;         // Static variable shared by all Product objects
                                      // Keeps track of the total number of products


public:                               // Starts the public section


    Product(int id, string name, double p, int stock)
        // Constructor of the Product class
        // id = product ID
        // name = product name
        // p = product price
        // stock = stock quantity

        : productId(id),               // Initializes productId with id
          productName(name),           // Initializes productName with name
          price(p),                    // Initializes price with p
          stockQuantity(stock)         // Initializes stockQuantity with stock

    {
        totalProducts++;               // Increases totalProducts by 1
                                        // Every time a Product object is created
    }


    inline int getId() const
    // inline = suggests that the function can be expanded at the place of call
    // int = function returns an integer
    // getId = function name
    // const = function will not modify the object

    {
        return productId;              // Returns the product ID
    }


    inline string getName() const
    // inline = inline function
    // string = function returns a string
    // getName = function name
    // const = does not modify the object

    {
        return productName;            // Returns the product name
    }


    inline double getPrice() const
    // inline = inline function
    // double = function returns a decimal value
    // getPrice = function name
    // const = does not modify the object

    {
        return price;                  // Returns the product price
    }


    void updateStock(int quantity)
    // void = function does not return a value
    // updateStock = function name
    // quantity = new stock quantity

    {
        stockQuantity = quantity;      // Updates the current stock quantity
    }


    static int getTotalProducts()
    // static = function belongs to the class, not a particular object
    // int = function returns an integer
    // getTotalProducts = function name

    {
        return totalProducts;          // Returns the total number of products
    }


    void display() const
    // void = function does not return a value
    // display = function name
    // const = function will not modify the object

    {
        cout << "ID: " << productId
             // Prints product ID

             << " | Product: " << productName
             // Prints product name

             << " | Price: Rs. " << price
             // Prints product price

             << " | Stock: " << stockQuantity
             // Prints available stock

             << endl;                  // Moves cursor to the next line
    }


    ~Product()
    // Destructor of the Product class
    // ~ is used to define a destructor
    // Destructor is automatically called when an object is destroyed

    {
        totalProducts--;                // Decreases totalProducts by 1
    }

};                                      // Ends the Product class


int Product::totalProducts = 0;
// Defines and initializes the static variable
// Product:: means totalProducts belongs to the Product class
// Initially, totalProducts is 0


int main()
{
    // Main function
    // Program execution starts from here


    Product p1(1001, "Laptop", 55000, 15);
    // Creates first Product object named p1
    // ID = 1001
    // Name = Laptop
    // Price = 55000
    // Stock = 15
    // Constructor is automatically called
    // totalProducts becomes 1


    Product p2(1002, "Mouse", 450, 50);
    // Creates second Product object named p2
    // ID = 1002
    // Name = Mouse
    // Price = 450
    // Stock = 50
    // totalProducts becomes 2


    Product p3(1003, "Keyboard", 1200, 30);
    // Creates third Product object named p3
    // ID = 1003
    // Name = Keyboard
    // Price = 1200
    // Stock = 30
    // totalProducts becomes 3


    cout << "=== Product Catalog ===" << endl;
    // Displays the heading
    // endl moves to the next line


    p1.display();
    // Calls display() for p1


    p2.display();
    // Calls display() for p2


    p3.display();
    // Calls display() for p3


    cout << "\nTotal Products in Catalog: "
         // \n creates a new line

         << Product::getTotalProducts()
         // Calls the static function using the class name
         // Returns the current total number of products

         << endl;                      // Moves to the next line


}                                       // Ends main() function