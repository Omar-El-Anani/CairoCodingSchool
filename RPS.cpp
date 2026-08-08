#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main() {
    string arr[3] = {"Rock","Paper","Scissors"};

    srand(time(0));

    int x;

    int CompWin=0;

    int PlayerWin=0;

    int rounds=0;

    while (rounds<5){
        cout<<"Choose number from (1-3) "<<endl<<"1-Rock "<<endl<<"2-Paper "<<endl<<"3-Scissors "<<endl;

        cin>>x;

        if(x<1||x>3) {
            cout<<"Wrong input! , Try Again "<<endl;

            continue;
        }
        rounds++;

        int randomIndex = rand() % 3;

        string PlayerChoice=arr[x-1];

        string ComputerChoice=arr[randomIndex];

        if(PlayerChoice =="Rock") {
            if(PlayerChoice==ComputerChoice) {
                cout<<"You Are Rock and I am Rock , it's Tie"<<endl;

            }else if(ComputerChoice=="Paper") {
                cout<<"You Are Rock and I am Paper , I Win"<<endl;
                CompWin++;

            }else if(ComputerChoice=="Scissors") {
                cout<<"You Are Rock and I am Scissors , You Win"<<endl;
                PlayerWin++;
            }
        }else if(PlayerChoice =="Paper") {
            if(ComputerChoice=="Rock") {
                cout<<"You Are Paper and I am Rock , You Win"<<endl;
                PlayerWin++;


            }else if(PlayerChoice==ComputerChoice) {
                cout<<"You Are Paper and I am Paper , It's Tie"<<endl;

            }else if(ComputerChoice=="Scissors") {
                cout<<"You Are Paper and I am Scissors , I Win"<<endl;
                CompWin++;
            }
        }else if(PlayerChoice =="Scissors") {
            if(ComputerChoice=="Rock") {
                cout<<"You Are Scissors and I am Rock , I Win"<<endl;
                CompWin++;

            }else if(ComputerChoice=="Paper") {
                cout<<"You Are Scissors and I am Paper , You Win"<<endl;
                PlayerWin++;

            }else if(PlayerChoice==ComputerChoice) {
                cout<<"You Are Scissors and I am Scissors , It's Tie"<<endl;

            }
        }

    }
    if(CompWin>PlayerWin) {
        cout<<"Computer Wins "<<CompWin<<" Rounds and You Wins "<<PlayerWin<<" Rounds "<<endl<<"Computer Wins The Game";
    }else if(PlayerWin>CompWin) {
        cout<<"Computer Wins "<<CompWin<<" Rounds and You Wins "<<PlayerWin<<" Rounds "<<endl<<"You Wins The Game";
    }else {
        cout<<"Computer Wins "<<CompWin<<" Rounds and You Wins "<<PlayerWin<<" Rounds "<<endl<<"The Game End With Tie";
    }

    return 0;
}