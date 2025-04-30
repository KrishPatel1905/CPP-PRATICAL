#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    
    vector<int> numbers = {1, 2, 3, 4, 5};

    
    reverse(numbers.begin(), numbers.end());

    
    cout << "Reversed vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }

    return 0;
}
