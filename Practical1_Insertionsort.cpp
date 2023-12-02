#include <iostream>
#include <string>
using namespace std;
struct Student {
int rollNo;
string name;
double sgpa;
};
void insertionSort(Student arr[], int n) {
for (int i = 1; i < n; ++i) {
Student key = arr[i];
int j = i - 1;
while (j >= 0 && arr[j].name > key.name) {
arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
int main() {
const int maxSize = 15;
Student students[maxSize];
cout << "Enter student details:" << endl;
for (int i = 0; i < maxSize; ++i) {
cout << "Student " << i + 1 << ":\n";
cout << "Roll No: ";
cin >> students[i].rollNo;
cin.ignore(); 
cout << "Name: ";
getline(cin, students[i].name);
cout << "SGPA: ";
cin >> students[i].sgpa;
}
insertionSort(students, maxSize);
cout << "\nSorted student database:\n\n";
cout << "Roll No\t\tName\t\tSGPA\n";
for (int i = 0; i < maxSize; ++i) {
cout << students[i].rollNo << "\t\t" << students[i].name << "\t\t" << students[i].sgpa << endl;
}
return 0;
}