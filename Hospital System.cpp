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

    string getDocName() {
        return name;
    }

};

class Patient : public Person {

    private:
    string itsDoc;
    string disease;

    public:
    Patient(int id, string name, string address, float age, string itsDoc="There is no doctor with the patient yet." , string disease="We don't know what the illness is yet.") {
        this->id = id;
        this->name = name;
        this->address = address;
        this->age = age;
        this->itsDoc = itsDoc;
        this->disease = disease;
    }

    void displayInfo() {
        cout<<"Patient ID : "<<id<<endl;
        cout<<"Patient Name : "<<name<<endl;
        cout<<"Patient Address : "<<address<<endl;
        cout<<"Patient Age : "<<age<<endl;
        cout<<"Patient Disease : "<<disease<<endl;
        cout<<"The Doctor Treating the Patient : "<<itsDoc<<endl;
    }

    string getPetaName() {
        return name;
    }

    void setitsDoc(string itsDoc) {
        this->itsDoc = itsDoc;
    }

};

class Hospital {
    private:

    Doctor *Doctors[100]; // array of doctors      pointer to doctor كل عنصر عباره عن       objects وبتخزن عناوين

    Patient *Patients[100]; // array of patient bey4awr 3la obj ,, 100 obj,, kul obj feh details 1 patient

    int Dcount;
    int Pcount;
    bool Found1=false;
    bool Found2=false;

    public:

    Hospital() {
        Dcount=0;
        Pcount=0;
    }

    void addDoctor(int id, string name, string address, float age, string spec) {

        Doctors[Dcount]= new Doctor(id,name,address,age,spec); // ببعت في ال heap بيانات اول دكتور بالترتيب  doctor object new in heap , من خلال constructor
        Dcount++; // عشان يتحرك على obj جديد فاضي يحط فيه تاني بعديه

    }

