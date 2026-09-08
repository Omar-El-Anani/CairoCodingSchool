#include <iostream>
#include <vector>

using namespace std;

class Book {
    private:
    string title;
    string author;
    bool available;

    public:

    Book(string title, string author) {
        this->title = title;
        this->author = author;
        available = true;
    }

    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    bool isAvailable() {
        return available;
    }
    void setAvailable(bool available) {
        this->available = available;
    }

};

class Member {
    private:
    string memberName;
    vector<string> bBooks;

    public:

    Member(string memberName) {
        this->memberName = memberName;
    }

    string getMemberName() {
        return memberName;
    }
    void BorrowBook(string bookName) {
        bBooks.push_back(bookName);
    }

    void returnBook(string bookName) {

        for (int i = 0; i < bBooks.size(); i++) {
            if (bBooks[i] == bookName) {
                bBooks.erase(bBooks.begin() + i);
                break;
            }
        }

    }


    bool hasBorrowedBook(string bookName) {

        for (int i = 0; i < bBooks.size(); i++) {

            if (bBooks[i] == bookName) {
                return true;
            }
        }

        return false;
    }



};

int main() {

    vector<Member> members;

    members.push_back(Member("John"));
    members.push_back(Member("Omar"));
    members.push_back(Member("Ali"));


    vector<Book> books;

    while (true) {
        cout<<"=== Library Management System ==="<<endl<<"1. Add Book"<<endl<<"2. Remove Book"<<endl<<"3. Borrow Book"<<endl<<"4. Return Book"<<endl<<"5. Search Book"<<endl<<"6. Display All Books"<<endl<<"7. Exit"<<endl;
        cout<<"Choose an option : ";

        int option;
        cin>>option;
        cin.ignore();

        if (option==1) {

            cout<<endl<<"Enter Book Title : ";
            string title;
            getline(cin, title);
            string author;
            cout<<endl<<"Enter Book Author : ";
            getline(cin, author);

            Book B(title,author);

            books.push_back(B);

            cout<<endl<<"Book "<<"'"<<title<<"'"<<" Added Successfully!"<<endl;


        }
        else if (option==2) {
            cout<<endl<<"Enter Book Title : ";
            string title;
            getline(cin, title);

            bool found = false;

            for (int i=0;i<books.size();i++) {
                if (books[i].getTitle()==title) {
                    found = true;
                    if (books[i].isAvailable()) {
                        books.erase(books.begin()+i);
                        cout<<"Book "<<"'"<<title<<"'"<<" is Removed Successfully!"<<endl;
                        break;
                    }else {
                        cout<<"Book "<<"'"<<title<<"'"<<" is Borrowed and Can't Removed !"<<endl;
                        break;
                    }
                }

            }
            if (found==false) {
                cout<<"Book "<<"'"<<title<<"'"<<"not in the Library !"<<endl;
            }
        }
        else if (option==3) {
            cout<<endl<<"Enter Your Name : ";
            string name;
            getline(cin, name);

            cout<<endl<<"Enter Book Title to borrow : ";
            string title;
            getline(cin, title);

            bool mFound=false;
            bool bFound=false;
            bool bAvaliable=false;

            int memindx;
            int bindx;

            for (int i=0;i<members.size();i++) {
                if (members[i].getMemberName()==name) {
                    mFound=true;
                    memindx=i;
                    break;
                     }
                    }

            if (mFound==true) {
                for (int j=0;j<books.size();j++) {
                    if (books[j].getTitle()==title) {
                        bFound=true;
                        bindx=j;
                        if (books[j].isAvailable()==true) {
                            bAvaliable=true;
                            members[memindx].BorrowBook(title);
                            books[j].setAvailable(false);
                            cout<<name<<" is Borrowed "<<title<<" Successfully ! "<<endl;
                            break;

                        }

                    }
                }
                if (bFound==true && bAvaliable == false) {

                        cout<<"Sorry ,"<<title<<"is not Available"<<endl;

                }
                else if (bFound==false) {


                        cout<<"Sorry ,"<<title<<" is not in The Library !"<<endl;


                }



            }else {
                Member m(name);
                members.push_back(m);
                memindx=members.size()-1;


                for (int i=0;i<books.size();i++) {
                    if (books[i].getTitle()==title) {
                        bFound=true;
                        bindx=i;
                        if (books[i].isAvailable()==true) {
                            bAvaliable=true;
                            members[memindx].BorrowBook(title);
                            books[i].setAvailable(false);
                            cout<<name<<" is Borrowed "<<title<<" Successfully ! "<<endl;
                            break;

                        }

                    }
                }

                if (bFound==true && bAvaliable == false) {

                    cout<<"Sorry ,"<<title<<"is not Available"<<endl;


                }else if (bFound==false) {

                    cout<<"Sorry ,"<<title<<" is not in The Library !"<<endl;


                }

            }




        }

        else if (option==4) {
            cout<<endl<<"Enter Your Name : ";
            string name;
            getline(cin, name);

            cout<<endl<<"Enter Book Title to return : ";
            string title;
            getline(cin, title);

            int memindx=0;
            int bindx=0;
            int isaval=0;

            bool mFound=false;
            bool bFound=false;

            for (int i=0;i<members.size();i++) {
                if (members[i].getMemberName()==name) {
                    mFound=true;
                    memindx=i;
                    break;

                }
            }
            for (int j=0;j<books.size();j++) {
                if (books[j].getTitle()==title) {
                    bFound=true;
                    bindx=j;
                    if (books[j].isAvailable()==false) {
                        isaval=0;
                        break;
                    }else {
                        isaval=1;
                        break;
                    }
                }
            }

            if ( mFound==true && bFound==true && isaval==1) {
                cout<<"Ops ! "<<title<<" is not borrowed by anyone ! "<<endl;
            }else if (mFound==true && bFound==false) {
                cout<<"Sorry ,"<<title<<" is not in the Library !"<<endl;
            }else if (mFound==false) {
                cout<<"there is no one with this name borrowed this book ! "<<endl;
            }else if (mFound==true && bFound==true && isaval==0) {
                bool borrowedByMember=members[memindx].hasBorrowedBook(title);

                if (borrowedByMember==true) {



                    members[memindx].returnBook(title);

                    books[bindx].setAvailable(true);

                    cout<<title<<" is Returned "<<" Successfully ! "<<endl;

                }
                else {
                    cout<<name<<" is not borrow this book !"<<endl;
                }
            }


        }
        else if (option==5) {
            cout<<endl<<"Enter Book Title : ";
            string title;
            getline(cin, title);

            bool bFound=false;

            for (int i=0;i<books.size();i++) {
                if (books[i].getTitle()==title) {
                    bFound=true;
                    break;
                }
            }
            if (bFound==true) {
                cout<<"Yes ,"<<title<<" is in the library !"<<endl;
            }else {
                cout<<"Sorry ,"<<title<<" is not in the Library !"<<endl;
            }
        }
        else if (option==6) {

            for (int i=0;i<books.size();i++) {

                cout<<"Title : "<<books[i].getTitle()<<" | "<<"Author : "<<books[i].getAuthor()<<" | "<<"Status : ";
                if (books[i].isAvailable()==true) {
                    cout<<"Book is Available"<<endl;
                }else {
                    cout<<"Book is Borrowed"<<endl;
                }
            }

        }else if (option==7) {
            cout<<"Goodbye !"<<endl;
            return 0;
        }else {
            cout<<"invalid option !"<<endl;
        }







    }
}