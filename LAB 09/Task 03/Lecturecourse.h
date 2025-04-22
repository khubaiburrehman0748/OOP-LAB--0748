#ifndef LECTURECOURSE_H
#define LECTURECOURSE_H

#include "Course.h"

class LectureCourse : public Course {
public:
    LectureCourse(string code, int c);
    char calculateGrade();
    void displayInfo();
};

#endif
