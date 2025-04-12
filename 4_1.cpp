#include <iostream>
using namespace std;

class shape {
protected:  
    float R;

public:
    void GetData() {
        cout << "Enter the value of R: ";
        cin >> R;
    }

    float get() {   
        return R;
    }
};

class circle : public shape {   
    float A;

public:
    void CalArea() {
        GetData();  
        A = 3.14 * get() * get();
        cout << "Area: " << A << endl;
    }
};

int main() {
    circle c;
    c.CalArea();

    return 0;
}
