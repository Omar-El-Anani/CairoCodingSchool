//
// Created by El3nany on 10/22/2026.
//

#ifndef UNTITLED2_SYSTEM_H
#define UNTITLED2_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
using namespace std;


class System {
    private:
    vector<Student*> students;

    public:
    void addStudent(string name , int id, float grade);
    void DisplayStudent();
    int getSize() {
        return students.size();
    }

    ~System();

    void BubbleSortGrade();

    void LinearSearchName(string target);

    void BinarySearchId(int target);

    double TotalGrades(int n);

    double AverageGrade(double t);

};


#endif //UNTITLED2_SYSTEM_H