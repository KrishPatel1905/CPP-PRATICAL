#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
string name;
int marks;
string grade;
};

void displayReport(Student students[], int count) {
cout << left << setw(20) << "Name"
<< setw(10) << "Marks"
<< "Grade" << endl;
cout << "----------------------------------------" << endl;

for (int i = 0; i < count; i++) {
cout << setw(20) << students[i].name
<< setw(10) << students[i].marks
<< students[i].grade << endl;
}
}

bool readFileAndProcessData(const string& filename, Student students[], int& count) {
ifstream file(filename);
if (!file) {
cerr << "Error: File could not be opened." << endl;
return false;
}

count = 0;
while (file >> students[count].name >> students[count].marks >> students[count].grade) {
count++;
if (count >= 100) break;
}

file.close();
return true;
}

int main() {
Student students[100];
int studentCount = 0;
string filename = "student.txt";

if (!readFileAndProcessData(filename, students, studentCount)) {
return 1;
}

displayReport(students, studentCount);

return 0;
}