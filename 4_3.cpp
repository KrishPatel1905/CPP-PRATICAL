#include <iostream>
using namespace std;

class Fuel {
protected:
    string fuelType;
public:
    Fuel(string type) {
        fuelType = type;
    }
    void showFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand {
protected:
    string brandName;
public:
    Brand(string name) {
        brandName = name;
    }
    void showBrand() {
        cout << "Brand Name: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand {
public:
    Car(string type, string name) : Fuel(type), Brand(name) {}

    void showDetails() {
        showBrand();
        showFuel();
    }
};

int main() {
    Car cars[3] = {
        Car("Petrol", "Toyota"),
        Car("Electric", "Tesla"),
        Car("Diesel", "Ford")
    };

    for (int i = 0; i < 3; i++) {
        cout << "Car " << i + 1 << " details:" << endl;
        cars[i].showDetails();
        cout << "----------------------" << endl;
    }

    return 0;
}
