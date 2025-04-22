#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main() {
    cout << "24K-0748\nKHUBAIB UR REHMAN\n" << endl;

    Course* c1 = new LectureCourse("CS101", 3);
    Course* c2 = new LabCourse("CS101L", 1);

    c1->displayInfo();
    cout << "Grade: " << c1->calculateGrade() << endl << endl;

    c2->displayInfo();
    cout << "Grade: " << c2->calculateGrade() << endl << endl;

    delete c1;
    delete c2;

    return 0;
}
    
