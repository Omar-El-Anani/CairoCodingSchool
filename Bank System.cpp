#include <iostream>
using namespace std;

class Account {
private:

    string OwnerName;

    double OwnerBalance;

public:

    Account(string OwnerName , double OwnerBalance = 0) {

        this->OwnerName = OwnerName;

        this->OwnerBalance = OwnerBalance;

    }

    void deposit(double amountD) {

        if (amountD > 0) {
            OwnerBalance += amountD;

            cout << OwnerName << " deposited $" << amountD <<". New Balance : $" << OwnerBalance << endl;

            cout<<"____________________";
        }else {

            cout<<"Invalid amount !"<<endl<<"____________________";

        }

    }

    void withdraw(double amountW) {

        if(amountW <= OwnerBalance && amountW > 0) {

            OwnerBalance -= amountW;

            cout<< OwnerName <<" withdrew $"<< amountW <<". Current Balance : $" << OwnerBalance<<endl;

            cout<<"____________________";
        }
        else if (amountW > OwnerBalance) {
            cout<<"Error: insufficient funds. Current balance: $"<<OwnerBalance<<endl;

            cout<<"____________________";
        }else {
            cout<<"Invalid amount !"<<endl;
            cout<<"____________________";

        }
    }



    double checkBalance() {

        return OwnerBalance;

    }



};



int main() {

    Account user1("Omar",5000);



    while(true) {

        cout <<"=== Bank System ==="<<endl<<"1. Deposit"<<endl<<"2. Withdraw"<<endl<<"3. Check Balance"<<endl<<"4. Exit"<<endl;

        cout <<"Choose an option : ";

        int x;

        cin >> x;

        if(x==1) {

            cout<<endl<<"Enter amount to deposit: ";

            double amountN;
            cin >> amountN;

            user1.deposit(amountN);

            cout<<endl;

        }
        else if(x==2) {
            cout<<endl<<"Enter amount to withdraw: ";

            double amountN;
            cin >> amountN;

            user1.withdraw(amountN);

            cout<<endl;

        }
        else if(x==3) {



            cout<<endl<<"Current Balance: $"<<user1.checkBalance()<<endl;

            cout<<"____________________"<<endl;


        }else if (x==4) {

            cout<<endl<<"Goodbye ! "<<endl;

            return 0;

        }
        else {

            cout<<endl<<"Invalid Choice"<<endl;

        }

    }









}