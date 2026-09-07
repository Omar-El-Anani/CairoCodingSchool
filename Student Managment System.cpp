#include <iostream>
#include <vector>

using namespace std;

class Student {
    private:
    string name;
    vector<string> courses;   // vector gwah courses l  one student

    public:

    Student(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void addCourses(string course) {
        courses.push_back(course);
    }

    void deleteCourses(string course) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i]==course) {
                courses.erase(courses.begin() + i);
                break;
            }
        }
    }

    void getCourse() {
        for (int i = 0; i < courses.size(); i++) {
            cout<<courses[i];
            cout<<endl;
        }
    }





};



int main() {

    vector<Student> students; // vector gwah objects mn class Student ,, kul object 4ayl one name only &  vector of courses

    while (true) {
        cout << "=== Student Management System ==== " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Add Course to student" << endl;
        cout << "4. Delete Course from student" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        int x;
        cin >> x;
       cin.ignore();

        if (x == 1) {
            cout<<endl;
            cout << "Enter Student name : ";
            string name;
            getline(cin, name);
            Student s(name);
            students.push_back(s);
            cout << endl;
            cout<<"Student Added Successfully!"<<endl;
        }else if (x == 2) {
            cout<<endl;
            cout << "Enter Student name : ";
            string name;
            getline(cin, name);
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getName()==name) {
                    students.erase(students.begin() + i);
                    cout<<endl;
                    cout<<"Student is deleted"<<endl;
                    break;
                }

            }
        }else if (x == 3) {
            cout<<endl;
            cout << "Enter Student name : ";
            string name;
            getline(cin, name);
            cout<<endl;
            cout<<"Enter Course name : ";
            string courseName;
            getline(cin, courseName);
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getName()==name) {
                    students[i].addCourses(courseName);
                    cout<<endl;
                    break;

                }

            }
            cout<<"Course : "<<courseName<<" is Added Successfully to "<<name<<endl;
        }else if (x == 4) {
            cout<<endl;
            cout << "Enter Student name : ";
            string name;
            getline(cin, name);
            cout<<endl;
            cout<<"Enter Course name : ";
            string courseName;
            getline(cin, courseName);
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getName()==name) {
                    students[i].deleteCourses(courseName);
                    cout<<endl;
                    break;
                }
            }
            cout<<"Course : "<<courseName<<" is Deleted Successfully!"<<endl;
        }else if (x == 5) {
            cout<<endl;
            for (int i = 0; i < students.size(); i++) {
                cout<<"Student name : ";
                cout<<students[i].getName();
                cout<<endl;
                cout<<"Courses : ";
                students[i].getCourse();
                cout<<endl;
            }
        }else if (x == 6) {
            cout<<endl;
            cout << "Goodbye! " << endl;
            return 0;
        }
    }
}