#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Form {
    string userName, password, Email, searchName, searchPass, searchEmail;
    fstream file;

public:
    void signUp() {
        cout << "---------signUp--------" << endl;
        cout << "Enter your username : " << endl;
        cin.ignore(); // ignore newline character left in input buffer
        getline(cin, userName);
        cout << "Enter your email address :" << endl;
        getline(cin, Email);
        cout << "Enter your password :" << endl;
        getline(cin, password);
        file.open("loginData.txt", ios::out | ios::app);
        if (file.is_open()) {
            file << userName << " * " << Email << " * " << password << endl;
            file.close();
            cout << "Sign up successful!" << endl;
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void login() {
        string line, temp;
        cout << "----------login----------" << endl;
        cout << "Enter your username : " << endl;
        cin.ignore(); // ignore newline character left in input buffer
        getline(cin, searchName);
        cout << "Enter your password : " << endl;
        getline(cin, searchPass);
        file.open("loginData.txt", ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                size_t pos1 = line.find(" * ");
                size_t pos2 = line.find(" * ", pos1 + 3);
                if (pos1 != string::npos && pos2 != string::npos) {
                    temp = line.substr(0, pos1);
                    if (temp == searchName) {
                        temp = line.substr(pos2 + 3);
                        if (temp == searchPass) {
                            cout << "Account login successful!" << endl;
                            cout << "Username: " << searchName << endl;
                            cout << "Email: " << line.substr(pos1 + 3, pos2 - pos1 - 3) << endl;
                            return;
                        }
                    }
                }
            }
            cout << "Invalid username or password!" << endl;
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }

    void forgetPwd() {
        string line, temp;
        cout << "Enter your username : " << endl;
        cin.ignore(); // ignore newline character left in input buffer
        getline(cin, searchName);
        cout << "Enter your email address : " << endl;
        getline(cin, searchEmail);
        file.open("loginData.txt", ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                size_t pos1 = line.find(" * ");
                size_t pos2 = line.find(" * ", pos1 + 3);
                if (pos1 != string::npos && pos2 != string::npos) {
                    temp = line.substr(0, pos1);
                    if (temp == searchName) {
                        temp = line.substr(pos1 + 3, pos2 - pos1 - 3);
                        if (temp == searchEmail) {
                            cout << "Account found!" << endl;
                            cout << "Your password is: " << line.substr(pos2 + 3) << endl;
                            return;
                        }
                    }
                }
            }
            cout << "Record not found!" << endl;
            file.close();
        } else {
            cout << "Unable to open file!" << endl;
        }
    }
};

int main() {
    Form obj;
    int choice;
    cout << "Enter what operation you want to perform: " << endl;
    cout << "1. Login" << endl;
    cout << "2. Sign up" << endl;
    cout << "3. Forget password" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            obj.login();
            break;
        case 2:
            obj.signUp();
            break;
        case 3:
            obj.forgetPwd();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    return 0;
}