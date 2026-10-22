//
// Created by El3nany on 10/22/2026.
//

#include "System.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void System::addStudent(string name , int id, float grade) {
    students.push_back(new Student(name, id, grade));
}
void System::DisplayStudent() {
    for (int i = 0; i < students.size(); i++) {
        cout << students.at(i)->getId() << " ";
        cout << students.at(i)->getName() << " ";
        cout << students.at(i)->getGrade() << " ";
        cout << endl;
    }
}

void System::BubbleSortGrade() {
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if ( students.at(j)->getGrade() < students.at(j + 1)->getGrade() ) {
                swap(students.at(j), students.at(j + 1) );
            }
        }
    }
    cout<<endl<<"Students are sorted by their grades ! "<<endl;

    for (int i = 0; i < students.size(); i++) {
        cout<<i+1<<"- "<<students.at(i)->getName() <<" "<<students.at(i)->getGrade() <<" ";
        cout<<endl;
    }

    cout<<endl;
    cout<<"The Highest Grade: "<<students.at(0)->getName()<<" "<<students.at(0)->getGrade()<<endl;
    cout<<"The Lowest Grade: "<<students.at(students.size()-1)->getName()<<" "<<students.at(students.size()-1)->getGrade()<<endl;

}

void System::LinearSearchName(string target) {
    bool found = false;
    int index = 0;
    int comparsion = 0;
    for (int i = 0; i < students.size(); i++) {
        comparsion++;
        if (students.at(i)->getName() == target) {
            found = true;
            index = i;
            break;
        }
    }
    if (found) {
        cout<<"Student found ! "<<endl;
        cout<<"it takes "<<comparsion<<" rounds to find the student !"<<endl;
        cout << students.at(index)->getName() << " ";
        cout << students.at(index)->getId() << " ";
        cout << students.at(index)->getGrade() << endl;
    }else {
        cout<<"Student not found ! "<<endl;
    }
}

void System::BinarySearchId(int target) {
    //Bubble Sort By ID FIRST
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if ( students.at(j)->getId() > students.at(j + 1)->getId() ) {
                swap(students.at(j), students.at(j + 1) );
            }
        }
    }

    int left = 0;
    int right = students.size() - 1;
    bool found = false;
    int index = 0;
    int comparsion = 0;

    while (left <= right) {
        comparsion++;
        int mid = left + (right - left) / 2;

        if (students.at(mid)->getId() == target) {
            index = mid;
            found = true;
            break;
        }
        else if (students.at(mid)->getId() < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (found) {
        cout<<"Student found ! "<<endl;
        cout<<"it takes "<<comparsion<<" rounds to find the student !"<<endl;
        cout << students.at(index)->getName() << " ";
        cout << students.at(index)->getId() << " ";
        cout << students.at(index)->getGrade() << endl;
    }else {
        cout<<"Student not found ! "<<endl;
    }

}

double System::TotalGrades(int n) {
    if (n == 0) { // base condition
        return 0;
    }
    return students.at(n - 1)->getGrade() + TotalGrades(n - 1); //recursive case
}

double System::AverageGrade(double t) {
    if (t == 0 || students.size() == 0) {
        return 0;
    }
    return t / students.size();
}

System::~System() {
    for (int i = 0; i < students.size(); i++) {
        delete students.at(i);
    }
    students.clear();
}
