#include <iostream>
using namespace std;


class Person {
    protected:
    int id;
    string name, address;
    float age;

    public:

    //Pure virtual function
    virtual void displayInfo()=0;
};

class Doctor : public Person {

    private:

    string spec;

    public:

    Doctor(int id, string name,string address, float age, string spec)
    {
        this->id = id;
        this->name = name;
        this->address=address;
        this->age=age;
        this->spec=spec;

    }

    void displayInfo() {

        cout<<"Doctor ID : "<<id<<endl;
        cout<<"Doctor Name : "<<name<<endl;
        cout<<"Doctor Address : "<<address<<endl;
        cout<<"Doctor Age : "<<age<<endl;
        cout<<"Doctor Spec : "<<spec<<endl;

    }

};

class Patient : public Person {

    private:
    string treat;
    string disease;

    public:
    Patient(int id, string name, string address, float age, string treat, string disease) {
        this->id = id;
        this->name = name;
        this->address = address;
        this->age = age;
        this->treat = treat;
        this->disease = disease;
    }

    void displayInfo() {
        cout<<"Patient ID : "<<id<<endl;
        cout<<"Patient Name : "<<name<<endl;
        cout<<"Patient Address : "<<address<<endl;
        cout<<"Patient Age : "<<age<<endl;
        cout<<"Patient Treat : "<<treat<<endl;
        cout<<"Patient Disease : "<<disease<<endl;
    }

};

class Hospital {
    private:

    Doctor *Doctors[100]; // array of doctors      pointer to doctor كل عنصر عباره عن       objects وبتخزن عناوين

    Patient *Patients[100]; // array of patient bey4awr 3la obj ,, 100 obj,, kul obj feh details 1 patient

    int Dcount;
    int Pcount;

    public:

    Hospital() {
        Dcount=0;
        Pcount=0;
    }

    void addDoctor(int id, string name, string address, float age, string spec) {

        Doctors[Dcount]= new Doctor(id,name,address,age,spec); // ببعت في ال heap بيانات اول دكتور بالترتيب  doctor object new in heap , من خلال constructor
        Dcount++; // عشان يتحرك على obj جديد فاضي يحط فيه تاني بعديه

    }

    void addPatient(int id, string name, string address,float age, string treat , string disease) {

        Patients[Pcount]= new Patient(id , name , address , age , treat , disease);
        Pcount++;
    }


    void displayDoctors() {
        cout<<"----------Doctors ----------"<<endl;

        for(int i=0;i<Dcount;i++) {

            Doctors[i]->displayInfo();

            cout<<"---------------------------"<<endl;

        }
    }

        void displayPatients() {

            cout<<"-----------Patients ----------"<<endl;

            for(int i=0;i<Pcount;i++) {

                Patients[i]->displayInfo();

                cout<<"---------------------------"<<endl;

            }
        }

    };


int main() {
    Hospital H;

    H.addDoctor(1,"Ahmed","Cairo",32,"bones");
    H.addDoctor(2,"Mohamed","Giza",44,"brain");
    H.addDoctor(3,"Magdy","Alex",50,"heart");

    H.addPatient(1,"Amr","Cairo",25,"powercaps","soda3");
    H.addPatient(2,"Mahmoud","Cairo",60,"augmantien","2alb");

    H.displayDoctors();

    H.displayPatients();


}