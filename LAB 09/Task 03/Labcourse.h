#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"

class LabCourse : public Course {
public:
    LabCourse(string code, int c);
    char calculateGrade();
    void displayInfo();
};

#endif


