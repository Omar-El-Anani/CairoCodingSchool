#include <iostream>

#include <algorithm>

#include<bits/stdc++.h>

#define ll long long

using namespace std;

class Abs {
    public:
    virtual void DisplayClassReport()=0;

};


class Student {
private:
    string name;
    int id;
    vector<pair<string, double>> subject_grade;

public:

    Student(string name, int id) {
        this->name =name;
        this->id = id;

    }

    string getName() {
        return name;
    }
    int getId() {
        return id;
    }

    vector<pair<string, double>> getSubjectGrade() {
        return subject_grade;
    }

    void setSubjectGrade(string subject ,double grade) {
        subject_grade.push_back({subject,grade});
    }

    void Display_Report() {
        double total = 0;
        int count = 0;
        for (int i = 0; i < subject_grade.size(); i++) {
            cout << subject_grade[i].first << ": " << subject_grade[i].second << endl;
            count++;
            total += subject_grade[i].second;
        }

        if (count == 0) {
            cout << "No grades recorded for this student yet." << endl;
            return;
        }

        double average = total / count;
        string LetterGrade;
        if (average >= 90.00 && average <= 100.00) {
            LetterGrade = "A+";
        }else if (average >= 85.00 && average <= 89.99) {
            LetterGrade = "A";
        }else if (average >= 80.00 && average <= 84.99) {
            LetterGrade = "A-";
        }else if (average >= 76.00 && average <= 79.99) {
            LetterGrade = "B+";
        }else if (average >= 72.00 && average <= 75.99) {
            LetterGrade = "B";
        }else if (average >= 68.00 && average <= 71.99) {
            LetterGrade = "B-";
        }else if (average >= 64.00 && average <= 67.99) {
            LetterGrade = "C+";
        }else if (average >= 60.00 && average <= 63.99) {
            LetterGrade = "C";
        }else if (average >=55.00 && average <= 59.99) {
            LetterGrade = "C-";
        }else if (average >= 50.00 && average <= 54.99) {
            LetterGrade = "D";
        }else if ( average>=0.00 && average <= 49.99) {
            LetterGrade = "F";
        }

        cout<<"Average: "<<average<<" || "<<"Grade: "<<LetterGrade<<endl;

    }

};

class StudentSystem : public Abs {
    private:
    vector<Student> students;

    public:

    void AddStudent(string name, int id) {
    students.push_back(Student(name, id));


}

    void addGrade(int id, string subject,double grade) {

    bool found = false;
    int indx;

    for (int i = 0; i < students.size(); i++) {
        if (students.at(i).getId() == id) {
            found = true;
            indx = i;
            break;
        }
    }
    if (!found) {
        cout<<"Student not found !"<<endl;
    }else {
        students[indx].setSubjectGrade(subject, grade);
        cout<<"Grade Added Successfully !"<<endl;

    }
}
    void DisplayClassReport() {
        cout<<"     =====Whole Class Report=====     "<<endl;
        for (int i = 0; i < students.size(); i++) {
            cout <<"ID : " <<students[i].getId()<<" || "<<"Student Name : "<<students[i].getName()<<endl;
            students[i].Display_Report();
        }
    }



};



int main() {
StudentSystem S;

    while (true) {
        cout<<"     ===== Student Grades System =====     "<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Record Grade"<<endl;
        cout<<"3. Display Report"<<endl;
        cout<<"4. Exit"<<endl;
        int input;
        cout<<"Enter your choice: ";
        cin>>input;
        cin.ignore();

        if (input == 1) {
            string name;
            cout<<"Enter Student Name: ";
            getline(cin, name);
            cout<<endl;

            int id;
            cout<<"Enter Student ID: ";
            cin>>id;
            cin.ignore();
            cout<<endl;

            S.AddStudent(name, id);

            cout<<"Student Added Successfully !"<<endl;

        }else if (input == 2) {
            int id;
            cout<<"Enter Student ID: ";
            cin>>id;
            cin.ignore();
            cout<<endl;

            string subject;
            cout<<"Enter Student Subject : ";
            getline(cin, subject);
            cout<<endl;

            double grade;
            cout<<"Enter Student Grade: ";
            cin>>grade;
            cin.ignore();
            cout<<endl;

            S.addGrade(id, subject, grade);

        }
        else if (input == 3) {
            S.DisplayClassReport();
        }
        else if (input == 4) {
            cout<<"GoodBye!"<<endl;
            return 0;
        }
        else {
            cout<<"Wrong Choice!"<<endl;
        }
    }


}



