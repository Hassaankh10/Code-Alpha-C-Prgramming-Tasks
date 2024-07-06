#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Login_system
{
private:
    string username;
    string password;
    string name;
    string phone;
    string email;
    string address;

public:
    Login_system() {} // Default constructor for flexibility

    Login_system(string username, string password, string name, string phone, string email, string address)
        : username(username), password(password), name(name), phone(phone), email(email), address(address) {}

    void display();

    bool check_login(string username, string password);
    bool register_user(string username, string password, string name, string phone, string email, string address);
};

void Login_system::display()
{
    cout << "Username: " << username << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Email: " << email << endl;
    cout << "Address: " << address << endl;
}

bool Login_system::check_login(string username, string password)
{
    ifstream infile("users.txt"); // Open file for reading

    if (!infile)
    {
        cerr << "Error: Failed to open file for reading." << endl;
        return false;
    }

    string u, p;
    while (infile >> u >> p)
    {
        if (u == username && p == password)
        {
            infile.close();
            return true; // Found matching credentials
        }
    }

    infile.close();
    return false; // Credentials not found
}

bool Login_system::register_user(string username, string password, string name, string phone, string email, string address)
{
    ofstream outfile("users.txt", ios::app); // Open file for appending

    if (!outfile)
    {
        cerr << "Error: Failed to open file for writing." << endl;
        return false;
    }

    // Write user details to file
    outfile << username << " " << password << " " << name << " " << phone << " " << email << " " << address << endl;

    outfile.close();
    return true;
}

void menu()
{
    Login_system user;

    cout << "Select an option" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            string username, password, name, phone, email, address;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone: ";
            cin >> phone;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter address: ";
            cin.ignore(); // Ignore newline character left in the stream
            getline(cin, address);

            if (user.register_user(username, password, name, phone, email, address))
            {
                cout << "Registration Successful!" << endl;
            }
            else
            {
                cout << "Registration Failed!" << endl;
            }
            menu();
            break;
            
        }
        case 2:
        {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (user.check_login(username, password))
            {
                cout << "Login Successful" << endl;
                // Display user details if needed
            }
            else
            {
                cout << "Invalid username or password" << endl;
            }
            menu();
            break;
        }
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            menu();
            break;
    }
}

int main()
{
    cout << "\t\tWelcome to Login System\t\t" << endl << endl;
    menu();

    return 0;
}
