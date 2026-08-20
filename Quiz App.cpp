#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Question {
    string text;
    vector<string> options;
    char correctAnswer;
};

class App {

    string userName;
    vector<Question> Quiz;
    int score=0;


    public:

App() {
    cout << "=================================" << endl;
    cout << "            QUIZ APP             " << endl;
    cout << "=================================" << endl;
}

    void entname(string user1) {
        userName = user1;
    }
    string getName() {
    return userName;
}

    void display() {
    cout<<"1. Start"<<endl;
    cout<<"2. Quit"<<endl;
}


void LoadQuest() {
    Question Q1;
    Q1.text="What is the capital of Egypt ? ";
    Q1.options.push_back("a) Alexandria *** b) Cairo *** c) Giza *** d) Aswan");
    Q1.correctAnswer = 'b';
    Quiz.push_back(Q1);
    Question Q2;
    Q2.text="What is the result of 3 x 3 ? ";
    Q2.options.push_back("a) 6 *** b) 12 *** c) 9 *** d) 15");
    Q2.correctAnswer = 'c';
    Quiz.push_back(Q2);
    Question Q3;
    Q3.text="Who's The Owner Of Album -Tammaly maak- ? ";
    Q3.options.push_back("a)Amr Diab *** b) Tamer Hosny *** c) Ramy Sabry *** d) Mohamed Mounir");
    Q3.correctAnswer = 'a';
    Quiz.push_back(Q3);
    Question Q4;
    Q4.text="What is The Most Popular Food in Egypt ? ";
    Q4.options.push_back("a) Koshri *** b) Pizza *** c) Pasta *** d) Burger");
    Q4.correctAnswer = 'a';
    Quiz.push_back(Q4);
    Question Q5;
    Q5.text="Who's The Egyptian King ? ";
    Q5.options.push_back("a) Omar Marmoush *** b) Mohamed Salah *** c) Mohamed Mounir *** d) Emam Ashour");
    Q5.correctAnswer = 'b';
    Quiz.push_back(Q5);
}
    void startQuiz() {
    for (int i = 0; i < Quiz.size(); i++) {
        cout << Quiz[i].text;
        cout << endl;
        cout <<Quiz[i].options[0];
        cout << endl;
        char y;
        cin >> y;
        if (y == Quiz[i].correctAnswer) {
            score++;
        }
    }

}
    int getScore() {
    return score;
}




};



int main() {
    App app;


    int x;
    app.display();
    cin>>x;
    cin.ignore();

    while (x!=1 && x!=2) {
        cout<<"     Invalid Input ! Try Again: "<<endl; cin>>x;
    }

    if (x==2) {
        cout<<"     Thanks For Playing     "<<endl;
        return 0;
    }else {
        cout<<"     Welcome Let's Play     "<<endl;
        string usnam;
        cout<<"Enter your name: "; cin >> usnam;
        app.entname(usnam);
        app.LoadQuest();
        app.startQuiz();
        cout<<"Your score is: "<<app.getScore()<<"/5"<<endl;
        cout<<"     Thanks For Playing      "<<endl;


    }
}
