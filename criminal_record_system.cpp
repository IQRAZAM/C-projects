#include <iostream>
#include <string>
using namespace std;
// Class for pre-registered criminals(inheritence)
class regcriminal {
protected:              //Encapsulation
    string Name[10];
    int Age[10];
    int Reg[10];
    int Date[10];
    int Month[10];
    int Year[10];
    string Crime[10];
    string Penalty[10];
public:
	 int Totalcriminal = 10;
    regcriminal() {
    Name[0] = "qadeer"; Age[0] = 34; Reg[0] = 1; Date[0] = 2; Month[0] = 3; Year[0] = 2014; Crime[0] = "murder"; Penalty[0] ="life imprisonment";
    Name[1] = "irfan"; Age[1] = 22; Reg[1] = 34; Date[1] = 4; Month[1] = 8; Year[1] = 2018; Crime[1] = "Robery"; Penalty[1] = "two year in prison";
    Name[2] = "ateeq"; Age[2] = 18; Reg[2] = 44; Date[2] = 7; Month[2] = 4; Year[2] = 2004; Crime[2] = "drug offense"; Penalty[2] = "two lac ";
    Name[3] = "saad"; Age[3] = 45; Reg[3] = 45; Date[3] = 5; Month[3] = 5; Year[3] = 2023; Crime[3] = "Fraud";Penalty[3] = "50 lac";
    Name[4] = "hafeez"; Age[4] = 30; Reg[4] = 453; Date[4] = 30; Month[4] = 2; Year[4] = 2011; Crime[4] = "kidnapping"; Penalty[4]="1 year in prsion" ;
    Name[5] = "adeel"; Age[5] = 28; Reg[5] = 437; Date[5] = 20; Month[5] = 3; Year[5] = 2024; Crime[5] = "vandalism";  Penalty[5] = "30 lac";
    Name[6] = "daniyal"; Age[6] = 22; Reg[6] = 675; Date[6] = 16; Month[6] = 4; Year[6] = 2022; Crime[6] = "perjury";  Penalty[6] = "5 years in prison";
    Name[7] = "haris"; Age[7] = 19; Reg[7] = 823; Date[7] = 19; Month[7] = 4; Year[7] = 2020; Crime[7] = "pickpocket";  Penalty[7] = "60 thousand";
    Name[8] = "sajjad"; Age[8] = 50; Reg[8] = 987; Date[8] = 25; Month[8] = 10; Year[8] = 2005; Crime[8] = "robery";  Penalty[8] = "20 lacs";
    Name[9] = "waleed"; Age[9] = 24; Reg[9] = 678; Date[9] = 8; Month[9] = 12; Year[9] = 2008; Crime[9] = "domestic violence";  Penalty[9] = "6 years in prison";
    }
    void virtual show(){
    	cout<<"details are"<<endl;
	}
    void virtual searched(){
    	cout<<"Searched data"<<endl;
	}
    void virtual changes(){
    	cout<<"Changed data"<<endl;
    
	}
	void virtual deleteRecords() {
		cout<<"Delete records"<<endl;
	}
};
	
class functions: public regcriminal {
public:
    void show() {
        cout << "Name\t\tAge\tReg no\tDate\tMonth\tYear\tCrime\t\tpenalty" << endl;
        cout << "---------------------------------------------------------------------------" << endl;
        for (int i = 0; i < Totalcriminal; i++) {
            cout << Name[i] << "\t\t" << Age[i] << "\t" << Reg[i] << "\t" << Date[i] << "\t" << Month[i] << "\t" << Year[i] << "\t" << Crime[i] << "\t\t" <<  Penalty[i] << endl;
        }
    }

