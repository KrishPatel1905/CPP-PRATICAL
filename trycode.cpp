#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
     fstream file;
    file.open("data.txt", ios::app); // Write mode
    file << "krish hitesh bhai" << endl;
    file.close();

    file.open("data.txt", ios::in); // Read mode
    string text;
    while (getline(file, text)) {
        cout << text << endl;
    }
    file.close();
    return 0;
}
