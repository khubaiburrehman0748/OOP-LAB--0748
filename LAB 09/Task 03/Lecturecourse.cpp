#include <iostream>
#include "LectureCourse.h"
using namespace std;

LectureCourse::LectureCourse(string code, int c) {
    courseCode = code;
    credits = c;
}

char LectureCourse::calculateGrade() {
    return credits >= 3 ? 'A' : 'B';
}

void LectureCourse::displayInfo() {
    cout << "Course Type: Lecture Course" << endl;
    cout << "Course Code: " << courseCode << endl;
    cout << "Credits: " << credits << endl;
}