    void searched() {
        
        string n;
        cout<<"enter name "<<endl;
        cin.ignore();
        getline(cin, n);
     
        
        bool found = false;

        for (int i = 0; i < Totalcriminal; i++) {
            if (n == Name[i]) {
                cout << "Criminal details are:" << endl;
                cout << "Name: " << Name[i] << endl;
                cout << "Age: " << Age[i] << endl;
                cout << "Registration number: " << Reg[i] << endl;
                cout << "Date: " << Date[i] << endl;
                cout << "Month: " << Month[i] << endl;
                cout << "Year: " << Year[i] << endl;
                cout << "Crime: " << Crime[i] << endl;
                cout << "Punishment: " <<  Penalty[i] << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No record found." << endl;
        }
    }

    void changes() {
        int regnu;
        cout << "Enter registration number of criminal you want to change data of: ";
        cin >> regnu;
        bool found = false;

        for (int i = 0; i < Totalcriminal; i++) {
            if (regnu == Reg[i]) {
                cout << "Previous data:" << endl;
                cout << "Name: " << Name[i] << endl;
                cout << "Age: " << Age[i] << endl;
                cout << "Registration number: " << Reg[i] << endl;
                cout << "Date: " << Date[i] << endl;
                cout << "Month: " << Month[i] << endl;
                cout << "Year: " << Year[i] << endl;
                cout << "Crime: " << Crime[i] << endl;
                cout << "Punishent: " << Penalty[i] << endl;

                cout << "Change data of the criminal:" << endl;
                cout << "Enter name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, Name[i]);
                cout << "Enter age: ";
                cin >> Age[i];
                cout << "Enter registration number: ";
                cin >> Reg[i];
                cout << "Date (dd): ";
                cin >> Date[i];
                cout << "Month (mm): ";
                cin >> Month[i];
                cout << "Year (yyyy): ";
                cin >> Year[i];
                cout << "Crime: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, Crime[i]);
                cout << "Punishment: ";
                cin.ignore(); 
                 getline(cin, Penalty[i]);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Data not found." << endl;
        }
    }

    void deleteRecords() {
        int regnu;
        cout << "Enter registration number of the criminal you want to delete: ";
        cin >> regnu;
        bool found = false;

        for (int i = 0; i < Totalcriminal; i++) {
            if (regnu == Reg[i]) {
                found = true;
                // Shift records to remove the deleted entry
                for (int j = i; j < Totalcriminal-1; j++) {  // Updated to 9 instead of 10 to avoid out-of-bounds
                    Name[j] = Name[j + 1];
                    Age[j] = Age[j + 1];
                    Reg[j] = Reg[j + 1];
                    Date[j] = Date[j + 1];
                    Month[j] = Month[j + 1];
                    Year[j] = Year[j + 1];
                    Crime[j] = Crime[j + 1];
                    Penalty[j] =  Penalty[j + 1];
                }
                Totalcriminal--;
                cout<<"Data has been deleted"<<endl;
                break;
            }
        }
        if (!found) {
            cout << "Record not found." << endl;
        }
    }
};
// Base class with pure virtual function(abstract class)
class Criminal {
protected:
    string name[100];
    int age[100];
    double reg[100];
    int date[100];
    int month[100];
    int year[100];
    string crime[100];
    string  penalty[100];
    

public:
	 int totalcriminal = 0;
     
    virtual void displayDetails() = 0;  // Pure virtual function

};

// Derived class for detailed operations(Inheritance)
class Detail : public Criminal {
public:
    void input() {
        int n;
        cout << "Enter number of criminals: ";
        cin >> n;

        if (totalcriminal + n > 100) { // Check to avoid array overflow
            cout << "Exceeds maximum number of criminals." << endl;
            return;
        }

        for (int i = 0; i < totalcriminal + n; i++) {
            cout << "Enter criminal details: " << i + 1 << endl;
            cout << "Enter name: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, name[i]);
            cout << "Enter age: ";
            cin >> age[i];
            cout << "Enter registration number: ";
            cin >> reg[i];
            cout << "Date (dd): ";
            cin >> date[i];
            cout << "Month (mm): ";
            cin >> month[i];
            cout << "Year (yyyy): ";
            cin >> year[i];
            cout << "Crime: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, crime[i]);
            cout << "punishment : ";
            getline(cin,penalty[i]);
        }
        totalcriminal += n;
    }
     void show() {
        if (totalcriminal == 0) {
            cout << "No data found." << endl;
        } else {
            for (int i = 0; i < totalcriminal; i++) {
                cout << "Criminal details: " << i + 1 << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Age: " << age[i] << endl;
                cout << "Registration number: " << reg[i] << endl;
                cout << "Date: " << date[i] << endl;
                cout << "Month: " << month[i] << endl;
                cout << "Year: " << year[i] << endl;
                cout << "Crime: " << crime[i] << endl;
                cout << "Punishment: " << penalty[i] << endl;
            }
        }
    }

    void search() {
        
        cout << "Enter name of the criminal you want to search: ";
        int j = 7;

       char name[j];
       for(int j = 0 ; j<7;j++){
        cin>>name[j];
       }
        bool found = false;

        for (int i = 0; i < totalcriminal; i++) {
            if ( name[j]== name[i]) {
                cout << "Criminal details are:" << endl;
                cin.ignore();
                cout << "Name: " << name[i] << endl;
                cout << "Age: " << age[i] << endl;
                cout << "Registration number: " << reg[i] << endl;
                cout << "Date: " << date[i] << endl;
                cout << "Month: " << month[i] << endl;
                cout << "Year: " << year[i] << endl;
                cin.ignore();
                cout << "Crime: " << crime[i] << endl;
                cout << "Punishment: " << penalty[i] << endl;
                cin.ignore();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No record found." << endl;
        }
    }

    void change() {
        double regno;
        cout << "Enter registration number of criminal you want to change data of: ";
        cin >> regno;
        bool found = false;

        for (int i = 0; i < totalcriminal; i++) {
            if (regno == reg[i]) {
                cout << "Previous data:" << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Age: " << age[i] << endl;
                cout << "Registration number: " << reg[i] << endl;
                cout << "Date: " << date[i] << endl;
                cout << "Month: " << month[i] << endl;
                cout << "Year: " << year[i] << endl;
                cout << "Crime: " << crime[i] << endl;
                cout << "Punishment: " << penalty[i] << endl;

                cout << "Change data of the criminal:" << endl;
                cout << "Enter name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name[i]);
                cout << "Enter age: ";
                cin >> age[i];
                cout << "Enter registration number: ";
                cin >> reg[i];
                cout << "Date (dd): ";
                cin >> date[i];
                cout << "Month (mm): ";
                cin >> month[i];
                cout << "Year (yyyy): ";
                cin >> year[i];
                cout << "Crime: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, crime[i]);
                cout << "Punishment:";
                cin.ignore();
                getline(cin,penalty[i]);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Data not found." << endl;
        }
    }

   

    void deleteRecord() {
        double regno;
        cout << "Enter registration number of the criminal you want to delete: ";
        cin >> regno;
        bool found = false;

        for (int i = 0; i < totalcriminal; i++) {
            if (regno == reg[i]) {
                found = true;
                // Shift records to remove the deleted entry
                for (int j = i; j < totalcriminal - 1; j++) {
                    name[j] = name[j + 1];
                    age[j] = age[j + 1];
                    reg[j] = reg[j + 1];
                    date[j] = date[j + 1];
                    month[j] = month[j + 1];
                    year[j] = year[j + 1];
                    crime[j] = crime[j + 1];
                    penalty[j] = penalty[j + 1];
                }
                totalcriminal--;
                break;
            }
        }
        if (!found) {
            cout << "Record not found." << endl;
        }
    }

    void displayDetails() override {
        show();  // Use the existing show function  (Polymorphism)
    }
};



int main() {
    cout << "\t\t\t\t\t\t*------------------------------*" << endl;
    cout << "\t\t\t\t\t\t¦   Criminal RECORD SYSTEM     ¦" << endl;
    cout << "\t\t\t\t\t\t*------------------------------*" << endl;
    Detail c;
    functions d;
    int press;
    do {
        cout << "MENU" << endl
             << "1. Show already registered criminals\n"
             << "2. Search registered criminal\n"
             << "3. Change data of registered criminal\n"
             << "4. Delete already existing data\n"
             << "5. Enter criminal's data.\n"
             << "6. Search criminal data.\n"
             << "7. Change data.\n"
             << "8. Show criminal data.\n"
             << "9. Delete criminal data.\n"
             
             << "10. EXIT" << endl;
        cout << "Enter choice: ";
        cin >> press;
        
        switch (press) {
           
            case 1:
                d.show();
                break;
            case 2:
                d.searched();
                break;
            case 3:
                d.changes();
                break;
            case 4:
                d.deleteRecords();
                break;
            case 5:
                c.input();
                break;
            case 6:
                c.search();
                break;
            case 7:
                c.change();
                break;
            case 8:
                c.displayDetails();  
                break;
            case 9:
                c.deleteRecord();
                break;
            case 10:
                cout << "Exiting......" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (press != 10);
    cout << "\t\t\t-----------------END OF PROGRAM-----------------" << endl;
    return 0;
}