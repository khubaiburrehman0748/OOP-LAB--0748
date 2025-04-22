#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
public:
    string courseCode;
    int credits;

    virtual char calculateGrade() = 0;
    virtual void displayInfo() = 0;

    virtual ~Course() {}
};

#endif
