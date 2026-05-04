#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int id;
    char name[50];
    int age;
    char course[50];
};

// Function to add student
void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(s.name, 50);

    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();

    cout << "Enter Course: ";
    cin.getline(s.course, 50);

    file.write((char*)&s, sizeof(s));
    file.close();

    cout << "Student added successfully!\n";
}

// Function to display all students
void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "No records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    while (file.read((char*)&s, sizeof(s))) {
        cout << "ID: " << s.id << endl;
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "Course: " << s.course << endl;
        cout << "-----------------------\n";
    }

    file.close();
}

// Function to search student
void searchStudent() {
    int id;
    Student s;
    bool found = false;

    cout << "Enter ID to search: ";
    cin >> id;

    ifstream file("students.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Course: " << s.course << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Student not found.\n";
}

// Function to update student
void updateStudent() {
    int id;
    Student s;
    bool found = false;

    cout << "Enter ID to update: ";
    cin >> id;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            cin.getline(s.name, 50);

            cout << "Enter new age: ";
            cin >> s.age;
            cin.ignore();

            cout << "Enter new course: ";
            cin.getline(s.course, 50);

            int pos = file.tellg() - sizeof(s);
            file.seekp(pos);

            file.write((char*)&s, sizeof(s));
            found = true;

            cout << "Record updated successfully!\n";
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Student not found.\n";
}

// Function to delete student
void deleteStudent() {
    int id;
    Student s;
    bool found = false;

    cout << "Enter ID to delete: ";
    cin >> id;

    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id != id) {
            temp.write((char*)&s, sizeof(s));
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "Record deleted successfully!\n";
    else
        cout << "Student not found.\n";
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
