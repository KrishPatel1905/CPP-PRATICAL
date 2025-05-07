#include <iostream>
using namespace std;

class ManagementSystem {
    int ProId;
    char ProName[25];
    int ProQuantity = 1;
    int ProPrice;
    int ProTotal = 1;
    static int total;

public:
    void AddProduct();
    void UpdateProduct(int id);
    void DisplayProduct();
    static void DisplayTotal();
};

int ManagementSystem::total = 0;

void ManagementSystem::AddProduct() {
    cout << "Enter the Product Id: ";
    cin >> ProId;
    cout << "Enter the Product Name: ";
    cin >> ProName;
    cout << "Enter the price of product: ";
    cin >> ProPrice;

    ProTotal = ProQuantity * ProPrice;
    total += ProTotal;
}

void ManagementSystem::UpdateProduct(int id) {
    if (ProId == id) {
        int x;
        cout << "Enter the quantity of product: ";
        cin >> x;
        ProQuantity += x;

        total -= ProTotal;
        ProTotal = ProQuantity * ProPrice;
        total += ProTotal;

        cout << "Updated total price of product is: " << ProTotal << endl;
    } else {
        cout << "Product ID not found." << endl;
    }
}

void ManagementSystem::DisplayProduct() {
    cout << "Product ID: " << ProId
         << ", Name: " << ProName
         << ", Quantity: " << ProQuantity
         << ", Price: " << ProPrice
         << ", Total: " << ProTotal << endl;
}

void ManagementSystem::DisplayTotal() {
    cout <<endl<< "Total price of all products: " << total << endl;
}

int main() {
    int numProducts = 2;
    ManagementSystem A[numProducts];

    for (int i = 0; i < numProducts; i++) {
        A[i].AddProduct();
        cout << "--------------------" << endl;
    }

    int id;
    cout << "Enter the product ID you want to update: ";
    cin >> id;
    
    for (int i = 0; i < numProducts; i++) {
        A[i].UpdateProduct(id);
    }

    cout << "\nAll Products Details:\n";
    for (int i = 0; i < numProducts; i++) {
        A[i].DisplayProduct();
    }

    ManagementSystem::DisplayTotal();

    return 0;
}
