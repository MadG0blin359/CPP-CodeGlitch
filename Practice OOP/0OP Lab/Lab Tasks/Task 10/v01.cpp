#include <iostream>
using namespace std;

class dateType {
    int year;
    int month;
    int day;

    public:
    dateType(int = 0, int = 0, int = 0);
    
    int get_moth() const {
        return month;
    }

    int get_year() {
        return year;
    }

    int get_day() {
        return day;
    }

    void set_year(int y) {
        year = y;
    }

    void set_month(int m) {
        month = m;
    }

    void set_day(int d) {
        day= d;
    }

};

dateType::dateType(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

class contact {
    string name;
    int phone_number;
    string gmail;
    dateType date;

    public:
    contact(string = "", int = 0, string = "", int = 0, int = 0, int = 0);
    
    void print() {
        cout<<"Name is: "<<name<<endl;
        cout<<"Phone Number is: "<<phone_number<<endl;
        cout<<"Gmail is: "<<gmail<<endl;
        cout<<"Year of birth is: "<<date.get_year()<<endl;
        cout<<"Month of year is: "<<date.get_moth()<<endl;
        cout<<"Day of year is: "<<date.get_day()<<endl;
    }

    int get_month() {
        return date.get_moth();
    }

    string get_name() const {
        return name;
    }

    void get_data() {
        string n;
        int p;
        string m;
        int y;
        int mo;
        int d;

        cout << endl;
        cout << endl;
        cout << "Enter your name: ";
        getchar();
        getline(cin, n);
        name = n;
        
        cout << "Enter your phone number: ";
        cin >> p;
        phone_number = p;
        getchar();
        
        cout << "Enter your mail address: ";
        getline(cin, m);
        gmail = m;
        
        cout << "Enter year of birth: ";
        cin >> y;
        date.set_year(y);
        
        cout << "Enter month of birth: ";
        cin >> mo;
        date.set_month(mo);
        
        cout << "Enter day of birth: ";
        cin >> d;
        date.set_day(d);
    }
};

contact::contact(string n, int p, string m, int y, int mo, int d) : date(y, mo, d) {
    name = n;
    phone_number = p;
    gmail = m;
}

class contact_book {
contact arr[2];
int input;

public:
    contact_book(string = "", int = 0, string = "", int = 0, int = 0, int = 0);
    
    void add_contact() {
        for(int i=0; i<2; i++) {
            arr[i].get_data();
        }
    }

    void print() {
        for (int i = 0; i < 2; i++) {
            cout << endl;
            arr[i].print();
        }

        cout << "Contact with birthdays in month: ";
        cin >> input;
        
        for (int i = 0; i < 2; i++) {
            if (input == arr[i].get_month()) {
                cout << "Name is: " << arr[i].get_name()<<endl;
            }
        }
    }
};

contact_book::contact_book(string n, int p, string m, int y, int mo, int d) {}

int main() {
    contact_book c1;
    c1.add_contact();
    c1.print();

    return 0;
}