#include <iostream>
#include <limits>

using namespace std;

// Class to represent a student
class Student {
private:
    int admno;            // Admission number
    char name[100];         // Full name
    char gender;           // Gender
    int semester;          // Semester
    char grade;
    float marks;           // Marks out of 500
    int age;
    
public:
    void getData();        // Method to input student details
    void showData() const; // Method to display student information
    int getAdmno() const { return admno; } // Method to retrieve admission number
};

// Class to represent a teacher
class Teacher {
private:
    int empId;             // Employee ID
    char name[20];         // Full name
    char gender;           // Gender
    
public:
    void getData();        // Method to input teacher details
    void showData() const; // Method to display teacher information
    int getEmpId() const { return empId; } // Method to retrieve employee ID
};

// Function to input student details
void Student::getData() {
    cout << "Enter Student Details...\n";

    // Input validation for admission number
    while (true) {
        cout << "Admission No.     : ";
        cin >> admno;
        if (cin.fail() || admno<1 || admno > 1000) 
        {
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // Input validation for Full Name
    while (true) 
    {
        cout << "Full Name         : ";
        cin.getline(name, 100);

        // Check if the name contains only alphabetical characters and spaces
        bool validName = true;
        for (int i = 0; name[i] != '\0'; ++i)
        {
            if (!isalpha(name[i]) && name[i] != ' ') {
                validName = false;
                break;
            }
        }

        if (validName)
        {
            break;
        } else {
            cout << "Invalid input. Please enter a valid name.\n";
        }
    }

    // Input validation for gender
    while (true) 
    {
        cout << "Gender (M/F)      : ";
        cin >> gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (gender == 'M' || gender == 'F' || gender == 'm' || gender == 'f') 
        {
            break;
        } else 
        {
            cout << "Invalid input. Please enter 'M' or 'F'.\n";
        }
    }

    // Input validation for semester
    while (true)
    {
        cout << "Semester          : ";
        cin >> semester;
        if (cin.fail() || semester<1 || semester > 12)
        {
            cout << "Invalid input. Please enter a  value between 1 to 12 .\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // Input validation for marks
    while (true) 
    {
        cout << "Marks (out of 500): ";
        cin >> marks;
        if (cin.fail() || marks < 0 || marks > 500) 
        {
            cout << "Invalid input. Please enter a  value between 0 and 500.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else 
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    
    // Input validation for grade
    while (true) 
    {
        cout << "Grade (P/F)      : ";
        cin >> grade;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (grade == 'P' || grade == 'F' || grade == 'p' || grade == 'f')
        {
            break;
        } else
        {
            cout << "Invalid input. Please enter 'P' or 'F'.\n";
        }
    }
    
 // Input validation for age
    while (true)
    {
        cout << "Age          : ";
        cin >> age;
        if (cin.fail() || age<4 || age > 1000)
        {
            cout << "Invalid input. Please enter a valid value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
}


// Function to display student information
void Student::showData() const {
    
    cout << "\n\nStudent Details...\n";
    cout << "Admission No.     : " << admno << endl;
    cout << "Full Name         : " << name << endl;
    cout << "Gender            : " << gender << endl;
    cout << "Semester          : " << semester << endl;
    cout << "Marks (out of 500): " << marks << endl;
    cout << "Grade            :  " << grade << endl;
    cout<< "Age                : " << age      <<endl;
    cout << endl;
}

// Function to input teacher details
void Teacher::getData() {
    cout << "Enter Teacher Details...\n";

    // Input validation for employee ID
    while (true) {
        cout << "Employee ID       : ";
        cin >> empId;
         if(cin.fail() ||empId<1 || empId > 1000) {
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    // Input validation for Full Name
    while (true) {
        cout << "Full Name         : ";
        cin.getline(name, 100);

        // Check if the name contains only alphabetical characters and spaces
        bool validName = true;
        for (int i = 0; name[i] != '\0'; ++i) {
            if (!isalpha(name[i]) && name[i] != ' ') {
                validName = false;
                break;
            }
        }

        if (validName) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid name.\n";
        }
    }

    // Input validation for gender
    while (true) {
        cout << "Gender (M/F)      : ";
        cin >> gender;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (gender == 'M' || gender == 'F' || gender == 'm' || gender == 'f') {
            break;
        } else {
            cout << "Invalid input. Please enter 'M' or 'F'.\n";
        }
    }
}

// Function to display teacher information
void Teacher::showData() const {
    cout << "\n\nTeacher Details...\n";
    cout << "Employee ID       : " << empId << endl;
    cout << "Full Name         : " << name << endl;
    cout << "Gender            : " << gender << endl;
    cout << endl;
}

// Main function
int main() {
    const int MAX_STUDENTS = 200;
    const int MAX_TEACHERS = 50;

    Student students[MAX_STUDENTS]; // Array to store students
    Teacher teachers[MAX_TEACHERS]; // Array to store teachers

    int studentCount =0;        // Track the number of students
    int teacherCount =0;        // Track the number of teachers

    int choice;
    do {
        cout << "SCHOOL MANAGEMENT SYSTEM\n";
        
        // Display menu options
        cout << "1. Enter Student Data\n";
        cout << "2. Enter Teacher Data\n";
        cout << "3. Display Student Data\n";
        cout << "4. Display Teacher Data\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        
        // Input validation for choice
        while (true) {
            cin >> choice;
            if (cin.fail()) {
                cout << "Invalid input. Please enter a numeric value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        // Switch statement for menu options
        switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    students[studentCount++].getData();
                    cout << "Student data entered successfully!\n";
                } else {
                    cout << "Maximum number of students reached!\n";
                }
                break;

            case 2:
                if (teacherCount < MAX_TEACHERS) {
                    teachers[teacherCount++].getData();
                    cout << "Teacher data entered successfully!\n";
                } else {
                    cout << "Maximum number of teachers reached!\n";
                }
                break;

            case 3:
                cout << "Enter Admission No. to display student data: ";
                int admNo;
                cin >> admNo;
                for (int i = 0; i < studentCount; ++i) {
                    if (students[i].getAdmno() == admNo) {
                        students[i].showData();
                        break;
                    }
                }
                break;

            case 4:
                cout << "Enter Employee ID to display teacher data: ";
                int empId;
                cin >> empId;
                for (int i = 0; i < teacherCount; ++i) {
                    if (teachers[i].getEmpId() == empId) {
                        teachers[i].showData();
                        break;
                    }
                }
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}