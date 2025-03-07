#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;
    int numScores;

public:
    Student(int id, string name, int* scores, int numScores) {
        this->id = id;
        this->name = name;
        this->numScores = numScores;
        this->scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            this->scores[i] = scores[i];
        }
    }

    Student( Student &other) {
        this->id = other.id;
        this->name = other.name;
        this->numScores = other.numScores;
        this->scores = new int[other.numScores];
        for (int i = 0; i < other.numScores; i++) {
            this->scores[i] = other.scores[i];
        }
    }

    ~Student() {
        delete[] scores;
    }

    void display()  {
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Scores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl << "-------------------------" << endl;
    }
};

int main() {
    int scores1[] = {85, 90, 78};
    Student student1(101, "khubaib", scores1, 3);
    cout << "Original Student:" << endl;
    student1.display();

    Student student2 = student1;
    cout << "Copied Student:" << endl;
    student2.display();

    int scores2[] = {88, 92, 80};
    Student student3(102, "taha", scores2, 3);
    cout << "Another Student:" << endl;
    student3.display();

    return 0;
}