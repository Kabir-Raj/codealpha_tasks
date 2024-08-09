
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Course
{
    string name;
    double credits;
    string grade;
    double gradePoints;
};

struct Semester
{
    int semesterNumber;
    vector<Course> courses;
    double totalCredits;
    double totalGradePoints;
    double GPA;
};

// Function to convert grade to grade points
double getGradePoints(string grade)
{
    if (grade == "A")
        return 4.0;
    else if (grade == "B")
        return 3.0;
    else if (grade == "C")
        return 2.0;
    else if (grade == "D")
        return 1.0;
    else if (grade == "F")
        return 0.0;
    else
        return 0.0; // Default for invalid grade
}

int main()
{
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    vector<Semester> semesters(numSemesters);
    double totalCGPACredits = 0;
    double totalCGPAGradePoints = 0;

    for (int i = 0; i < numSemesters; ++i)
    {
        Semester &semester = semesters[i];
        semester.semesterNumber = i + 1;

        int numCourses;
        cout << "Enter the number of courses for semester " << semester.semesterNumber << ": ";
        cin >> numCourses;

        semester.courses.resize(numCourses);
        semester.totalCredits = 0;
        semester.totalGradePoints = 0;

        for (int j = 0; j < numCourses; ++j)
        {
            Course &course = semester.courses[j];
            cout << "Enter course " << j + 1 << " name: ";
            cin >> course.name;
            cout << "Enter course " << j + 1 << " credits: ";
            cin >> course.credits;
            cout << "Enter course " << j + 1 << " grade (A, B, C, D, F): ";
            cin >> course.grade;

            course.gradePoints = getGradePoints(course.grade);
            semester.totalCredits += course.credits;
            semester.totalGradePoints += course.gradePoints * course.credits;
        }

        semester.GPA = semester.totalGradePoints / semester.totalCredits;
        totalCGPACredits += semester.totalCredits;
        totalCGPAGradePoints += semester.totalGradePoints;

        cout << "GPA for semester " << semester.semesterNumber << ": " << semester.GPA << endl;
    }

    double CGPA = totalCGPAGradePoints / totalCGPACredits;
    cout << "CGPA: " << CGPA << endl;

    return 0;
}
