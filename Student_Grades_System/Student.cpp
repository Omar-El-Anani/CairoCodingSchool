#include "Student.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;



Student::Student(string name, int id, float grade) {
    this->name = name;
    this->id = id;
    this->grade = grade;
}
void Student::print() {
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Grade: " << grade << endl;
}
string Student::getName() {
    return name;
}
int Student::getId() {
    return id;
}
float Student::getGrade() {
    return grade;
}
