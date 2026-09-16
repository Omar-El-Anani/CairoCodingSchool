



#include <iostream>

#include <algorithm>

#include<bits/stdc++.h>

#define ll long long

using namespace std;

class Abs {
    public:
    virtual void stock_value()=0;
};


class Item  {
    protected:
    string name;
    ll quantity;
    double price;

    public:


    Item(string name, ll quantity, double price) {
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    string getName() {
        return name;
    }

    ll getQuantity() {
        return quantity;
    }

    double getPrice() {
        return price;
    }

    void setQuantity(ll newQuantity) {
        quantity += newQuantity;
    }




};

class Inventory  : public Abs {
    private:
    vector<Item> Items;



    public:



    void addItem(string name, ll quantity, double price) {

        Items.push_back(Item(name, quantity, price));

        cout<<"Item Added Successfully !"<<endl;

    }

    void removeItem(string name) {
        bool found = false;

        for (int i = 0; i < Items.size(); i++) {

            if (Items[i].getName()==name) {
                Items.erase(Items.begin() + i);
                found = true;
                break;
            }

        }
        if (!found) {
            cout << "Item does not exist!" << endl;
        }else {
            cout << "Item removed!" << endl;
        }

    }

    void updateQuantity(string name, ll quantity) {
        for (int i = 0; i < Items.size(); i++) {
            if (Items[i].getName()==name) {


                    if (quantity>0 && Items[i].getQuantity()>=0) {
                        Items[i].setQuantity(quantity);
                        cout<<"Quantity updated!"<<endl;
                        cout<<"New Quantity: "<<Items[i].getQuantity()<<endl;
                        break;
                    }else if (quantity<0 && Items[i].getQuantity() >= quantity*-1) {
                        Items[i].setQuantity(quantity);
                        cout<<"Quantity updated!"<<endl;
                        cout<<"New Quantity: "<<Items[i].getQuantity()<<endl;
                        break;
                    }else  {
                        cout<<"The current quantity is insufficient !"<<endl;
                        break;
                    }


            }

        }
    }

    void SearchItem(string name) {
        bool found = false;
        for (int i = 0; i < Items.size(); i++) {
            if (Items[i].getName()==name) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item does not exist!" << endl;
        }else {
            cout << "Item found!" << endl;
        }
    }

    void stock_value() {
        double Total=0;

        for (int i = 0; i < Items.size(); i++) {
            cout<<"Item : "<<Items[i].getName()<<" || "<<"Qty : "<<Items[i].getQuantity();
            cout<<" || "<<"Price : "<<Items[i].getPrice()<<" || "<<"Total : "<<Items[i].getQuantity() * Items[i].getPrice()<<endl;
            Total+=Items[i].getPrice()*Items[i].getQuantity();

        }
        cout<<"Total Prices For all Items: "<<Total<<endl;


    }




};



int main() {

    Inventory I;



    while(true) {

        cout<<"=====Inventory Management System====="<<endl;
        cout<<"1. Add Item"<<endl;
        cout<<"2. Remove Item"<<endl;
        cout<<"3. Update Quantity"<<endl;
        cout<<"4. Search Item"<<endl;
        cout<<"5. Display Inventory"<<endl;
        cout<<"6. Exit"<<endl;

        int answer;

        cout<<"Enter your choice : ";
        cin>>answer;
        cin.ignore();

        if (answer==1) {

            string Iname;
            cout<<"Enter Item Name : ";
            getline(cin, Iname);

            ll Iquantity;
            cout<<"Enter Item Quantity : ";
            cin>>Iquantity;
            cin.ignore();

            double Iprice;
            cout<<"Enter Item Price : ";
            cin>>Iprice;
            cin.ignore();

            I.addItem(Iname, Iquantity, Iprice);



        }

        else if (answer==2) {
            string Iname;
            cout<<"Enter Item Name : ";
            getline(cin, Iname);

            I.removeItem(Iname);
        }
        else if (answer==3) {
            string Iname;
            cout<<"Enter Item Name : ";
            getline(cin, Iname);

            ll Changequantity;
            cout<<"Enter Quantity Change : ";
            cin>>Changequantity;
            cin.ignore();

            I.updateQuantity(Iname, Changequantity);

        }
        else if (answer==4) {
            string Iname;
            cout<<"Enter Item Name : ";
            getline(cin, Iname);

            I.SearchItem(Iname);
        }
        else if (answer==5) {

            I.stock_value();

        }else if (answer==6) {
            cout<<"GoodBye!"<<endl;
            return 0;
        }else {
            cout<<"Invalid Input !"<<endl;
        }

    }
}

