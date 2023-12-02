
#include <iostream>
#include <string>
struct Student {
int rollNo;
std::string name;
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
void binarySearch(Student arr[], int n, const std::string& searchName) {
int left = 0, right = n - 1;
bool found = false;
while (left <= right) {
int mid = left + (right - left) / 2;
if (arr[mid].name == searchName) {
found = true;
int start = mid, end = mid;
while (start > 0 && arr[start - 1].name == searchName) {
start--;
}
while (end < n - 1 && arr[end + 1].name == searchName) {
end++;
}
std::cout << "\nStudent(s) with name " << searchName << " found:\n";
for (int i = start; i <= end; ++i) {
std::cout << "Roll No: " << arr[i].rollNo << " , Name: " << arr[i].name << " , SGPA: " << arr[i].sgpa
<< "\n";
}
break;
} else if (arr[mid].name < searchName) {
left = mid + 1;
} else {
right = mid - 1;
}
}
if (!found) {
std::cout << "\nStudent with name " << searchName << " not found.\n\n";
}
}
int main() {
const int maxSize = 15;
Student students[maxSize];
for (int i = 0; i < maxSize; ++i) {
std::cout << "\nEnter details for student " << i + 1 << ":\n\n";
students[i].rollNo = i + 1;
std::cout << "Name: ";
std::cin >> students[i].name;
std::cout << "SGPA: ";
std::cin >> students[i].sgpa;
}
insertionSort(students, maxSize);
std::string searchName;
std::cout << "\nEnter the name of the student to search for: \n";
std::cin >> searchName;
binarySearch(students, maxSize, searchName);
return 0;
}