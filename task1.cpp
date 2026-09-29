#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to convert grade into grade point
float getGradePoint(char grade) {
    switch (grade) {
        case 'A':
        case 'a': return 10.0;
        case 'B':
        case 'b': return 8.0;
        case 'C':
        case 'c': return 6.0;
        case 'D':
        case 'd': return 5.0;
        case 'E':
        case 'e': return 4.0;
        case 'F':
        case 'f': return 0.0;
        default: return -1.0;
    }
}

int main() {
    int courses;

    cout << "Enter number of courses: ";
    cin >> courses;

    vector<char> grades(courses);
    vector<float> credits(courses);
    vector<float> gradePoints(courses);

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < courses; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> grades[i];

        gradePoints[i] = getGradePoint(grades[i]);

        if (gradePoints[i] == -1) {
            cout << "Invalid grade entered!" << endl;
            return 0;
        }

        cout << "Enter credit hours: ";
        cin >> credits[i];

        // Calculate grade point × credit hours
        totalGradePoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }

    // Calculate GPA
    float GPA = totalGradePoints / totalCredits;

    // Since only one semester is entered,
    // semester GPA is also the current CGPA.
    float CGPA = GPA;

    // Display course details
    cout << "\n========== COURSE DETAILS ==========\n";

    for (int i = 0; i < courses; i++) {
        cout << "Course " << i + 1
             << " | Grade: " << grades[i]
             << " | Credits: " << credits[i]
             << " | Grade Point: " << gradePoints[i]
             << endl;
    }

    cout << fixed << setprecision(2);

    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nTotal Grade Points : " << totalGradePoints;
    cout << "\nSemester GPA       : " << GPA;
    cout << "\nOverall CGPA       : " << CGPA << endl;

    return 0;
}