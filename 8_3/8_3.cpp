#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> transactionIDs;
    cout << "Enter the transaction IDs: ";
    while (n--) {
        int id;
        cin >> id;
        transactionIDs.insert(id); 
    }

    cout << "Unique transaction IDs in sorted order: ";
    for (int id : transactionIDs) {
        cout << id << " "; 
    }
    cout << endl;

    return 0;
}