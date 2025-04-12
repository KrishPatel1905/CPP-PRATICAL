#include <iostream>
using namespace std;

// Forward declaration
class Fahrenheit;

class Celsius {
public:
    float temp;

    Celsius(float t = 0) {
        temp = t;
    }

  
    operator Fahrenheit();
};

class Fahrenheit {
public:
    float temp;

    Fahrenheit(float t = 32) {
        temp = t;
    }

  
    operator Celsius() {
        return Celsius((temp - 32) * 5 / 9);
    }
};


Celsius::operator Fahrenheit() {
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main() {
   
    Celsius celsiusTemps[3] = { Celsius(25), Celsius(0), Celsius(100) };
    
    
    Fahrenheit fahrenheitTemps[3];

    for (int i = 0; i < 3; i++) {
        fahrenheitTemps[i] = celsiusTemps[i]; 
    }

  
    cout << "\nTemperatures in Fahrenheit (Array): ";
    for (int i = 0; i < 3; i++) {
        cout << fahrenheitTemps[i].temp << " F, ";
    }

    return 0;
}