    void addPatient(int id, string name, string address,float age, string itsDoc , string disease) {

        Patients[Pcount]= new Patient(id , name , address , age , itsDoc , disease);
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



    void searchDoctor(string Dname) {

        for(int i=0;i<Dcount;i++) {
            if (Doctors[i]->getDocName()==Dname) {
                Found1 = true;
                break;
            }

        }

    }

    void searchPatient(string Pname) {
        for(int i=0;i<Pcount;i++) {
            if (Patients[i]->getPetaName()==Pname) {
                Found2 = true;
                break;
            }
        }
    }





    Doctor* searchDoctor2(string Dname) {

        for(int i=0;i<Dcount;i++) {
            if (Doctors[i]->getDocName()==Dname) {
                return Doctors[i];
            }

        }
        return nullptr;

    }










    Patient* searchPatient2(string Pname) {
        for(int i=0;i<Pcount;i++) {
            if (Patients[i]->getPetaName()==Pname) {
                return Patients[i];
            }
        }
        return nullptr;
    }




    void setF1() {
        Found1=false;
    }
    bool fff() {
        if (Found1) {
            return true;
        }else {
            return false;
        }
    }

    void setF2() {
        Found2=false;
    }
    bool fff2() {
        if (Found2) {
            return true;
        }else {
            return false;
        }
    }

    };


int main() {
    Hospital H;

    H.addDoctor(551 , "Dr.Mahmoud" ,"Nasr City", 44 , "Orthopedics");
    H.addDoctor(552 , "Dr.Mona" ,"El Zamalek", 37 , "Brain");
    H.addDoctor(553 , "Dr.Mazen" ,"El Manial", 31 , "Surgery");
    H.addDoctor(554 , "Dr.Ali" ,"El Sayeda Zainab", 42 , "Neurology");
    H.addDoctor(555 , "Dr.Mai" ,"El Sheikh Zayed", 30 , "Ophthalmology");
    H.addDoctor(556 , "Dr.Omar" ,"Banha", 50 , "Radiology");
    H.addDoctor(557 , "Dr.Wanes" ,"Faisal El Lebeny", 48 , "Anesthesiology");


    while(true) {

        cout<<"=====Welcome to the Hospital System====="<<endl;
        cout<<"1. Add Patient"<<endl;
        cout<<"2. Assign Doctor"<<endl;
        cout<<"3. Search Patient"<<endl;
        cout<<"4. Display All Patients"<<endl;
        cout<<"5. Search Doctor"<<endl;
        cout<<"6. Display All Doctors"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice : ";

       int answer;
        cin>>answer;

        cout<<endl;

        if(answer==1) {



                int id;
                cout<<"Enter Patient ID : ";
                cin>>id;
                cin.ignore();
                cout<<endl;

                string name;
                cout<<"Enter Patient Name : ";
                getline(cin,name);
                cout<<endl;

                float age;
                cout<<"Enter Patient Age : ";
                cin>>age;
                cin.ignore();
                cout<<endl;

                string address;
                cout<<"Enter Patient Address : ";
                getline(cin,address);
                cout<<endl;

                string disease1;
                cout<<"Enter Patient Disease : ";
                getline(cin,disease1);
                cout<<endl;



                string patientDoctor;
                while(H.fff()==false) {


                    cout<<"Enter Patient Doctor : ";
                    getline(cin,patientDoctor);
                    H.searchDoctor(patientDoctor);
                    cout<<endl;
                    if(H.fff()==true) {
                        break;
                    }else {
                        cout<<endl;
                        cout<<"There's No Doctor With This Name , Try Again ! "<<endl;
                    }

                }

                H.setF1();



                H.addPatient(id,name,address,age,patientDoctor,disease1);

                cout<<"Patient Added Successfully !";
                cout<<endl;
            }
                else if(answer==2) {
                    cin.ignore();

                    string PatientName;
                    Patient *P;

                    while(true) {
                        cout<<"Enter Patient Name : ";
                        getline(cin,PatientName);
                        cout<<endl;

                        P = H.searchPatient2(PatientName);

                        if(P!=nullptr) {
                            break;
                        }else {
                            cout<<endl;
                            cout<<"There's No Patient With This Name , Try Again ! "<<endl;
                        }

                    }


                    string itsDoc;
                    while(H.fff()==false) {
                        cout<<"Enter Doctor Name : ";
                        getline(cin,itsDoc);
                        cout<<endl;

                        H.searchDoctor(itsDoc);

                        if(H.fff()==true) {
                            break;
                        }else {
                            cout<<endl;
                            cout<<"There's No Doctor With This Name, Try Again ! "<<endl;
                        }
                    }
                    H.setF1();

                    P->setitsDoc(itsDoc);

                    cout<<"Doctor Assigned Successfully!"<<endl;
                }

        else if(answer==3) {
            cin.ignore();
            string PatientName;
            Patient *P;


                cout<<"Enter Patient Name : ";
                getline(cin,PatientName);
                cout<<endl;

                P=H.searchPatient2(PatientName);
                if(P!=nullptr) {
                    cout<<"Patient is in Hospital !"<<endl;

                }else {
                    cout<<"There's no Patient With This Name in Hospital"<<endl;

                }


        }
        else if(answer==4) {
            H.displayPatients();
        }

        else if(answer==5) {

            cin.ignore();

            string DoctorName;

            Doctor *D;

            cout<<"Enter Doctor Name : ";
            getline(cin,DoctorName);
            cout<<endl;

            D=H.searchDoctor2(DoctorName);
            if(D!=nullptr) {
                cout<<"Doctor is in Hospital !"<<endl;
            }else {
                cout<<"There's no Doctor With This Name in Hospital "<<endl;
            }
        }
        else if(answer==6) {
            H.displayDoctors();
        }
        else if(answer==7) {
            cout<<"GoodBye !"<<endl;
            return 0;
        }else {
            cout<<endl;
            cout<<"Invalid Choice !"<<endl;
        }






        }



    }


