#include <iostream>
#include <cstdlib> 
#include <stdexcept>
#include <cstring> 

using namespace std;

class DynamicArray {
private:
    int* data; 
    size_t capacity; 
    size_t size; 

public:
    DynamicArray(size_t initial_capacity = 10) : capacity(initial_capacity), size(0) {
        data = static_cast<int*>(std::malloc(capacity * sizeof(int))); 
        if (!data) {
            throw std::runtime_error("Memory allocation failed"); 
        }
    }

    ~DynamicArray() {
        std::free(data); 
    }

    void push_back(int value) {
        if (size == capacity) { 
            resize();
        }
        data[size++] = value; 
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range"); 
        }
        std::memmove(data + index, data + index + 1, (size - index - 1) * sizeof(int)); 
        --size; 
    }

    size_t getSize() const {
        return size;
    }

    int get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range"); 
        }
        return data[index]; 
    }

    void resize() {
        capacity *= 2; 
        int* new_data = static_cast<int*>(std::realloc(data, capacity * sizeof(int))); 
        if (!new_data) {
            throw std::runtime_error("Memory reallocation failed"); 
        }
        data = new_data; 
    }
};

int main() {
    try {
        DynamicArray arr; 

        for (int i = 0; i < 20; ++i) {
            arr.push_back(i); 
        }

        cout << "Elements in the array: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            cout << arr.get(i) << " "; 
        }
        cout << endl;

        arr.remove(7);
        cout << "After removing element at index 5: ";
        for (size_t i = 0; i < arr.getSize(); ++i) {
            cout << arr.get(i) << " "; 
        }
        cout << endl;

    } catch (const std::exception& e) {
        cout<< "Error: " << e.what() << endl; 
    }

    return 0;
}
