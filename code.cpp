#include <iostream>
using namespace std;

class book {
public:
    string title, author;
    double price;
    int quantity;
    virtual void getdata() = 0;
    virtual void display() = 0;  
};

class fiction : public book {
public:
    void getdata() {
        cout << "________________________" << endl;
        cout << "Enter Fiction title: ";
        getline(cin, title);
        cout << "Enter Fiction author: ";
        getline(cin, author);
        cout << "Enter Fiction price: ";
        cin >> price;
        cout << "Enter Fiction quantity: ";
        cin >> quantity;
        cin.ignore();  
        cout << "______________________" << endl;
    }

    void display() {  
        cout << "..........................." << endl;
        cout << "Fiction Book - " << title << endl;
        cout << "Author   : " << author << endl;
        cout << "Price    : " << price << endl;
        cout << "Quantity : " << quantity << endl;
        cout << "______________________________" << endl;
    }
};

class nonfiction : public book {
public:
    void getdata() {
        cout << "______________________________" << endl;
        cout << "Enter NonFiction title: ";
        getline(cin, title);
        cout << "Enter NonFiction author: ";
        getline(cin, author);
        cout << "Enter NonFiction price: ";
        cin >> price;
        cout << "Enter NonFiction quantity: ";
        cin >> quantity;
        cin.ignore();
        cout << "______________________________" << endl;
    }


    void display() {
        cout << "______________________________" << endl;
        cout << "NonFiction Book - " << title << endl;
        cout << "Author   : " << author << endl;
        cout << "Price    : " << price << endl;
        cout << "Quantity : " << quantity << endl;
        cout << "______________________________" << endl;
    }
};

int main() {
    book* obj[2];
    cout << "________ Bookstore Management System!_________" << endl;

    int choice;
    for (int i = 0; i < 2; i++) {
        cout << "--------------------------" << endl;
        cout << "  1. Add Fiction Book" << endl;
        cout << "  2. Add Non-Fiction Book" << endl;
        cout << "  3. Display Book Inventory" << endl;
        cout << "  4. Exit" << endl << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            obj[i] = new fiction;
            break;
        case 2:
            obj[i] = new nonfiction;
            break;
        case 3: {
            cout << "---Bookstore Inventory---" << endl;
            for (int j = 0; j < i; j++) {
                obj[j]->display();
            }
            break;
        }
        case 4:
            cout << endl << endl;
            cout << "Thank you for using Bookstore Management System. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Using fiction as default." << endl;
            obj[i] = new fiction;
            break;
        }

        obj[i]->getdata();
    }

    for (int i = 0; i < 2; i++) {
        obj[i]->display();
    }

    // Clean up the allocated memory
    for (int i = 0; i < 2; i++) {
        delete obj[i];
    }

    return 0;
}
