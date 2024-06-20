#include <iostream>
using namespace std;

int main() {
    string name;
    int scount;
    cout << "\tWelcome to CGPA Calculator" << endl;
    cout << "Enter Your Name: ";
    cin >> name;
    cout << "Enter the semester you are in: ";
    cin >> scount;

    float GPA[scount];
    float CGPA = 0;
    int totalCredits = 0;

    for (int i = 0; i < scount; i++) {
        cout << "\nEnter the number of courses you took in semester " << i + 1 << ": ";
        int numberOfSubjects;
        cin >> numberOfSubjects;

        int credits[numberOfSubjects];
        double grades[numberOfSubjects];

        float semesterCredits = 0;
        float semesterGPA = 0;

        for (int j = 0; j < numberOfSubjects; j++) {
            cout << "\nEnter the grade and credits for Course " << j + 1 << ": ";
            cin >> grades[j] >> credits[j];
            semesterCredits += credits[j];
            semesterGPA += grades[j] * credits[j];
        }

        GPA[i] = semesterGPA / semesterCredits;
        totalCredits += semesterCredits;
        CGPA += semesterGPA;

        cout << "\nThe GPA for semester " << i + 1 << " is: " << GPA[i] << endl;
    }

    CGPA /= totalCredits;
    cout << "\nThe CGPA is: " << CGPA << endl;

    return 0;
}
