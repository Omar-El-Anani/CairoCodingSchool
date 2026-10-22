//
// Created by El3nany on 10/22/2026.
//

#ifndef UNTITLED2_STUDENT_H
#define UNTITLED2_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Student {
    private:
    string name;
    int id;
    float grade;

    public:
    Student();
    Student(string name , int id , float grade);
    void print();
    string getName();
    int getId();
    float getGrade();

};

#endif //UNTITLED2_STUDENT_H