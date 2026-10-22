
#include<bits/stdc++.h>
#include "Student.h"
#include "System.h"

#define ll long long

using namespace std;


#include <string>


void showMenu() {
    cout << "\n=========================================\n";
    cout << "       STUDENT GRADES SYSTEM             \n";
    cout << "=========================================\n";
    cout << "1. Add a New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Sort Students by Grade & Show Ranks/Highest/Lowest\n";
    cout << "4. Search Student by Name \n";
    cout << "5. Search Student by ID \n";
    cout << "6. Show Class Total & Average Grades \n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    System sys;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            float grade;

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Grade: ";
            cin >> grade;

            sys.addStudent(name, id, grade);
            cout << "-> Student added successfully!\n";
        }
        else if (choice == 2) {
            cout << "\n--- All Students List ---\n";
            cout << "ID   | Name                 | Grade \n";
            cout << "------------------------------------\n";
            sys.DisplayStudent();
        }
        else if (choice == 3) {
            sys.BubbleSortGrade();
        }
        else if (choice == 4) {
            string searchName;
            cout << "Enter student name to search: ";
            cin.ignore();
            getline(cin, searchName);
            sys.LinearSearchName(searchName);
        }
        else if (choice == 5) {
            int searchId;
            cout << "Enter student ID to search: ";
            cin >> searchId;
            sys.BinarySearchId(searchId);
        }
        else if (choice == 6) {

            double total = sys.TotalGrades(sys.getSize());
            double avg = sys.AverageGrade(total);
            cout << "\n--- Statistics (Recursion) ---\n";
            cout << "Total Grades: " << total << endl;
            cout << "Class Average: " << avg << endl;
        }
        else if (choice == 7) {
            cout << "Exiting program. Good luck\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}