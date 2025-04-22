#include <iostream>
#include "LabCourse.h"
using namespace std;

LabCourse::LabCourse(string code, int c) {
    courseCode = code;
    credits = c;
}

char LabCourse::calculateGrade() {
    return credits >= 2 ? 'A' : 'C';
}

void LabCourse::displayInfo() {
    cout << "Course Type: Lab Course" << endl;
    cout << "Course Code: " << courseCode << endl;
    cout << "Credits: " << credits << endl;
}
