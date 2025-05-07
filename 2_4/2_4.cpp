#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:
    InventoryItem() {
        itemID = 0;
        itemName = "NoName";
        price = 0.0;
        quantity = 0;
    }

    InventoryItem(int id, string name, float p, int qty) {
        itemID = id;
        itemName = name;
        price = p;
        quantity = qty;
    }

    void addStock(int qty) {
        quantity += qty;
        cout << qty << " units added. New quantity: " << quantity << endl;
    }

    void sellItem(int qty) {
        if (qty <= quantity) {
            quantity -= qty;
            cout << qty << " units sold. Remaining quantity: " << quantity << endl;
        } else {
            cout << "Error: Not enough stock to sell " << qty << " units!" << endl;
        }
    }

    void displayItem() {
        cout << "ID: " << itemID 
             << ", Name: " << itemName 
             << ", Price: " << price 
             << ", Quantity: " << quantity << endl;
    }
};

int main() {
    InventoryItem pen(1, "Pen", 10.5, 100);
    InventoryItem notebook(2, "Notebook", 50.0, 200);
    InventoryItem eraser(3, "Eraser", 5.0, 150);

    cout << "\nAdding Stock:\n";
    pen.addStock(50);
    notebook.addStock(30);
    eraser.addStock(20);

    cout << "\nSelling Items:\n";
    pen.sellItem(20);
    notebook.sellItem(50);
    eraser.sellItem(200);

    cout << "\nUpdated Inventory:\n";
    pen.displayItem();
    notebook.displayItem();
    eraser.displayItem();

    return 0;
}
