#include <iostream>
#include <string>
struct Student {
int rollNo;
std::string name;
float sgpa;
};
void swap(Student& a, Student& b) {
Student temp = a;
a = b;
b = temp;
}
int partition(Student arr[], int low, int high) {
float pivot = arr[high].sgpa;
int i = (low - 1);
for (int j = low; j <= high - 1; j++) {
if (arr[j].sgpa >= pivot) {
i++;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[high]);
return (i + 1);
}
void quickSort(Student arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
int main() {
const int numStudents = 15;
Student students[numStudents];
// Accept input from the user
for (int i = 0; i < numStudents; i++) {
std::cout << "Enter details for student " << i + 1 << ":" << std::endl;
std::cout << "Roll No: ";
std::cin >> students[i].rollNo;
std::cout << "Name: ";
std::cin.ignore(); // Clear the newline character from previous input
std::getline(std::cin, students[i].name);
std::cout << "SGPA: ";
std::cin >> students[i].sgpa;
}
quickSort(students, 0, numStudents - 1);
std::cout << "\nTop 10 students:\n\n";
for (int i = 0; i <= 2; i++) {
std::cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " <<
students[i].sgpa << std::endl;
std::cout<<"\n";
}
return 0;
}