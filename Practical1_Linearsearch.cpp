#include <iostream>
#include <string>
struct Student {
int rollNo;
std::string name;
double sgpa;
};
int main() {
const int maxStudents = 5;
Student students[maxStudents];
for (int i = 0; i < maxStudents; i++) {
std::cout << "Enter details for student " << i + 1 << ":\n";
students[i].rollNo = i + 1;
std::cout << "Name: ";
std::cin >> students[i].name;
std::cout << "SGPA: ";
std::cin >> students[i].sgpa;
}
double searchSGPA;
bool found = false;
std::cout << "\nEnter SGPA to search for: ";
std::cin >> searchSGPA;
std::cout << "\nStudents with SGPA : " << searchSGPA << "\n";
for (int i = 0; i < maxStudents; i++) {
if (students[i].sgpa == searchSGPA) {
std::cout << "\nRoll No: " << students[i].rollNo << " , Name: " << students[i].name << " , SGPA: "
<< students[i].sgpa << "\n";
found = true;
}
}
if (!found) {
std::cout << "\nNo students found with SGPA " << searchSGPA << "\n";
}
return 0;
}