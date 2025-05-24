#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "PLEASE ENTER THE VALID OUTPUT '" << filename << "'" << endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    string line;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length() + 1; // +1 for newline character

        int inWord = 0;
        for (int i = 0; line[i] != '\0'; i++) {
            char ch = line[i];
            if (ch == ' ' || ch == '\t') {
                inWord = 0;
            } else {
                if (inWord == 0) {
                    wordCount++;
                    inWord = 1;
                }
            }
        }
    }

    cout << "Lines: " << lineCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << charCount << endl;

    return 0;
}
