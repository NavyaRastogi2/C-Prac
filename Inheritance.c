//Design and implement a foos delivery system in C++ using inheritence 
//Create a classs Foodorder with the following data
//Order id 
//Customer name
//numberofitems 
//Create a derived class restaurant oprder that inherits from Foodorder and the derived class should store the following details for maximum 5 different items.
// THE PROGRAM SHOULD - 
// !. use a parameterized constructor for base and derived class 
//2. accept the details of the food orderered by the customer 
// 3. Calculate the cost of each item using - 
//  Total item cost = Quantity * price
// 4. calculate the total food cost of the orders 
// 5. calculate the delivery chargwe acc to the following rules 
//  total food cost       delivery xharge 
//  Cost <v 300              RP 50 
//  RP 300 < cost <700 RP    RP 30 
//  RP 700 < cost            Free // rp 0 
// 6. Provide 10% discount on total food cost if orders more than 3 different food items 
// Display a properly formatted bill consisting of customer name , details, restautrant name, food cost, delivery charge , discount, and final bill 
// FINAL BILL = TOTAL FOOD COST + DELIVERY CHARGE  - DISCOUNT 
#include <iostream>

using namespace std;

class FoodOrder {
public
    int orderId;
    string customerName;
    int numberOfItems;

    FoodOrder(int id, string name) {
        orderId = id;
        customerName = name;
        numberOfItems = 1;   // Only one item
    }

    void displayDetails() {
        cout << "\n========== ORDER DETAILS ==========\n";
        cout << "Order ID       : " << orderId << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Number of Items: " << numberOfItems << endl;
    }
};

int main() {
    int orderId;
    string customerName;

    cout << "Enter order ID: ";
    cin >> orderId;

    cout << "Enter customer name: ";
    cin >> ws;
    getline(cin, customerName);

    FoodOrder order(orderId, customerName);

    order.displayDetails();

    return 0;
}

