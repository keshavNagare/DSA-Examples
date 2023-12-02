#include <iostream>
#include <string>
using namespace std;
struct Student {
int rollNo;
string name;
float sgpa;
};
// Function to perform Bubble Sort
void bubbleSort(Student arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j].rollNo > arr[j + 1].rollNo) {
// Swap the students
Student temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}
int main() {
const int maxStudents = 5;
Student students[maxStudents];
cout << "Enter student details:\n";
for (int i = 0; i < maxStudents; i++) {
cout << "Student " << i + 1 << ":\n";
cout << "Roll No: ";
cin >> students[i].rollNo;
cout << "Name: ";
cin.ignore(); // Clear the newline character from previous input
getline(cin, students[i].name);
cout << "SGPA: ";
cin >> students[i].sgpa;
cout << endl;
}
// Sort the students by roll number using Bubble Sort
bubbleSort(students, maxStudents);
cout << "\nRoll Call List (sorted by Roll No):\n";
cout << "-----------------------------------\n";
for (int i = 0; i < maxStudents; i++) {
cout << "Roll No: " << students[i].rollNo << "\n";
cout << "Name: " << students[i].name << "\n";
cout << "SGPA: " << students[i].sgpa << "\n";
cout << "-----------------------------------\n";
}
return 0;
}