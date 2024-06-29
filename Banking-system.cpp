#include <iostream>
using namespace std;

class Bankingsystem {
private:
    int accno, ph;
    float balance;
    string name;
    int age;
    char gender;

public:
    Bankingsystem(int ano, int phno, float bal, string n, int ag, char gen) {
        accno = ano;
        ph = phno;
        balance = bal;
        name = n;
        age = ag;
        gender = gen;
    }
    
    void acccreation() {
        cout << "Enter your name: ";
        cin >> name;
        if (name.length() > 15) {
            cout << "Name too long" << endl;
            return;
        }
        cout << "Enter your age: ";
        cin >> age;
        if (age < 18) {
            cout << "You are not eligible to open an account" << endl;
            return;
        }
        cout << "Enter your gender (M/F): ";
        cin >> gender;
        if (gender != 'M' && gender != 'F') {
            cout << "Invalid gender" << endl;
            return;
        }
        cout << "Enter your account number: ";
        cin >> accno;
        cout << "Enter your phone number: ";
        cin >> ph;
        cout << "Enter your balance: ";
        cin >> balance;

        cout << "Account created successfully!" << endl;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(float amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        } else {
            cout << "Invalid amount or insufficient balance!" << endl;
        }
    }

    void displayAccountInfo() {
        cout << "Account Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << (gender == 'M' ? "Male" : "Female") << endl;
        cout << "Account Number: " << accno << endl;
        cout << "Phone Number: " << ph << endl;
        cout << "Balance: " << balance << endl;
    }

    ~Bankingsystem() {}
};

int main() {
    cout << "\t\tWelcome to the Banking System\t\t" << endl;

    Bankingsystem obj1(0, 0, 0.0, "", 0, ' ');
    obj1.acccreation();

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Info\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        float amount;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                obj1.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                obj1.withdraw(amount);
                break;
            case 3:
                obj1.displayAccountInfo();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}